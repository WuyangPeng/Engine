/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2024/01/02 15:10)

#ifndef RENDERING_RENDERER_ENGINE_ENVIRONMENT_PARAMETER_IMPL_H
#define RENDERING_RENDERER_ENGINE_ENVIRONMENT_PARAMETER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/Windows/Using/WindowsUsing.h"
#include "Rendering/RendererEngine/RendererEngineInternalFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE EnvironmentParameterImpl
    {
    public:
        using ClassType = EnvironmentParameterImpl;
        using FactoryType = EnvironmentParameterFactory;

        using WindowsHWnd = System::WindowsHWnd;
        using EnvironmentParameterSharedPtr = std::shared_ptr<EnvironmentParameterImpl>;

    public:
        EnvironmentParameterImpl() noexcept;
        virtual ~EnvironmentParameterImpl() noexcept = default;
        EnvironmentParameterImpl(const EnvironmentParameterImpl& rhs) = default;
        EnvironmentParameterImpl& operator=(const EnvironmentParameterImpl& rhs) = default;
        EnvironmentParameterImpl(EnvironmentParameterImpl&& rhs) noexcept = default;
        EnvironmentParameterImpl& operator=(EnvironmentParameterImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual EnvironmentParameterSharedPtr Clone() const;

        NODISCARD virtual WindowsHWnd GetWindowsHWnd() const;
    };
}

#endif  // RENDERING_RENDERER_ENGINE_ENVIRONMENT_PARAMETER_IMPL_H
