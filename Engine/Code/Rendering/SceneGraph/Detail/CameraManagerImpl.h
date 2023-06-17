///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:06)

#ifndef RENDERING_SCENE_GRAPH_CAMERA_MANAGE_IMPL_H
#define RENDERING_SCENE_GRAPH_CAMERA_MANAGE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "Rendering/SceneGraph/Flags/CameraFlags.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE CameraManagerImpl
    {
    public:
        using ClassType = CameraManagerImpl;

    public:
        CameraManagerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        // 你应该在平台相关应用程序层设置。
        // 这个保证你访问正确的投影矩阵在GetProjection()。
        void SetDefaultDepthType(RendererTypes type) noexcept;
        NODISCARD DepthType GetDepthType() const noexcept;

    private:
        // 指定类型的投影矩阵(DirectX和OpenGL不同）。
        DepthType depthType;
    };
}

#endif  // RENDERING_SCENE_GRAPH_CAMERA_MANAGE_IMPL_H
