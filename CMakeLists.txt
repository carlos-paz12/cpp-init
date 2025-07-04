# === Project Metadata ===
# Application name (used as the project name and executable name).
set(APP_NAME "cpp_init")
# Application version.
set(APP_VERSION 1.0)
# Short description of the project.
set(APP_DESCRIPTION "Template repository to cpp projects.")
# Programming language used in the project.
set(APP_LANG CXX)
# Binaries output directory.
set(APP_OUT_DIR ${CMAKE_SOURCE_DIR}/bin)
# Include directory for header files.
set(APP_INC_HEADERS ${CMAKE_SOURCE_DIR}/include)
# Modules directory for third-party or modular headers.
set(APP_MOD_HEADERS ${CMAKE_SOURCE_DIR}/modules)
# Variable used by the tests subdirectory
set(TESTS_NAME "tests")
# Minimum required CMake version.
set(CMAKE_VERSION 4.0.2)

# === Declare the project ===
# Specify the minimum CMake version required to build this project.
cmake_minimum_required(VERSION ${CMAKE_VERSION})
# Declare the project using the variables defined above.
project(${APP_NAME}
    VERSION ${APP_VERSION}
    DESCRIPTION "${APP_DESCRIPTION}"
    LANGUAGES ${APP_LANG}
)

# === Output & Tooling Options ===
# Set where the compiled binary (executable) will be placed.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${APP_OUT_DIR})
# Export compile_commands.json.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# === Main Executable ===
# Define the executable target and its entry point source file.
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/sources/cpp-init/*.cpp"
)
add_executable(${APP_NAME} ${SOURCES} ${CMAKE_SOURCE_DIR}/sources/main.cpp)
# Specify directories to search for header files.
# These paths are added to the compiler's -I flags.
target_include_directories(${APP_NAME} PRIVATE
    ${APP_INC_HEADERS} # For your project's headers.
    ${APP_MOD_HEADERS} # For third-party headers.
)

# === Compilation Properties ===
# Require C++20 standard
set_target_properties(${APP_NAME} PROPERTIES
    CXX_STANDARD 20 # Use the C++20 standard
    CXX_STANDARD_REQUIRED ON # Enforce using exactly the specified standard
)
# Add compiler flags for strict warnings and good coding practices.
target_compile_options(${APP_NAME} PRIVATE
    -Wall # Show all common warnings
    -Wextra # Show extra (less common) warnings
    -Wpedantic # Enforce ISO compliance
    # -O2        # Optimization flag (commented for debug, useful for release)
)

# === Testing ===
# Add the subdirectory that contains the test configuration and test sources.
add_subdirectory(tests) # Assumes tests/CMakeLists.txt will define the test targets
