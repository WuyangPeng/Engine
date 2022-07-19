///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.8.0.11 (2022/07/18 16:04)

#ifndef QUEST_DLL_H
#define QUEST_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_QUEST_NO_IMPORT) || defined(BUILDING_QUEST_STATIC)

    #define QUEST_DEFAULT_DECLARE
    #define QUEST_HIDDEN_DECLARE
    #define QUEST_VISIBLE

#else  // !defined(BUILDING_QUEST_NO_IMPORT) && !defined(BUILDING_QUEST_STATIC)

    #if defined(BUILDING_QUEST_EXPORT)

        #define QUEST_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define QUEST_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_QUEST_EXPORT)

        #define QUEST_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define QUEST_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_QUEST_EXPORT

    #define QUEST_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_QUEST_NO_IMPORT) || defined(BUILDING_QUEST_STATIC)

#endif  // QUEST_DLL_H
