## MWB-sgraph

**MWB-sgraph** - **M**aximal **W**eighted **B**ipartite **s**ub**graph**

### Brief overview

**MWB-sgraph** is a universal toolset for finding the maximal weighted bipartite subgraphs of the provided weighted graph using different approaches. The project is coherent with NI-PDP course at the Faculty of Information Technologies, Czech Technical University, 2022.

**MWB-sgraph** is a command line tool that compounds *bash scripts* and *C++ executable*. The tool currently supports the following approaches to solve the problem:
* **Sequential** - finds the soluition using the sequential _recursive_ algorithm by searching through _entire_ state space;  `--seq`


### Prepositions to build

Executable is being built via the CMake toolchain. The toolchain can be installed from the command line at the Linux environment (Ubuntu / Mint) with the next command:

`sudo apt-get install cmake`

Also, in order to check for runtime memory leaks during the development or execution, valgrind tool must be installed.

`sudo apt-get install valgrind`

### Build the project

Firstly, if the project is being built at first, the `out` directory must be empty or must not exist (should be removed). In order to build the project `build.sh` script must be run from the root directory of a project. 
NOTE: some building issues might appear at the moment while building on other platforms (not tested).

### Run MWB-sgraph from the command line

The toolset requires additional parameters to be run: method of solving and input data. Examples of input files are present at `/data` folder.

In order to run the project, `run.sh --seq -d filename` or `v-run.sh --seq -d filename` (valgrind-run, to trace memory behavoiur) script must be executed from the root directory of a project.

**Example:** `bash ./run.sh --seq -d graph03.txt`



