/*
 * Copyright (c) 2013, Roland Bock
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 *   Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * 
 *   Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include <iostream>
#include "sqlpp11/exception.h"
#include "sqlpp11/odbc2/connection.h"
#include "detail/prepared_statement_handle.h"
#include "detail/result_handle.h"
#include "detail/connection_handle.h"

#include "spdlog/spdlog.h"

#include "magic_enum.hpp"

#include <map>
#include <string_view>

using std::map;

namespace sqlpp
{
	namespace odbc2
	{
		enum class NeeConvert
		{
			COUNT,
			AVG,
			MAX,
			MIN,
		};
		constexpr auto& _needConvertNames = magic_enum::enum_names<NeeConvert>();
		void convert_columns(otl_stream* os, const std::string& sql)
		{
			map<size_t, std::string_view> poss;
			for(const auto& v: _needConvertNames)
			{
				auto pos = sql.find(v);
				if(pos!=string::npos)
				{
					poss.insert({ pos, v });
				}
			}
			int index = 1;
			for(const auto& v: poss)
			{
				if(v.second==magic_enum::enum_name(NeeConvert::COUNT))
				{
					os->set_column_type(index++, otl_var_long_int);
				}
				else
				{
					os->set_column_type(index++, otl_var_double);
				}
			}
		}

		static connection_config _config;
        void execute_prepared_statement(detail::prepared_statement_handle_t& prepared_statement)
        {
            
        }

        void execute_statement(detail::connection_handle_t& handle, const std::string& statement)
        {
			handle._db.direct_exec(statement.c_str());
        }

		connection::connection(connection_config config):
			_handle(new detail::connection_handle_t(config))
		{
			_config = config;
		}

		connection::~connection()
		{
			// FIXME
		}

		char_result_t connection::select_impl(const std::string& statement)
		{
			spdlog::info("select str:{}", statement);

			auto _stream = std::make_unique<otl_stream>(50, statement.c_str(), _handle->_db, otl_explicit_select, "");
			convert_columns(_stream.get(), statement);
			std::unique_ptr<detail::result_handle> result_handle(
                new detail::result_handle(std::move(_stream), _handle->_conf.debug));
			
            return { std::move(result_handle) };
		}

		bind_result_t connection::run_prepared_select_impl(prepared_statement_t& prepared_statement)
		{
            execute_prepared_statement(*prepared_statement._handle);
            return prepared_statement._handle;
		}

		size_t connection::run_prepared_insert_impl(prepared_statement_t& prepared_statement)
		{
            execute_prepared_statement(*prepared_statement._handle);
			return 0; //fix me
		}

		size_t connection::run_prepared_update_impl(prepared_statement_t& prepared_statement)
		{
            execute_prepared_statement(*prepared_statement._handle);
			return 0; //fix me
		}

		size_t connection::run_prepared_remove_impl(prepared_statement_t& prepared_statement)
		{
            execute_prepared_statement(*prepared_statement._handle);
			return 0; //fix me
		}

		prepared_statement_t connection::prepare_impl(const std::string& statement, size_t no_of_parameters, size_t no_of_columns)
		{
			spdlog::info("prepare sql:{}", statement);
			auto _stream = std::make_unique<otl_stream>(50, statement.c_str(), _handle->_db,  otl_explicit_select, "");

			return { std::unique_ptr<detail::prepared_statement_handle_t>(
				new detail::prepared_statement_handle_t(std::move(_stream), no_of_parameters, no_of_columns, true)) };
		}

		size_t connection::insert_impl(const std::string& statement)
		{
			spdlog::info("execute sql:{}", statement);
			execute_statement(*_handle, statement);
            return 0; //fix me
		}

		void connection::execute(const std::string& command)
		{
			spdlog::info("execute:{}", command);
			execute_statement(*_handle, command);
		}

		size_t connection::update_impl(const std::string& statement)
		{
			spdlog::info("execute sql:{}", statement);
            execute_statement(*_handle, statement);
            return 0; //fix me
		}

		size_t connection::remove_impl(const std::string& statement)
		{
			spdlog::info( "execute sql:{}", statement);
            execute_statement(*_handle, statement);
            return 0; //fix me
		}

		std::string connection::escape(const std::string& s) const
		{
            std::string t;
            size_t count(s.size());
            for (auto c : s) {
                if (c == '\'') {
                    count++;
                }
            }
            t.reserve(count);
            for (auto c : s) {
                if (c == '\'') {
                    t.push_back(c);
                }
                t.push_back(c);
            }
            return t;
		}

		void connection::start_transaction()
		{
			//fix me
		}

		void connection::commit_transaction()
		{
			//fix me
		}

		void connection::rollback_transaction(bool report)
		{
			//fix me
		}

		void connection::report_rollback_failure(const std::string message) noexcept
		{
			//fix me
		}
	}
}

