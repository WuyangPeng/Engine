// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/05 16:31)

#include "ControlledObjectTest.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include SYSTEM_WARNING_DISABLE(26455)
CORE_TOOLS_RTTI_DEFINE(Rendering, ControlledObjectTest);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ControlledObjectTest);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ControlledObjectTest);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, ControlledObjectTest);

Rendering::ControlledObjectTest::ControlledObjectTest()
    : ParentType{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ControlledObjectTest)

Rendering::ControlledObjectTest::ControllerInterfaceSharedPtr Rendering::ControlledObjectTest::Clone() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return nullptr;
}

CoreTools::ObjectInterface::ObjectInterfaceSharedPtr Rendering::ControlledObjectTest::CloneObject() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return nullptr;
}
