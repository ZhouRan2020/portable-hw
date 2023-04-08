cmake_minimum_required(VERSION 3.0)
project(portable)

message(STATUS "sys: ${CMAKE_SYSTEM_NAME}")

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
	add_executable(plusone
		${CMAKE_SOURCE_DIR}/src/file-hw-unix.cpp	
	)
elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
	add_executable(plusone
		${CMAKE_SOURCE_DIR}/src/file-hw-win.cpp
	)
else()
	message(CHECK_FAIL "unknown system")
endif()
