//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/20 13:59)

#ifndef SYSTEM_DLL_H
#define SYSTEM_DLL_H

#include "Helper/ExportMacro.h"

#if defined(BUILDING_SYSTEM_NO_IMPORT) || defined(BUILDING_SYSTEM_STATIC)

    #define SYSTEM_DEFAULT_DECLARE
    #define SYSTEM_VISIBLE

    #if defined(BUILDING_SYSTEM_EXPORT)

        #define SYSTEM_HIDDEN_DECLARE

    #else  // !defined(BUILDING_SYSTEM_EXPORT)

        #define SYSTEM_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_SYSTEM_EXPORT

#else  // !defined(BUILDING_SYSTEM_NO_IMPORT) && !defined(BUILDING_SYSTEM_STATIC)

    #if defined(BUILDING_SYSTEM_EXPORT)

        #define SYSTEM_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define SYSTEM_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_SYSTEM_EXPORT)

        #define SYSTEM_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define SYSTEM_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_SYSTEM_EXPORT

    #define SYSTEM_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_SYSTEM_NO_IMPORT) || defined(BUILDING_SYSTEM_STATIC)

#endif  // SYSTEM_DLL_H