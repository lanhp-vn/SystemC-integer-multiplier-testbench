# SystemC - Integer Multiplier Testbench

## Project Overview
This project demonstrates fundamental SystemC concepts through the implementation of a complete integer multiplier testbench. The design follows SystemC best practices and showcases key concepts learned from the Doulos SystemC training materials and hands-on implementation.

## SystemC Architecture & Design

### Module Hierarchy
```
Top (SC_MODULE)
├── Stim (Stimulus Generator)
├── Mult (Multiplier - DUT)  
└── Mon (Monitor/Checker)
```

### Key SystemC Concepts Demonstrated

#### 1. SystemC Modules (SC_MODULE)
All components are implemented as SystemC modules using the `SC_MODULE` macro:
- **Top Module** (`top.h:9`): Top-level testbench connecting all components
- **Mult Module** (`mult.h:6`): Design Under Test (DUT) performing multiplication
- **Stim Module** (`stim.h:5`): Stimulus generation for test vectors
- **Mon Module** (`mon.h:3`): Result monitoring and verification

#### 2. SystemC Processes & Sensitivity
Different process types are used based on functionality:
- **SC_METHOD** (`mult.h:16`): Combinational logic in multiplier, sensitive to input changes
- **SC_THREAD** (`stim.h:15`, `mon.h:10`): Sequential processes for stimulus generation and monitoring
- **Sensitivity Lists**: 
  - Multiplier sensitive to both inputs: `sensitive << a << b` (`mult.h:17`)
  - Stimulus sensitive to positive clock edge: `sensitive << clk.pos()` (`stim.h:16`)
  - Monitor sensitive to negative clock edge: `sensitive << clk.neg()` (`mon.h:11`)

#### 3. SystemC Ports & Signals
Proper port and signal usage for module communication:
- **Input Ports**: `sc_in<int> a, b` for multiplier inputs (`mult.h:8-9`)
- **Output Ports**: `sc_out<int> f` for multiplier output (`mult.h:10`)
- **Clock Ports**: `sc_in<bool> clk` for synchronization (`stim.h:7`, `mon.h:4`)
- **Internal Signals**: `sc_signal<int> asig, bsig, fsig` for inter-module communication (`top.h:11`)

#### 4. SystemC Clock Generation
Clock generation and timing control:
- **Clock Declaration**: `sc_clock testclk` (`top.h:13`)
- **Clock Parameters**: 20ns period with proper initialization (`top.h:20`)
- **Clock Distribution**: Connected to all modules requiring synchronization

#### 5. Module Instantiation & Port Binding
Proper SystemC module instantiation and connection pattern:
```cpp
// Module instantiation in top.h:15-17
Stim stim1;
Mult uut;  
Mon mon1;

// Port binding in constructor top.h:25-36
stim1.a(asig); stim1.b(bsig); stim1.clk(testclk);
uut.a(asig); uut.b(bsig); uut.f(fsig);
mon1.a(asig); mon1.b(bsig); mon1.f(fsig); mon1.clk(testclk);
```

#### 6. SystemC Data Types & Operations
- **Integer Types**: Using `int` for arithmetic operations
- **Boolean Types**: Using `bool` for clock signals
- **Port Operations**: `.read()` and `.write()` methods for signal access (`mult.cpp:8`)

#### 7. SystemC Simulation Control
- **Simulation Start**: `sc_start()` in main function (`main.cpp:9`)
- **Simulation Stop**: `sc_stop()` called after test completion (`stim.cpp:24`)
- **Time Advancement**: `wait()` statements for process synchronization

## Implementation Details

### Stimulus Generation Strategy
The stimulus module (`stim.cpp:5-25`) implements a comprehensive test strategy:
- **Test Cases**: Eight specific multiplication pairs (1×42, 2×21, 3×14, 6×7, 7×6, 14×3, 21×2, 42×1)
- **Sequential Testing**: Each test case applied on consecutive clock cycles
- **Deterministic Patterns**: All test cases result in product of 42, enabling systematic verification

### Multiplier Implementation
The multiplier module demonstrates pure combinational logic:
- **Simple Operation**: Direct multiplication `f.write(a.read() * b.read())` (`mult.cpp:8`)
- **Immediate Response**: SC_METHOD ensures output updates whenever inputs change
- **No Clock Dependency**: Combinational behavior independent of clock

### Monitor & Verification
The monitor module provides comprehensive result checking:
- **Timing Alignment**: Uses negative clock edge to sample stable values (`mon.h:11`)
- **Result Display**: Formatted output showing inputs, outputs, and timestamps (`mon.cpp:10-12`)
- **Assertion-Based Verification**: `sc_assert()` validates correctness (`mon.cpp:15`)