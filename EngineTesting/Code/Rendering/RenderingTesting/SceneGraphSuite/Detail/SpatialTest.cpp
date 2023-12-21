/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/07 14:05)

#include "SpatialTest.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, SpatialTest);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, SpatialTest);
CORE_TOOLS_FACTORY_DEFINE(Rendering, SpatialTest);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, SpatialTest);

Rendering::SpatialTest::SpatialTestSharedPtr Rendering::SpatialTest::Create(const std::string& name)
{
    return std::make_shared<ClassType>(name, Constructor::Default);
}

Rendering::SpatialTest::SpatialTest(const std::string& name, Constructor constructor)
    : ParentType{ name }
{
    System::UnusedFunction(constructor);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, SpatialTest)

Rendering::SpatialTest::ControllerSharedPtr Rendering::SpatialTest::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

void Rendering::SpatialTest::GetVisibleSet(Culler& culler, const CameraSharedPtr& camera, bool noCull) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    System::UnusedFunction(culler, camera, noCull);
}

void Rendering::SpatialTest::UpdateWorldBound() noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}

CoreTools::ObjectInterfaceSharedPtr Rendering::SpatialTest::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_1;

    return Clone();
}
