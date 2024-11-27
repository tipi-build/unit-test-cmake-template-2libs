#include "MathFunctions.h"

#include <cmath>
#include <lib.h> // straight out of HfcDependencyProvidedLib

namespace MathFunctions {
double sqrt(double x)
{
  print_hello();
  return std::sqrt(x);
}
}