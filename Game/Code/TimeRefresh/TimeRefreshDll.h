///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.8.0.11 (2022/07/15 14:41)

#ifndef ACTIVITY_DLL_H
#define ACTIVITY_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_ACTIVITY_NO_IMPORT) || defined(BUILDING_ACTIVITY_STATIC)

    #define ACTIVITY_DEFAULT_DECLARE
    #define ACTIVITY_HIDDEN_DECLARE
    #define ACTIVITY_VISIBLE

#else  // !defined(BUILDING_ACTIVITY_NO_IMPORT) && !defined(BUILDING_ACTIVITY_STATIC)

    #if defined(BUILDING_ACTIVITY_EXPORT)

        #define ACTIVITY_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define ACTIVITY_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_ACTIVITY_EXPORT)

        #define ACTIVITY_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define ACTIVITY_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_ACTIVITY_EXPORT

    #define ACTIVITY_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_ACTIVITY_NO_IMPORT) || defined(BUILDING_ACTIVITY_STATIC)

#endif  // ACTIVITY_DLL_H
