///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/17 15:57)

#include "Rendering/RenderingExport.h"

#include "PlanarReflectionEffect.h"
#include "Detail/PlanarReflectionEffectImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, PlanarReflectionEffect)

Rendering::PlanarReflectionEffect::PlanarReflectionEffect(const NodeSharedPtr& reflectionCaster,
                                                          const VisualContainer& planeVisuals,
                                                          const ReflectanceType& reflectances)
    : impl{ reflectionCaster, planeVisuals, reflectances }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlanarReflectionEffect)

void Rendering::PlanarReflectionEffect::Draw(const BaseRendererSharedPtr& engine, ProjectionViewWorldUpdater& projectionViewWorldMatrices)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Draw(engine, projectionViewWorldMatrices);
}

Rendering::PlanarReflectionEffect::VisualContainer Rendering::PlanarReflectionEffect::GetPlaneVisuals() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetPlaneVisuals();
}

Rendering::PlanarReflectionEffect::Vector4Container Rendering::PlanarReflectionEffect::GetPlaneOrigins() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetPlaneOrigins();
}

Rendering::PlanarReflectionEffect::Vector4Container Rendering::PlanarReflectionEffect::GetPlaneNormals() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetPlaneNormals();
}

void Rendering::PlanarReflectionEffect::SetReflectance(int index, float reflectance)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetReflectance(index, reflectance);
}

float Rendering::PlanarReflectionEffect::GetReflectance(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetReflectance(index);
}
