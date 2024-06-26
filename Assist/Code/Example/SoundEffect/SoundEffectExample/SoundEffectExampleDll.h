///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 10:55)

#ifndef SOUND_EFFECT_EXAMPLE_DLL_DLL_H
#define SOUND_EFFECT_EXAMPLE_DLL_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_SOUND_EFFECT_EXAMPLE_NO_IMPORT) || defined(BUILDING_SOUND_EFFECT_EXAMPLE_STATIC)

    #define SOUND_EFFECT_EXAMPLE_DEFAULT_DECLARE
    #define SOUND_EFFECT_EXAMPLE_VISIBLE

    #if defined(BUILDING_SOUND_EFFECT_EXAMPLE_EXPORT)

        #define SOUND_EFFECT_EXAMPLE_HIDDEN_DECLARE

    #else  // !defined(BUILDING_SOUND_EFFECT_EXAMPLE_EXPORT)

        #define SOUND_EFFECT_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_SOUND_EFFECT_EXAMPLE_EXPORT

#else  // !defined(BUILDING_SOUND_EFFECT_EXAMPLE_NO_IMPORT) && !defined(BUILDING_SOUND_EFFECT_EXAMPLE_STATIC)

    #if defined(BUILDING_SOUND_EFFECT_EXAMPLE_EXPORT)

        #define SOUND_EFFECT_EXAMPLE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define SOUND_EFFECT_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_SOUND_EFFECT_EXAMPLE_EXPORT)

        #define SOUND_EFFECT_EXAMPLE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define SOUND_EFFECT_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_SOUND_EFFECT_EXAMPLE_EXPORT

    #define SOUND_EFFECT_EXAMPLE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_SOUND_EFFECT_EXAMPLE_NO_IMPORT) || defined(BUILDING_SOUND_EFFECT_EXAMPLE_STATIC)

#endif  // SOUND_EFFECT_EXAMPLE_DLL_DLL_H
