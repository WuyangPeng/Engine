///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:01)

#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_REGISTER_PARAMETER_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_REGISTER_PARAMETER_H

#include "Framework/FrameworkDll.h"

#include "System/Windows/Flags/WindowsClassStyleFlags.h"
#include "System/Windows/Flags/WindowsFlags.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE WindowRegisterParameter
    {
    public:
        using ClassType = WindowRegisterParameter;
        using HInstance = System::WindowsHInstance;
        using WindowClassStyle = System::WindowsClassStyle;

    public:
        explicit WindowRegisterParameter(HInstance instance,
                                         WindowClassStyle styles = WindowClassStyle::CommonUse,
                                         int windowClassExtra = 0,
                                         int windowExtra = 0);

        CLASS_INVARIANT_DECLARE;

        NODISCARD HInstance GetHInstance() const noexcept;
        NODISCARD WindowClassStyle GetStyle() const noexcept;
        NODISCARD int GetWindowClassExtra() const noexcept;
        NODISCARD int GetWindowExtra() const noexcept;

    private:
        HInstance instance;
        WindowClassStyle style;
        int windowClassExtra;
        int windowExtra;
    };
}

#endif  // FRAMEWORK_WINDOW_REGISTER_WINDOW_REGISTER_PARAMETER_H