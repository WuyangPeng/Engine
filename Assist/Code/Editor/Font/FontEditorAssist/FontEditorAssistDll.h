///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/07 11:18)

#ifndef FONT_EDITOR_DLL_DLL_H
#define FONT_EDITOR_DLL_DLL_H

#include "Macro/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_FONT_EDITOR_NO_IMPORT) || defined(BUILDING_FONT_EDITOR_STATIC)

    #define FONT_EDITOR_DEFAULT_DECLARE
    #define FONT_EDITOR_HIDDEN_DECLARE
    #define FONT_EDITOR_VISIBLE

#else  // !defined(BUILDING_FONT_EDITOR_NO_IMPORT) && !defined(BUILDING_FONT_EDITOR_STATIC)

    #if defined(BUILDING_FONT_EDITOR_EXPORT)

        #define FONT_EDITOR_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define FONT_EDITOR_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_FONT_EDITOR_EXPORT)

        #define FONT_EDITOR_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define FONT_EDITOR_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_FONT_EDITOR_EXPORT

    #define FONT_EDITOR_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_FONT_EDITORNO_IMPORT) || defined(BUILDING_FONT_EDITOR_STATIC)

#endif  // FONT_EDITOR_DLL_DLL_H
