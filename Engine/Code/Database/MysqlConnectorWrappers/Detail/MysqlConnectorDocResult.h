// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 10:17)

#ifndef DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_DOC_RESULT_H
#define DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_DOC_RESULT_H

#include "Database/DatabaseDll.h"

#include "Database/SqlInterface/Detail/ResultImpl.h" 
#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR 
 
namespace Database
{
	class DATABASE_HIDDEN_DECLARE MysqlConnectorDocResult : public ResultImpl
	{
	public:
		using ClassType = MysqlConnectorDocResult;
		using ParentType = ResultImpl;
		using MysqlxDocResultPtr = std::shared_ptr<MysqlxDocResult>;

	public:
		MysqlConnectorDocResult(const ConfigurationStrategy& configurationStrategy, const MysqlxDocResultPtr& mysqlxDocResult);
		virtual ~MysqlConnectorDocResult();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE; 

		virtual ResultRowPtr FetchOne() override;
		virtual ResultRowContainer FetchAll() override;

	private:
		MysqlxDocResultPtr m_MysqlxDocResult;
	};
}

#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR

#endif // DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_DOC_RESULT_H
