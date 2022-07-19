///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.8.0.11 (2022/07/18 11:41)

#ifndef SKILL_DLL_H
#define SKILL_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_SKILL_NO_IMPORT) || defined(BUILDING_SKILL_STATIC)

    #define SKILL_DEFAULT_DECLARE
    #define SKILL_HIDDEN_DECLARE
    #define SKILL_VISIBLE

#else  // !defined(BUILDING_SKILL_NO_IMPORT) && !defined(BUILDING_SKILL_STATIC)

    #if defined(BUILDING_SKILL_EXPORT)

        #define SKILL_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define SKILL_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_SKILL_EXPORT)

        #define SKILL_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define SKILL_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_SKILL_EXPORT

    #define SKILL_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_SKILL_NO_IMPORT) || defined(BUILDING_SKILL_STATIC)

#endif  // SKILL_DLL_H
