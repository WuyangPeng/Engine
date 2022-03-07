///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 18:50)

#include "Database/DatabaseExport.h"

#include "MysqlConnectorDatabaseObject.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::make_shared;
using std::make_unique;

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

Database::MysqlConnectorDatabaseObject::MysqlConnectorDatabaseObject(const ConfigurationStrategy& configurationStrategy)
    : ParentType{ configurationStrategy },
      mysqlxClient{ make_unique<MysqlxClient>(mysqlx::SessionOption::USER,
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
                                              configurationStrategy.IsUseSSL() ? mysqlx::SSLMode::VERIFY_CA : mysqlx::SSLMode::REQUIRED,
                                              mysqlx::ClientOption::POOLING,
                                              configurationStrategy.GetPooling(),
                                              mysqlx::ClientOption::POOL_MAX_SIZE,
                                              configurationStrategy.GetPoolMaxSize(),
                                              mysqlx::ClientOption::POOL_QUEUE_TIMEOUT,
                                              configurationStrategy.GetPoolQueueTimeout(),
                                              mysqlx::ClientOption::POOL_MAX_IDLE_TIME,
                                              configurationStrategy.GetPoolMaxIdleTime()) }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

Database::MysqlConnectorDatabaseObject::~MysqlConnectorDatabaseObject() noexcept
{
    EXCEPTION_TRY
    {
        mysqlxClient->close();
    }
    EXCEPTION_ALL_CATCH(Database)

    DATABASE_SELF_CLASS_IS_VALID_1;
}

    #ifdef OPEN_CLASS_INVARIANT

bool Database::MysqlConnectorDatabaseObject::IsValid() const noexcept
{
    if (ParentType::IsValid() && mysqlxClient)
        return true;
    else
        return false;
}

    #endif  // OPEN_CLASS_INVARIANT

Database::DatabaseObjectImpl::MysqlxSessionUniquePtr Database::MysqlConnectorDatabaseObject::GetMysqlxSession() const
{
    DATABASE_CLASS_IS_VALID_1;

    return make_unique<MysqlxSession>(mysqlxClient->getSession());
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR