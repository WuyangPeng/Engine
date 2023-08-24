/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：0.9.1.3 (2023/08/21 10:42)

#ifndef LEADERBOARD_SERVER_MIDDLE_LAYER_DLL_H
#define LEADERBOARD_SERVER_MIDDLE_LAYER_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_NO_IMPORT) || defined(BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_STATIC)

    #define LEADERBOARD_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE
    #define LEADERBOARD_SERVER_MIDDLE_LAYER_VISIBLE

    #if defined(BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_EXPORT)

        #define LEADERBOARD_SERVER_MIDDLE_LAYER_HIDDEN_DECLARE

    #else  // !defined(BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_EXPORT)

        #define LEADERBOARD_SERVER_MIDDLE_LAYER_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_EXPORT

#else  // !defined(BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_NO_IMPORT) && !defined(BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_STATIC)

    #if defined(BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_EXPORT)

        #define LEADERBOARD_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define LEADERBOARD_SERVER_MIDDLE_LAYER_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_EXPORT)

        #define LEADERBOARD_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define LEADERBOARD_SERVER_MIDDLE_LAYER_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_EXPORT

    #define LEADERBOARD_SERVER_MIDDLE_LAYER_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_NO_IMPORT) || defined(BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_STATIC)

#endif  // LEADERBOARD_SERVER_MIDDLE_LAYER_DLL_H