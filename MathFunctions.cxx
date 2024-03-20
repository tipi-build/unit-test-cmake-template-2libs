#if !defined(TIPI_TEAM)
  #error TIPI_TEAM was not forwarded as define
#endif

#if !defined(TIPI_TEAM_ZURICH)
  #error TIPI_TEAM was not forwarded as define
#endif




#include "MathFunctions.h"

#include <cmath>

namespace MathFunctions {
double sqrt(double x)
{
  return std::sqrt(x);
}
}