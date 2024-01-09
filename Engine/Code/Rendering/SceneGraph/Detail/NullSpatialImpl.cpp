/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:48)

#include "Rendering/RenderingExport.h"

#include "NullSpatialImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/SceneGraph/Spatial.h"

Rendering::NullSpatialImpl::NullSpatialImpl(CullingMode cullingMode) noexcept
    : ParentType{ cullingMode }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, NullSpatialImpl)

void Rendering::NullSpatialImpl::SetParent(const SpatialSharedPtr& aParent) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::UnusedFunction(aParent);
}

Rendering::SpatialImpl::SpatialSharedPtr Rendering::NullSpatialImpl::GetParent()
{
    RENDERING_CLASS_IS_VALID_9;

    return Spatial::GetNullObject();
}

Rendering::SpatialImpl::ConstSpatialSharedPtr Rendering::NullSpatialImpl::GetParent() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return Spatial::GetNullObject();
}

Rendering::SpatialImpl::SpatialImplSharedPtr Rendering::NullSpatialImpl::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}
