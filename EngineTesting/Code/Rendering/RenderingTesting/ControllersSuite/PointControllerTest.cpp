// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/06 09:43)

#include "PointControllerTest.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

#include SYSTEM_WARNING_DISABLE(26455)

CORE_TOOLS_RTTI_DEFINE(Rendering, PointControllerTest);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, PointControllerTest);
CORE_TOOLS_FACTORY_DEFINE(Rendering, PointControllerTest);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, PointControllerTest);

Rendering::PointControllerTest::PointControllerTest()
    : ParentType{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, PointControllerTest)

Rendering::PointControllerTest::ControllerInterfaceSharedPtr Rendering::PointControllerTest::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ControllerInterfaceSharedPtr(std::make_shared<ClassType>(*this));
}

CoreTools::ObjectInterfaceSharedPtr Rendering::PointControllerTest::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ControllerInterfaceSharedPtr(std::make_shared<ClassType>(*this));
}
