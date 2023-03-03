///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.3 (2023/03/01 13:32)

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