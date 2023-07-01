///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/28 13:51)

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
