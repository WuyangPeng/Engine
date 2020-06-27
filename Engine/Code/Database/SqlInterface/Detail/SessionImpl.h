// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 11:27)

#ifndef DATABASE_SQL_INTERFACE_SESSION_IMPL_H
#define DATABASE_SQL_INTERFACE_SESSION_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/SqlInterface/Schema.h"
#include "Database/SqlInterface/Result.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"

namespace Database
{
	class DATABASE_HIDDEN_DECLARE SessionImpl
	{
	public:
		using ClassType = SessionImpl;
		using ImplTypePtr = std::shared_ptr<ClassType>;
		using MysqlxSchemaPtr = std::unique_ptr<MysqlxSchema>;
		using SchemaPtr = std::unique_ptr<Schema>;
		using SchemaContainer = std::vector<SchemaPtr>;
		using ResultPtr = std::shared_ptr<Result>;

	public:
		explicit SessionImpl(const ConfigurationStrategy& configurationStrategy);
		virtual ~SessionImpl() = 0;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		ConfigurationStrategy GetConfigurationStrategy() const;

		virtual MysqlxSchemaPtr GetMysqlxSchemaPtr();
		virtual MysqlxSchemaPtr GetMysqlxSchemaPtr(int dbIndex);
		virtual SchemaContainer GetSchemaContainer();

		virtual ResultPtr ExecuteResult(const std::string& findStatement, int bindStatement);
		virtual ResultPtr ExecuteResult(const std::string& findStatement);
		virtual ResultPtr ExecuteResult(const std::string& findStatement, const std::string& bindStatement);
		virtual void Execute(const std::string& findStatement, int bindStatement);
		virtual void Execute(const std::string& findStatement, const std::string& bindStatement);
		virtual void Execute(const std::string& findStatement);

	private:
		ConfigurationStrategy m_ConfigurationStrategy;
	};
}

#endif // DATABASE_SQL_INTERFACE_SESSION_IMPL_H
