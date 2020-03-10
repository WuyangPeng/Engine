// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/03 09:58)

#ifndef DATABASE_SQL_INTERFACE_DOC_RESULT_ROW_FACTORY_H
#define DATABASE_SQL_INTERFACE_DOC_RESULT_ROW_FACTORY_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"

namespace Database
{
	class ResultRowImpl; 

	class DATABASE_HIDDEN_DECLARE ResultRowFactory
	{
	public:
		using ClassType = ResultRowFactory;
		using ImplType = ResultRowImpl;
		using ImplTypePtr = std::shared_ptr<ImplType>;
		using MysqlxDbDocPtr = std::shared_ptr<MysqlxDbDoc>;
		using MysqlxRowPtr = std::shared_ptr<MysqlxRow>;

	public:
		ResultRowFactory();

		CLASS_INVARIANT_DECLARE;	 

		static ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy);
		static ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy, const MysqlxDbDocPtr& mysqlxDbDoc);
		static ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy, const MysqlxRowPtr& mysqlxRow);
	};	
}

#endif // DATABASE_SQL_INTERFACE_DOC_RESULT_ROW_FACTORY_H
