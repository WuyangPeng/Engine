///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/09 14:57)

#ifndef THINKING_LOW_LEVEL_WRITING_HIGH_LEVEL_DLL_H
#define THINKING_LOW_LEVEL_WRITING_HIGH_LEVEL_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_THINKING_LOW_LEVEL_WRITING_HIGH_LEVEL_NO_IMPORT) || defined(BUILDING_THINKING_LOW_LEVEL_WRITING_HIGH_LEVEL_STATIC)

    #define THINKING_LOW_LEVEL_WRITING_HIGH_LEVEL_DEFAULT_DECLARE
    #define THINKING_LOW_LEVEL_WRITING_HIGH_LEVEL_HIDDEN_DECLARE
    #define THINKING_LOW_LEVEL_WRITING_HIGH_LEVEL_VISIBLE

#else  // !defined(BUILDING_THINKING_LOW_LEVEL_WRITING_HIGH_LEVEL_NO_IMPORT) && !defined(BUILDING_THINKING_LOW_LEVEL_WRITING_HIGH_LEVEL_STATIC)

    #if defined(BUILDING_THINKING_LOW_LEVEL_WRITING_HIGH_LEVEL_EXPORT)

        #define THINKING_LOW_LEVEL_WRITING_HIGH_LEVEL_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define THINKING_LOW_LEVEL_WRITING_HIGH_LEVEL_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_THINKING_LOW_LEVEL_WRITING_HIGH_LEVEL_EXPORT)

        #define THINKING_LOW_LEVEL_WRITING_HIGH_LEVEL_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define THINKING_LOW_LEVEL_WRITING_HIGH_LEVEL_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_THINKING_LOW_LEVEL_WRITING_HIGH_LEVEL_EXPORT

    #define THINKING_LOW_LEVEL_WRITING_HIGH_LEVEL_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_THINKING_LOW_LEVEL_WRITING_HIGH_LEVEL_NO_IMPORT) || defined(BUILDING_THINKING_LOW_LEVEL_WRITING_HIGH_LEVEL_STATIC)

#endif  // THINKING_LOW_LEVEL_WRITING_HIGH_LEVEL_DLL_H