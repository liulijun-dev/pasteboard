cmake_minimum_required(VERSION 3.0.0)
project(c2p LANGUAGES CXX VERSION 0.1.0)

#include(CTest)
#enable_testing()

# 指定源文件
file(GLOB SOURCES_AND_HEADERS "*.cpp" "include/*.h")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(c2p ${SOURCES_AND_HEADERS})

# 引入clip库
include(FetchContent)
message (STATUS "Adding clip..")
FetchContent_Declare(
  clip
  GIT_REPOSITORY https://github.com/dacap/clip.git
  GIT_TAG        2ada8b17b39bf41a669248a2be5c6e4be4c27f14 # release-1.10.0
  SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ext/clip
  GIT_PROGRESS TRUE
)

# 禁止编译clip examples和clip tests
set(CLIP_EXAMPLES off)
set(CLIP_TESTS off)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wc++11-extensions")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/ext/clip")

FetchContent_MakeAvailable(clip)

# need to install boost in local before find boost
FIND_PACKAGE(Boost 1.80.0 REQUIRED COMPONENTS program_options)
IF (Boost_program_options_FOUND)
  include_directories( ${Boost_INCLUDE_DIR} )
  target_link_libraries(c2p LINK_PUBLIC ${Boost_LIBRARIES} )
endif()

target_link_libraries(c2p PRIVATE clip)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)