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


#ifndef SQLPP_SKELETON_DETAIL_RESULT_HANDLE_H
#define SQLPP_SKELETON_DETAIL_RESULT_HANDLE_H


#include "odbc_defines.h"

namespace sqlpp
{
	namespace odbc2
	{
		// FIXME
		using ODBC2_RES = std::unique_ptr<otl_stream>;

		namespace detail
		{
			struct result_handle
			{
				ODBC2_RES odbc2_res;
				bool debug;

				result_handle(ODBC2_RES res, bool debug_):
					odbc2_res(std::move(res)),
					debug(debug_)
				{}

				result_handle(const result_handle&) = delete;
				result_handle(result_handle&&) = default;
				result_handle& operator=(const result_handle&) = delete;
				result_handle& operator=(result_handle&&) = default;

				~result_handle()
				{
					// FIXME
				}

				bool operator!() const
				{
					return odbc2_res==nullptr;
				}
			};
		}
	}
}

#endif


