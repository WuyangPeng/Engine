///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.9.0.12 (2023/06/16 16:01)

#ifndef STATUS_DLL_H
#define STATUS_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_STATUS_NO_IMPORT) || defined(BUILDING_STATUS_STATIC)

    #define STATUS_DEFAULT_DECLARE
    #define STATUS_VISIBLE

    #if defined(BUILDING_STATUS_EXPORT)

        #define STATUS_HIDDEN_DECLARE

    #else  // !defined(BUILDING_STATUS_EXPORT)

        #define STATUS_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_STATUS_EXPORT

#else  // !defined(BUILDING_STATUS_NO_IMPORT) && !defined(BUILDING_STATUS_STATIC)

    #if defined(BUILDING_STATUS_EXPORT)

        #define STATUS_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define STATUS_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_STATUS_EXPORT)

        #define STATUS_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define STATUS_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_STATUS_EXPORT

    #define STATUS_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_STATUS_NO_IMPORT) || defined(BUILDING_STATUS_STATIC)

#endif  // STATUS_DLL_H
