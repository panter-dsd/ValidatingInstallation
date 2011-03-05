set (PROJECT_NAME ServiceChecker)
project (${PROJECT_NAME})
cmake_minimum_required( VERSION 2.6 )

add_definitions(-DUNICODE)

find_package( Boost 1.36.0 COMPONENTS system program_options)

include_directories(
	src
	${Boost_INCLUDE_DIRS}
)

################################################################
# src
################################################################

set (src_SRC
src/main.cpp
src/servicechecker.cpp
src/tcpsocket.cpp
src/processchecker.cpp
)

set (src_HEADERS
)

################################################################
# all
################################################################

set(
	SOURCES
	${src_SRC}
)

set(
	HEADERS
	${src_HEADERS}
)

if(${CMAKE_BUILD_TYPE} STREQUAL Debug)
	add_executable( ${PROJECT_NAME} ${SOURCES})
else()
	add_executable( ${PROJECT_NAME} WIN32 ${SOURCES})
endif()
		
target_link_libraries( ${PROJECT_NAME} ${Boost_LIBRARIES})
