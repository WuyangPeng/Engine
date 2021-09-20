///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.0 (2021/07/18 18:43)

#ifndef NETWORKED_GRAPHICS_BUILDING_NETWORKED_GAMES_AND_VIRTUAL_ENVIRONMENTS_DLL_H
#define NETWORKED_GRAPHICS_BUILDING_NETWORKED_GAMES_AND_VIRTUAL_ENVIRONMENTS_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_NETWORKED_GRAPHICS_BUILDING_NETWORKED_GAMES_AND_VIRTUAL_ENVIRONMENTS_NO_IMPORT) || defined(BUILDING_NETWORKED_GRAPHICS_BUILDING_NETWORKED_GAMES_AND_VIRTUAL_ENVIRONMENTS_STATIC)

    #define NETWORKED_GRAPHICS_BUILDING_NETWORKED_GAMES_AND_VIRTUAL_ENVIRONMENTS_DEFAULT_DECLARE
    #define NETWORKED_GRAPHICS_BUILDING_NETWORKED_GAMES_AND_VIRTUAL_ENVIRONMENTS_VISIBLE

    #if defined(BUILDING_NETWORKED_GRAPHICS_BUILDING_NETWORKED_GAMES_AND_VIRTUAL_ENVIRONMENTS_EXPORT)

        #define NETWORKED_GRAPHICS_BUILDING_NETWORKED_GAMES_AND_VIRTUAL_ENVIRONMENTS_HIDDEN_DECLARE

    #else  // !defined(BUILDING_NETWORKED_GRAPHICS_BUILDING_NETWORKED_GAMES_AND_VIRTUAL_ENVIRONMENTS_EXPORT)

        #define NETWORKED_GRAPHICS_BUILDING_NETWORKED_GAMES_AND_VIRTUAL_ENVIRONMENTS_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_NETWORKED_GRAPHICS_BUILDING_NETWORKED_GAMES_AND_VIRTUAL_ENVIRONMENTS_EXPORT

#else  // !defined(BUILDING_NETWORKED_GRAPHICS_BUILDING_NETWORKED_GAMES_AND_VIRTUAL_ENVIRONMENTS_NO_IMPORT) && !defined(BUILDING_NETWORKED_GRAPHICS_BUILDING_NETWORKED_GAMES_AND_VIRTUAL_ENVIRONMENTS_STATIC)

    #if defined(BUILDING_NETWORKED_GRAPHICS_BUILDING_NETWORKED_GAMES_AND_VIRTUAL_ENVIRONMENTS_EXPORT)

        #define NETWORKED_GRAPHICS_BUILDING_NETWORKED_GAMES_AND_VIRTUAL_ENVIRONMENTS_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define NETWORKED_GRAPHICS_BUILDING_NETWORKED_GAMES_AND_VIRTUAL_ENVIRONMENTS_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_NETWORKED_GRAPHICS_BUILDING_NETWORKED_GAMES_AND_VIRTUAL_ENVIRONMENTS_EXPORT)

        #define NETWORKED_GRAPHICS_BUILDING_NETWORKED_GAMES_AND_VIRTUAL_ENVIRONMENTS_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define NETWORKED_GRAPHICS_BUILDING_NETWORKED_GAMES_AND_VIRTUAL_ENVIRONMENTS_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_NETWORKED_GRAPHICS_BUILDING_NETWORKED_GAMES_AND_VIRTUAL_ENVIRONMENTS_EXPORT

    #define NETWORKED_GRAPHICS_BUILDING_NETWORKED_GAMES_AND_VIRTUAL_ENVIRONMENTS_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_NETWORKED_GRAPHICS_BUILDING_NETWORKED_GAMES_AND_VIRTUAL_ENVIRONMENTS_NO_IMPORT) || defined(BUILDING_NETWORKED_GRAPHICS_BUILDING_NETWORKED_GAMES_AND_VIRTUAL_ENVIRONMENTS_STATIC)

#endif  // NETWORKED_GRAPHICS_BUILDING_NETWORKED_GAMES_AND_VIRTUAL_ENVIRONMENTS_DLL_H
