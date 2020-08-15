// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/16 12:30)

#include "Database/DatabaseExport.h"

#include "ResultRowImpl.h"
#include "System/Helper/UnusedMacro.h"
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

void Database::ResultRowImpl
	::Print(std::ostream& os) const
{
	DATABASE_CLASS_IS_VALID_9;

	CoreTools::DoNothing();

	SYSTEM_UNUSED_ARG(os);
}

int Database::ResultRowImpl
	::GetIntValue(int pos) const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	SYSTEM_UNUSED_ARG(pos);

	THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl��GetIntValueδʵ�֡�"s));
}

uint32_t Database::ResultRowImpl
	::GetUIntValue(int pos) const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	SYSTEM_UNUSED_ARG(pos);

	THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl��GetUIntValueδʵ�֡�"s));
}

int64_t Database::ResultRowImpl
	::GetInt64Value(int pos) const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	SYSTEM_UNUSED_ARG(pos);

	THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl��GetInt64Valueδʵ�֡�"s));
}

uint64_t Database::ResultRowImpl
	::GetUInt64Value(int pos) const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	SYSTEM_UNUSED_ARG(pos);

	THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl��GetUInt64Valueδʵ�֡�"s));
}

float Database::ResultRowImpl
	::GetFloatValue(int pos) const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	SYSTEM_UNUSED_ARG(pos);

	THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl��GetFloatValueδʵ�֡�"s));
}

double Database::ResultRowImpl
	::GetDoubleValue(int pos) const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	SYSTEM_UNUSED_ARG(pos);

	THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl��GetDoubleValueδʵ�֡�"s));
}

bool Database::ResultRowImpl
	::GetBoolValue(int pos) const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	SYSTEM_UNUSED_ARG(pos);

	THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl��GetBoolValueδʵ�֡�"s));
}

string Database::ResultRowImpl
	::GetStringValue(int pos) const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	SYSTEM_UNUSED_ARG(pos);

	THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl��GetStringValueδʵ�֡�"s));
}

wstring Database::ResultRowImpl
	::GetWStringValue(int pos) const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	SYSTEM_UNUSED_ARG(pos);

	THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl��GetWStringValueδʵ�֡�"s));
}

int Database::ResultRowImpl
	::GetColCount() const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	CoreTools::DoNothing();

	return 0;
}

