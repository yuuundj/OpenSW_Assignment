#include "advanced_ops.h"

double mypow(double a, double b) {
    for (int i=0; i<b; i++) {
        a *= a;
    }
    return a;
}