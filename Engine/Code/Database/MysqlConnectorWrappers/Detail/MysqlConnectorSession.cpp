///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 18:53)

#include "Database/DatabaseExport.h"

#include "MysqlConnectorSession.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "Database/SqlInterface/DatabaseObject.h"
#include "Database/SqlInterface/Detail/DatabaseObjectImpl.h"

using std::make_shared;
using std::make_unique;
using std::string;

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

Database::MysqlConnectorSession::MysqlConnectorSession(const ConfigurationStrategy& configurationStrategy)
    : ParentType{ configurationStrategy },
      mysqlxSession{ make_unique<MysqlxSession>(mysqlx::SessionOption::USER,
                                                configurationStrategy.GetDBUserName(),
                                                mysqlx::SessionOption::PWD,
                                                configurationStrategy.GetDBPassword(),
                                                mysqlx::SessionOption::HOST,
                                                configurationStrategy.GetIP(),
                                                mysqlx::SessionOption::PORT,
                                                configurationStrategy.GetPort(),
                                                mysqlx::SessionOption::DB,
                                                configurationStrategy.GetDBHostName(),
                                                mysqlx::SessionOption::SSL_MODE,
                                                configurationStrategy.IsUseSSL() ? mysqlx::SSLMode::VERIFY_CA : mysqlx::SSLMode::REQUIRED) }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

Database::MysqlConnectorSession::MysqlConnectorSession(const DatabaseObject& databaseObject)
    : ParentType{ databaseObject.GetConfigurationStrategy() },
      mysqlxSession{ databaseObject.GetMysqlxSession() }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

Database::MysqlConnectorSession::~MysqlConnectorSession()
{
    EXCEPTION_TRY
    {
        mysqlxSession->close();
    }
    EXCEPTION_ALL_CATCH(Database)

    DATABASE_SELF_CLASS_IS_VALID_1;
}

    #ifdef OPEN_CLASS_INVARIANT

bool Database::MysqlConnectorSession::IsValid() const noexcept
{
    if (ParentType::IsValid() && mysqlxSession)
        return true;
    else
        return false;
}

    #endif  // OPEN_CLASS_INVARIANT

Database::MysqlConnectorSession::MysqlxSchemaUniquePtr Database::MysqlConnectorSession::GetMysqlxSchema() const
{
    DATABASE_CLASS_IS_VALID_1;

    return make_unique<MysqlxSchema>(mysqlxSession->getDefaultSchema());
}

Database::SessionImpl::MysqlxSchemaUniquePtr Database::MysqlConnectorSession::GetMysqlxSchema(int dbIndex) const
{
    DATABASE_CLASS_IS_VALID_1;

    auto strategy = GetConfigurationStrategy();

    return make_unique<MysqlxSchema>(mysqlxSession->getSchema(strategy.GetDBName(dbIndex)));
}

Database::SessionImpl::SchemaContainer Database::MysqlConnectorSession::GetSchemaContainer()
{
    DATABASE_CLASS_IS_VALID_1;

    SchemaContainer schemaContainer{};

    auto schemas = mysqlxSession->getSchemas();

    for (const auto& schema : schemas)
    {
        schemaContainer.emplace_back(make_unique<Schema>(GetConfigurationStrategy(), schema));
    }

    return schemaContainer;
}

Database::SessionImpl::ResultUniquePtr Database::MysqlConnectorSession::ExecuteResult(const string& findStatement, int bindStatement)
{
    DATABASE_CLASS_IS_VALID_1;

    return make_shared<Result>(GetConfigurationStrategy(), make_shared<MysqlxRowResult>(mysqlxSession->sql(findStatement).bind(bindStatement).execute()));
}

void Database::MysqlConnectorSession::Execute(const string& findStatement, int bindStatement)
{
    DATABASE_CLASS_IS_VALID_1;

    mysqlxSession->sql(findStatement).bind(bindStatement).execute();
}

void Database::MysqlConnectorSession::Execute(const string& findStatement)
{
    DATABASE_CLASS_IS_VALID_1;

    mysqlxSession->sql(findStatement).execute();
}

Database::SessionImpl::ResultUniquePtr Database::MysqlConnectorSession::ExecuteResult(const string& findStatement)
{
    DATABASE_CLASS_IS_VALID_1;

    return make_shared<Result>(GetConfigurationStrategy(), make_shared<MysqlxRowResult>(mysqlxSession->sql(findStatement).execute()));
}

Database::SessionImpl::ResultUniquePtr Database::MysqlConnectorSession::ExecuteResult(const string& findStatement, const string& bindStatement)
{
    DATABASE_CLASS_IS_VALID_1;

    return make_shared<Result>(GetConfigurationStrategy(), make_shared<MysqlxRowResult>(mysqlxSession->sql(findStatement).bind(bindStatement).execute()));
}

void Database::MysqlConnectorSession::Execute(const string& findStatement, const string& bindStatement)
{
    DATABASE_CLASS_IS_VALID_1;

    mysqlxSession->sql(findStatement).bind(bindStatement).execute();
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR