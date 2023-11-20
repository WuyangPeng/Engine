/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.0 (2023/11/18 17:09)

#ifndef ROBOT_CLIENT_CORE_DLL_H
#define ROBOT_CLIENT_CORE_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_ROBOT_CLIENT_CORE_NO_IMPORT) || defined(BUILDING_ROBOT_CLIENT_CORE_STATIC)

    #define ROBOT_CLIENT_CORE_DEFAULT_DECLARE
    #define ROBOT_CLIENT_CORE_VISIBLE

    #if defined(BUILDING_ROBOT_CLIENT_CORE_EXPORT)

        #define ROBOT_CLIENT_CORE_HIDDEN_DECLARE

    #else  // !defined(BUILDING_ROBOT_CLIENT_CORE_EXPORT)

        #define ROBOT_CLIENT_CORE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_ROBOT_CLIENT_CORE_EXPORT

#else  // !defined(BUILDING_ROBOT_CLIENT_CORE_NO_IMPORT) && !defined(BUILDING_ROBOT_CLIENT_CORE_STATIC)

    #if defined(BUILDING_ROBOT_CLIENT_CORE_EXPORT)

        #define ROBOT_CLIENT_CORE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define ROBOT_CLIENT_CORE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_ROBOT_CLIENT_CORE_EXPORT)

        #define ROBOT_CLIENT_CORE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define ROBOT_CLIENT_CORE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_ROBOT_CLIENT_CORE_EXPORT

    #define ROBOT_CLIENT_CORE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_ROBOT_CLIENT_CORE_NO_IMPORT) || defined(BUILDING_ROBOT_CLIENT_CORE_STATIC)

#endif  // ROBOT_CLIENT_CORE_DLL_H