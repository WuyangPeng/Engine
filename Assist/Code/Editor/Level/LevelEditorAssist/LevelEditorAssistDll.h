///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/07 16:20)

#ifndef LEVEL_EDITOR_DLL_DLL_H
#define LEVEL_EDITOR_DLL_DLL_H

#include "Macro/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_LEVEL_EDITOR_NO_IMPORT) || defined(BUILDING_LEVEL_EDITOR_STATIC)

    #define LEVEL_EDITOR_DEFAULT_DECLARE
    #define LEVEL_EDITOR_HIDDEN_DECLARE
    #define LEVEL_EDITOR_VISIBLE

#else  // !defined(BUILDING_LEVEL_EDITOR_NO_IMPORT) && !defined(BUILDING_LEVEL_EDITOR_STATIC)

    #if defined(BUILDING_LEVEL_EDITOR_EXPORT)

        #define LEVEL_EDITOR_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define LEVEL_EDITOR_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_LEVEL_EDITOR_EXPORT)

        #define LEVEL_EDITOR_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define LEVEL_EDITOR_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_LEVEL_EDITOR_EXPORT

    #define LEVEL_EDITOR_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_LEVEL_EDITORNO_IMPORT) || defined(BUILDING_LEVEL_EDITOR_STATIC)

#endif  // LEVEL_EDITOR_DLL_DLL_H
