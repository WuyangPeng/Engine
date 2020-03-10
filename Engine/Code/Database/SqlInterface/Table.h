// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 10:00)

#ifndef DATABASE_SQL_INTERFACE_TABLE_H
#define DATABASE_SQL_INTERFACE_TABLE_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Helper/ExportMacro.h"  

#include <string>
#include <map>

DATABASE_EXPORT_SHARED_PTR(TableImpl);
EXPORT_NONCOPYABLE_CLASS(DATABASE);

namespace Database
{
	class ConfigurationStrategy;
	class Schema;
	class Result;

	class DATABASE_DEFAULT_DECLARE Table : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(Table);
		using ResultPtr = std::shared_ptr<Result>;
		using BindStatementType = std::map<std::string, std::string>;

	public:
		Table(const Schema& schema,const std::string& tableName);

		CLASS_INVARIANT_DECLARE;

		ConfigurationStrategy GetConfigurationStrategy() const;

		ResultPtr Select(std::initializer_list<std::string> selectStatement, const std::string& whereStatement,
			             const std::string& orderByStatement, const BindStatementType& bindStatement);

	private:
		IMPL_TYPE_DECLARE(Table);
	};
}

#endif // DATABASE_SQL_INTERFACE_TABLE_H
