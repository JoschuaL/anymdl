cmake_minimum_required(VERSION 3.7 FATAL_ERROR)

project(benchy)

find_package(AnyDSL_runtime REQUIRED)
include_directories(${AnyDSL_runtime_INCLUDE_DIRS})
set(ANYDSL_RUNTIME_LIBRARIES ${AnyDSL_runtime_LIBRARIES})


set(BACKEND ${BACKEND} CACHE STRING "select the backend from the following: CPU, AVX, NVVM, CUDA, OPENCL")
if(NOT BACKEND)
    set(BACKEND cpu CACHE STRING "select the backend from the following: CPU, AVX, NVVM, CUDA, OPENCL" FORCE)
endif()
string(TOLOWER "${BACKEND}" BACKEND)
message(STATUS "Selected backend: ${BACKEND}")




if(BACKEND STREQUAL "cpu")
    set(DEVICE "cpu")
    set(DEVICE_COMM "cpu")
elseif(BACKEND STREQUAL "avx")
    set(DEVICE "avx")
    set(DEVICE_COMM "cpu")
else()
    set(DEVICE "gpu")
    set(DEVICE_COMM "gpu")
endif()


# Don't change the order of the files!
# The impala compiler crashes sometimes depending on
# the definition order of "static" constants.
anydsl_runtime_wrap(benchy FILES 
    src/buildins.impala
    src/df.impala
    src/glm.impala
    src/math_impl.impala
    src/math.impala
    src/mdl_glm.impala
    src/mdl_support.impala
    src/state.impala
    src/test.impala
    src/testy.impala
) 

add_executable(benchy 
    src/test.cpp
    ${benchy}
)


target_link_libraries(benchy 
    ${ANYDSL_RUNTIME_LIBRARY} 
    ${ANYDSL_RUNTIME_LIBRARIES}
    -pthread  # needed for the queuing stuff
)

set_target_properties(benchy PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)
