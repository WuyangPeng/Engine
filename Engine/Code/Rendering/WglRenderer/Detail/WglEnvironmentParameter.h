///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:20)

#ifndef RENDERING_WGL_RENDERER_WGL_ENVIRONMENT_PARAMETER_H
#define RENDERING_WGL_RENDERER_WGL_ENVIRONMENT_PARAMETER_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/Detail/EnvironmentParameterImpl.h"
#include "Rendering/Renderers/RenderersFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE WglEnvironmentParameter : public EnvironmentParameterImpl
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
