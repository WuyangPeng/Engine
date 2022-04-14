// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/05 16:36)

#include "ControllerTest.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, ControllerTest);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ControllerTest);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ControllerTest);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, ControllerTest);
#include SYSTEM_WARNING_DISABLE(26455)
Rendering::ControllerTest::ControllerTest()
    : ParentType{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ControllerTest)

Rendering::ControllerInterfaceSharedPtr Rendering::ControllerTest::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

CoreTools::ObjectInterface::ObjectInterfaceSharedPtr Rendering::ControllerTest::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
