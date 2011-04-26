#include <nt2/sdk/simd/pack.hpp>
#include <nt2/sdk/simd/pack/io.hpp>
#include <nt2/sdk/details/type_id.hpp>

#include <boost/lexical_cast.hpp>

namespace nt2
{

namespace tag
{
  NT2_HIERARCHY_CLASS(tostring_, meta::unspecified_<tostring_>);
}
  
namespace meta
{
  template <class Tag>
  struct tostring_
      : boost::proto::
        unpack< boost::proto::
                call< functor<Tag, tag::tostring_> > ( boost::proto::_, boost::proto::_state )
              >
  {};
  
  template <>
  struct tostring_<tag::terminal_>
      : boost::proto::
        call< functor<tag::terminal_, tag::tostring_> ( boost::proto::_value, boost::proto::_state ) >
  {
  };
  
} }

namespace boost { namespace proto
{
  template<class Tag>
  struct  is_callable<nt2::meta::tostring_<Tag> >
        : boost::mpl::true_  {};
} }

NT2_REGISTER_DISPATCH ( Tag , tag::tostring_, (Tag)(A0)(A1)(State)
                      , (unspecified_<A0>)(unspecified_<A1>)(unspecified_<State>)
                      )

namespace nt2 { namespace ext
{
  template<class Tag,class Dummy>
  struct call < Tag(tag::unspecified_, tag::unspecified_, tag::unspecified_)
              , tag::tostring_, Dummy
              >
        : callable
  {
    typedef std::string result_type;

    NT2_FUNCTOR_CALL(3)
    {
      return nt2::type_id<Tag>() + "("
           + meta::compile<meta::tostring_<boost::mpl::_1> >()(a0, a2)
           + ", "
           + meta::compile<meta::tostring_<boost::mpl::_1> >()(a1, a2)
           + ")";
    }
  };
} }

NT2_REGISTER_DISPATCH ( Tag , tag::tostring_, (Tag)(A0)(State)
                      , (unspecified_<A0>)(unspecified_<State>)
                      )

namespace nt2 { namespace ext
{
  template<class Tag,class Dummy>
  struct call < Tag(tag::unspecified_, tag::unspecified_)
              , tag::tostring_, Dummy
              >
        : callable
  {
    typedef std::string result_type;

    NT2_FUNCTOR_CALL(2)
    {
      return nt2::type_id<Tag>() + "("
           + meta::compile<meta::tostring_<boost::mpl::_1> >()(a0, a1)
           + ")";
    }
  };
} }

NT2_REGISTER_DISPATCH ( tag::terminal_, tag::tostring_, (A0)(A1)
                       , (unspecified_<A0>)(unspecified_<A1>)
                       )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call < tag::terminal_(  tag::unspecified_, tag::unspecified_ )
  , tag::tostring_, Dummy
  >
  : callable
  {
    typedef std::string result_type;

    template<class Value, class State> inline
    result_type operator()( Value& v, State const& s ) const
    {
      BOOST_ASSERT(s.get().find(boost::addressof(v)) != s.get().end());
        
      return "a" + boost::lexical_cast<std::string>(s.get().find(boost::addressof(v))->second);
    }
  };
} }

struct terminal_do : boost::proto::callable
{
    template<typename Sig>
    struct result;
    
    template<typename This, typename T, typename State>
    struct result<This(T, State)>
    {
        typedef State& type;
    };
    
    template<typename T, typename State>
    typename boost::result_of<terminal_do(T const&, State&)>::type
    operator()(T& t, State& state)
    {
        const void* addr = boost::addressof(t);
        typename State::iterator it = state.find(addr);
        if(it == state.end())
        {
            std::cout << "input a" << state.size() << ": " << nt2::type_id<T>() << " " << t << std::endl;
            
            state.insert(std::make_pair(addr, state.size()));
        }
            
        return state;
    }
};

struct find_terminals : boost::proto::or_<
    boost::proto::when<
        boost::proto::terminal<boost::proto::_>,
        terminal_do(boost::proto::_value, boost::proto::_state)
    >,
    boost::proto::otherwise<
        boost::proto::fold<boost::proto::_, boost::proto::_state, find_terminals>
    >
>
{
};

template<typename Expr>
void make_kernel(Expr const& expr)
{
    std::map<const void*, size_t> map;
    
    find_terminals()(expr, map);
    
    std::cout << "expression: \n";
    std::cout << nt2::meta::compile< nt2::meta::tostring_<boost::mpl::_1> >()(expr, boost::ref(map)) << std::endl;
}

int main()
{
    using nt2::simd::pack;
    namespace proto = boost::proto;

    pack<float> a, b, c, d;
    
    make_kernel(
      !(a + 3*~c)+4*nt2::div(c,d)
    );
}
