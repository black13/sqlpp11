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

#ifndef SQLPP_MOCK_DB_H
#define  SQLPP_MOCK_DB_H

#include <sqlpp11/connection.h>
#include <sqlpp11/serializer_context.h>
#include <sqlpp11/serialize.h>

struct DbMock: public sqlpp::connection
{
	struct _serializer_context_t : public sqlpp::serializer_context_t
	{
		_serializer_context_t(std::ostream& os): sqlpp::serializer_context_t(os) {}
	};

	using _interpreter_context_t = _serializer_context_t;

	template<typename T>
	static _serializer_context_t& _serialize_interpretable(const T& t, _serializer_context_t& context)
	{
		return ::sqlpp::serialize(t, context);
	}

	template<typename T>
	static _interpreter_context_t& _interpret_interpretable(const T& t, _interpreter_context_t& context)
	{
		return ::sqlpp::serialize(t, context);
	}
};

#endif

