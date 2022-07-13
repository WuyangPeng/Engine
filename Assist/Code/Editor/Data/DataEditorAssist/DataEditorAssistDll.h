///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/06 15:25)

#ifndef DATA_EDITOR_DLL_DLL_H
#define DATA_EDITOR_DLL_DLL_H

#include "Macro/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_DATA_EDITOR_NO_IMPORT) || defined(BUILDING_DATA_EDITOR_STATIC)

    #define DATA_EDITOR_DEFAULT_DECLARE
    #define DATA_EDITOR_HIDDEN_DECLARE
    #define DATA_EDITOR_VISIBLE

#else  // !defined(BUILDING_DATA_EDITOR_NO_IMPORT) && !defined(BUILDING_DATA_EDITOR_STATIC)

    #if defined(BUILDING_DATA_EDITOR_EXPORT)

        #define DATA_EDITOR_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define DATA_EDITOR_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_DATA_EDITOR_EXPORT)

        #define DATA_EDITOR_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define DATA_EDITOR_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_DATA_EDITOR_EXPORT

    #define DATA_EDITOR_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_DATA_EDITORNO_IMPORT) || defined(BUILDING_DATA_EDITOR_STATIC)

#endif  // DATA_EDITOR_DLL_DLL_H
