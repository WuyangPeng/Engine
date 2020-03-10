// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/03 09:59)

#ifndef DATABASE_SQL_INTERFACE_TABLE_IMPL_H
#define DATABASE_SQL_INTERFACE_TABLE_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/SqlInterface/Result.h"

#include <map>

namespace Database
{
	class DATABASE_HIDDEN_DECLARE TableImpl
	{
	public:
		using ClassType = TableImpl;
		using ImplTypePtr = std::shared_ptr<ClassType>;
		using ResultPtr = std::shared_ptr<Result>;
		using BindStatementType = std::map<std::string, std::string>;

	public:
		explicit TableImpl(const ConfigurationStrategy& configurationStrategy);
		virtual ~TableImpl();

		CLASS_INVARIANT_VIRTUAL_DECLARE;	

		ConfigurationStrategy GetConfigurationStrategy() const;

		virtual ResultPtr Select(std::initializer_list<std::string> selectStatement,const std::string& whereStatement, 
			                     const std::string& orderByStatement,const BindStatementType& bindStatement);
		
	public:	
		ConfigurationStrategy m_ConfigurationStrategy;
	};	
}

#endif // DATABASE_SQL_INTERFACE_TABLE_IMPL_H
