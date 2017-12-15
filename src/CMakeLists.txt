cmake_minimum_required(VERSION 2.8)

project(test_shared_memory)

set(Boost_INCLUD_EDIR /usr/include/boost)
set(BOOST_INCLUDE_DIRS /usr/include/boost)

find_package(Boost COMPONENTS system thread filesystem timer interprocess)
add_definitions(-lstdc++ -std=c++11)

include_directories(
	${Boost_INCLUDE_DIR}
	${BOOST_INCLUDE_DIRS}
)

add_executable(thread1 thread1.cpp)
target_link_libraries(thread1 ${Boost_LIBRARIES})

add_executable(thread2 thread2.cpp)
target_link_libraries(thread2 ${Boost_LIBRARIES})

add_executable(remove_sm remove_shared_memory.cpp)
target_link_libraries(remove_sm ${Boost_LIBRARIES})
