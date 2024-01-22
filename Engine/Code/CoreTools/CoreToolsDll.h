/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 20:02)

#ifndef CORE_TOOLS_DLL_H
#define CORE_TOOLS_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_CORE_TOOLS_NO_IMPORT) || defined(BUILDING_CORE_TOOLS_STATIC)

    #define CORE_TOOLS_DEFAULT_DECLARE
    #define CORE_TOOLS_VISIBLE

    #if defined(BUILDING_CORE_TOOLS_EXPORT)

        #define CORE_TOOLS_HIDDEN_DECLARE

    #else  // !defined(BUILDING_CORE_TOOLS_EXPORT)

        #define CORE_TOOLS_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_CORE_TOOLS_EXPORT

#else  // !defined(BUILDING_CORE_TOOLS_NO_IMPORT) && !defined(BUILDING_CORE_TOOLS_STATIC)

    #if defined(BUILDING_CORE_TOOLS_EXPORT)

        #define CORE_TOOLS_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define CORE_TOOLS_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_CORE_TOOLS_EXPORT)

        #define CORE_TOOLS_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define CORE_TOOLS_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_CORE_TOOLS_EXPORT

    #define CORE_TOOLS_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_CORE_TOOLS_NO_IMPORT) || defined(BUILDING_CORE_TOOLS_STATIC)

#endif  // CORE_TOOLS_DLL_H