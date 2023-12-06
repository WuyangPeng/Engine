/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/22 12:32)

#include "ViewVolumeTest.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, ViewVolumeTest);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ViewVolumeTest);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ViewVolumeTest);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, ViewVolumeTest);

Rendering::ViewVolumeTest::ViewVolumeTestSharedPtr Rendering::ViewVolumeTest::Create(bool isPerspective, DepthType depthType, float epsilon)
{
    return std::make_shared<ClassType>(isPerspective, depthType, epsilon, Constructor::Default);
}

Rendering::ViewVolumeTest::ViewVolumeTest(bool isPerspective, DepthType depthType, float epsilon, Constructor constructor)
    : ParentType{ isPerspective, depthType, epsilon }
{
    System::UnusedFunction(constructor);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ViewVolumeTest)

Rendering::ViewVolumeTest::ObjectInterfaceSharedPtr Rendering::ViewVolumeTest::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

void Rendering::ViewVolumeTest::UpdateProjectionViewMatrix() noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}