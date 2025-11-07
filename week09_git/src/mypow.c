#include "myops.h"

double mypow(int a, int b) {
    double result = 1.0;
    if (b == 0) {
        return 1.0;
    }
    else if (b < 0) {
        b = -b;
        for (int i=0; i<b; i++) {
            result *= (1/a);
        }
    }
    else {
        for (int i=0; i<b; i++) {
            result *= a;
        }
    }
    return result;
}