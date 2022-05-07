// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/05 11:24)

#include "SpatialTest.h"
#include "System/Helper/Helper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26455)
CORE_TOOLS_RTTI_DEFINE(Rendering, SpatialTest);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, SpatialTest);
CORE_TOOLS_FACTORY_DEFINE(Rendering, SpatialTest);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, SpatialTest);

Rendering::SpatialTest::SpatialTest()
    : ParentType{ VisualPrimitiveType::None }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, SpatialTest)

Rendering::SpatialTest::ControllerInterfaceSharedPtr Rendering::SpatialTest::Clone() const
{
    CLASS_IS_VALID_CONST_1;

    return nullptr;
    //ControllerInterfaceSharedPtr(new ClassType(*this));
}

void Rendering::SpatialTest::GetVisibleSet([[maybe_unused]] Culler& culler, [[maybe_unused]] bool noCull)
{
    CLASS_IS_VALID_1;
}

void Rendering::SpatialTest::UpdateWorldBound()
{
    CLASS_IS_VALID_1;
}

CoreTools::ObjectInterfaceSharedPtr Rendering::SpatialTest::CloneObject() const
{
    return nullptr;
}
