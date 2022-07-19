///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/14 14:08)

#ifndef USER_INFO_DLL_H
#define USER_INFO_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_USER_INFO_NO_IMPORT) || defined(BUILDING_USER_INFO_STATIC)

    #define USER_INFO_DEFAULT_DECLARE
    #define USER_INFO_HIDDEN_DECLARE
    #define USER_INFO_VISIBLE

#else  // !defined(BUILDING_USER_INFO_NO_IMPORT) && !defined(BUILDING_USER_INFO_STATIC)

    #if defined(BUILDING_USER_INFO_EXPORT)

        #define USER_INFO_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define USER_INFO_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_USER_INFO_EXPORT)

        #define USER_INFO_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define USER_INFO_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_USER_INFO_EXPORT

    #define USER_INFO_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_USER_INFO_NO_IMPORT) || defined(BUILDING_USER_INFO_STATIC)

#endif  // USER_INFO_DLL_H
