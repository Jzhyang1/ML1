#include <vector>
#include "state.h"
#include "media.h"
#include "neuron.h"
using namespace std;

class layering
{
private:
    state s;
    vector<layer> layers = vector<layer>();

public:
    layering();
    
    void add_layer(layer l);

    void set_state(state s);
    state& get_state();

    void build();

    /**
     * @brief call build before test
     * 
     * @param input 
     * @return media 
     */
    media test(media input);
};


/**
 * @brief 
 * pass null for parent if this is the first layer
 * 
 * call test from the final layer
 */
class layer
{
private:
    const layering* s;
public:
    layer(layering* s): s(s) {};

    void add_neuron(neuron n, vector<neuron*> stems_from);
    void add_neuron(neuron n, vector<int> stems_from);
};
