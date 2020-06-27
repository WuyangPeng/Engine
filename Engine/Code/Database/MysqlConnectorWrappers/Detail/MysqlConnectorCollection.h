// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 12:47)

#ifndef DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_COLLECTION_H
#define DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_COLLECTION_H

#include "Database/DatabaseDll.h"

#include "Database/SqlInterface/SqlInterfaceFwd.h"
#include "Database/SqlInterface/Detail/CollectionImpl.h" 
#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR 

namespace Database
{
	class DATABASE_HIDDEN_DECLARE MysqlConnectorCollection : public CollectionImpl
	{
	public:
		using ClassType = MysqlConnectorCollection;
		using ParentType = CollectionImpl;

	public:
		explicit MysqlConnectorCollection(const Schema& schema, const std::string& collectionName);
		virtual ~MysqlConnectorCollection();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual ResultPtr ExecuteDoc(const std::string& findStatement, const BindStatementType& bindStatement, int limitStatement) override;

	private:
		using MysqlxCollectionPtr = std::unique_ptr<MysqlxCollection>;

	private:
		static MysqlxCollectionPtr GetMysqlxCollectionPtr(const Schema& schema, const std::string& collectionName);

	private:
		MysqlxCollectionPtr m_MysqlxCollection;
	};
}

#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR

#endif // DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_COLLECTION_H
