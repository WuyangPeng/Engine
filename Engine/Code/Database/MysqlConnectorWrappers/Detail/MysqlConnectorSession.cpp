// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 10:26)

#include "Database/DatabaseExport.h"

#include "MysqlConnectorSession.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 
#include "Database/SqlInterface/DatabaseObject.h"
#include "Database/SqlInterface/Detail/DatabaseObjectImpl.h"

using std::make_shared;
using std::make_unique;
using std::string;

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR
 
Database::MysqlConnectorSession
	::MysqlConnectorSession(const ConfigurationStrategy& configurationStrategy)
	: ParentType{ configurationStrategy }, 
	  m_MysqlxSession{ make_unique<MysqlxSession>(mysqlx::SessionOption::USER, configurationStrategy.GetDBUserName(),
	                                              mysqlx::SessionOption::PWD,  configurationStrategy.GetDBPassword(),
		                                          mysqlx::SessionOption::HOST, configurationStrategy.GetIP(),
		                                          mysqlx::SessionOption::PORT, configurationStrategy.GetPort(),
		                                          mysqlx::SessionOption::DB,   configurationStrategy.GetDBHostName(),
		                                          mysqlx::SessionOption::SSL_MODE,
		                                          configurationStrategy.IsUseSSL() ? mysqlx::SSLMode::VERIFY_CA : mysqlx::SSLMode::REQUIRED) }
{
	DATABASE_SELF_CLASS_IS_VALID_1;
}

Database::MysqlConnectorSession
	::MysqlConnectorSession(const DatabaseObject& databaseObject)
	: ParentType{ databaseObject.GetConfigurationStrategy() },
	  m_MysqlxSession{ GetMysqlxSessionPtr(databaseObject) }
{
	DATABASE_SELF_CLASS_IS_VALID_1;
}

Database::MysqlConnectorSession
	::~MysqlConnectorSession()
{
	try
	{
		m_MysqlxSession->close();
	}
	catch (const std::exception& error)
	{
		LOG_SINGLETON_ENGINE_APPENDER(Warn, Database) 
			<< error.what()	 
			<< LOG_SINGLETON_TRIGGER_ASSERT;
	}	 

	DATABASE_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Database::MysqlConnectorSession
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && m_MysqlxSession)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

Database::MysqlConnectorSession::MysqlxSchemaPtr Database::MysqlConnectorSession
	::GetMysqlxSchemaPtr()
{
	DATABASE_CLASS_IS_VALID_1;

	return make_unique<MysqlxSchema>(m_MysqlxSession->getDefaultSchema());
}

Database::SessionImpl::MysqlxSchemaPtr Database::MysqlConnectorSession
	::GetMysqlxSchemaPtr(int dbIndex)
{
	DATABASE_CLASS_IS_VALID_1;

	auto configurationStrategy = GetConfigurationStrategy();

	return make_unique<MysqlxSchema>(m_MysqlxSession->getSchema(configurationStrategy.GetDBName(dbIndex)));
}

Database::MysqlConnectorSession::MysqlxSessionPtr Database::MysqlConnectorSession
	::GetMysqlxSessionPtr(const DatabaseObject& databaseObject)
{
	auto implPtr = databaseObject.GetImplType().lock();

	if (implPtr)
	{
		return implPtr->GetMysqlxSessionPtr(); 
	}
	else
	{

		THROW_EXCEPTION(SYSTEM_TEXT("ªÒ»°schema ß∞‹°£"));
	}
}

Database::SessionImpl::SchemaContainer Database::MysqlConnectorSession
	::GetSchemaContainer()
{
	DATABASE_CLASS_IS_VALID_1;

	SchemaContainer schemaContainer;

	auto schemas = m_MysqlxSession->getSchemas();

	for (auto schema:schemas)
	{
		schemaContainer.push_back(make_unique<Schema>(GetConfigurationStrategy(), schema));
	}
	 
	return schemaContainer;
}

Database::SessionImpl::ResultPtr Database::MysqlConnectorSession
	::ExecuteResult(const string& findStatement, int bindStatement)
{
	DATABASE_CLASS_IS_VALID_1;

	return make_shared<Result>(GetConfigurationStrategy(), make_shared<MysqlxRowResult>(m_MysqlxSession->sql(findStatement).bind(bindStatement).execute()));
}

void Database::MysqlConnectorSession
	::Execute(const string& findStatement, int bindStatement)
{
	DATABASE_CLASS_IS_VALID_1;

	m_MysqlxSession->sql(findStatement).bind(bindStatement).execute();
}

void Database::MysqlConnectorSession
	::Execute(const string& findStatement)
{
	DATABASE_CLASS_IS_VALID_1;

	m_MysqlxSession->sql(findStatement).execute();
}

Database::SessionImpl::ResultPtr Database::MysqlConnectorSession
	::ExecuteResult(const string& findStatement)
{
	DATABASE_CLASS_IS_VALID_1;

	return make_shared<Result>(GetConfigurationStrategy(), make_shared<MysqlxRowResult>(m_MysqlxSession->sql(findStatement).execute()));
}

Database::SessionImpl::ResultPtr Database::MysqlConnectorSession
	::ExecuteResult(const string& findStatement, const string& bindStatement)
{
	DATABASE_CLASS_IS_VALID_1;

	return make_shared<Result>(GetConfigurationStrategy(), make_shared<MysqlxRowResult>(m_MysqlxSession->sql(findStatement).bind(bindStatement).execute()));
} 

void Database::MysqlConnectorSession
	::Execute(const string& findStatement, const string& bindStatement)
{
	DATABASE_CLASS_IS_VALID_1;

	m_MysqlxSession->sql(findStatement).bind(bindStatement).execute();
}

#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR