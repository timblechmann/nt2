    template<class This,class A0 , class A1> struct result<This(A0 , A1)> { BOOST_DISPATCH_DECLTYPE( 0 ? boost::declval<A0>() : boost::declval<A1>() , type ); }; template<class This,class A0 , class A1 , class A2> struct result<This(A0 , A1 , A2)> { BOOST_DISPATCH_DECLTYPE( 0 ? 0 ? boost::declval<A0>() : boost::declval<A1>() : boost::declval<A2>() , type ); }; template<class This,class A0 , class A1 , class A2 , class A3> struct result<This(A0 , A1 , A2 , A3)> { BOOST_DISPATCH_DECLTYPE( 0 ? 0 ? 0 ? boost::declval<A0>() : boost::declval<A1>() : boost::declval<A2>() : boost::declval<A3>() , type ); }; template<class This,class A0 , class A1 , class A2 , class A3 , class A4> struct result<This(A0 , A1 , A2 , A3 , A4)> { BOOST_DISPATCH_DECLTYPE( 0 ? 0 ? 0 ? 0 ? boost::declval<A0>() : boost::declval<A1>() : boost::declval<A2>() : boost::declval<A3>() : boost::declval<A4>() , type ); };
    
    
