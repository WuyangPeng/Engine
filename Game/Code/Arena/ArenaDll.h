///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 15:22)

#ifndef ARENA_DLL_H
#define ARENA_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_ARENA_NO_IMPORT) || defined(BUILDING_ARENA_STATIC)

    #define ARENA_DEFAULT_DECLARE
    #define ARENA_VISIBLE

    #if defined(BUILDING_ARENA_EXPORT)

        #define ARENA_HIDDEN_DECLARE

    #else  // !defined(BUILDING_ARENA_EXPORT)

        #define ARENA_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_ARENA_EXPORT

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
