// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 11:31)

#ifndef DATABASE_SQL_INTERFACE_DOC_RESULT_ROW_H
#define DATABASE_SQL_INTERFACE_DOC_RESULT_ROW_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Helper/ExportMacro.h"  
#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/MysqlConnectorWrappers/Fwd/MysqlConnectorFwd.h"

#include <string>

DATABASE_EXPORT_SHARED_PTR(ResultRowImpl);
EXPORT_NONCOPYABLE_CLASS(DATABASE);

namespace Database
{
	class DATABASE_DEFAULT_DECLARE ResultRow : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(ResultRow);

	public:
		explicit ResultRow(const ConfigurationStrategy& configurationStrategy);

		CLASS_INVARIANT_DECLARE;

		void Print(std::ostream& os) const;

		int GetIntValue(int pos) const;
		uint32_t GetUIntValue(int pos) const;
		int64_t GetInt64Value(int pos) const;
		uint64_t GetUInt64Value(int pos) const;
		float GetFloatValue(int pos) const;
		double GetDoubleValue(int pos) const;
		bool GetBoolValue(int pos) const;
		std::string GetStringValue(int pos) const;
		std::wstring GetWStringValue(int pos) const;

		int GetColCount() const;

	private:
		IMPL_TYPE_DECLARE(ResultRow);

	#if defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)
	public:
		using MysqlxDbDocPtr = std::shared_ptr<MysqlxDbDoc>;
		using MysqlxRowPtr = std::shared_ptr<MysqlxRow>;

	public:
		ResultRow(const ConfigurationStrategy& configurationStrategy, const MysqlxDbDocPtr& mysqlxDbDoc);
		ResultRow(const ConfigurationStrategy& configurationStrategy, const MysqlxRowPtr& mysqlxRow);
	#endif // defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)
	};

	DATABASE_DEFAULT_DECLARE std::ostream& operator<<(std::ostream& out, const ResultRow& docResultRow);
}

#endif // DATABASE_SQL_INTERFACE_DOC_RESULT_ROW_H
