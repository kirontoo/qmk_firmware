#include "laplace.h"

void matrix_init_kb(void) {
  // Turn status LED on
  //setPinOutput(C13);
  // fswritePinHigh(C13);

  matrix_init_user();
}