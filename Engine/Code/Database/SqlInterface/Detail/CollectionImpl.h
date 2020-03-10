// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 09:54)

#ifndef DATABASE_SQL_INTERFACE_COLLECTION_IMPL_H
#define DATABASE_SQL_INTERFACE_COLLECTION_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/SqlInterface/Result.h"

namespace Database
{
	class DATABASE_HIDDEN_DECLARE CollectionImpl
	{
	public:
		using ClassType = CollectionImpl;
		using ImplTypePtr = std::shared_ptr<ClassType>;
		using ResultPtr = std::shared_ptr<Result>;
		using BindStatementType = std::map<std::string, std::string>;

	public:
		explicit CollectionImpl(const ConfigurationStrategy& configurationStrategy);
		virtual ~CollectionImpl() = 0;

		CLASS_INVARIANT_VIRTUAL_DECLARE; 

		virtual ResultPtr ExecuteDoc(const std::string& findStatement, const BindStatementType& bindStatement,int limitStatement);

		ConfigurationStrategy GetConfigurationStrategy() const;
		
	public:	
		ConfigurationStrategy m_ConfigurationStrategy;
	};	
}

#endif // DATABASE_SQL_INTERFACE_COLLECTION_IMPL_H
