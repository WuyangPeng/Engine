///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 17:07)

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

    THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl的GetIntValue未实现。"s));
}

uint32_t Database::ResultRowImpl::GetUIntValue(MAYBE_UNUSED int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl的GetUIntValue未实现。"s));
}

int64_t Database::ResultRowImpl::GetInt64Value(MAYBE_UNUSED int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl的GetInt64Value未实现。"s));
}

uint64_t Database::ResultRowImpl::GetUInt64Value(MAYBE_UNUSED int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl的GetUInt64Value未实现。"s));
}

float Database::ResultRowImpl::GetFloatValue(MAYBE_UNUSED int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl的GetFloatValue未实现。"s));
}

double Database::ResultRowImpl::GetDoubleValue(MAYBE_UNUSED int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl的GetDoubleValue未实现。"s));
}

bool Database::ResultRowImpl::GetBoolValue(MAYBE_UNUSED int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl的GetBoolValue未实现。"s));
}

string Database::ResultRowImpl::GetStringValue(MAYBE_UNUSED int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl的GetStringValue未实现。"s));
}

wstring Database::ResultRowImpl::GetWStringValue(MAYBE_UNUSED int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl的GetWStringValue未实现。"s));
}
