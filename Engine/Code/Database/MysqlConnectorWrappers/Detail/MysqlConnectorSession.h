// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 10:18)

#ifndef DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_SESSION_H
#define DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_SESSION_H

#include "Database/DatabaseDll.h"

#include "Database/SqlInterface/Detail/SessionImpl.h" 
#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR 
 
namespace Database
{
	class DatabaseObject;

	class DATABASE_HIDDEN_DECLARE MysqlConnectorSession : public SessionImpl
	{
	public:
		using ClassType = MysqlConnectorSession;
		using ParentType = SessionImpl;

	public:
		explicit MysqlConnectorSession(const ConfigurationStrategy& configurationStrategy); 
		explicit MysqlConnectorSession(const DatabaseObject& databaseObject);
		virtual ~MysqlConnectorSession();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual MysqlxSchemaPtr GetMysqlxSchemaPtr() override;
		virtual MysqlxSchemaPtr GetMysqlxSchemaPtr(int dbIndex) override;
		virtual SchemaContainer GetSchemaContainer() override;

		virtual ResultPtr ExecuteResult(const std::string& findStatement, int bindStatement) override;
		virtual ResultPtr ExecuteResult(const std::string& findStatement) override;
		virtual ResultPtr ExecuteResult(const std::string& findStatement, const std::string& bindStatement) override;
		virtual void Execute(const std::string& findStatement, int bindStatement) override;
		virtual void Execute(const std::string& findStatement) override;
		virtual void Execute(const std::string& findStatement, const std::string& bindStatement) override;

	private:
		using MysqlxSessionPtr = std::unique_ptr<MysqlxSession>;

	private:
		static MysqlxSessionPtr GetMysqlxSessionPtr(const DatabaseObject& databaseObject);

	private:
		MysqlxSessionPtr m_MysqlxSession;
	};
}

#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR

#endif // DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_SESSION_H
