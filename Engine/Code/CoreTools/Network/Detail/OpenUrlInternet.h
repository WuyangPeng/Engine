//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/26 14:50)

#ifndef CORE_TOOLS_OPEN_URL_INTERNET_H
#define CORE_TOOLS_OPEN_URL_INTERNET_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Network/Using/WindowsInternetUsing.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE OpenUrlInternet final
    {
    public:
        using ClassType = OpenUrlInternet;
        using String = System::String;
        using InternetHandle = System::InternetHandle;

    public:
        explicit OpenUrlInternet(InternetHandle internet, const String& url, const String& header);
        ~OpenUrlInternet() noexcept;
        OpenUrlInternet(const OpenUrlInternet&) noexcept = delete;
        OpenUrlInternet& operator=(const OpenUrlInternet&) noexcept = delete;
        OpenUrlInternet(OpenUrlInternet&&) noexcept = delete;
        OpenUrlInternet& operator=(OpenUrlInternet&&) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] InternetHandle GetInternet() const noexcept;

    private:
        // ���HTTP�汾Ϊ1.1����߰汾������֤�ɹ���
        void CheckHttpVersionsOK();

    private:
        InternetHandle m_UrlInternet;
    };
}

#endif  // CORE_TOOLS_OPEN_URL_INTERNET_H
