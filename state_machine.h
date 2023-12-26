#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <systemc.h>

// TODO
enum base {Start, G, GA, GAA, GAAG};

SC_MODULE(stateMachine) {
    public:
    sc_in<char> input;
    sc_in<bool> clk;
    base state;
    int counter;
    int position;

    SC_HAS_PROCESS(stateMachine);
    stateMachine(const sc_module_name &name);
    // SC_CTOR(stateMachine);
    //  {
    //     SC_METHOD(process);
    //     sensitive << input;
    //     dont_initialize();
    // }

    private:
    void process();

};

#endif // STATE_MACHINE_H


// SC_MODULE(stimuli)
// {
// public:
//     sc_in<bool> clk;
//     sc_out<char> output;
//     SC_HAS_PROCESS(stimuli);   
//     stimuli(const sc_module_name &name);

// private:
//     std::string sequence;
//     void process();
//     unsigned int counter;
// };