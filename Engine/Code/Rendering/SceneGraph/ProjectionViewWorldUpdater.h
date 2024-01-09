/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:55)

#ifndef RENDERING_SCENE_GRAPH_PROJECTION_VIEW_WORLD_UPDATER_H
#define RENDERING_SCENE_GRAPH_PROJECTION_VIEW_WORLD_UPDATER_H

#include "Rendering/RenderingDll.h"

#include "Camera.h"
#include "Visual.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Rendering/RendererEngine/BaseRenderer.h"
#include "Rendering/Resources/Buffers/ConstantBuffer.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(ProjectionViewWorldUpdater, ProjectionViewWorldUpdaterImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ProjectionViewWorldUpdater
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ProjectionViewWorldUpdater);

        using VisualContainer = std::vector<VisualSharedPtr>;

    public:
        ProjectionViewWorldUpdater(const CameraSharedPtr& camera, const BaseRendererSharedPtr& baseRenderer);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool Subscribe(const VisualSharedPtr& visual,
                                 const ConstantBufferSharedPtr& constantBuffer,
                                 const std::string& projectionViewWorldMatrixName = "projectionViewWorldMatrix");

        NODISCARD bool Subscribe(const VisualSharedPtr& visual,
                                 const std::string& projectionViewWorldMatrixName = "projectionViewWorldMatrix");

        NODISCARD bool Unsubscribe(const VisualSharedPtr& visual) noexcept;
        void UnsubscribeAll() noexcept;

        void Update();
        void Update(const VisualContainer& updateSet);

        NODISCARD CameraSharedPtr GetCamera() noexcept;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SCENE_GRAPH_PROJECTION_VIEW_WORLD_UPDATER_H
