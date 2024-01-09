/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:56)

#include "Rendering/RenderingExport.h"

#include "NullSpatial.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::NullSpatial::NullSpatial(const std::string& name)
    : ParentType{ name, true }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, NullSpatial)

CoreTools::ObjectInterface::ObjectInterfaceSharedPtr Rendering::NullSpatial::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return Clone();
}

void Rendering::NullSpatial::GetVisibleSet(Culler& culler, const CameraSharedPtr& camera, bool noCull) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    System::UnusedFunction(culler, camera, noCull);
}

Rendering::ControllerInterface::ControllerSharedPtr Rendering::NullSpatial::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

void Rendering::NullSpatial::UpdateWorldBound() noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}

bool Rendering::NullSpatial::IsNullObject() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return true;
}