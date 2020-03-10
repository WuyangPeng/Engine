// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 09:56)

#ifndef DATABASE_SQL_INTERFACE_DATABASE_OBJECT_FACTORY_H
#define DATABASE_SQL_INTERFACE_DATABASE_OBJECT_FACTORY_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"

namespace Database
{
	class DatabaseObjectImpl;

	class DATABASE_HIDDEN_DECLARE DatabaseObjectFactory
	{
	public:
		using ClassType = DatabaseObjectFactory;
		using ImplType = DatabaseObjectImpl;
		using ImplTypePtr = std::shared_ptr<ImplType>;

	public:
		DatabaseObjectFactory();

		CLASS_INVARIANT_DECLARE;	 

		static ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy);
	};	
}

#endif // DATABASE_SQL_INTERFACE_DATABASE_OBJECT_FACTORY_H
