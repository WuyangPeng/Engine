// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 09:59)

#ifndef DATABASE_SQL_INTERFACE_DOC_RESULT_H
#define DATABASE_SQL_INTERFACE_DOC_RESULT_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Helper/ExportMacro.h"  
#include "Database/MysqlConnectorWrappers/Fwd/MysqlConnectorFwd.h"
#include "ResultRow.h"

#include <vector>

DATABASE_EXPORT_SHARED_PTR(ResultImpl);

namespace Database
{
	class ConfigurationStrategy;

	class DATABASE_DEFAULT_DECLARE Result : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(Result);
		using ResultRowPtr = std::unique_ptr<ResultRow>;
		using ResultRowContainer = std::vector<ResultRowPtr>; 

	public:
		explicit Result(const ConfigurationStrategy& configurationStrategy);

		CLASS_INVARIANT_DECLARE;

		ConfigurationStrategy GetConfigurationStrategy() const;

		virtual ResultRowPtr FetchOne();
		virtual ResultRowContainer FetchAll();

	private:
		IMPL_TYPE_DECLARE(Result);

#if defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)
	public:
		using MysqlxDocResultPtr = std::shared_ptr<MysqlxDocResult>;
		using MysqlxRowResultPtr = std::shared_ptr<MysqlxRowResult>;

	public:	 
		Result(const ConfigurationStrategy& configurationStrategy, const MysqlxDocResultPtr& mysqlxDocResult);
		Result(const ConfigurationStrategy& configurationStrategy, const MysqlxRowResultPtr& mysqlxRowResult);
#endif // defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)
	};
}

#endif // DATABASE_SQL_INTERFACE_DOC_RESULT_H
