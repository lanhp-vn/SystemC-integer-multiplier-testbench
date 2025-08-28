// Source code adapted from “SystemC Training: The Definitive Guide to SystemC” by Doulos Ltd., 2015.

#include "stim.h"

void Stim::stimulus()
{
    wait();
    a.write(1); b.write(42);  // First test case
    wait();
    a.write(2); b.write(21);  // Second test case
    wait();
    a.write(3); b.write(14);  // Third test case
    wait();
    a.write(6); b.write(7);   // Fourth test case
    wait();
    a.write(7); b.write(6);   // Fifth test case
    wait();
    a.write(14); b.write(3);  // Sixth test case
    wait();
    a.write(21); b.write(2);  // Seventh test case
    wait();
    a.write(42); b.write(1);  // Eighth test case
    wait();
    sc_stop();  // Stop simulation
}

