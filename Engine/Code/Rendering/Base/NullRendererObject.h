/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/08 17:41)

#ifndef RENDERING_BASE_NULL_RENDERER_OBJECT_H
#define RENDERING_BASE_NULL_RENDERER_OBJECT_H

#include "Rendering/RenderingDll.h"

#include "RendererObject.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE NullRendererObject final : public RendererObject
    {
    public:
        using ClassType = NullRendererObject;
        using ParentType = RendererObject;

    public:
        explicit NullRendererObject(const GraphicsObjectSharedPtr& graphicsObject, const std::string& name = "");

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Enable() noexcept override;
        void Disable() noexcept override;

        NODISCARD bool Update() noexcept override;
        NODISCARD bool Update(int level) noexcept override;
        NODISCARD bool Update(int item, int level) noexcept override;

        NODISCARD bool CopyGpuToCpu() noexcept override;
        NODISCARD bool CopyGpuToCpu(int level) noexcept override;
        NODISCARD bool CopyGpuToCpu(int item, int level) noexcept override;

        NODISCARD bool CopyCpuToGpu() noexcept override;
        NODISCARD bool CopyCpuToGpu(int level) noexcept override;
        NODISCARD bool CopyCpuToGpu(int item, int level) noexcept override;

        NODISCARD bool GetNumActiveElements() noexcept override;
    };
}

#endif  // RENDERING_BASE_NULL_RENDERER_OBJECT_H
