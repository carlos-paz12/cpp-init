# cpp-init
Template repository to cpp projects.

## Introduction
This repository provides a minimal and modern template for starting new C++ projects. It includes basic structure, build configuration using CMake, and guidelines to help you get started quickly and cleanly.

## Directory structure
> TODO

## Compiling and running
### Manually with CMake
> This method requires CMake (>= <cmake_version>) to be installed on your system. CMake is a cross-platform build system generator used to configure and compile the project. If it's not already installed, you can install it using your system’s package manager (e.g., `sudo apt install cmake` on Debian/Ubuntu or `brew install cmake` on macOS).

Once CMake is set up, follow the steps:

1. Clone this repository:

```bash
git clone https://github.com/carlos-paz12/cpp-init
```

2. Navigate to the project directory:

```bash
cd cpp-init
```

3. Compile and build the program using `cmake`:

```bash
cmake -S . -B build
cmake --build build
```

4. Run:

```bash
./bin/cpp_init
```

### Using bash script
You can also build and compile **cpp-init** using just one command line. Run the script ()[bootstrap.sh] and wait for it to finish executing.

1. Compile and build:
```bash
./bootstrap.sh
```

2. Run:
```bash
./bin/cpp_init
```

## Authors
> TODO

## Licence
> TODO

---

&copy; Copyright