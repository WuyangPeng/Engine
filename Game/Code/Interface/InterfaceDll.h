///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 15:54)

#ifndef INTERFACE_DLL_H
#define INTERFACE_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_INTERFACE_NO_IMPORT) || defined(BUILDING_INTERFACE_STATIC)

    #define INTERFACE_DEFAULT_DECLARE
    #define INTERFACE_VISIBLE

    #if defined(BUILDING_INTERFACE_EXPORT)

        #define INTERFACE_HIDDEN_DECLARE

    #else  // !defined(BUILDING_INTERFACE_EXPORT)

        #define INTERFACE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_INTERFACE_EXPORT

#else  // !defined(BUILDING_INTERFACE_NO_IMPORT) && !defined(BUILDING_INTERFACE_STATIC)

    #if defined(BUILDING_INTERFACE_EXPORT)

        #define INTERFACE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define INTERFACE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_INTERFACE_EXPORT)

        #define INTERFACE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define INTERFACE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_INTERFACE_EXPORT

    #define INTERFACE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_INTERFACE_NO_IMPORT) || defined(BUILDING_INTERFACE_STATIC)

#endif  // INTERFACE_DLL_H
