# RISC-V CPU Design with TL-Verilog aka RV32I Core

*This repository contains all necessary information regarding the RISC-V based CPU Core Design MYTH (Microprocessor for You in Thirty Hours) Workshop, offered by for VLSI System Design (VSD) and Redwood EDA.*

  ## RISC-V ISA

RISC-V (known as *risk five*) is an open standard instruction set architecture (ISA) based on established reduced instruction set computer(RISC) principles which was first developed by Dr. Krste Asanovic (*Co-inventor of RISCV and Co-founder of SiFive*) and graduate students Yunsup Lee and Andrew Waterman in May 2010 as part of the Parallel Computing Laboratory at UC Berkeley. 

   ***A new RISC-V processor core IP introduced by Dr. Krste Asanovic & Dr. Yunsup Lee at Linley Fall Virtual Processor Conference***

![SiFive](https://github.com/kuby1412/RISC-V-MYTH-Workshop/blob/master/Documentation/SiFive-CPU-Feature-768x425.jpg)

## RISC-V Block Diagram 

![Block Diagram](https://github.com/kuby1412/RISC-V-MYTH-Workshop/blob/master/Documentation/Block%20Diagram.PNG)



 ## ISA base and extensions

The RISC-V instruction set has modular characteristics. The instruction set is organized in a modular manner.Each module is represented by an English letter. 
The instruction set includes the standard part and the extension part. The standard part must be implemented.

The ISA base and its extensions are developed in a collective effort between industry, the research community and educational institutions. The base specifies instructions (and their encoding), control flow, registers (and their sizes), memory and addressing, logic (i.e., integer) manipulation, and ancillaries. 
The standard extensions are specified to work with all of the standard bases, and with each other without conflict.

![ISA_base_and_extensions](https://github.com/RISCV-MYTH-WORKSHOP/RISC-V-CPU-Core-using-TL-Verilog/blob/master/Documentation/Snaps/ISA%20_base_and_extensions.JPG)

The RISC-V ISA is defined as a Base integer ISA, which is the basic necessity for the implemetation of any CPU core. In addition to that it also has optional extensions to the base ISA. The base RISC-V ISA has a little-endian memory system. The standard is maintained by the RISC-V foundation. You can learn more about RISC-V here.

The base integer instructions set, that exclusively operate on integer numbers, are represented as RV32I/RV64I. The other extensions avaialable are as follows:

  - **RV64M** - **Multiply Extension** :  These are the Instructions that is used to caluclate multiplication and division.
  - **RV64F** and **RV64D** - **Single and Double precision floating point extension** : These are the instructions used to realize floating point numbers.

A CPU core that implements all the above type of instructions is called as **"RV64IMFD"** CPU Core.



In this workshop, we were given the overview of the software as well as the hardware aspect of the RISC-V core and ISA. In addition to that, hands on labs were also conducted in order to learn by doing, rather than just reading the theory and specifications, or just watching the videos.



# Setting up the Environment - Installation of Workshop Collaterals Files

In order to understand RISC-V ISA and work on the implementation, you will need a GNU GCC cross-compiler for RISC-V and a simulator(Here we have used **Spike** simulator).For all the necessary files(compilers and toolchains) required for the workshop to be installed on your local machine, follow the below instructions: 

1. Go to https://github.com/kunalg123/riscv_workshop_collaterals 

2. You can either download the repository zip file into you local machine or you can type in the following command in your terminal in the local machine : 

    `$git clone https://github.com/kunalg123/riscv_workshop_collaterals.git`

3. After downloading the repository , get inside the riscv_workshop_collaterals directory.

    `$cd riscv_workshop_collaterals`

4. For installation of the complete toolchain, run the "run.sh" shell script. For this, type the following command:

    `$./run.sh`
    
5. After installation of all the required files, you can move on to perform the compilation and simulation of your codes by following [here](https://github.com/RISCV-MYTH-WORKSHOP/RISC-V-CPU-Core-using-TL-Verilog/tree/master/Day_1)

**_For detailed steps regarding the source code, compilation, simulation and debugging, visit [Day_1](https://github.com/RISCV-MYTH-WORKSHOP/RISC-V-CPU-Core-using-TL-Verilog/tree/master/Day_1) and [Day_2](https://github.com/RISCV-MYTH-WORKSHOP/RISC-V-CPU-Core-using-TL-Verilog/tree/master/Day_2) folders._**



# Application Binary Interface (ABI) 

- The **Application Binary Interface(ABI)** , or also called as System Call Interface is used by the application programmer to directly access the registers of the RISC-V architecture via system calls. In other words, if the applpication programmer wants to access the harware resources of the processor, it has to do via the resgiters, and the way it does it, is thorugh ABI or system calls. RISC-V ABI defines standard functions for registers which allows for software interoperability. 

- The ABI or application binary interface, consists of 2 parts – one is the set of all user instructions itself, and second is the system call interface through the operating system layer.

- The RISC-V architecture has 32 registers from x(0) to x(31) whose width is defined by XLEN which can be 32/64  for RV32/RV64 respectively. Application programmer can access each of these 32 registers through its ABI name.

![Application Binary Interface](https://github.com/RISCV-MYTH-WORKSHOP/RISC-V-CPU-Core-using-TL-Verilog/blob/master/Documentation/Snaps/ABI.png)

- In RISC-V architecture, the memories are byte addressable. The RISC-V belongs to the little endian memory addressing system.

- There are two methods to load data in to the registers:
     - **By loading directly into the registers:** But since there are only limited a,ount of registers available, so at a time only few bit numbers can be loaded.
     - **By using the Memory:** We load the data into the memory and then from memory we can load the data into the registers.


### Register File:

RISC-V contains 32 integer registers and 32 floating point registers. Through the ABI names, we reserve some of these registers for certain purposes. For example, all registers that start with a t for temporary can be used for any purposes. All registers that start with an a for argument are used for arguments passed to a function. All registers that start with s (except sp) for saved are registers that are preserved across function calls.

![Register_file](https://github.com/RISCV-MYTH-WORKSHOP/RISC-V-CPU-Core-using-TL-Verilog/blob/master/Documentation/Snaps/Register_file.JPG)
