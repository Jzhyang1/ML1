#include "../lib/lib.h"

int main()
{
    layering l = layering();

    tprocess t = histogram;
    
    layer l1 = layer(nullptr);
    l1.add_neuron(neuron(1, histogram), vector<neuron*>());
}

/**
 * @brief will count the characters of all queued_args strings and output a 1028-byte vector (256 ints)
 * 
 */
void histogram (vector<hparam>& params, vector<hparam>& queued_args, vector<hparam>& outputs){
    outputs.resize(256);
    for (int i = 0; i < queued_args.size(); i++) {
        const string& s = queued_args[i].s;
        for (int j = 0; j < s.length(); j++) {
            outputs[s[j]].i++;
        }
    }
}

/**
 * @brief will break up the strings in queued_args into individual strings at spaces and output a variable-length string vector as one hparam
 * 
 */
void split (vector<hparam>& params, vector<hparam>& queued_args, vector<hparam>& outputs){
    outputs.resize(1);
    vector<string>& vs = outputs[0].vs;
    for (int i = 0; i < queued_args.size(); i++) {
        const string& s = queued_args[i].s;
        int last_space = 0;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == ' ' && j > last_space + 1) {
                vs.push_back(s.substr(last_space, j - last_space));
                last_space = j + 1;
            }
        }
        if(s.length() > last_space + 1)
            vs.push_back(s.substr(last_space, s.length() - last_space));
    }
}