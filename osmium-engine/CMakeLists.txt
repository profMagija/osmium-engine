# CMakeList.txt : CMake project for osmium-engine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)


# Add source to this project's executable.
add_executable (osmiumengine
    "atom"
    "env"
    "expr"
	"matcher"
    "osmium-engine"
    "symbol"
    "symbol_expr"
    "symtab"
	"value"
    "matchers/blank"
)


# TODO: Add tests and install targets if needed.
