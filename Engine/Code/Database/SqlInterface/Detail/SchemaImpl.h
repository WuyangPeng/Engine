// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 09:58)

#ifndef DATABASE_SQL_INTERFACE_SCHEMA_IMPL_H
#define DATABASE_SQL_INTERFACE_SCHEMA_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"

namespace Database
{
	class DATABASE_HIDDEN_DECLARE SchemaImpl
	{
	public:
		using ClassType = SchemaImpl;
		using ImplTypePtr = std::shared_ptr<ClassType>;
		using MysqlxCollectionPtr = std::unique_ptr<MysqlxCollection>;
		using MysqlxTablePtr = std::unique_ptr<MysqlxTable>;

	public:
		explicit SchemaImpl(const ConfigurationStrategy& configurationStrategy);
		virtual ~SchemaImpl() = 0;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		ConfigurationStrategy GetConfigurationStrategy() const;

		virtual MysqlxCollectionPtr GetCollection(const std::string& collectionName);
		virtual MysqlxTablePtr GetTable(const std::string& tableonName);
		
	public:	
		ConfigurationStrategy m_ConfigurationStrategy;
	};	
}

#endif // DATABASE_SQL_INTERFACE_SCHEMA_IMPL_H
