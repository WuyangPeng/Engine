/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 20:15)

#ifndef RESOURCE_MANAGER_DLL_H
#define RESOURCE_MANAGER_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_RESOURCE_MANAGER_NO_IMPORT) || defined(BUILDING_RESOURCE_MANAGER_STATIC)

    #define RESOURCE_MANAGER_DEFAULT_DECLARE
    #define RESOURCE_MANAGER_VISIBLE

    #if defined(BUILDING_BUILDING_RESOURCE_EXPORT)

        #define RESOURCE_MANAGER_HIDDEN_DECLARE

    #else  // !defined(BUILDING_BUILDING_RESOURCE_EXPORT)

        #define RESOURCE_MANAGER_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_BUILDING_RESOURCE_EXPORT

#else  // !defined(BUILDING_RESOURCE_MANAGER_NO_IMPORT) && !defined(BUILDING_RESOURCE_MANAGER_STATIC)

    #if defined(BUILDING_RESOURCE_MANAGER_EXPORT)

        #define RESOURCE_MANAGER_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define RESOURCE_MANAGER_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_RESOURCE_MANAGER_EXPORT)

        #define RESOURCE_MANAGER_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define RESOURCE_MANAGER_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_RESOURCE_MANAGER_EXPORT

    #define RESOURCE_MANAGER_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_RESOURCE_MANAGER_NO_IMPORT) || defined(BUILDING_RESOURCE_MANAGER_STATIC)

#endif  // RESOURCE_MANAGER_DLL_H