# CMakeList.txt : CMake project for osmium-engine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (osmiumengine
    "atom"
    "env"
    "expr"
    "symtab"
    "osmium-engine"
    "symbol_expr"
    "symbol"
)

# TODO: Add tests and install targets if needed.
