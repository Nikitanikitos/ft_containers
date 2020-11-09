cmake_minimum_required(VERSION 3.16)
project(ft_containers)
set(CMAKE_CXX_STANDARD 98)

SET(MYCOMPILE_FLAGS "-Wall -Wextra -Werror")
add_definitions(${MYCOMPILE_FLAGS})

add_executable(ft_containers
        ft.cpp

		tests/map_tests/map_access_tests.cpp
		tests/map_tests/map_constructor_tests.cpp
		tests/map_tests/map_erase_tests.cpp
		tests/map_tests/map_insert_tests.cpp
		tests/map_tests/map_iterator_tests.cpp
		tests/map_tests/map_lower_upper_bound_tests.cpp)

include_directories(
		tests
		ft
		ft/list
		ft/list/iterators
		ft/map
		ft/map/iterators
		ft/queue
		ft/stack
		ft/vector
		ft/vector/iterators
        )

find_package(Catch2 REQUIRED)
target_link_libraries(ft_containers Catch2::Catch2)
