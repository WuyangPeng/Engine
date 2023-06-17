///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.9.0.12 (2023/06/16 13:14)

#ifndef THREADING_CORE_RENDER_ENGINE_GAME_DLL_H
#define THREADING_CORE_RENDER_ENGINE_GAME_DLL_H

#include "UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_THREADING_CORE_RENDER_ENGINE_GAME_NO_IMPORT) || defined(BUILDING_GAME_STATIC)

    #define THREADING_CORE_RENDER_ENGINE_GAME_DEFAULT_DECLARE
    #define THREADING_CORE_RENDER_ENGINE_GAME_VISIBLE

    #if defined(BUILDING_THREADING_CORE_RENDER_ENGINE_GAME_EXPORT)

        #define THREADING_CORE_RENDER_ENGINE_GAME_HIDDEN_DECLARE

    #else  // !defined(BUILDING_THREADING_CORE_RENDER_ENGINE_GAME_EXPORT)

        #define THREADING_CORE_RENDER_ENGINE_GAME_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_THREADING_CORE_RENDER_ENGINE_GAME_EXPORT

#else  // !defined(BUILDING_THREADING_CORE_RENDER_ENGINE_GAME_NO_IMPORT) && !defined(BUILDING_GAME_STATIC)

    #if defined(BUILDING_THREADING_CORE_RENDER_ENGINE_GAME_EXPORT)

        #define THREADING_CORE_RENDER_ENGINE_GAME_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define THREADING_CORE_RENDER_ENGINE_GAME_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_THREADING_CORE_RENDER_ENGINE_GAME_EXPORT)

        #define THREADING_CORE_RENDER_ENGINE_GAME_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define THREADING_CORE_RENDER_ENGINE_GAME_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_THREADING_CORE_RENDER_ENGINE_GAME_EXPORT

    #define THREADING_CORE_RENDER_ENGINE_GAME_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_THREADING_CORE_RENDER_ENGINE_GAME_NO_IMPORT) || defined(BUILDING_GAME_STATIC)

#endif  // THREADING_CORE_RENDER_ENGINE_GAME_DLL_H