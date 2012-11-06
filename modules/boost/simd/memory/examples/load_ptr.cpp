#include <iostream>
#include <boost/simd/include/functions/load.hpp>

using boost::simd::load;

int main()
{
  float data[] = { 1, 2, 3, 4 };
  std::cout << load<float>(&data[0])     << std::endl;
  std::cout << load<float>(&data[1])     << std::endl;
  std::cout << load<float>(&data[2])     << std::endl;
  std::cout << load<float>(&data[3])     << std::endl;
}
