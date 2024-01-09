/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:51)

#include "Rendering/RenderingExport.h"

#include "SpatialImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Rendering/SceneGraph/Spatial.h"
#include "Rendering/Visibility/VisibilityFwd.h"

Rendering::SpatialImpl::SpatialImpl(CullingMode cullingMode) noexcept
    : localTransform{},
      worldTransform{},
      worldTransformIsCurrent{ false },
      worldBound{},
      worldBoundIsCurrent{ false },
      culling{ cullingMode }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, SpatialImpl)

void Rendering::SpatialImpl::SetWorldBound(const BoundingSphere& bound) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    worldBound = bound;
}

void Rendering::SpatialImpl::DirectSetWorldTransform(const Transform& transform) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    worldTransform = transform;
    worldTransformIsCurrent = true;
}

void Rendering::SpatialImpl::DirectSetWorldBound(const BoundingSphere& bound) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    worldBound = bound;
    worldBoundIsCurrent = true;
}

void Rendering::SpatialImpl::SetLocalTransform(const Transform& transform) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    localTransform = transform;
    worldTransformIsCurrent = false;
}

void Rendering::SpatialImpl::SetCullingMode(CullingMode aCulling) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    culling = aCulling;
}

void Rendering::SpatialImpl::SetLocalTransformToWorldTransform(const Transform& aWorldTransform)
{
    RENDERING_CLASS_IS_VALID_9;

    worldTransform = aWorldTransform * localTransform;
    worldTransformIsCurrent = false;
}

void Rendering::SpatialImpl::SetLocalTransformToWorldTransform() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    worldTransform = localTransform;
    worldTransformIsCurrent = false;
}

void Rendering::SpatialImpl::InitWorldBound()
{
    RENDERING_CLASS_IS_VALID_9;

    worldBound = BoundingSphere{ APoint::GetOrigin(), 0.0f };
    worldBoundIsCurrent = false;
}

void Rendering::SpatialImpl::GrowToContain(const BoundingSphere& aWorldBound)
{
    RENDERING_CLASS_IS_VALID_9;

    worldBound.GrowToContain(aWorldBound);
    worldBoundIsCurrent = false;
}

bool Rendering::SpatialImpl::GetWorldTransformIsCurrent() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return worldTransformIsCurrent;
}

bool Rendering::SpatialImpl::GetWorldBoundIsCurrent() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return worldBoundIsCurrent;
}

Mathematics::TransformF Rendering::SpatialImpl::GetLocalTransform() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return localTransform;
}

Mathematics::TransformF Rendering::SpatialImpl::GetWorldTransform() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return worldTransform;
}

Mathematics::BoundingSphereF Rendering::SpatialImpl::GetWorldBound() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return worldBound;
}

Rendering::CullingMode Rendering::SpatialImpl::GetCullingMode() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return culling;
}

void Rendering::SpatialImpl::Load(CoreTools::BufferSource& source)
{
    source.ReadAggregate(localTransform);
    source.ReadAggregate(worldTransform);
    worldTransformIsCurrent = source.ReadBool();
    source.ReadAggregate(worldBound);
    worldBoundIsCurrent = source.ReadBool();
    source.ReadEnum(culling);
}

void Rendering::SpatialImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteAggregate(localTransform);
    target.WriteAggregate(worldTransform);
    target.Write(worldTransformIsCurrent);
    target.WriteAggregate(worldBound);
    target.Write(worldBoundIsCurrent);
    target.WriteEnum(culling);
}

int Rendering::SpatialImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = RENDERING_STREAM_SIZE(localTransform);
    size += RENDERING_STREAM_SIZE(worldTransform);
    size += CoreTools::GetStreamSize(worldTransformIsCurrent);
    size += RENDERING_STREAM_SIZE(worldBound);
    size += CoreTools::GetStreamSize(worldBoundIsCurrent);
    size += CoreTools::GetStreamSize(culling);

    // parent 不保存且不需要注册。
    return size;
}

void Rendering::SpatialImpl::SetLocalTransformTranslate(const APoint& translate) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    localTransform.SetTranslate(translate);
}

void Rendering::SpatialImpl::SetLocalTransformRotate(const Matrix& rotate) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    localTransform.SetRotate(rotate);
}

void Rendering::SpatialImpl::SetWorldTransformOnUpdate(const Mathematics::TransformF& transform) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    worldTransform = transform;
}
