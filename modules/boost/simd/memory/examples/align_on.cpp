#include <iostream>
#include <boost/simd/memory/align_on.hpp>

using boost::simd::align_on;

int main()
{
  std::cout << align_on(0,4)     << std::endl;
  std::cout << align_on(1,4)     << std::endl;
  std::cout << align_on(11,4)    << std::endl;
  std::cout << align_on(1337,4)  << std::endl;
}
