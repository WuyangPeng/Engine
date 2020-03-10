// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 09:56)

#ifndef DATABASE_SQL_INTERFACE_NULL_SCHEMA_H
#define DATABASE_SQL_INTERFACE_NULL_SCHEMA_H

#include "Database/DatabaseDll.h"

#include "SchemaImpl.h"

namespace Database
{
	class DATABASE_HIDDEN_DECLARE NullSchema : public SchemaImpl
	{
	public:
		using ClassType = NullSchema;
		using ParentType = SchemaImpl;

	public:
		explicit NullSchema(const ConfigurationStrategy& configurationStrategy);
		virtual ~NullSchema();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
	};
}

#endif // DATABASE_SQL_INTERFACE_NULL_SCHEMA_H
