///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/22 15:17)

#ifndef CORE_TOOLS_EXCEPTION_WINDOWS_ERROR_H
#define CORE_TOOLS_EXCEPTION_WINDOWS_ERROR_H

#include "CoreTools/CoreToolsDll.h"

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

        NODISCARD String GetError() const override;

    private:
        WindowError lastError;
        String windowsErrorDescribed;
    };
}

#endif  // CORE_TOOLS_EXCEPTION_WINDOWS_ERROR_H