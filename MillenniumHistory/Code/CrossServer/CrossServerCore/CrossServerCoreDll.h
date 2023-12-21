/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/12/17 20:09)

#ifndef CROSS_SERVER_CORE_DLL_H
#define CROSS_SERVER_CORE_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_CROSS_SERVER_CORE_NO_IMPORT) || defined(BUILDING_CROSS_SERVER_CORE_STATIC)

    #define CROSS_SERVER_CORE_DEFAULT_DECLARE
    #define CROSS_SERVER_CORE_VISIBLE

    #if defined(BUILDING_CROSS_SERVER_CORE_EXPORT)

        #define CROSS_SERVER_CORE_HIDDEN_DECLARE

    #else  // !defined(BUILDING_CROSS_SERVER_CORE_EXPORT)

        #define CROSS_SERVER_CORE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_CROSS_SERVER_CORE_EXPORT

#else  // !defined(BUILDING_CROSS_SERVER_CORE_NO_IMPORT) && !defined(BUILDING_CROSS_SERVER_CORE_STATIC)

    #if defined(BUILDING_CROSS_SERVER_CORE_EXPORT)

        #define CROSS_SERVER_CORE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define CROSS_SERVER_CORE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_CROSS_SERVER_CORE_EXPORT)

        #define CROSS_SERVER_CORE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define CROSS_SERVER_CORE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_CROSS_SERVER_CORE_EXPORT

    #define CROSS_SERVER_CORE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_CROSS_SERVER_CORE_NO_IMPORT) || defined(BUILDING_CROSS_SERVER_CORE_STATIC)

#endif  // CROSS_SERVER_CORE_DLL_H