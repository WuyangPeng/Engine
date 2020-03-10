// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 09:57)

#ifndef DATABASE_SQL_INTERFACE_NULL_TABLE_H
#define DATABASE_SQL_INTERFACE_NULL_TABLE_H

#include "Database/DatabaseDll.h"

#include "TableImpl.h"
 
namespace Database
{
	class DATABASE_HIDDEN_DECLARE NullTable : public TableImpl
	{
	public:
		using ClassType = NullTable;
		using ParentType = TableImpl;

	public:
		explicit NullTable(const ConfigurationStrategy& configurationStrategy);
		virtual ~NullTable();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
	};
}

#endif // DATABASE_SQL_INTERFACE_NULL_TABLE_H
