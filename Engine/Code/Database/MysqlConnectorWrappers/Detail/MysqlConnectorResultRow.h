// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 10:17)

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
		explicit MysqlConnectorResultRow(const ConfigurationStrategy& configurationStrategy,const MysqlxRowPtr& mysqlxRow);
		virtual ~MysqlConnectorResultRow();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual void Print(std::ostream& os) const override;

		virtual int GetIntValue(int pos) const override;
		virtual uint32_t GetUIntValue(int pos) const override;
		virtual int64_t GetInt64Value(int pos) const override;
		virtual uint64_t GetUInt64Value(int pos) const override;
		virtual float GetFloatValue(int pos) const override;
		virtual double GetDoubleValue(int pos) const override;
		virtual bool GetBoolValue(int pos) const override;
		virtual std::string GetStringValue(int pos) const override;
		virtual std::wstring GetWStringValue(int pos) const override;

		virtual int GetColCount() const override;

	private:
		MysqlxRowPtr m_MysqlxRow;
	};
}

#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR

#endif // DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_RESULT_ROW_H
