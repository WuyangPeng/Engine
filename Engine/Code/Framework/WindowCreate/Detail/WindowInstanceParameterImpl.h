///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 14:11)

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
        WindowInstanceParameterImpl(WindowsHInstance instance, const String& className);

        CLASS_INVARIANT_DECLARE;

        NODISCARD WindowsHInstance GetHInstance() const noexcept;
        NODISCARD String GetWindowClassName() const;

    private:
        WindowsHInstance hInstance;
        String className;
    };
}

#endif  // FRAMEWORK_WINDOW_CREATE_WINDOW_INSTANCE_PARAMETER_IMPL_H