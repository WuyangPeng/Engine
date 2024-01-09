/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/02 15:16)

#ifndef RENDERING_RENDERER_ENGINE_ENVIRONMENT_PARAMETER_H
#define RENDERING_RENDERER_ENGINE_ENVIRONMENT_PARAMETER_H

#include "Rendering/RenderingDll.h"

#include "RendererEngineFwd.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"

RENDERING_PERFORMANCE_UNSHARED_EXPORT_IMPL(EnvironmentParameterImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE EnvironmentParameter
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(EnvironmentParameter);

        using WindowsHWnd = System::WindowsHWnd;
        using DisableNotThrow = CoreTools::DisableNotThrow;

    public:
        NODISCARD static EnvironmentParameter Create();
        NODISCARD static EnvironmentParameter Create(WindowsHWnd windowsHWnd);

        CLASS_INVARIANT_DECLARE;

        NODISCARD WindowsHWnd GetWindowsHWnd() const;

    private:
        explicit EnvironmentParameter(WindowsHWnd windowsHWnd);
        explicit EnvironmentParameter(DisableNotThrow disableNotThrow);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RENDERER_ENGINE_ENVIRONMENT_PARAMETER_H
