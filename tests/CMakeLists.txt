# Define a function to simplify test creation.
# Takes a filename (without extension) and creates a test executable from it.
function(create_test filename)
    # Set the test executable name.
    set(TEST_EXECUTABLE ${filename})
    # Define the executable target using the source file <filename>.cpp.
    add_executable(${TEST_EXECUTABLE} ${filename}.cpp ${SOURCES})
    # Set C++ standard properties for the test target.
    set_target_properties(${TEST_EXECUTABLE} PROPERTIES
        CXX_STANDARD 17 # Use the C++17 standard
        CXX_STANDARD_REQUIRED ON # Enforce the required C++ standard
    )
    # Include necessary directories for the test target.
    target_include_directories(${TEST_EXECUTABLE} PRIVATE
        ${APP_INC_HEADERS} # For your project's headers.
        ${APP_MOD_HEADERS} # For third-party headers.
    )
endfunction()

# Get all .cpp test source files in the current directory.
# TEST_SOURCES will contain relative paths to each file.
file(GLOB TEST_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# Loop over each test source file.
foreach(test_src IN LISTS TEST_SOURCES)
    # Extract the filename without extension to use as the test name.
    get_filename_component(test_name ${test_src} NAME_WE)
    # Call the function to create the test.
    create_test(${test_name})
endforeach()
