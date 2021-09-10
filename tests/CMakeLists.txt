project(sqlitetest)

IF(CMAKE_SYSTEM_NAME MATCHES "Windows")
	link_libraries(odbc32)
ELSEIF(CMAKE_SYSTEM_NAME MATCHES "Linux")
	
ENDIF(CMAKE_SYSTEM_NAME MATCHES "Windows")

aux_source_directory(./ DEMO_SOURCE)

add_executable(sqlitetest ${DEMO_SOURCE})
target_link_libraries(sqlitetest  PUBLIC sqlpp-odbc2) #PUBLIC Sqlpp11
set_target_properties(sqlitetest PROPERTIES VS_GLOBAL_VcpkgEnabled true)
#set_target_properties(sqlitetest PROPERTIES VS_GLOBAL_VcpkgTriplet x64-windows-static)

add_test(sqlitetest "${arg}")

