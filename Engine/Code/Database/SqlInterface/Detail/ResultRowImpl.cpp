///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/25 17:07)

#include "Database/DatabaseExport.h"

#include "ResultRowImpl.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::ostream;
using std::string;
using std::wstring;

Database::ResultRowImpl::ResultRowImpl(const ConfigurationStrategy& configurationStrategy) noexcept
    : configurationStrategy{ configurationStrategy }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, ResultRowImpl)

int Database::ResultRowImpl::GetIntValue(MAYBE_UNUSED int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl��GetIntValueδʵ�֡�"s));
}

uint32_t Database::ResultRowImpl::GetUIntValue(MAYBE_UNUSED int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl��GetUIntValueδʵ�֡�"s));
}

int64_t Database::ResultRowImpl::GetInt64Value(MAYBE_UNUSED int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl��GetInt64Valueδʵ�֡�"s));
}

uint64_t Database::ResultRowImpl::GetUInt64Value(MAYBE_UNUSED int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl��GetUInt64Valueδʵ�֡�"s));
}

float Database::ResultRowImpl::GetFloatValue(MAYBE_UNUSED int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl��GetFloatValueδʵ�֡�"s));
}

double Database::ResultRowImpl::GetDoubleValue(MAYBE_UNUSED int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl��GetDoubleValueδʵ�֡�"s));
}

bool Database::ResultRowImpl::GetBoolValue(MAYBE_UNUSED int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl��GetBoolValueδʵ�֡�"s));
}

string Database::ResultRowImpl::GetStringValue(MAYBE_UNUSED int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl��GetStringValueδʵ�֡�"s));
}

wstring Database::ResultRowImpl::GetWStringValue(MAYBE_UNUSED int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl��GetWStringValueδʵ�֡�"s));
}
