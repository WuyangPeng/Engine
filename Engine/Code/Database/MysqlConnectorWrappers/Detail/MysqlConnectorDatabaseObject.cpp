// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 12:49)

#include "Database/DatabaseExport.h"

#include "MysqlConnectorDatabaseObject.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::make_shared;
using std::make_unique;

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

Database::MysqlConnectorDatabaseObject ::MysqlConnectorDatabaseObject(const ConfigurationStrategy& configurationStrategy)
    : ParentType{ configurationStrategy },
      m_MysqlxClient{ make_unique<MysqlxClient>(mysqlx::SessionOption::USER, configurationStrategy.GetDBUserName(),
                                                mysqlx::SessionOption::PWD, configurationStrategy.GetDBPassword(),
                                                mysqlx::SessionOption::HOST, configurationStrategy.GetIP(),
                                                mysqlx::SessionOption::PORT, configurationStrategy.GetPort(),
                                                mysqlx::SessionOption::DB, configurationStrategy.GetDBHostName(),
                                                mysqlx::SessionOption::SSL_MODE,
                                                configurationStrategy.IsUseSSL() ? mysqlx::SSLMode::VERIFY_CA : mysqlx::SSLMode::REQUIRED,
                                                mysqlx::ClientOption::POOLING, configurationStrategy.GetPooling(),
                                                mysqlx::ClientOption::POOL_MAX_SIZE, configurationStrategy.GetPoolMaxSize(),
                                                mysqlx::ClientOption::POOL_QUEUE_TIMEOUT, configurationStrategy.GetPoolQueueTimeout(),
                                                mysqlx::ClientOption::POOL_MAX_IDLE_TIME, configurationStrategy.GetPoolMaxIdleTime()) }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

Database::MysqlConnectorDatabaseObject ::~MysqlConnectorDatabaseObject()
{
    EXCEPTION_TRY
    {
    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26447)
        m_MysqlxClient->close();
    #include STSTEM_WARNING_POP
    }
    EXCEPTION_ALL_CATCH(Database)

    DATABASE_SELF_CLASS_IS_VALID_1;
}

    #ifdef OPEN_CLASS_INVARIANT
bool Database::MysqlConnectorDatabaseObject ::IsValid() const noexcept
{
    if (ParentType::IsValid() && m_MysqlxClient)
        return true;
    else
        return false;
}
    #endif  // OPEN_CLASS_INVARIANT

Database::DatabaseObjectImpl::MysqlxSessionPtr Database::MysqlConnectorDatabaseObject ::GetMysqlxSessionPtr()
{
    DATABASE_CLASS_IS_VALID_1;

    return std::make_unique<MysqlxSession>(m_MysqlxClient->getSession());
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR