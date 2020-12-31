//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/26 14:45)

#ifndef CORE_TOOLS_INTERNET_CONNECTION_H
#define CORE_TOOLS_INTERNET_CONNECTION_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Network/Using/WindowsInternetUsing.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE InternetConnection final
    {
    public:
        using ClassType = InternetConnection;
        using String = System::String;
        using InternetHandle = System::InternetHandle;

    public:
        explicit InternetConnection(const System::String& agent);
        ~InternetConnection() noexcept;
        InternetConnection(const InternetConnection&) noexcept = delete;
        InternetConnection& operator=(const InternetConnection&) noexcept = delete;
        InternetConnection(InternetConnection&&) noexcept = delete;
        InternetConnection& operator=(InternetConnection&&) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] InternetHandle GetInternet() const noexcept;

    private:
        InternetHandle m_Internet;
    };
}

#endif  // CORE_TOOLS_INTERNET_CONNECTION_H
