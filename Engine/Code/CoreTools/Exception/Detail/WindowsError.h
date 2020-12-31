//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 14:21)

#ifndef CORE_TOOLS_EXCEPTION_WINDOWS_ERROR_H
#define CORE_TOOLS_EXCEPTION_WINDOWS_ERROR_H

#include "ErrorImpl.h"
#include "System/Window/Fwd/WindowFlagsFwd.h"

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

        [[nodiscard]] const String GetError() const final;

    private:
        WindowError m_LastError;
        String m_WindowsErrorDescribed;
    };
}

#endif  // CORE_TOOLS_EXCEPTION_WINDOWS_ERROR_H