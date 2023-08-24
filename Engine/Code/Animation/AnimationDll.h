///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/01 19:48)

#ifndef ANIMATION_DLL_H
#define ANIMATION_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_ANIMATION_NO_IMPORT) || defined(BUILDING_ANIMATION_STATIC)

    #define ANIMATION_DEFAULT_DECLARE
    #define ANIMATION_VISIBLE

    #if defined(BUILDING_ANIMATION_EXPORT)

        #define ANIMATION_HIDDEN_DECLARE

    #else  // !defined(BUILDING_ANIMATION_EXPORT)

        #define ANIMATION_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_ANIMATION_EXPORT

#else  // !defined(BUILDING_ANIMATION_NO_IMPORT) && !defined(BUILDING_ANIMATION_STATIC)

    #if defined(BUILDING_ANIMATION_EXPORT)

        #define ANIMATION_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define ANIMATION_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_ANIMATION_EXPORT)

        #define ANIMATION_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define ANIMATION_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_ANIMATION_EXPORT

    #define ANIMATION_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_ANIMATION_NO_IMPORT) || defined(BUILDING_ANIMATION_STATIC)

#endif  // ANIMATION_DLL_H