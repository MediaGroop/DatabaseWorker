cmake_minimum_required(VERSION 2.6)
project(rakdatabaseworker)
set(CMAKE_CXX_FLAGS " -D_ELPP_THREAD_SAFE=1 -D_ELPP_DEBUG_ERRORS=1 -D_ELPP_STACKTRACE_ON_CRASH=1 -D_ELPP_FORCE_USE_STD_THREAD=1 -D_ELPP_LOGGING_FLAGS_FROM_ARG=1 -std=gnu++11 -lodb-pgsql -lodb -lpq -lcrypto -lpthread -lrt")

include_directories ("Deps/Rak-Net/Source/")
include_directories ("Deps/libodb-2.3.0/")
include_directories ("Deps/libodb-pgsql-2.3.0/")
include_directories ("Deps/openssl/include/")

file(GLOB files "*.cpp" "*.c" "*.a" "*.cxx")

add_executable(rakdatabaseworker ${files})
target_link_libraries(rakdatabaseworker ${CMAKE_SOURCE_DIR}/libraknet.a)
target_link_libraries(rakdatabaseworker ${CMAKE_SOURCE_DIR}/libodbpgsql.a)
target_link_libraries(rakdatabaseworker ${CMAKE_SOURCE_DIR}/libodb.a)

install(TARGETS rakdatabaseworker RUNTIME DESTINATION bin)
