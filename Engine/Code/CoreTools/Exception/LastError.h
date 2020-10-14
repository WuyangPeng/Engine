//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/12 14:26)

#ifndef CORE_TOOLS_EXCEPTION_LAST_ERROR_H
#define CORE_TOOLS_EXCEPTION_LAST_ERROR_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Window/Fwd/WindowFlagsFwd.h"

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
        LastError(const LastError&) = delete;
        LastError& operator=(const LastError&) = delete;
        LastError(LastError&&) noexcept = delete;
        LastError& operator=(LastError&&) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] WindowError GetLastError() const noexcept;

    private:
        WindowError m_LastError;
    };
}

#endif  // CORE_TOOLS_EXCEPTION_LAST_ERROR_H