cmake_minimum_required(VERSION 3.17)
project(ft_containers)
set(CMAKE_CXX_STANDARD 98)

SET(MYCOMPILE_FLAGS "-Wall -Wextra -Werror")
add_definitions(${MYCOMPILE_FLAGS})

add_executable(ft_containers
        main.cpp

#        list/tests/list_constructor_test.cpp
#        list/tests/list_push_front_back_tests.cpp
#        list/tests/list_iterator_tests.cpp
#        list/tests/test_assign_tests.cpp
#        list/tests/list_insert_tests.cpp
#        list/tests/list_erase_tests.cpp
#        list/tests/list_clear_tests.cpp
#        list/tests/list_comparison_operators_tests.cpp
#        list/tests/list_resize_tests.cpp
#        list/tests/list_swap_tests.cpp
#        list/tests/list_remove_tests.cpp
#        list/tests/list_reverse_tests.cpp
#        list/tests/list_unique_tests.cpp
#        list/tests/list_sort_tests.cpp
#        list/tests/list_splice_list.cpp
#        list/tests/list_merge_lists.cpp

#        vector/tests/vector_constructor_tests.cpp
#        vector/tests/vector_comparison_operators_tests.cpp
#        vector/tests/vector_push_pop_back_tests.cpp
#        vector/tests/vector_resize_tests.cpp
#        vector/tests/vector_access_operator_tests.cpp
#        vector/tests/vector_iterator_tests.cpp
#        vector/tests/vector_insert_tests.cpp
#        vector/tests/vector_swap_tests.cpp
#        vector/tests/vector_front_back_tests.cpp
#        vector/tests/vector_erase_tests.cpp
#
#        stack/tests/stack_constructor_tests.cpp
#        stack/tests/stack_push_pop_tests.cpp
#        queue/tests/queue_constructor_tests.cpp
#        queue/tests/queue_push_pop_tests.cpp

        map/tests/map_constructor_tests.cpp
        map/tests/map_iterator_tests.cpp
        map/iterators/reverse_map_iterator.hpp
        map/tests/map_insert_tests.cpp)

include_directories(
        includes

        list
        list/iterators

        vector
        vector/iterators

        stack

        queue

        map
        map/iterators
        )

find_package(Catch2 REQUIRED)
target_link_libraries(ft_containers Catch2::Catch2)
