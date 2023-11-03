#include <vector>
#include "hparam.h"
#include "matrix.h"

using namespace std;

struct state
{
private:
    matrix<vector<hparam>> hyperparameters = matrix<vector<hparam>>();

public:
    state(int layers, int neurons);

    vector<vector<hparam>>& operator[](int layer);
};