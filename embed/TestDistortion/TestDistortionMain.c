#include "TestDistortion.c"

int main() {
    int count = 1024;
    float **inputs;
    float **outputs;

    /* Project instance */
    TestDistortion* dsp = newTestDistortion();
    initTestDistortion(dsp, 44100);

    while(1) {
        /* Update effect */
        computeTestDistortion(dsp, count, inputs, outputs);
    }

    /* Delete instance */
    deleteTestDistortion(dsp);

    return 0;
}
