///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 16:57)

#ifndef USER_INFO_DLL_H
#define USER_INFO_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_USER_INFO_NO_IMPORT) || defined(BUILDING_USER_INFO_STATIC)

    #define USER_INFO_DEFAULT_DECLARE
    #define USER_INFO_VISIBLE

    #if defined(BUILDING_USER_INFO_EXPORT)

        #define USER_INFO_HIDDEN_DECLARE

    #else  // !defined(BUILDING_USER_INFO_EXPORT)

        #define USER_INFO_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_USER_INFO_EXPORT

#else  // !defined(BUILDING_USER_INFO_NO_IMPORT) && !defined(BUILDING_USER_INFO_STATIC)

    #if defined(BUILDING_USER_INFO_EXPORT)

        #define USER_INFO_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define USER_INFO_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_USER_INFO_EXPORT)

        #define USER_INFO_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define USER_INFO_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_USER_INFO_EXPORT

    #define USER_INFO_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_USER_INFO_NO_IMPORT) || defined(BUILDING_USER_INFO_STATIC)

#endif  // USER_INFO_DLL_H
