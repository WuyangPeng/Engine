///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/17 15:59)

#include "Rendering/RenderingExport.h"

#include "PlanarShadowEffect.h"
#include "Detail/PlanarShadowEffectImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, PlanarShadowEffect)

Rendering::PlanarShadowEffect::PlanarShadowEffect(const BaseRendererSharedPtr& engine,
                                                  const ProgramFactorySharedPtr& factory,
                                                  const NodeSharedPtr& shadowCaster,
                                                  const LightProjectorSharedPtr& lightProjector,
                                                  const VisualContainer& planeVisuals,
                                                  const Vector4Container& shadowColors)
    : impl{ engine, factory, shadowCaster, lightProjector, planeVisuals, shadowColors }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlanarShadowEffect)

void Rendering::PlanarShadowEffect::Draw(const BaseRendererSharedPtr& engine, ProjectionViewWorldUpdater& projectionViewWorldMatrices)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Draw(engine, projectionViewWorldMatrices);
}
