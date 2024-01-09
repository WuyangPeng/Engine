/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 20:12)

#ifndef SCRIPT_DLL_H
#define SCRIPT_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_SCRIPT_NO_IMPORT) || defined(BUILDING_SCRIPT_STATIC)

    #define SCRIPT_DEFAULT_DECLARE
    #define SCRIPT_VISIBLE

    #if defined(BUILDING_SCRIPT_EXPORT)

        #define SCRIPT_HIDDEN_DECLARE

    #else  // !defined(BUILDING_SCRIPT_EXPORT)

        #define SCRIPT_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_SCRIPT_EXPORT

#else  // !defined(BUILDING_SCRIPT_NO_IMPORT) && !defined(BUILDING_SCRIPT_STATIC)

    #if defined(BUILDING_SCRIPT_EXPORT)

        #define SCRIPT_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define SCRIPT_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_SCRIPT_EXPORT)

        #define SCRIPT_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define SCRIPT_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_SCRIPT_EXPORT

    #define SCRIPT_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_SCRIPT_NO_IMPORT) || defined(BUILDING_SCRIPT_STATIC)

#endif  // SCRIPT_DLL_H