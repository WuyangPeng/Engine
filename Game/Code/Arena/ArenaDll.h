///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.8.0.11 (2022/07/19 11:21)

#ifndef ARENA_DLL_H
#define ARENA_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_ARENA_NO_IMPORT) || defined(BUILDING_ARENA_STATIC)

    #define ARENA_DEFAULT_DECLARE
    #define ARENA_HIDDEN_DECLARE
    #define ARENA_VISIBLE

#else  // !defined(BUILDING_ARENA_NO_IMPORT) && !defined(BUILDING_ARENA_STATIC)

    #if defined(BUILDING_ARENA_EXPORT)

        #define ARENA_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define ARENA_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_ARENA_EXPORT)

        #define ARENA_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define ARENA_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_ARENA_EXPORT

    #define ARENA_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_ARENA_NO_IMPORT) || defined(BUILDING_ARENA_STATIC)

#endif  // ARENA_DLL_H
