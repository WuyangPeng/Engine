// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 11:30)

#ifndef DATABASE_SQL_INTERFACE_DOC_RESULT_H
#define DATABASE_SQL_INTERFACE_DOC_RESULT_H

#include "Database/DatabaseDll.h"

#include "ResultRow.h"
#include "CoreTools/Helper/ExportMacro.h"  
#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/MysqlConnectorWrappers/Fwd/MysqlConnectorFwd.h"

#include <vector>

DATABASE_EXPORT_SHARED_PTR(ResultImpl);

namespace Database
{
	class DATABASE_DEFAULT_DECLARE Result  
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(Result);
		using ResultRowPtr = std::unique_ptr<ResultRow>;
		using ResultRowContainer = std::vector<ResultRowPtr>;

	public:
		explicit Result(const ConfigurationStrategy& configurationStrategy);
		virtual ~Result() noexcept = default;
		Result(const Result&) = delete;
		Result& operator=(const Result&) = delete;
		Result(Result&&) noexcept = default;
		Result& operator=(Result&&) noexcept = default;

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
