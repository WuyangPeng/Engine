/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:46)

#ifndef FRAMEWORK_WINDOW_CREATE_WINDOW_INSTANCE_PARAMETER_IMPL_H
#define FRAMEWORK_WINDOW_CREATE_WINDOW_INSTANCE_PARAMETER_IMPL_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

#include <string>

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE WindowInstanceParameterImpl
    {
    public:
        using ClassType = WindowInstanceParameterImpl;

        using String = System::String;
        using WindowsHInstance = System::WindowsHInstance;

    public:
        WindowInstanceParameterImpl(WindowsHInstance instance, String className);

        CLASS_INVARIANT_DECLARE;

        NODISCARD WindowsHInstance GetHInstance() const noexcept;
        NODISCARD String GetWindowClassName() const;

    private:
        WindowsHInstance hInstance;
        String className;
    };
}

#endif  // FRAMEWORK_WINDOW_CREATE_WINDOW_INSTANCE_PARAMETER_IMPL_H