#include "${project}.c"

int main() {
    int count = 1024;
    float **inputs;
    float **outputs;

    /* Project instance */
    ${project}* dsp = new${project}();
    init${project}(dsp, 44100);

    while(1) {
        /* Update effect */
        compute${project}(dsp, count, inputs, outputs);
    }

    /* Delete instance */
    delete${project}(dsp);

    return 0;
}
