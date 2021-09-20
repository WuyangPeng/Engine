///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/09 14:57)

#ifndef HOW_TO_SOLVE_DLL_H
#define HOW_TO_SOLVE_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_HOW_TO_SOLVE_NO_IMPORT) || defined(BUILDING_HOW_TO_SOLVE_STATIC)

    #define HOW_TO_SOLVE_DEFAULT_DECLARE
    #define HOW_TO_SOLVE_HIDDEN_DECLARE
    #define HOW_TO_SOLVE_VISIBLE

#else  // !defined(BUILDING_HOW_TO_SOLVE_NO_IMPORT) && !defined(BUILDING_HOW_TO_SOLVE_STATIC)

    #if defined(BUILDING_HOW_TO_SOLVE_EXPORT)

        #define HOW_TO_SOLVE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define HOW_TO_SOLVE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_HOW_TO_SOLVE_EXPORT)

        #define HOW_TO_SOLVE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define HOW_TO_SOLVE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_HOW_TO_SOLVE_EXPORT

    #define HOW_TO_SOLVE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_HOW_TO_SOLVE_NO_IMPORT) || defined(BUILDING_HOW_TO_SOLVE_STATIC)

#endif  // HOW_TO_SOLVE_DLL_H
