///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 16:13)

#ifndef SCENE_DLL_H
#define SCENE_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_SCENE_NO_IMPORT) || defined(BUILDING_SCENE_STATIC)

    #define SCENE_DEFAULT_DECLARE
    #define SCENE_VISIBLE

    #if defined(BUILDING_SCENE_EXPORT)

        #define SCENE_HIDDEN_DECLARE

    #else  // !defined(BUILDING_SCENE_EXPORT)

        #define SCENE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_SCENE_EXPORT

#else  // !defined(BUILDING_SCENE_NO_IMPORT) && !defined(BUILDING_SCENE_STATIC)

    #if defined(BUILDING_SCENE_EXPORT)

        #define SCENE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define SCENE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_SCENE_EXPORT)

        #define SCENE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define SCENE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_SCENE_EXPORT

    #define SCENE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_SCENE_NO_IMPORT) || defined(BUILDING_SCENE_STATIC)

#endif  // SCENE_DLL_H
