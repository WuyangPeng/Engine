// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 09:59)

#ifndef DATABASE_SQL_INTERFACE_SESSION_H
#define DATABASE_SQL_INTERFACE_SESSION_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Helper/ExportMacro.h"  
#include "Schema.h"
#include "Result.h"
#include "Database/Configuration/ConfigurationStrategy.h"

#include <boost/noncopyable.hpp>

DATABASE_EXPORT_SHARED_PTR(SessionImpl);

namespace Database
{
	class ConfigurationStrategy;
	class DatabaseObject;

	class DATABASE_DEFAULT_DECLARE Session : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(Session);
		using SchemaPtr = std::unique_ptr<Schema>;
		using SchemaContainer = std::vector<SchemaPtr>;
		using ResultPtr = std::shared_ptr<Result>;

	public:
		explicit Session(const ConfigurationStrategy& configurationStrategy);
		explicit Session(const DatabaseObject& databaseObject);

		CLASS_INVARIANT_DECLARE;

		ConfigurationStrategy GetConfigurationStrategy() const;

		SchemaContainer GetSchemaContainer();

		ResultPtr ExecuteResult(const std::string& findStatement, int bindStatement);
		ResultPtr ExecuteResult(const std::string& findStatement, const std::string& bindStatement);
		ResultPtr ExecuteResult(const std::string& findStatement);
		void Execute(const std::string& findStatement, int bindStatement);
		void Execute(const std::string& findStatement, const std::string& bindStatement);
		void Execute(const std::string& findStatement);

	private:
		IMPL_TYPE_DECLARE(Session);

#if defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)
	public:
		using SessionWeakPtr = std::weak_ptr<ImplType>;

	public:
		SessionWeakPtr GetImplType() const;
#endif // defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)
	};
}

#endif // DATABASE_SQL_INTERFACE_SESSION_H
