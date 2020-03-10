// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 09:56)

#ifndef DATABASE_SQL_INTERFACE_NULL_DATABASE_OBJECT_H
#define DATABASE_SQL_INTERFACE_NULL_DATABASE_OBJECT_H

#include "Database/DatabaseDll.h"

#include "DatabaseObjectImpl.h"

namespace Database
{
	class DATABASE_HIDDEN_DECLARE NullDatabaseObject : public  DatabaseObjectImpl
	{
	public:
		using ClassType = NullDatabaseObject;
		using ParentType = DatabaseObjectImpl;

	public:
		explicit NullDatabaseObject(const ConfigurationStrategy& configurationStrategy);
		virtual ~NullDatabaseObject();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
	};
}

#endif // DATABASE_SQL_INTERFACE_NULL_DATABASE_OBJECT_H
