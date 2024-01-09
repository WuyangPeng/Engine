/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/22 10:21)

#ifndef RENDERING_WGL_RENDERER_WGL_ENVIRONMENT_PARAMETER_H
#define RENDERING_WGL_RENDERER_WGL_ENVIRONMENT_PARAMETER_H

#include "Rendering/RenderingDll.h"

#include "Rendering/RendererEngine/Detail/EnvironmentParameterImpl.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE WglEnvironmentParameter final : public EnvironmentParameterImpl
    {
    public:
        using ClassType = WglEnvironmentParameter;
        using ParentType = EnvironmentParameterImpl;

    public:
        explicit WglEnvironmentParameter(WindowsHWnd windowsHWnd) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD EnvironmentParameterSharedPtr Clone() const override;

        NODISCARD WindowsHWnd GetWindowsHWnd() const noexcept override;

    private:
        WindowsHWnd windowsHWnd;
    };
}

#endif  // RENDERING_WGL_RENDERER_WGL_ENVIRONMENT_PARAMETER_H
