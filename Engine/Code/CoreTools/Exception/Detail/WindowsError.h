///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.2 (2021/08/30 15:14)

#ifndef CORE_TOOLS_EXCEPTION_WINDOWS_ERROR_H
#define CORE_TOOLS_EXCEPTION_WINDOWS_ERROR_H

#include "ErrorImpl.h"
#include "System/Windows/Fwd/WindowsFlagsFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE WindowsError final : public ErrorImpl
    {
    public:
        using ClassType = WindowsError;
        using ParentType = ErrorImpl;
        using WindowError = System::WindowError;

    public:
        WindowsError(const FunctionDescribed& functionDescribed, WindowError lastError, const String& message);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD const String GetError() const final;

    private:
        WindowError lastError;
        String windowsErrorDescribed;
    };
}

#endif  // CORE_TOOLS_EXCEPTION_WINDOWS_ERROR_H