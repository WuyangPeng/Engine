///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 16:06)

#include "Mail/MailExport.h"

#include "Mail/Mail.h"

#ifndef BUILDING_MAIL_STATIC

    #include "DllLib.h"

#else  // !BUILDING_MAIL_STATIC

namespace Mail
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_MAIL_STATIC
