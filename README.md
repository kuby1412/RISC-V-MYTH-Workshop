# RISC-V based MYTH Workshop - Building a RISC-V Core using TL-Verilog

This repository contains source code and all necessary information regarding the **5-day RISC-V based CPU Core Design MYTH (Microprocessor for You in Thirty Hours) Workshop**, offered by for **VLSI System Design (VSD) and Redwood EDA.**. The RISC-V CPU Core has been designed with **Transaction Level Verilog (TL-Verilog) via Makerchip IDE Platform.** Find below the accompanying details:


# Introduction to RISC-V ISA

RISC-V is an open standard instruction set architecture based on established reduced instruction set computer(RISC) principles. It was first started by Prof. Krste Asanović and graduate students Yunsup Lee and Andrew Waterman in May 2010 as part of the Parallel Computing Laboratory, at UC Berkeley. Unlike most other ISA designs, the RISC-V ISA is provided under open source licenses that do not require fees to use, which provides it a huge edge over other commercially available ISAs. It is a simple, stable, small standard base ISA with extensible ISA support, that has been redefining the flexibility, scalability, extensibility, and modularity of chip designs. This has made it easier and flexible for anyone to build a processor on his own at almost zero cost. 

![SiFive] (https://www.sifive.com/client/8f69dbd08576165d08aae5fd3f0fe273.jpg)

## What’s Different About RISC-V?

   Comparing to ARM and X86, RISC-V has below advantages:

   - **Free:** RISC-V is open-source, there is no need to pay for the IP.
   - **Simple:** RISC-V is far smaller than other commercial ISAs.
   - **Modular:** RISC-V has a small standard base ISA, with multiple standard extensions.
   - **Stable:** Base and first standard extensions are already frozen. There is no need to worry about major updates.
   - **Extensibility:** Specific functions can be added based on extensions. There are many more extensions are under development, such as Vector.


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

## RISC-V International
The RISC-V Foundation was founded in 2015 to build an open, collaborative community of software and hardware innovators based on the RISC-V ISA. The Foundation, a non-profit corporation controlled by its members, directed the development to drive the initial adoption of the RISC-V ISA. For more information visit the site : www.riscv.org

![RISCV_logo](https://github.com/RISCV-MYTH-WORKSHOP/RISC-V-CPU-Core-using-TL-Verilog/blob/master/Documentation/Snaps/RISCV_logo.jpg)

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
