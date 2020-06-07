cmake_minimum_required(VERSION 3.10)

project(compiler)

add_custom_command(
        OUTPUT ${PROJECT_BINARY_DIR}/parser.h ${PROJECT_BINARY_DIR}/parser.cpp
        COMMAND bison --defines=${PROJECT_BINARY_DIR}/parser.h -o ${PROJECT_BINARY_DIR}/parser.cpp ${PROJECT_SOURCE_DIR}/src/parser.y
        DEPENDS ${PROJECT_SOURCE_DIR}/src/parser.y
)

add_custom_command(
        OUTPUT ${PROJECT_BINARY_DIR}/lexer.cpp
        COMMAND flex -o ${PROJECT_BINARY_DIR}/lexer.cpp ${PROJECT_SOURCE_DIR}/src/lexer.l
        DEPENDS ${PROJECT_SOURCE_DIR}/src/lexer.l
)

add_executable(compiler ${PROJECT_BINARY_DIR}/parser.cpp ${PROJECT_BINARY_DIR}/lexer.cpp src/compiler.cpp src/compoundstatement.cpp src/context.cpp src/literalexpression.cpp)
set_property(TARGET compiler PROPERTY CXX_STANDARD 11)

set_source_files_properties(${PROJECT_BINARY_DIR}/lexer.cpp PROPERTIES LANGUAGE CXX)
set_source_files_properties(${PROJECT_BINARY_DIR}/parser.cpp PROPERTIES LANGUAGE CXX)

target_include_directories(compiler PUBLIC ${PROJECT_BINARY_DIR})
target_include_directories(compiler PUBLIC include)
