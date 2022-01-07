// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 14:15)

#include "TestObject.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLink.h"
#include "CoreTools/ObjectSystems/ObjectRegister.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26432)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26456)
#include SYSTEM_WARNING_DISABLE(26455)
using std::string;

CoreTools::TestObject ::TestObject()
    : ParentType{ "TestObject" }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::TestObject ::~TestObject()
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, TestObject)

CORE_TOOLS_RTTI_DEFINE(CoreTools, TestObject);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, TestObject);
CORE_TOOLS_FACTORY_DEFINE(CoreTools, TestObject);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(CoreTools, TestObject);

CoreTools::ObjectInterfaceSharedPtr CoreTools::TestObject::CloneObject() const
{
    return nullptr;
}
#include STSTEM_WARNING_POP
