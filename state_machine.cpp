#include <iostream>

#include "state_machine.h"

// TODO
stateMachine::stateMachine(const sc_module_name &name) : sc_module(name) {
    state = Start;
    counter = 0;
    position = 0;
    SC_METHOD(process);
    sensitive << clk.pos();
    dont_initialize();
}

void stateMachine::process() {
    switch(state) {
        case Start:
            if(input == 'G') {
                state = G;
            }
            break;
        case G:
            if(input == 'A') {
                state = GA;
            } else if(input == 'C' || input == 'T') {
                state = Start;
            }
            break;
        case GA:
            if(input == 'A') {
                state = GAA;
            } else if(input == 'C' || input == 'T') {
                state = Start;
            } else if (input == 'G') {
                state = G;
            }
            break;
        case GAA:
            if(input == 'G') {
                state = GAAG;
            } else if(input == 'C' || input == 'T') { // removed input == 'A' ||
                state = Start;
            }
            break;
        case GAAG:
            counter++;
            std::cout << sc_time_stamp()  << "\tNumber " << counter << " GAAG at position: " << position << std::endl;
            if(input == 'G') {
                state = G;
            } else if(input == 'A' || input == 'C' || input == 'T') {
                state = Start;
            }
            break;
        // default:
            // state = Start;
    }
    position++;
}