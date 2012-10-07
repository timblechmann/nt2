/*******************************************************************************
 *         Copyright 2003-2012 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2011-2012 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_TOOLBOX_LINALG_FUNCTIONS_DETAILS_SJQR_HPP_INCLUDED
#define NT2_TOOLBOX_LINALG_FUNCTIONS_DETAILS_SJQR_HPP_INCLUDED
// Matlab syntaxes
// Note that the syntaxes can be obtained using sjqr and pqr
// These 2 are qr ie no_p
//    [q,r] = qr(a), where a is m-by-n, produces an m-by-n upper triangular
//     matrix r and an m-by-m unitary matrix q so that a = q*r.

//     [q,r] = qr(a,0) produces the "economy size" decomposition.
//     if m>n, only the first n columns of q and the first n rows of r are
//     computed. if m<=n, this is the same as [q,r] = qr(a).

// and also these
//     x = qr(a) and x = qr(a,0) return the output of lapack's *geqrf routine.
//     (values() in the class)
//     triu(x) is the upper triangular factor r.
//////////// TODO
// to get the econmy size we much expand the results to the liked dimensions
////////////
// The others use pqr

//     if a is full:

//     [q,r,p] = qr(a) produces unitary q, upper triangular r and a
//     permutation matrix p so that a*p = q*r. the column permutation p is
//     chosen so that abs(diag(r)) is decreasing.

//     [q,r,p] = qr(a,'vector') returns the permutation information as a
//     vector instead of a matrix.  that is, p is a row vector such that
//     a(:,p) = q*r. similarly, [q,r,p] = qr(a,'matrix') returns a permutation
//     matrix e. this is the default behavior.

//     [q,r,p] = qr(a,0) produces an "economy size" decomposition in which p
//     is a permutation vector, so that a(:,p) = q*r.


#include <nt2/toolbox/linalg/details/utility/workspace.hpp>
#include <nt2/toolbox/linalg/details/utility/options.hpp>
#include <nt2/include/functions/sjqr.hpp>
#include <nt2/include/functions/of_size.hpp>
#include <nt2/include/functions/min.hpp>
#include <nt2/include/functions/max.hpp>
#include <nt2/include/functions/zeros.hpp>
#include <nt2/include/functions/eye.hpp>
#include <nt2/include/functions/triu.hpp>
#include <nt2/include/functions/expand.hpp>
#include <nt2/include/functions/globalprod.hpp>
#include <nt2/include/functions/globalsum.hpp>
#include <nt2/include/functions/height.hpp>
#include <nt2/include/functions/width.hpp>
#include <nt2/include/functions/first_index.hpp>
#include <nt2/include/functions/diag_of.hpp>
#include <nt2/include/functions/if_one_else_zero.hpp>
#include <nt2/include/constants/one.hpp>
#include <nt2/include/constants/eps.hpp>
#include <nt2/include/functions/isempty.hpp>
#include <nt2/toolbox/linalg/details/lapack/geqp3.hpp>
#include <nt2/toolbox/linalg/details/lapack/geqrf.hpp>
#include <nt2/toolbox/linalg/details/lapack/gqr.hpp>
#include <nt2/toolbox/linalg/details/lapack/mqr.hpp>
#include <nt2/toolbox/linalg/details/lapack/trtrs.hpp>
#include <nt2/table.hpp>


namespace nt2 {

  namespace details
  {
    template<class T> struct qr_helper
    {
      typedef typename meta::strip<T>::type                   source_t;
      typedef typename source_t::value_type                     type_t;
      typedef typename meta::as_integer<type_t, signed>::type  itype_t;
      typedef typename source_t::index_type                    index_t;
      typedef typename meta::as_real<type_t>::type              base_t;
      typedef T                                                 data_t;
      typedef nt2::table<type_t,nt2::matlab_index_>              tab_t;
      typedef nt2::table<base_t,nt2::matlab_index_>             btab_t;
      typedef nt2::table<itype_t,nt2::matlab_index_>            itab_t;
      typedef nt2::details::workspace<type_t>              workspace_t;
      typedef nt2::table<nt2_la_int,nt2::matlab_index_>         ibuf_t;
      typedef nt2::table<type_t,index_t>                   result_type;
      typedef nt2::table<itype_t,index_t>                 iresult_type;
    };

    template<class T> struct sjqr_members
    {
      typedef qr_helper<T> qrh_t; 
      typedef typename qrh_t::tab_t              tab_t;
      typedef typename qrh_t::data_t            data_t;
      typedef typename qrh_t::result_type  result_type;
      typedef typename qrh_t::base_t            base_t; 
     
      template<class Input>
      sjqr_members ( Input& xpr)
        : a_(xpr)
        , aa_(xpr)
        , m_(nt2::height(xpr))
        , n_(nt2::width(xpr))
        , k_(nt2::min(m_, n_))
        , lda_(a_.leading_size())
        , info_(0)
      {}
      
      data_t values() const { return a_; }
      result_type qr() const { return aa_; }
      
      typename meta::call<tag::triu_(tab_t)>::type
      r() const { return nt2::triu(aa_); }
      
      nt2_la_int status() const { return info_; }

      size_t     rank(base_t epsi = nt2::Eps<base_t>())const
      {
        base_t thresh = nt2::max(n_, m_)*epsi*nt2::max(nt2::abs(diag_of(aa_)(_)));
        return  size_t(globalsum(if_one_else_zero(gt(nt2::abs(nt2::diag_of(aa_)), thresh))));
      }

      base_t absdet()const{
        BOOST_ASSERT_MSG(m_ == n_, "non square matrix in determinant computation");
        return nt2::globalprod(nt2::abs(diag_of(aa_)));
      }
      
      
      data_t                 a_;
      tab_t                 aa_;
      nt2_la_int     m_, n_, k_;
      nt2_la_int           lda_;
      nt2_la_int          info_;
      tab_t                  q_; 
    };
    
    
    template<class T,  char Jobp> struct sjqr
      : public sjqr_members<T>
    {
      typedef qr_helper<T> qrh_t; 
      typedef typename qrh_t::tab_t               tab_t;
      typedef typename qrh_t::ibuf_t             ibuf_t;
      typedef typename qrh_t::iresult_type iresult_type;
      typedef typename qrh_t::result_type   result_type;
      typedef typename qrh_t::type_t             type_t;
      typedef typename qrh_t::base_t             base_t; 
      template<class Input>
      sjqr( Input& xpr)
        : sjqr_members<T>(xpr)
        , jpvt_(nt2::zeros(this->n_,1, nt2::meta::as_<nt2_la_int>()))
        , p_(nt2::zeros(this->n_,this->n_, nt2::meta::as_<type_t>()))
        , tau_(nt2::of_size(this->k_,1))
      {
        nt2::details::geqp3(&this->m_, &this->n_, this->aa_.raw(), &this->lda_,
                            jpvt_.raw(), tau_.raw(), &this->info_);
      }      

      result_type q ()
      {
        nt2_la_int info;
        nt2_la_int nn = this->m_;
        this->q_ = nt2::expand(this->aa_, nn, nn);
        nt2::details::gqr(&this->m_, &nn, &this->k_, this->q_.raw(), &this->lda_,
                          this->tau_.raw(), &info);
        return this->q_;
      }

      result_type p()
      {
        typedef typename qrh_t::type_t type_t; 
        for(unsigned int i=1; i <= nt2::size(p_, 1) ; ++i)
          {
            p_(jpvt_(i), i) = One<type_t>();
          }
        return p_;
      }
      
      iresult_type jp() const
      {
        typedef typename qrh_t::itype_t itype_t;
        typedef typename qrh_t::itab_t   itab_t; 
        itype_t start = first_index<1>(this->a_); 
        itab_t jip(of_size(1, numel(jpvt_)));
        for(size_t i=1; i <= numel(jpvt_); ++i) jip(i) = jpvt_(i)+start-1;
        return jip;
      }

      //==========================================================================
      // Solver interface
      //==========================================================================
      template<class XPR> result_type solve(const XPR & b, base_t epsi = nt2::Eps<base_t>(),
                                            bool transpose = false)const
      {
        tab_t bb = b; 
        char side = 'L';
        char tr = (transpose) ? 'N' : !is_real(type_t(1))? 'C':'T';
        nt2_la_int M = nt2::size(bb, 1), N = nt2::size(bb, 2);
        nt2_la_int ldb = bb.leading_size();
        nt2_la_int info;
        nt2::details::mqr(&side, &tr, &M, &N, &this->k_, this->aa_.raw(), &this->lda_,
                          this->tau_.raw(), bb.raw(), &ldb, &info);
        nt2_la_int nrhs = size(bb, 2);
        char uplo =  'U', d = 'N';
        char tr1 = (transpose) ?  (!is_real(type_t(1))? 'C':'T') : 'N';
        nt2_la_int rk = rank(epsi);
        nt2::details::trtrs(&uplo, &tr1, &d, &rk, &nrhs, this->aa_.raw(),
                            &this->lda_, bb.raw(), &ldb, &info);
        const size_t m =  nt2::min(size(bb, 1), numel(jpvt_));
         tab_t res(nt2::of_size(size(bb, 1), size(bb, 2)));
         res(jpvt_(nt2::_(1, m)), nt2::_) = bb;
         
         return res; 
         //        return permute(bb); 
        //       b = permute(b);
      }
      
    private :
      inline tab_t permute(const tab_t& bb) const
      {
        tab_t res(nt2::of_size(nt2::numel(jpvt_), nt2::size(bb, 2)));
        const size_t m =  nt2::min(size(bb, 1), numel(jpvt_));
        for(size_t i=1; i <= m; ++i)
          {
            res(jpvt_(i), _) = bb(i, _);
          }
        //       res(jpvt_(nt2::_(1, m)), _) = bb; //TODO
        return res;
      }

      ibuf_t   jpvt_;
      tab_t       p_; 
      tab_t     tau_;
    };
    
    template<class T> struct sjqr<T, 'N'>
      : public sjqr_members<T>
    {
      typedef qr_helper<T> qrh_t; 
      typedef typename qrh_t::tab_t       tab_t;
      typedef typename qrh_t::result_type  result_type; 

      template<class Input>
      sjqr( Input& xpr) : sjqr_members<T>(xpr)
      {
        nt2::details::geqrf(&this->m_, &this->n_, this->aa_.raw(), &this->lda_,
                            this->tau_.raw(), &this->info_, this->wrk_);
      }
      
      result_type q () const
      {
        nt2_la_int info;
        nt2_la_int nn = this->k_;
        this->q_ = nt2::expand(this->aa_, nn, nn);
        nt2::details::gqr(&this->m_, &nn, &this->k_, this->q_.raw(), &this->lda_,
                          this->tau_.raw(), &info);
        return this->q_;
      }

//       sjqr_result(sjqr_result const& src)
//       : a_(src.a_),aa_(src.aa_),m_(src.m_),n_(src.n_),
//         k_(src.k_),lda_(src.lda_),jpvt_(src.jpvt_),
//         tau_(src.tau_),info_(src.info_),
//         nop_(src.nop_){}

//       sjqr_result& operator=(sjqr_result const& src)
//       {
//         a_      = src.a_;
//         aa_     = src.aa_;
//         m_      = src.m_;
//         n_      = src.n_;
//         k_      = src.k_;
//         lda_    = src.lda_;
//         jpvt_   = src.jpvt_;
//         tau_    = src.tau_;
//         info_   = src.info_;
//         nop_    =  src.nop_;
//         return *this;
//       }


//       //==========================================================================
//       // Solver interface
//       //==========================================================================
//       template<class XPR> result_type solve(const XPR & b, base_t epsi = nt2::Eps<base_t>(),
//                                             bool transpose = false)const
//       {
//         result_type bb = b;
//         inplace_solve(bb, epsi, transpose);
//         return bb;
//       }

//       template < class XPR > void inplace_solve(XPR & b, base_t epsi = nt2::Eps<base_t>(),
//                                                 bool transpose = false) const
//       {
//         char side = 'L';
//         char tr = (transpose) ? 'N' : !is_real(type_t(1))? 'C':'T';
//         nt2_la_int M = nt2::size(b, 1), N = nt2::size(b, 2);
//         nt2_la_int ldb = b.leading_size();
//         nt2_la_int info;
//         nt2::details::mqr(&side, &tr, &M, &N, &k_, aa_.raw(), &lda_, tau_.raw(), b.raw(), &ldb, &info, wrk_);
//          nt2_la_int nrhs = size(b, 2);
//         char uplo =  'U', d = 'N';
//         char tr1 = (transpose) ?  (!is_real(type_t(1))? 'C':'T') : 'N';
//         nt2_la_int rk = rank(epsi);
//          nt2::details::trtrs(&uplo, &tr1, &d, &rk, &nrhs, aa_.raw(), &lda_, b.raw(), &ldb, &info);
//          if (!nop_) b = permute(b);
//       }

//     private :



//       data_t                 a_;
//       tab_t                 aa_;
//       nt2_la_int     m_, n_, k_;
//       nt2_la_int           lda_;
//       ibuf_t              jpvt_;
//       tab_t                tau_;
//       nt2_la_int          info_;
//       char                 nop_;
//       mutable workspace_t  wrk_;

    };

  }
}
#endif
