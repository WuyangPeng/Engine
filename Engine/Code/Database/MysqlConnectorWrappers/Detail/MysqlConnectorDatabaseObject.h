// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 10:17)

#ifndef DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_DATABASE_OBJECT_H
#define DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_DATABASE_OBJECT_H

#include "Database/DatabaseDll.h"

#include "Database/SqlInterface/Detail/DatabaseObjectImpl.h" 
#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR 
 
namespace Database
{
	class DATABASE_HIDDEN_DECLARE MysqlConnectorDatabaseObject : public  DatabaseObjectImpl
	{
	public:
		using ClassType = MysqlConnectorDatabaseObject;
		using ParentType = DatabaseObjectImpl;

	public:
		explicit MysqlConnectorDatabaseObject(const ConfigurationStrategy& configurationStrategy);
		virtual ~MysqlConnectorDatabaseObject();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual MysqlxSessionPtr GetMysqlxSessionPtr() override;

	private:
		using MysqlxClientPtr = std::unique_ptr<MysqlxClient>;

	private:
		MysqlxClientPtr m_MysqlxClient;
	};
}

#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR

#endif // DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_DATABASE_OBJECT_H
