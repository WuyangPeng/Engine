///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:13)

#include "Rendering/RenderingExport.h"

#include "SpatialData.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Rendering/DataTypes/SpecializedIO.h"

Rendering::SpatialData::SpatialData() noexcept
    : localTransform{},
      worldTransform{},
      worldTransformIsCurrent{ false },
      worldBound{},
      worldBoundIsCurrent{ false },
      culling{ CullingMode::Dynamic }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, SpatialData)

void Rendering::SpatialData::DirectSetWorldTransform(const Mathematics::TransformF& transform) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    worldTransform = transform;
    worldTransformIsCurrent = true;
}

void Rendering::SpatialData::DirectSetWorldBound(const Bound& bound) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    worldBound = bound;
    worldBoundIsCurrent = true;
}

void Rendering::SpatialData::SetLocalTransform(const Mathematics::TransformF& transform) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    localTransform = transform;
    worldTransformIsCurrent = false;
}

void Rendering::SpatialData::SetCullingMode(CullingMode aCulling) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    culling = aCulling;
}

void Rendering::SpatialData::SetLocalTransformToWorldTransform(const Mathematics::TransformF& aWorldTransform)
{
    RENDERING_CLASS_IS_VALID_9;

    worldTransform = aWorldTransform * localTransform;
    worldTransformIsCurrent = false;
}

void Rendering::SpatialData::SetLocalTransformToWorldTransform() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    worldTransform = localTransform;
    worldTransformIsCurrent = false;
}

void Rendering::SpatialData::InitWorldBound()
{
    RENDERING_CLASS_IS_VALID_9;

    worldBound = Bound{ Mathematics::APointF::GetOrigin(), 0.0f };
    worldBoundIsCurrent = false;
}

void Rendering::SpatialData::SetWorldBound(const Bound& aWorldBound)
{
    RENDERING_CLASS_IS_VALID_9;

    worldBound.GrowToContain(aWorldBound);
    worldBoundIsCurrent = false;
}

bool Rendering::SpatialData::GetWorldTransformIsCurrent() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return worldTransformIsCurrent;
}

bool Rendering::SpatialData::GetWorldBoundIsCurrent() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return worldBoundIsCurrent;
}

Mathematics::TransformF Rendering::SpatialData::GetLocalTransform() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return localTransform;
}

Mathematics::TransformF Rendering::SpatialData::GetWorldTransform() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return worldTransform;
}

Mathematics::BoundingSphereF Rendering::SpatialData::GetWorldBound() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return worldBound;
}

Rendering::CullingMode Rendering::SpatialData::GetCullingMode() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return culling;
}

void Rendering::SpatialData::Load(CoreTools::BufferSource& source)
{
    source.ReadAggregate(localTransform);
    source.ReadAggregate(worldTransform);
    worldTransformIsCurrent = source.ReadBool();
    source.ReadAggregate(worldBound);
    worldBoundIsCurrent = source.ReadBool();
    source.ReadEnum(culling);
}

void Rendering::SpatialData::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteAggregate(localTransform);
    target.WriteAggregate(worldTransform);
    target.Write(worldTransformIsCurrent);
    target.WriteAggregate(worldBound);
    target.Write(worldBoundIsCurrent);
    target.WriteEnum(culling);
}

int Rendering::SpatialData::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = RENDERING_STREAM_SIZE(localTransform);
    size += RENDERING_STREAM_SIZE(worldTransform);
    size += CoreTools::GetStreamSize(worldTransformIsCurrent);
    size += RENDERING_STREAM_SIZE(worldBound);
    size += CoreTools::GetStreamSize(worldBoundIsCurrent);
    size += CoreTools::GetStreamSize(culling);

    return size;
}

void Rendering::SpatialData::SetLocalTransformTranslate(const APoint& translate) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    localTransform.SetTranslate(translate);
}

void Rendering::SpatialData::SetLocalTransformRotate(const Matrix& rotate) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    localTransform.SetRotate(rotate);
}

void Rendering::SpatialData::SetWorldTransformOnUpdate(const Mathematics::TransformF& transform) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    worldTransform = transform;
}
