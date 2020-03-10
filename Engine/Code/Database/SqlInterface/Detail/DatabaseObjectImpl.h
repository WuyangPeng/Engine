// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 09:56)

#ifndef DATABASE_SQL_INTERFACE_DATABASE_OBJECT_IMPL_H
#define DATABASE_SQL_INTERFACE_DATABASE_OBJECT_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"

namespace Database
{
	class DATABASE_HIDDEN_DECLARE DatabaseObjectImpl
	{
	public:
		using ClassType = DatabaseObjectImpl;
		using ImplTypePtr = std::shared_ptr<ClassType>;
		using MysqlxSessionPtr = std::unique_ptr<MysqlxSession>;

	public:
		explicit DatabaseObjectImpl(const ConfigurationStrategy& configurationStrategy);
		virtual ~DatabaseObjectImpl() = 0;

		CLASS_INVARIANT_VIRTUAL_DECLARE; 
		
	public:	
		ConfigurationStrategy GetConfigurationStrategy() const; 
		virtual MysqlxSessionPtr GetMysqlxSessionPtr();

	private:
		ConfigurationStrategy m_ConfigurationStrategy;
	};
}

#endif // DATABASE_SQL_INTERFACE_DATABASE_OBJECT_IMPL_H
