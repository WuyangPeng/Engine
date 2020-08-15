// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 12:48)

#ifndef DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_DOC_RESULT_ROW_H
#define DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_DOC_RESULT_ROW_H

#include "Database/DatabaseDll.h"

#include "Database/SqlInterface/Detail/ResultRowImpl.h" 
#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR 

namespace Database
{
	class DATABASE_HIDDEN_DECLARE MysqlConnectorDocResultRow : public ResultRowImpl
	{
	public:
		using ClassType = MysqlConnectorDocResultRow;
		using ParentType = ResultRowImpl;
		using MysqlxDbDocPtr = std::shared_ptr<MysqlxDbDoc>;

	public:
                MysqlConnectorDocResultRow(const ConfigurationStrategy& configurationStrategy, const MysqlxDbDocPtr& mysqlxDbDoc) noexcept;
	 

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		  void Print(std::ostream& os) const override;

	private:
		MysqlxDbDocPtr m_MysqlxDbDoc;
	};
}

#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR

#endif // DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_DOC_RESULT_ROW_H
