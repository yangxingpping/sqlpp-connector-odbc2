
cmake_minimum_required(VERSION 3.19)

if(DEFINED ENV{VCPKG_ROOT} )
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
      CACHE STRING "")
endif()

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

project (sqlpp11-connector-odbc2)


IF(CMAKE_SYSTEM_NAME MATCHES "Windows")
#set_property(TARGET foo PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
ELSEIF(CMAKE_SYSTEM_NAME MATCHES "Linux")
	add_definitions(-D OTL_ODBC_UNIX)
	include_directories(/home/alqaz/vcpkg/installed/x64-linux/include)
	link_libraries(odbc)
ENDIF(CMAKE_SYSTEM_NAME MATCHES "Windows")

find_package(Sqlpp11  REQUIRED)
#find_package(magic_enum REQUIRED)


set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(testotl)

install(DIRECTORY "${PROJECT_SOURCE_DIR}/include/sqlpp11" DESTINATION include)

