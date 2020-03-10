// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/03 10:24)

#include "Database/DatabaseExport.h"

#include "MysqlConnectorDatabaseObject.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 

using std::make_shared;
using std::make_unique;

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR
 
Database::MysqlConnectorDatabaseObject
	::MysqlConnectorDatabaseObject(const ConfigurationStrategy& configurationStrategy)
	: ParentType{ configurationStrategy },
	  m_MysqlxClient{ make_unique<MysqlxClient>(mysqlx::SessionOption::USER, configurationStrategy.GetDBUserName(),
											    mysqlx::SessionOption::PWD,  configurationStrategy.GetDBPassword(),
		                                        mysqlx::SessionOption::HOST, configurationStrategy.GetIP(),
												mysqlx::SessionOption::PORT, configurationStrategy.GetPort(),
												mysqlx::SessionOption::DB,   configurationStrategy.GetDBHostName(),
												mysqlx::SessionOption::SSL_MODE,
												configurationStrategy.IsUseSSL() ? mysqlx::SSLMode::VERIFY_CA : mysqlx::SSLMode::REQUIRED,
		                                        mysqlx::ClientOption::POOLING, configurationStrategy.GetPooling(),
	                                            mysqlx::ClientOption::POOL_MAX_SIZE, configurationStrategy.GetPoolMaxSize(),
	                                            mysqlx::ClientOption::POOL_QUEUE_TIMEOUT, configurationStrategy.GetPoolQueueTimeout(),
	                                            mysqlx::ClientOption::POOL_MAX_IDLE_TIME, configurationStrategy.GetPoolMaxIdleTime()) }
{
	DATABASE_SELF_CLASS_IS_VALID_1;
}

Database::MysqlConnectorDatabaseObject
	::~MysqlConnectorDatabaseObject()
{
	m_MysqlxClient->close();
	 
	DATABASE_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Database::MysqlConnectorDatabaseObject
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && m_MysqlxClient)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

Database::DatabaseObjectImpl::MysqlxSessionPtr Database::MysqlConnectorDatabaseObject
	::GetMysqlxSessionPtr()
{
	DATABASE_CLASS_IS_VALID_1;

	return std::make_unique<MysqlxSession>(m_MysqlxClient->getSession());
}

#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR