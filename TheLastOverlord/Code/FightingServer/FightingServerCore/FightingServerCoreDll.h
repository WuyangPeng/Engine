///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/25 15:42)

#ifndef FIGHTING_SERVER_CORE_DLL_H
#define FIGHTING_SERVER_CORE_DLL_H

#include "Macro/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_FIGHTING_SERVER_CORE_NO_IMPORT) || defined(BUILDING_FIGHTING_SERVER_CORE_STATIC)

    #define FIGHTING_SERVER_CORE_DEFAULT_DECLARE
    #define FIGHTING_SERVER_CORE_HIDDEN_DECLARE
    #define FIGHTING_SERVER_CORE_VISIBLE

#else  // !defined(BUILDING_FIGHTING_SERVER_CORE_NO_IMPORT) && !defined(BUILDING_FIGHTING_SERVER_CORE_STATIC)

    #if defined(BUILDING_FIGHTING_SERVER_CORE_EXPORT)

        #define FIGHTING_SERVER_CORE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define FIGHTING_SERVER_CORE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_FIGHTING_SERVER_CORE_EXPORT)

        #define FIGHTING_SERVER_CORE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define FIGHTING_SERVER_CORE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_FIGHTING_SERVER_CORE_EXPORT

    #define FIGHTING_SERVER_CORE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_FIGHTING_SERVER_CORE_NO_IMPORT) || defined(BUILDING_FIGHTING_SERVER_CORE_STATIC)

#endif  // FIGHTING_SERVER_CORE_DLL_H
