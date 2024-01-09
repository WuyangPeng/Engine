/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 15:14)

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