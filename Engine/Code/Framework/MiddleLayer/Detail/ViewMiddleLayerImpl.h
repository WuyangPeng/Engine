///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/06 16:06)

#ifndef FRAMEWORK_MIDDLE_LAYER_VIEW_MIDDLE_LAYER_IMPL_H
#define FRAMEWORK_MIDDLE_LAYER_VIEW_MIDDLE_LAYER_IMPL_H

#include "Framework/FrameworkDll.h"

#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/Renderers/Renderer.h"
#include "Framework/WindowCreate/WindowCreateFwd.h"

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE ViewMiddleLayerImpl
    {
    public:
        using ClassType = ViewMiddleLayerImpl;
        using Renderer = Rendering::Renderer;
        using Colour = Rendering::Colour<float>;
        using RendererSharedPtr = Rendering::RendererSharedPtr;
        using ConstRendererSharedPtr = Rendering::ConstRendererSharedPtr;

    public:
        ViewMiddleLayerImpl() noexcept;
        ~ViewMiddleLayerImpl() noexcept = default;
        ViewMiddleLayerImpl(const ViewMiddleLayerImpl& rhs) noexcept = delete;
        ViewMiddleLayerImpl& operator=(const ViewMiddleLayerImpl& rhs) noexcept = delete;
        ViewMiddleLayerImpl(ViewMiddleLayerImpl&& rhs) noexcept;
        ViewMiddleLayerImpl& operator=(ViewMiddleLayerImpl&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        void Resize(int width, int height);
        void DrawFrameRate(int x, int y, const Colour& color, const std::string& message);
        void ResetRenderer(const std::string& fileName);
        void ClearColorBuffer();

        NODISCARD Colour GetClearColor() const;
        void SetClearColor(const Colour& colour);

        NODISCARD RendererSharedPtr GetRenderer() noexcept;
        NODISCARD ConstRendererSharedPtr GetRenderer() const noexcept;

    private:
        RendererSharedPtr renderer;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_VIEW_MIDDLE_LAYER_IMPL_H
