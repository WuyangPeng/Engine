// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 12:27)

#include "Database/DatabaseExport.h"

#include "NullCollection.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 

using std::make_shared;

Database::NullCollection
	::NullCollection(const ConfigurationStrategy& configurationStrategy)
	: ParentType{ configurationStrategy }
{
	DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::NullCollection
	::~NullCollection()
{
	DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, NullCollection)



