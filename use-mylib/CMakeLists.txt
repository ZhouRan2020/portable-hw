cmake_minimum_required(VERSION 3.0)
project(use-mylib)
#--------------------------------------------
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
#--------------------------------------------
add_subdirectory(static-portable)
add_subdirectory(shared-portable)
#--------------------------------------------
link_directories(./shared-portable/lib)
link_directories(./static-portable/lib)
add_executable(use-mylib
	./src/use-mylib.cpp
)
target_link_libraries(use-mylib
	mymath
	mymathdll
)
target_include_directories(use-mylib
	PUBLIC
	./shared-portable/include
	./shared-portable/include
)
#--------------------------------------------------
