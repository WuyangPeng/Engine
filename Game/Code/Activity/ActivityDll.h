///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 15:18)

#ifndef ACTIVITY_DLL_H
#define ACTIVITY_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_ACTIVITY_NO_IMPORT) || defined(BUILDING_ACTIVITY_STATIC)

    #define ACTIVITY_DEFAULT_DECLARE
    #define ACTIVITY_VISIBLE

    #if defined(BUILDING_ACTIVITY_EXPORT)

        #define ACTIVITY_HIDDEN_DECLARE

    #else  // !defined(BUILDING_ACTIVITY_EXPORT)

        #define ACTIVITY_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_ACTIVITY_EXPORT

#else  // !defined(BUILDING_ACTIVITY_NO_IMPORT) && !defined(BUILDING_ACTIVITY_STATIC)

    #if defined(BUILDING_ACTIVITY_EXPORT)

        #define ACTIVITY_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define ACTIVITY_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_ACTIVITY_EXPORT)

        #define ACTIVITY_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define ACTIVITY_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_ACTIVITY_EXPORT

    #define ACTIVITY_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_ACTIVITY_NO_IMPORT) || defined(BUILDING_ACTIVITY_STATIC)

#endif  // ACTIVITY_DLL_H
