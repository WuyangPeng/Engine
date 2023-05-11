///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/27 14:07)

#ifndef MAIL_SERVER_MIDDLE_LAYER_LIB_H
#define MAIL_SERVER_MIDDLE_LAYER_LIB_H

#include "Macro/UserMacro.h"

#if defined(_MSC_VER)

    #ifndef BUILDING_MAIL_SERVER_MIDDLE_LAYER_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "MailServerMiddleLayerD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "MailServerMiddleLayer.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_MAIL_SERVER_MIDDLE_LAYER_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "MailServerMiddleLayerStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "MailServerMiddleLayerStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_MAIL_SERVER_MIDDLE_LAYER_STATIC

#endif  // _MSC_VER

#endif  // MAIL_SERVER_MIDDLE_LAYER_LIB_H