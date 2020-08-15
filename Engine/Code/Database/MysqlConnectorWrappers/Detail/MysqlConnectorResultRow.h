// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 12:48)

#ifndef DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_RESULT_ROW_H
#define DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_RESULT_ROW_H

#include "Database/DatabaseDll.h"

#include "Database/SqlInterface/Detail/ResultRowImpl.h" 
#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR 

namespace Database
{
	class DATABASE_HIDDEN_DECLARE MysqlConnectorResultRow : public ResultRowImpl
	{
	public:
		using ClassType = MysqlConnectorResultRow;
		using ParentType = ResultRowImpl;
		using MysqlxRowPtr = std::shared_ptr<MysqlxRow>;

	public:
                explicit MysqlConnectorResultRow(const ConfigurationStrategy& configurationStrategy, const MysqlxRowPtr& mysqlxRow) noexcept;
	 

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		  void Print(std::ostream& os) const override;

		  int GetIntValue(int pos) const override;
		  uint32_t GetUIntValue(int pos) const override;
		  int64_t GetInt64Value(int pos) const override;
		  uint64_t GetUInt64Value(int pos) const override;
		  float GetFloatValue(int pos) const override;
		  double GetDoubleValue(int pos) const override;
		  bool GetBoolValue(int pos) const override;
		  std::string GetStringValue(int pos) const override;
		  std::wstring GetWStringValue(int pos) const override;

		  int GetColCount() const override;

	private:
		MysqlxRowPtr m_MysqlxRow;
	};
}

#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR

#endif // DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_RESULT_ROW_H
