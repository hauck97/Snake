add_library(${LIBRARY_NAME} snake.cc extern_symbols.cc LinkedList.cc)
target_link_libraries(${LIBRARY_NAME} PUBLIC
    Catch2::Catch2
)
target_include_directories(${LIBRARY_NAME} PUBLIC ./)
