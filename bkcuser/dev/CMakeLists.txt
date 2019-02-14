cmake_minimum_required(VERSION 3.1)
project(dev)

set (GCC_COVERAGE_COMPILE_FLAGS "-g3 -std=c++17 -ltomcrypt -DTFM_DESC -DTFM_DESC -DLTM_DESC -DMP_32BIT -USE_TFM")

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(blc REQUIRED)

find_package(nlohmann_json 3.2.0 REQUIRED)

set (SRCS
	src/aliasMap.cpp
	src/confFile.cpp
	src/connectedFunction.cpp
	src/connectedPeer.cpp
	src/functionMap.cpp
	src/getMyIp.cpp
	src/handleKeyParam.cpp
	src/main.cpp
	src/rsaKey.cpp
	src/trans.cpp
	)

set (PROTOS
	)

set (HEADER
	include/aliasMap.hpp
	include/confFile.hpp
	include/connectedFunction.hpp
	include/connectedPeer.hpp
	include/functionMap.hpp
	include/getMyIp.hpp
	include/handleKeyParam.hpp
	include/identity.hpp
	include/rsaKey.hpp
	include/trans.hpp
	)

add_library(devobj STATIC ${SRCS} ${HEADER} ${PROTOS})

target_include_directories(devobj PRIVATE ./include)
target_include_directories(devobj PRIVATE ../)
target_include_directories(devobj PRIVATE ${CMAKE_SOURCE_DIR}/dep/libtomcrypt/src/headers)
target_include_directories(devobj PRIVATE ${CMAKE_SOURCE_DIR}/dep/libtommath)
target_link_libraries(devobj PRIVATE Threads::Threads)
target_link_libraries(devobj PRIVATE blc)

target_link_libraries(devobj PRIVATE nlohmann_json::nlohmann_json)

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
