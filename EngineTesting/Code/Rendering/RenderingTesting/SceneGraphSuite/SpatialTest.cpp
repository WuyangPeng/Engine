///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:35)

#include "SpatialTest.h"
#include "System/Helper/Helper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, SpatialTest);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, SpatialTest);
CORE_TOOLS_FACTORY_DEFINE(Rendering, SpatialTest);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, SpatialTest);

Rendering::SpatialTest::SpatialTest(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ VisualPrimitiveType::None }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, SpatialTest)

Rendering::SpatialTest::ControllerSharedPtr Rendering::SpatialTest::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

void Rendering::SpatialTest::GetVisibleSet(MAYBE_UNUSED Culler& culler, MAYBE_UNUSED bool noCull) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}

void Rendering::SpatialTest::UpdateWorldBound() noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}

CoreTools::ObjectInterfaceSharedPtr Rendering::SpatialTest::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_1;

    return std::make_shared<ClassType>(*this);
}
