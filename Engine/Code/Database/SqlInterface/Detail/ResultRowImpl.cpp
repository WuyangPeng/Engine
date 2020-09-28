// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/16 12:30)

#include "Database/DatabaseExport.h"

#include "ResultRowImpl.h"

#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 
#include "CoreTools/ClassInvariant/Noexcept.h"

using std::ostream;
using std::string;
using std::wstring;

Database::ResultRowImpl ::ResultRowImpl(const ConfigurationStrategy& configurationStrategy) noexcept
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

void Database::ResultRowImpl ::Print([[maybe_unused]] std::ostream& os) const
{
	DATABASE_CLASS_IS_VALID_9;

	CoreTools::DoNothing();
 
}

int Database::ResultRowImpl ::GetIntValue([[maybe_unused]] int pos) const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

 

	THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl的GetIntValue未实现。"s));
}

uint32_t Database::ResultRowImpl ::GetUIntValue([[maybe_unused]] int pos) const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

 

	THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl的GetUIntValue未实现。"s));
}

int64_t Database::ResultRowImpl ::GetInt64Value([[maybe_unused]] int pos) const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

 

	THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl的GetInt64Value未实现。"s));
}

uint64_t Database::ResultRowImpl ::GetUInt64Value([[maybe_unused]] int pos) const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

 

	THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl的GetUInt64Value未实现。"s));
}

float Database::ResultRowImpl ::GetFloatValue([[maybe_unused]] int pos) const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

 

	THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl的GetFloatValue未实现。"s));
}

double Database::ResultRowImpl ::GetDoubleValue([[maybe_unused]] int pos) const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

 

	THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl的GetDoubleValue未实现。"s));
}

bool Database::ResultRowImpl ::GetBoolValue([[maybe_unused]] int pos) const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

 

	THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl的GetBoolValue未实现。"s));
}

string Database::ResultRowImpl ::GetStringValue([[maybe_unused]] int pos) const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

 

	THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl的GetStringValue未实现。"s));
}

wstring Database::ResultRowImpl ::GetWStringValue([[maybe_unused]] int pos) const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

 

	THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl的GetWStringValue未实现。"s));
}

int Database::ResultRowImpl
	::GetColCount() const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	CoreTools::DoNothing();

	return 0;
}

