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
      return s.get().first[s.get().second++];
    }
  };
} }

int main()
{
    using nt2::simd::pack;
    namespace proto = boost::proto;

    pack<float> a, b, c, d;
    
    boost::array<const char*, 6> m = {
		"d",
		"c",
		"j",
		"c",
		"i",
		"a"
	};
	
	std::pair< boost::array<const char*, 6>, int > state(m, 0);
    
    std::cout << nt2::meta::compile<
      nt2::meta::tostring_<boost::mpl::_1>
    >()
    (
      !(a + 3*~c)+4*nt2::div(c,d),
      boost::ref(state)
    ) << std::endl;
}
