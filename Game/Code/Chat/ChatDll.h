///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.8.0.11 (2022/07/19 10:25)

#ifndef CHAT_DLL_H
#define CHAT_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_CHAT_NO_IMPORT) || defined(BUILDING_CHAT_STATIC)

    #define CHAT_DEFAULT_DECLARE
    #define CHAT_HIDDEN_DECLARE
    #define CHAT_VISIBLE

#else  // !defined(BUILDING_CHAT_NO_IMPORT) && !defined(BUILDING_CHAT_STATIC)

    #if defined(BUILDING_CHAT_EXPORT)

        #define CHAT_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define CHAT_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_CHAT_EXPORT)

        #define CHAT_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define CHAT_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_CHAT_EXPORT

    #define CHAT_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_CHAT_NO_IMPORT) || defined(BUILDING_CHAT_STATIC)

#endif  // CHAT_DLL_H
