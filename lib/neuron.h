#include <vector>
#include <functional>
#include "hparam.h"
#include "media.h"
using namespace std;

#define no_params() NO_PARAMS


// typedef void(* tset_params)(vector<hparam>& params);
// typedef void(* tprocess)(vector<hparam>& params, vector<hparam>& queued_args, vector<hparam>& outputs);

typedef function<void(vector<hparam>& params)> tset_params;
typedef function<void(vector<hparam>& params, vector<hparam>& queued_args, vector<hparam>& outputs)> tprocess;


class neuron
{
private:
    vector<neuron*> outputs = vector<neuron*>();
    vector<vector<hparam>> queued_args = vector<vector<hparam>>();

    const tset_params init_rand_params;
    const tprocess process;
public:
    int count;
    neuron(int count, tset_params init_rand_params, tprocess process);
    neuron(int count, tprocess process);

    /**
     * @brief initializes the hyperparameters for this neuron randomly
     * 
     * @param params the params to initialize
     */
    void init_params(vector<hparam>& params);

    /**
     * @brief queues the inputs for this neuron
     * 
     * @param inputs 
     */
    void accept_input(vector<hparam>& inputs);

    /**
     * @brief processes the inputs and outputs the result to the next neuron
     * 
     * @param outputs 
     */
    void test(vector<hparam>& hparams);
};

const tset_params NO_PARAMS;

tset_params int_rand_params(const int count);
tset_params int_rand_params(const int count, const int max);
tset_params int_rand_params(const int count, const int min, const int max);

tset_params float_rand_params(const int count);

tprocess conv1d(const int kernel_size, const int stride, const int padding);
tprocess conv2d(const int kernel_size, const int stride, const int padding);

tprocess relu();
tprocess sigmoid();
tprocess tanh();
tprocess sin();
tprocess softmax();
tprocess minmax();
tprocess mean();
tprocess max();
tprocess min();
tprocess sum();
tprocess product();

/**
 * @brief filters out the inputs that are strictly less than n, where n is the only hyperparameter
 * 
 * @return tprocess 
 */
tprocess filter();

tprocess weighted_sum();