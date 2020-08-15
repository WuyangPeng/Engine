// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.5 (2020/03/16 12:27)

#include "Database/DatabaseExport.h"

#include "NullSchema.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 

using std::make_shared;

Database::NullSchema
	::NullSchema(const ConfigurationStrategy& configurationStrategy) noexcept
	: ParentType{ configurationStrategy }
{
	DATABASE_SELF_CLASS_IS_VALID_9;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, NullSchema)

