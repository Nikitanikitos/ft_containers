cmake_minimum_required(VERSION 3.16)
project(ft_containers)
set(CMAKE_CXX_STANDARD 98)

SET(MYCOMPILE_FLAGS "-Wall -Wextra -Werror")
add_definitions(${MYCOMPILE_FLAGS})

add_executable(ft_containers
        main.cpp

#		tests/map_tests/map_access_tests.cpp
#		tests/map_tests/map_constructor_tests.cpp
#		tests/map_tests/map_erase_tests.cpp
#		tests/map_tests/map_insert_tests.cpp
#		tests/map_tests/map_iterator_tests.cpp
#		tests/map_tests/map_lower_upper_bound_tests.cpp
#
#		tests/list_tests/list_push_front_back_tests.cpp
#		tests/list_tests/list_clear_tests.cpp
#		tests/list_tests/list_comparison_operators_tests.cpp
#		tests/list_tests/list_constructor_test.cpp
#		tests/list_tests/list_erase_tests.cpp
#		tests/list_tests/list_insert_tests.cpp
#		tests/list_tests/list_iterator_tests.cpp
#		tests/list_tests/list_merge_lists.cpp
#		tests/list_tests/list_remove_tests.cpp
#		tests/list_tests/list_resize_tests.cpp
#		tests/list_tests/list_reverse_tests.cpp
#		tests/list_tests/list_sort_tests.cpp
#		tests/list_tests/list_splice_list.cpp
#		tests/list_tests/list_swap_tests.cpp
#		tests/list_tests/list_unique_tests.cpp
#
#		tests/vector_tests/vector_insert_tests.cpp
#		tests/vector_tests/vector_erase_tests.cpp
#		tests/vector_tests/vector_front_back_tests.cpp
#		tests/vector_tests/vector_access_operator_tests.cpp
#		tests/vector_tests/vector_comparison_operators_tests.cpp
#		tests/vector_tests/vector_constructor_tests.cpp
#		tests/vector_tests/vector_iterator_tests.cpp
#		tests/vector_tests/vector_push_pop_back_tests.cpp
#		tests/vector_tests/vector_resize_tests.cpp
#		tests/vector_tests/vector_swap_tests.cpp

		tests/deque_tests/deque_constructor_tests.cpp
		tests/deque_tests/deque_push_pop_front_back_tests.cpp
		tests/deque_tests/deque_access_operator_tests.cpp
		tests/deque_tests/deque_iterator_tests.cpp
		tests/deque_tests/deque_swap_tests.cpp
		tests/deque_tests/deque_resize_tests.cpp
		tests/deque_tests/deque_assign_tests.cpp)

include_directories(
		tests
		ft
        ft/iterators
		ft/list
		ft/map
		ft/queue
		ft/stack
		ft/vector
		ft/deque
        )

find_package(Catch2 REQUIRED)
target_link_libraries(ft_containers Catch2::Catch2)
