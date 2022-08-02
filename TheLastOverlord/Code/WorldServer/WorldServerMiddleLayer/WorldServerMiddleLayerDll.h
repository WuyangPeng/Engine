///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/25 18:32)

#ifndef WORLD_SERVER_MIDDLE_LAYER_DLL_H
#define WORLD_SERVER_MIDDLE_LAYER_DLL_H

#include "Macro/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_WORLD_SERVER_MIDDLE_LAYER_NO_IMPORT) || defined(BUILDING_WORLD_SERVER_MIDDLE_LAYER_STATIC)

    #define WORLD_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE
    #define WORLD_SERVER_MIDDLE_LAYER_HIDDEN_DECLARE
    #define WORLD_SERVER_MIDDLE_LAYER_VISIBLE

#else  // !defined(BUILDING_WORLD_SERVER_MIDDLE_LAYER_NO_IMPORT) && !defined(BUILDING_WORLD_SERVER_MIDDLE_LAYER_STATIC)

    #if defined(BUILDING_WORLD_SERVER_MIDDLE_LAYER_EXPORT)

        #define WORLD_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define WORLD_SERVER_MIDDLE_LAYER_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_WORLD_SERVER_MIDDLE_LAYER_EXPORT)

        #define WORLD_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define WORLD_SERVER_MIDDLE_LAYER_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_WORLD_SERVER_MIDDLE_LAYER_EXPORT

    #define WORLD_SERVER_MIDDLE_LAYER_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_WORLD_SERVER_MIDDLE_LAYER_NO_IMPORT) || defined(BUILDING_WORLD_SERVER_MIDDLE_LAYER_STATIC)

#endif  // WORLD_SERVER_MIDDLE_LAYER_DLL_H
