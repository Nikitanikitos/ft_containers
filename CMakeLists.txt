cmake_minimum_required(VERSION 3.17)
project(ft_containers)
set(CMAKE_CXX_STANDARD 98)

SET(MYCOMPILE_FLAGS "-Wall -Wextra -Werror")
add_definitions(${MYCOMPILE_FLAGS})

add_executable(ft_containers
        main.cpp

        list/tests/list_constructor_test.cpp
        list/tests/list_push_front_back_tests.cpp
        list/tests/list_iterator_tests.cpp
        list/tests/test_assign_tests.cpp
        list/tests/list_insert_tests.cpp
        list/tests/list_erase_tests.cpp
        list/tests/list_clear_tests.cpp
        list/tests/list_comparison_operators_tests.cpp
        list/tests/list_resize_tests.cpp
        list/tests/list_swap_tests.cpp
        list/tests/list_remove_tests.cpp
        list/tests/list_reverse_tests.cpp
        list/tests/list_unique_tests.cpp
        list/tests/list_sort_tests.cpp
        )

include_directories(
        list
        includes
        list/iterators
        )

find_package(Catch2 REQUIRED)
target_link_libraries(ft_containers Catch2::Catch2)
