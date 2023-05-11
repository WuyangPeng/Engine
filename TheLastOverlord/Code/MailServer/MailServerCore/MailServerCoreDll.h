///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/27 13:22)

#ifndef MAIL_SERVER_CORE_DLL_H
#define MAIL_SERVER_CORE_DLL_H

#include "Macro/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_MAIL_SERVER_CORE_NO_IMPORT) || defined(BUILDING_MAIL_SERVER_CORE_STATIC)

    #define MAIL_SERVER_CORE_DEFAULT_DECLARE
    #define MAIL_SERVER_CORE_HIDDEN_DECLARE
    #define MAIL_SERVER_CORE_VISIBLE

#else  // !defined(BUILDING_MAIL_SERVER_CORE_NO_IMPORT) && !defined(BUILDING_MAIL_SERVER_CORE_STATIC)

    #if defined(BUILDING_MAIL_SERVER_CORE_EXPORT)

        #define MAIL_SERVER_CORE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define MAIL_SERVER_CORE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_MAIL_SERVER_CORE_EXPORT)

        #define MAIL_SERVER_CORE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define MAIL_SERVER_CORE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_MAIL_SERVER_CORE_EXPORT

    #define MAIL_SERVER_CORE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_MAIL_SERVER_CORE_NO_IMPORT) || defined(BUILDING_MAIL_SERVER_CORE_STATIC)

#endif  // MAIL_SERVER_CORE_DLL_H