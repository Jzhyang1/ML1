#include <vector>
using namespace std;

union hparam
{
    int i;
    double f;
    bool b;
    char c;
    string s;
    vector<int> vi;
    vector<string> vs;
};