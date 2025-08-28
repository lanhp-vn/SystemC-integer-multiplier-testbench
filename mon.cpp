#include "mon.h"
#include <iostream>
using namespace std;

void Mon::monitor()
{
    while (true)
    {
        wait();  // Wait for the falling edge of Clk
        cout << "At time " << sc_time_stamp() << "::";
        cout << "(a, b): (" << a.read() << ", " << b.read() << ")";
        cout << " -> f: " << f.read() << endl;

        // Check that the multiplier is working correctly
        sc_assert(f.read() == a.read() * b.read());
    }
}
