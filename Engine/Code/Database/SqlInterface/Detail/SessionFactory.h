// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 09:58)

#ifndef DATABASE_SQL_INTERFACE_SESSION_FACTORY_H
#define DATABASE_SQL_INTERFACE_SESSION_FACTORY_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"

namespace Database
{
	class SessionImpl;
	class DatabaseObject;

	class DATABASE_HIDDEN_DECLARE SessionFactory
	{
	public:
		using ClassType = SessionFactory;
		using ImplType = SessionImpl;
		using ImplTypePtr = std::shared_ptr<ImplType>;

	public:
		SessionFactory();

		CLASS_INVARIANT_DECLARE;	 

		static ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy);
		static ImplTypePtr Create(const DatabaseObject& databaseObject);
	};	
}

#endif // DATABASE_SQL_INTERFACE_SESSION_FACTORY_H
