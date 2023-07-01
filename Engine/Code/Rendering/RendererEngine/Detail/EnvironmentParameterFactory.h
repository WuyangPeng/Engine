///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/28 13:51)

#ifndef RENDERING_RENDERER_ENGINE_RENDERING_ENVIRONMENT_FACTORY_H
#define RENDERING_RENDERER_ENGINE_RENDERING_ENVIRONMENT_FACTORY_H

#include "Rendering/RenderingDll.h"

#include "System/Windows/Using/WindowsUsing.h"
#include "Rendering/RendererEngine/RendererEngineInternalFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE EnvironmentParameterFactory
    {
    public:
        using ClassType = EnvironmentParameterFactory;

        using EnvironmentParameterSharedPtr = std::shared_ptr<EnvironmentParameterImpl>;
        using WindowsHWnd = System::WindowsHWnd;

    private:
        EnvironmentParameterFactory() noexcept;

    public:
        CLASS_INVARIANT_DECLARE;

        NODISCARD static EnvironmentParameterSharedPtr Create();
        NODISCARD static EnvironmentParameterSharedPtr Create(WindowsHWnd windowsHWnd);
    };
}

#endif  // RENDERING_RENDERER_ENGINE_RENDERING_ENVIRONMENT_FACTORY_H
