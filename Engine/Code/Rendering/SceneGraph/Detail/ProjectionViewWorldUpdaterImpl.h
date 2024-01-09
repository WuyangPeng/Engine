/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:50)

#ifndef RENDERING_SCENE_GRAPH_PROJECTION_VIEW_WORLD_UPDATER_IMPL_H
#define RENDERING_SCENE_GRAPH_PROJECTION_VIEW_WORLD_UPDATER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/RendererEngine/BaseRenderer.h"
#include "Rendering/Resources/Buffers/ConstantBuffer.h"
#include "Rendering/SceneGraph/Camera.h"

#include <map>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ProjectionViewWorldUpdaterImpl
    {
    public:
        using ClassType = ProjectionViewWorldUpdaterImpl;

        using VisualContainer = std::vector<VisualSharedPtr>;

    public:
        ProjectionViewWorldUpdaterImpl(CameraSharedPtr camera, const BaseRendererSharedPtr& baseRenderer);

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
        using BaseRendererWeakPtr = std::weak_ptr<BaseRenderer>;
        using ProjectionViewWorldValue = std::pair<ConstantBufferSharedPtr, std::string>;
        using Subscribers = std::map<VisualSharedPtr, ProjectionViewWorldValue>;

    private:
        CameraSharedPtr camera;
        BaseRendererWeakPtr baseRenderer;
        Subscribers subscribers;
    };
}

#endif  // RENDERING_SCENE_GRAPH_PROJECTION_VIEW_WORLD_UPDATER_IMPL_H
