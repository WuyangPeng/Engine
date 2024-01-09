/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/22 10:18)

#ifndef RENDERING_WGL_RENDERER_WGL_ENVIRONMENT_H
#define RENDERING_WGL_RENDERER_WGL_ENVIRONMENT_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/WglExtensionsUsing.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "Rendering/OpenGLRenderer/Detail/OpenGLEnvironment.h"
#include "Rendering/RendererEngine/EnvironmentParameter.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE WglEnvironment final : public OpenGLEnvironment
    {
    public:
        using ClassType = WglEnvironment;
        using ParentType = OpenGLEnvironment;

        using WindowsHdc = System::WindowsHdc;
        using OpenGLRcHandle = System::OpenGLRcHandle;
        using WindowsHWnd = System::WindowsHWnd;
        using PixelFormatDescriptor = System::PixelFormatDescriptor;

    public:
        explicit WglEnvironment(const EnvironmentParameter& environmentParameter, const RendererParameter& rendererParameter);
        ~WglEnvironment() noexcept;
        WglEnvironment(const WglEnvironment& rhs) = default;
        WglEnvironment& operator=(const WglEnvironment& rhs) = default;
        WglEnvironment(WglEnvironment&& rhs) noexcept = default;
        WglEnvironment& operator=(WglEnvironment&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD RenderingEnvironmentSharedPtr Clone() const override;

        void InitEnvironment() override;

        void Release() noexcept override;

        NODISCARD RenderingDevice GetRenderingDevice() const override;

    private:
        void CreateDevice();
        NODISCARD PixelFormatDescriptor GetPixelFormatDescriptor() const noexcept;
        void SetWindowPixelFormat(const PixelFormatDescriptor& pixelFormatDescriptor);
        void CreateContext();

    private:
        EnvironmentParameter environmentParameter;
        WindowsHWnd handle;
        WindowsHdc device;
        OpenGLRcHandle immediate;
    };
}

#endif  // RENDERING_WGL_RENDERER_WGL_ENVIRONMENT_H
