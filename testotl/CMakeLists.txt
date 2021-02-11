project(testotl)

IF(CMAKE_SYSTEM_NAME MATCHES "Windows")
	link_libraries(odbc32)
ELSEIF(CMAKE_SYSTEM_NAME MATCHES "Linux")

ENDIF(CMAKE_SYSTEM_NAME MATCHES "Windows")

aux_source_directory(./ DEMO_SOURCE)
add_definitions(-DOTL_ODBC)

add_executable(testotl ${DEMO_SOURCE})
#target_link_libraries(testotl  PUBLIC sqlpp-odbc2) #PUBLIC Sqlpp11
set_target_properties(testotl PROPERTIES VS_GLOBAL_VcpkgEnabled true)
add_test(testotl "${arg}")

