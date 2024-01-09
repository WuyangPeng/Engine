/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:56)

#include "Rendering/RenderingExport.h"

#include "ProjectionViewWorldUpdater.h"
#include "Detail/ProjectionViewWorldUpdaterImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, ProjectionViewWorldUpdater)

Rendering::ProjectionViewWorldUpdater::ProjectionViewWorldUpdater(const CameraSharedPtr& camera, const BaseRendererSharedPtr& baseRenderer)
    : impl{ camera, baseRenderer }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ProjectionViewWorldUpdater)

bool Rendering::ProjectionViewWorldUpdater::Subscribe(const VisualSharedPtr& visual, const ConstantBufferSharedPtr& constantBuffer, const std::string& projectionViewWorldMatrixName)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Subscribe(visual, constantBuffer, projectionViewWorldMatrixName);
}

bool Rendering::ProjectionViewWorldUpdater::Subscribe(const VisualSharedPtr& visual, const std::string& projectionViewWorldMatrixName)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Subscribe(visual, projectionViewWorldMatrixName);
}

bool Rendering::ProjectionViewWorldUpdater::Unsubscribe(const VisualSharedPtr& visual) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Unsubscribe(visual);
}

void Rendering::ProjectionViewWorldUpdater::UnsubscribeAll() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->UnsubscribeAll();
}

void Rendering::ProjectionViewWorldUpdater::Update()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Update();
}

void Rendering::ProjectionViewWorldUpdater::Update(const VisualContainer& updateSet)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Update(updateSet);
}

Rendering::CameraSharedPtr Rendering::ProjectionViewWorldUpdater::GetCamera() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetCamera();
}
