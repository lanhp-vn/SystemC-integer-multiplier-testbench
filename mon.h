#include "systemc.h"

SC_MODULE(Mon) {
    sc_in<bool> clk;         // Clock signal
    sc_in<int> a, b, f;      // Input and output signals from Mult

    void monitor();          // Function to monitor the multiplication process

    SC_CTOR(Mon) {
        SC_THREAD(monitor);  // Register monitor method
        sensitive << clk.neg(); // Sensitive to falling edge of clock
    }
};
