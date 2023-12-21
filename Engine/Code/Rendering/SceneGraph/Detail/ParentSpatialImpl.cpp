///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.2 (2023/12/07 10:52)

#include "Rendering/RenderingExport.h"

#include "ParentSpatialImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/SceneGraph/Spatial.h"

Rendering::ParentSpatialImpl::ParentSpatialImpl(CullingMode cullingMode)
    : ParentType{ cullingMode },
      parent{ Spatial::GetNullObject() }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ParentSpatialImpl)

void Rendering::ParentSpatialImpl::SetParent(const SpatialSharedPtr& aParent)
{
    RENDERING_CLASS_IS_VALID_9;

    if (aParent == nullptr)
    {
        parent = Spatial::GetNullObject();
    }
    else
    {
        parent = aParent;
    }
}

Rendering::ParentSpatialImpl::SpatialSharedPtr Rendering::ParentSpatialImpl::GetParent()
{
    RENDERING_CLASS_IS_VALID_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26473)

    return std::const_pointer_cast<Spatial>(static_cast<const ClassType*>(this)->GetParent());

#include SYSTEM_WARNING_POP
}

Rendering::ParentSpatialImpl::ConstSpatialSharedPtr Rendering::ParentSpatialImpl::GetParent() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto result = parent.lock();

    if (!result)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("parent 指针已释放。"))
    }

    return result;
}

Rendering::SpatialImpl::SpatialImplSharedPtr Rendering::ParentSpatialImpl::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}
