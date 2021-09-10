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
#include <sqlpp11/sqlpp11.h>
#include <sqlpp11/ppgen.h>
#include "sqlpp11/odbc2/odbc2.h"
#include "demo.h"

#include "spdlog/spdlog.h"

#include <iostream>
#include <vector>

//SQLPP_DECLARE_TABLE(
//	(tab_bar),
//    (alpha, int, SQLPP_PRIMARY_KEY)
//    (beta, varchar(255))
//    (gamma, int, SQLPP_NOT_NULL)
//    (delta, varchar(255) )
//)

//SQLPP_ALIAS_PROVIDER(left);
//SQLPP_ALIAS_PROVIDER(right);

namespace odbc2 = sqlpp::odbc2;
int main()
{
	odbc2::connection_config config{};
 	config.user = "";
 	config.database = "demo_sqlite";
	config.debug = true;
	try
	{
		odbc2::connection db(config);

        spdlog::info("connect success");

        hhhhh::TabBar tab{};

        //select all
        /*for (const auto& row : db(select(all_of(tab)).from(tab).unconditionally().limit(5u)))
        {
            spdlog::info("alpha:{}, beta:{}, gamma:{}, delta:{}", row.alpha.value(), row.beta.value(), row.gamma.value(), row.delta.value());
        }*/

        db(insert_into(tab).set(tab.gamma = 1, tab.beta = "world3", tab.alpha = 55, tab.delta="ddd"));

        //select max value
        if (const auto& row = *(db(select(max(tab.alpha)).from(tab).unconditionally()).begin()))
        {
            spdlog::info("max row.alpha: {}", row.max.value());
        }

        //select min value
        if (const auto& row = *(db(select(min(tab.alpha)).from(tab).unconditionally()).begin()))
        {
            spdlog::info("row count: {}", row.min.value());
        }

        //select count value
        if (const auto& row = *(db(select(count(tab.alpha)).from(tab).unconditionally()).begin()))
        {
            spdlog::info("row count: {}", row.count.value());
        }

        

        //select avg value current not support
        if (const auto& row = *(db(select(avg(tab.alpha), count(tab.alpha)).from(tab).unconditionally()).begin()))
        {
            spdlog::info("avg of alpha: {}, count alpha:{}" ,row.avg.value(), row.count.value());
        }

		

		////select some fields
		//for (const auto& row : db(select(multi_column(tab.alpha,tab.beta).as(left)).from(tab).unconditionally().limit(5u)))
		//{
  //          spdlog::info("alpha:{}, beta:{}", row.left.alpha.value(), row.left.beta.value());
		//}
	}
	catch(const sqlpp::exception& )
	{
		std::cerr << "For testing, you'll need to create a database sqlpp_sample with a table tab_sample, as shown in tests/TabSample.sql" << std::endl;
		throw;
	}
	

	return 0;
}
