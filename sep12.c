#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

    float i;
    float increment = 0.00000001;
    float n = 0.00000204; //this is 204 times increment
    int count = 1;

    for (i=0.0; i<n; i+=increment) {
        printf("Loop Number: %d\n", count);
        count++;
    }

    return 0;
}
//The stress test fails when the increment is larger than 203, after which it returns an extra loop