// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 10:17)

#ifndef DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_SCHEMA_H
#define DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_SCHEMA_H

#include "Database/DatabaseDll.h"

#include "Database/SqlInterface/Detail/SchemaImpl.h" 
#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR 
 
namespace Database
{
	class SessionImpl;

	class DATABASE_HIDDEN_DECLARE MysqlConnectorSchema : public SchemaImpl
	{
	public:
		using ClassType = MysqlConnectorSchema;
		using ParentType = SchemaImpl;
		using SessionWeakPtr = std::weak_ptr<SessionImpl>;	

	public:
		explicit MysqlConnectorSchema(const SessionWeakPtr& sessionWeakPtr);
		MysqlConnectorSchema(const SessionWeakPtr& sessionWeakPtr,int dbIndex);
		MysqlConnectorSchema(const ConfigurationStrategy& configurationStrategy, const MysqlxSchema& mysqlxSchema);
		virtual ~MysqlConnectorSchema();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual MysqlxCollectionPtr GetCollection(const std::string& collectionName) override;
		virtual MysqlxTablePtr GetTable(const std::string& tableonName) override;

	private:
		using MysqlxSchemaPtr = std::unique_ptr<MysqlxSchema>;

	private:
		static ConfigurationStrategy GetConfigurationStrategy(const SessionWeakPtr& sessionWeakPtr);
		static MysqlxSchemaPtr GetMysqlxSchemaPtr(const SessionWeakPtr& sessionWeakPtr);
		static MysqlxSchemaPtr GetMysqlxSchemaPtr(const SessionWeakPtr& sessionWeakPtr,int dbIndex);

	private:
		MysqlxSchemaPtr m_MysqlxSchema;		
	};
}

#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR

#endif // DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_SCHEMA_H
