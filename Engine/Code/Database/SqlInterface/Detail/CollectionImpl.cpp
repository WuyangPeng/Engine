// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.2.5 (2020/03/16 12:26)

#include "Database/DatabaseExport.h"

#include "CollectionImpl.h"

#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::string;

Database::CollectionImpl ::CollectionImpl(const ConfigurationStrategy& configurationStrategy) noexcept
    : m_ConfigurationStrategy{ configurationStrategy }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::CollectionImpl ::~CollectionImpl()
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, CollectionImpl)

Database::CollectionImpl::ResultPtr Database::CollectionImpl ::ExecuteDoc([[maybe_unused]] const string& findStatement, [[maybe_unused]] const BindStatementType& bindStatement, [[maybe_unused]] int limitStatement)
{
    DATABASE_CLASS_IS_VALID_9;

 

    THROW_EXCEPTION(SYSTEM_TEXT("CollectionImplδʵ��Execute"s));
}

Database::ConfigurationStrategy
    Database::CollectionImpl::GetConfigurationStrategy() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return m_ConfigurationStrategy;
}
