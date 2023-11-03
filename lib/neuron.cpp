#include "neuron.h"


neuron::neuron(int count, tset_params init_rand_params, tprocess process):
        count(count), init_rand_params(init_rand_params), process(process) {};
neuron::neuron(int count, tprocess process):
        count(count), init_rand_params(NO_PARAMS), process(process) {};


tset_params int_rand_params(const int count) {
    return [count](vector<hparam>& params) {
        for (int i = 0; i < count; i++) {
            params[i].i = rand() % 37;
        }
    };
}

tset_params int_rand_params(const int count, const int max) {
    return [count, max](vector<hparam>& params) {
        for (int i = 0; i < count; i++) {
            params[i].i = rand() % max;
        }
    };
}

tset_params int_rand_params(const int count, const int min, const int max) {
    const int range = max - min;
    return [count, min, range](vector<hparam>& params) {
        for (int i = 0; i < count; i++) {
            params[i].i = rand() % range + min;
        }
    };
}