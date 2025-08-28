// Source code adapted from “SystemC Training: The Definitive Guide to SystemC” by Doulos Ltd., 2015.


#include "systemc.h"
#include "stim.h"
#include "mult.h"
#include "mon.h"

SC_MODULE(Top)
{
	sc_signal<int> asig, bsig, fsig;

	sc_clock testclk;

	Stim stim1;
	Mult uut;
	Mon mon1;

	SC_CTOR(Top)
		: testclk("testclk", 20, SC_NS),
		stim1("stim1"),
		uut ("uut"),
		mon1 ("mon1")
	{
		stim1.a(asig);
		stim1.b(bsig);
		stim1.clk(testclk);

		uut.a(asig);
		uut.b(bsig);
		uut.f(fsig);

		mon1.a(asig);
		mon1.b(bsig);
		mon1.f(fsig);
		mon1.clk(testclk);
	}
};
