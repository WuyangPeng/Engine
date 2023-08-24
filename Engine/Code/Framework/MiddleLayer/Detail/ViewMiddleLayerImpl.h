///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/08 14:36)

#ifndef FRAMEWORK_MIDDLE_LAYER_VIEW_MIDDLE_LAYER_IMPL_H
#define FRAMEWORK_MIDDLE_LAYER_VIEW_MIDDLE_LAYER_IMPL_H

#include "Framework/FrameworkDll.h"

#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/RendererEngine/BaseRenderer.h"
#include "Framework/WindowCreate/WindowCreateFwd.h"

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE ViewMiddleLayerImpl
    {
    public:
        using ClassType = ViewMiddleLayerImpl;

        using Colour = Rendering::Colour<float>;
        using Renderer = Rendering::BaseRenderer;
        using RendererSharedPtr = Rendering::BaseRendererSharedPtr;
        using ConstRendererSharedPtr = Rendering::ConstBaseRendererSharedPtr;
        using EnvironmentParameter = Rendering::EnvironmentParameter;

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
        void ResetRenderer(const std::string& fileName, const EnvironmentParameter& environmentParameter);
        void ClearColorBuffer();

        NODISCARD Colour GetClearColor() const;
        void SetClearColor(const Colour& colour);

        NODISCARD RendererSharedPtr GetRenderer();
        NODISCARD ConstRendererSharedPtr GetRenderer() const;

        void Release();
        void SwapBuffers();

    protected:
        SYSTEM_NORETURN static void ThrowException();

    private:
        RendererSharedPtr renderer;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_VIEW_MIDDLE_LAYER_IMPL_H
