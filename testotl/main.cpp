/*
 * Copyright (c) 2013, Roland Bock
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met:
 * 
 *  * Redistributions of source code must retain the above copyright notice, 
 *    this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright notice, 
 *    this list of conditions and the following disclaimer in the documentation 
 *    and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE 
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED 
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

//#include "demo.h"
#include "../include/otl/otlv4.h"

#include "spdlog/spdlog.h"

#include <iostream>
#include <vector>


otl_connect conn;

int main()
{
	conn.rlogon("", "", "demo_sqlite");
	otl_stream os;
	try
	{
		os.set_column_type(1, otl_var_int, sizeof(otl_var_int));
		os.set_column_type(2, otl_var_double, sizeof(otl_var_int));
		os.open(1, "select count(*),avg(alpha) from tab_bar;", conn, otl_explicit_select);
		if (!os.eof())
		{
			int f = 1;
			double j = 0;
			os >> f >> j;
			int q = 22;
		}
	}
	catch(const otl_exception& e)
	{
		os.skip_to_end_of_row();
        char ch[1024] = { 0 };
        os >> ch;
		std::cerr << "For testing, you'll need to create a database sqlpp_sample with a table tab_sample, as shown in tests/TabSample.sql:" << e.msg << std::endl;
		throw;
	}
	return 0;
}
