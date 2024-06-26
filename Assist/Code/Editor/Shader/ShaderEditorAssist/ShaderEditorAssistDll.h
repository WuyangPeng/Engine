///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 14:42)

#ifndef SHADER_EDITOR_DLL_DLL_H
#define SHADER_EDITOR_DLL_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_SHADER_EDITOR_NO_IMPORT) || defined(BUILDING_SHADER_EDITOR_STATIC)

    #define SHADER_EDITOR_DEFAULT_DECLARE
    #define SHADER_EDITOR_VISIBLE

    #if defined(BUILDING_SHADER_EDITOR_EXPORT)

        #define SHADER_EDITOR_HIDDEN_DECLARE

    #else  // !defined(BUILDING_SHADER_EDITOR_EXPORT)

        #define SHADER_EDITOR_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_SHADER_EDITOR_EXPORT

#else  // !defined(BUILDING_SHADER_EDITOR_NO_IMPORT) && !defined(BUILDING_SHADER_EDITOR_STATIC)

    #if defined(BUILDING_SHADER_EDITOR_EXPORT)

        #define SHADER_EDITOR_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define SHADER_EDITOR_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_SHADER_EDITOR_EXPORT)

        #define SHADER_EDITOR_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define SHADER_EDITOR_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_SHADER_EDITOR_EXPORT

    #define SHADER_EDITOR_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_SHADER_EDITORNO_IMPORT) || defined(BUILDING_SHADER_EDITOR_STATIC)

#endif  // SHADER_EDITOR_DLL_DLL_H
