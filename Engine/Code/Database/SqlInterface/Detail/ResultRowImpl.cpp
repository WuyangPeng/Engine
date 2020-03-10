// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/03 10:05)

#include "Database/DatabaseExport.h"

#include "ResultRowImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 
#include "System/Helper/UnusedMacro.h"

using std::ostream;
using std::string;
using std::wstring;

Database::ResultRowImpl
	::ResultRowImpl(const ConfigurationStrategy& configurationStrategy)
	: m_ConfigurationStrategy{ configurationStrategy }
{
	DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::ResultRowImpl
	::~ResultRowImpl()
{
	DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, ResultRowImpl)

void Database::ResultRowImpl
	::Print(std::ostream& os) const
{
	DATABASE_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(os);
}

int Database::ResultRowImpl
	::GetIntValue(int pos) const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	SYSTEM_UNUSED_ARG(pos);

	THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl的GetIntValue未实现。"));
}

uint32_t Database::ResultRowImpl
	::GetUIntValue(int pos) const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	SYSTEM_UNUSED_ARG(pos);

	THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl的GetUIntValue未实现。"));
}

int64_t Database::ResultRowImpl
	::GetInt64Value(int pos) const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	SYSTEM_UNUSED_ARG(pos);

	THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl的GetInt64Value未实现。"));
}

uint64_t Database::ResultRowImpl
	::GetUInt64Value(int pos) const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	SYSTEM_UNUSED_ARG(pos);

	THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl的GetUInt64Value未实现。"));
}

float Database::ResultRowImpl
	::GetFloatValue(int pos) const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	SYSTEM_UNUSED_ARG(pos);

	THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl的GetFloatValue未实现。"));
}

double Database::ResultRowImpl
	::GetDoubleValue(int pos) const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	SYSTEM_UNUSED_ARG(pos);

	THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl的GetDoubleValue未实现。"));
}

bool Database::ResultRowImpl
	::GetBoolValue(int pos) const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	SYSTEM_UNUSED_ARG(pos);

	THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl的GetBoolValue未实现。"));
}

string Database::ResultRowImpl
	::GetStringValue(int pos) const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	SYSTEM_UNUSED_ARG(pos);

	THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl的GetStringValue未实现。"));
}

wstring Database::ResultRowImpl
	::GetWStringValue(int pos) const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	SYSTEM_UNUSED_ARG(pos);

	THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl的GetWStringValue未实现。"));
}

int Database::ResultRowImpl
	::GetColCount() const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	return 0;
}

