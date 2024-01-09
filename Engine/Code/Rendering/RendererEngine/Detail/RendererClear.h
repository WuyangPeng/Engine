/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/02 15:11)

#ifndef RENDERING_RENDERER_ENGINE_RENDERER_CLEAR_H
#define RENDERING_RENDERER_ENGINE_RENDERER_CLEAR_H

#include "Rendering/RenderingDll.h"

#include "Rendering/DataTypes/Colour.h"

// 清除帧缓冲区。
namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE RendererClear
    {
    public:
        using ClassType = RendererClear;

        using Colour = Colour<float>;

    public:
        RendererClear() noexcept;

        CLASS_INVARIANT_DECLARE;

        void SetClearColor(const Colour& aClearColor) noexcept;
        NODISCARD Colour GetClearColor() const noexcept;
        void SetClearDepth(float aClearDepth) noexcept;
        NODISCARD float GetClearDepth() const noexcept;
        void SetClearStencil(int aClearStencil) noexcept;
        NODISCARD int GetClearStencil() const noexcept;

    private:
        Colour clearColor;
        float clearDepth;
        int clearStencil;
    };
}

#endif  // RENDERING_RENDERER_ENGINE_RENDERER_CLEAR_H