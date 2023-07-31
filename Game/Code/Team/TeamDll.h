///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 16:50)

#ifndef TEAM_DLL_H
#define TEAM_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_TEAM_NO_IMPORT) || defined(BUILDING_TEAM_STATIC)

    #define TEAM_DEFAULT_DECLARE
    #define TEAM_VISIBLE

    #if defined(BUILDING_TEAM_EXPORT)

        #define TEAM_HIDDEN_DECLARE

    #else  // !defined(BUILDING_TEAM_EXPORT)

        #define TEAM_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_TEAM_EXPORT

#else  // !defined(BUILDING_TEAM_NO_IMPORT) && !defined(BUILDING_TEAM_STATIC)

    #if defined(BUILDING_TEAM_EXPORT)

        #define TEAM_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define TEAM_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_TEAM_EXPORT)

        #define TEAM_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define TEAM_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_TEAM_EXPORT

    #define TEAM_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_TEAM_NO_IMPORT) || defined(BUILDING_TEAM_STATIC)

#endif  // TEAM_DLL_H
