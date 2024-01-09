/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:56)

#include "Rendering/RenderingExport.h"

#include "Light.h"
#include "Detail/LightImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Light)

CORE_TOOLS_RTTI_DEFINE(Rendering, Light)
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Light)
CORE_TOOLS_FACTORY_DEFINE(Rendering, Light)
CORE_TOOLS_IMPL_NON_OBJECT_PTR_DEFAULT_STREAM(Rendering, Light)

Rendering::Light::Light(bool isPerspective, DepthType depthType, float epsilon)
    : ParentType{ isPerspective, depthType, epsilon },
      impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, Light)

CoreTools::ObjectInterface::ObjectInterfaceSharedPtr Rendering::Light::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}