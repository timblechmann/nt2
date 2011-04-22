#include <nt2/sdk/simd/pack.hpp>
#include <nt2/sdk/details/type_id.hpp>

namespace nt2
{

namespace tag
{
  NT2_HIERARCHY_CLASS(tostring_, formal_);
}
  
namespace meta
{
  template <class Tag>
  struct tostring_
      : boost::proto::
        unpack< boost::proto::
                call< functor<Tag, tag::tostring_> >(boost::proto::pass_through<boost::mpl::_1>)
              >
  {};
  
  template <>
  struct tostring_<tag::terminal_>
      : boost::proto::
        call< functor<tag::terminal_, tag::tostring_> ( boost::proto::_value ) >
  {
  };
  
} }

namespace boost { namespace proto
{
  template<class Tag>
  struct  is_callable<nt2::meta::tostring_<Tag> >
        : boost::mpl::true_  {};
} }

NT2_REGISTER_DISPATCH ( Tag , tag::tostring_, (Tag)(A0)(A1)
                      , ((unspecified_<A0>))(unspecified_<A1>)
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
           + std::string(meta::compile<meta::tostring_<boost::mpl::_1> >()(a0))
           + ","
           + std::string(meta::compile<meta::tostring_<boost::mpl::_1> >()(a1))
           + ")";
    }
  };
} }

NT2_REGISTER_DISPATCH ( Tag , tag::tostring_, (Tag)(A0)
                      , ((unspecified_<A0>))
                      )

namespace nt2 { namespace ext
{
  template<class Tag,class Dummy>
  struct call < Tag(tag::unspecified_)
              , tag::tostring_, Dummy
              >
        : callable
  {
    typedef std::string result_type;

    NT2_FUNCTOR_CALL(1)
    {
      return nt2::type_id<Tag>() + "("
           + std::string(meta::compile<meta::tostring_<boost::mpl::_1> >()(a0))
           + ")";
    }
  };
} }

NT2_REGISTER_DISPATCH ( tag::terminal_, tag::tostring_, (A0)
                      , ((unspecified_<A0>))
                      )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call < tag::terminal_(tag::unspecified_)
              , tag::tostring_, Dummy
              >
        : callable
  {
    typedef std::string result_type;

    NT2_FUNCTOR_CALL(1)
    {
      return "foo";
    }
  };
} }

int main()
{
    using nt2::simd::pack;
    namespace proto = boost::proto;
    
    pack<float> a, b, c, d;
    
    std::cout << nt2::meta::compile<
      nt2::meta::tostring_<boost::mpl::_1>
    >()
    (
       a + b
    ) << std::endl;
}
