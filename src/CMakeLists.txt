
add_library(sqlpp-odbc2 
		connection.cpp
		prepared_statement.cpp
		char_result.cpp
		bind_result.cpp
		detail/connection_handle.cpp)

#target_link_libraries(sqlpp-odbc2 PUBLIC Sqlpp11)
set_target_properties(sqlpp-odbc2 PROPERTIES VS_GLOBAL_VcpkgEnabled true)

install(TARGETS sqlpp-odbc2 DESTINATION lib)
