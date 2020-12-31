//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/29 10:41)

#include "Database/DatabaseExport.h"

#include "SchemaImpl.h"

#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::string;

Database::SchemaImpl::SchemaImpl(const ConfigurationStrategy& configurationStrategy) noexcept
    : m_ConfigurationStrategy{ configurationStrategy }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::SchemaImpl::~SchemaImpl() noexcept
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, SchemaImpl)

Database::ConfigurationStrategy Database::SchemaImpl::GetConfigurationStrategy() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return m_ConfigurationStrategy;
}

Database::SchemaImpl::MysqlxCollectionPtr Database::SchemaImpl::GetCollection([[maybe_unused]] const string& collectionName)
{
    DATABASE_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("SchemaImpl��GetCollectionδʵ�֡�"s));
}

Database::SchemaImpl::MysqlxTablePtr Database::SchemaImpl::GetTable([[maybe_unused]] const string& tableonName)
{
    DATABASE_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("SchemaImpl��GetTableδʵ�֡�"s));
}
