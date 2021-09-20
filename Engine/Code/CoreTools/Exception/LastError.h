///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.2 (2021/08/30 14:42)

#ifndef CORE_TOOLS_EXCEPTION_LAST_ERROR_H
#define CORE_TOOLS_EXCEPTION_LAST_ERROR_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Windows/Fwd/WindowsFlagsFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE LastError final
    {
    public:
        using ClassType = LastError;
        using WindowError = System::WindowError;

    public:
        LastError() noexcept;
        ~LastError() noexcept;
        LastError(const LastError& rhs) noexcept = delete;
        LastError& operator=(const LastError& rhs) noexcept = delete;
        LastError(LastError&& rhs) noexcept = delete;
        LastError& operator=(LastError&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD WindowError GetLastError() const noexcept;

    private:
        WindowError lastError;
    };
}

#endif  // CORE_TOOLS_EXCEPTION_LAST_ERROR_H