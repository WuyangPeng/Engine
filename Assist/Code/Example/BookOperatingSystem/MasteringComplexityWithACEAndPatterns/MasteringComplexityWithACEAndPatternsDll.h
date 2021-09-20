///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.4 (2021/06/06 21:47)

#ifndef MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_DLL_H
#define MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_NO_IMPORT) || defined(BUILDING_MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_STATIC)

    #define MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_DEFAULT_DECLARE
    #define MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_VISIBLE

    #if defined(BUILDING_MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_EXPORT)

        #define MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_HIDDEN_DECLARE

    #else  // !defined(BUILDING_MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_EXPORT)

        #define MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_EXPORT

#else  // !defined(BUILDING_MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_NO_IMPORT) && !defined(BUILDING_MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_STATIC)

    #if defined(BUILDING_MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_EXPORT)

        #define MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_EXPORT)

        #define MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_EXPORT

    #define MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_NO_IMPORT) || defined(BUILDING_MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_STATIC)

#endif  // MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_DLL_H
