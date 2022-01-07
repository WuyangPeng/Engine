// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 14:10)

#include "ErrorObject.h" 
#include "CoreTools/Helper/AssertMacro.h"

#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26432)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26456)
#include SYSTEM_WARNING_DISABLE(26455)
CoreTools::ErrorObject
	::ErrorObject()
	:ParentType{ "ErrorObject" }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::ErrorObject
	::~ErrorObject()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ErrorObject)

CORE_TOOLS_RTTI_DEFINE(CoreTools, ErrorObject);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, ErrorObject);
CORE_TOOLS_FACTORY_DEFINE(CoreTools, ErrorObject);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(CoreTools, ErrorObject);

CoreTools::ObjectInterfaceSharedPtr CoreTools::ErrorObject::CloneObject() const
{
    return nullptr;
}
#include STSTEM_WARNING_POP