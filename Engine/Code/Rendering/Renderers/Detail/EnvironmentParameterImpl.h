///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.2 (2022/09/06 23:04)

#ifndef RENDERING_RENDERERS_ENVIRONMENT_PARAMETER_IMPL_H
#define RENDERING_RENDERERS_ENVIRONMENT_PARAMETER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/Windows/Using/WindowsUsing.h"
#include "Rendering/Renderers/RenderersInternalFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE EnvironmentParameterImpl
    {
    public:
        using ClassType = EnvironmentParameterImpl;
        using FactoryType = EnvironmentParameterFactory;
        using EnvironmentParameterSharedPtr = std::shared_ptr<EnvironmentParameterImpl>;

        using WindowsHWnd = System::WindowsHWnd;

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

#endif  // RENDERING_RENDERERS_ENVIRONMENT_PARAMETER_IMPL_H
