// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 10:03)

#include "Database/DatabaseExport.h"

#include "NullTable.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 

using std::make_shared;

Database::NullTable
	::NullTable(const ConfigurationStrategy& configurationStrategy)
	: ParentType{ configurationStrategy }
{
	DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::NullTable
	::~NullTable()
{
	DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, NullTable)

