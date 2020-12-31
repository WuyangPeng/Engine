//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/29 10:40)

#include "Database/DatabaseExport.h"

#include "ResultRowImpl.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::ostream;
using std::string;
using std::wstring;

Database::ResultRowImpl::ResultRowImpl(const ConfigurationStrategy& configurationStrategy) noexcept
    : m_ConfigurationStrategy{ configurationStrategy }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, ResultRowImpl)

void Database::ResultRowImpl::Print([[maybe_unused]] std::ostream& os) const
{
    DATABASE_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();
}

int Database::ResultRowImpl::GetIntValue([[maybe_unused]] int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl��GetIntValueδʵ�֡�"s));
}

uint32_t Database::ResultRowImpl::GetUIntValue([[maybe_unused]] int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl��GetUIntValueδʵ�֡�"s));
}

int64_t Database::ResultRowImpl::GetInt64Value([[maybe_unused]] int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl��GetInt64Valueδʵ�֡�"s));
}

uint64_t Database::ResultRowImpl::GetUInt64Value([[maybe_unused]] int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl��GetUInt64Valueδʵ�֡�"s));
}

float Database::ResultRowImpl::GetFloatValue([[maybe_unused]] int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl��GetFloatValueδʵ�֡�"s));
}

double Database::ResultRowImpl::GetDoubleValue([[maybe_unused]] int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl��GetDoubleValueδʵ�֡�"s));
}

bool Database::ResultRowImpl::GetBoolValue([[maybe_unused]] int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl��GetBoolValueδʵ�֡�"s));
}

string Database::ResultRowImpl::GetStringValue([[maybe_unused]] int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl��GetStringValueδʵ�֡�"s));
}

wstring Database::ResultRowImpl::GetWStringValue([[maybe_unused]] int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("ResultRowImpl��GetWStringValueδʵ�֡�"s));
}

int Database::ResultRowImpl::GetColCount() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    CoreTools::DisableNoexcept();

    return 0;
}
