///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.9.0.12 (2023/06/16 16:41)

#ifndef MAIL_LIB_H
#define MAIL_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_MAIL_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "MailD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "Mail.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_MAIL_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "MailStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "MailStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_MAIL_STATIC

#endif  // TCRE_USE_MSVC

#endif  // MAIL_LIB_H
