///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:36)

#ifndef RENDERING_RENDERERS_ENVIRONMENT_PARAMETER_H
#define RENDERING_RENDERERS_ENVIRONMENT_PARAMETER_H

#include "Rendering/RenderingDll.h"

#include "RenderersFwd.h"
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

#endif  // RENDERING_RENDERERS_ENVIRONMENT_PARAMETER_H
