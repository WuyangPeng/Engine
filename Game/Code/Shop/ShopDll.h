///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 16:22)

#ifndef SHOP_DLL_H
#define SHOP_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_SHOP_NO_IMPORT) || defined(BUILDING_SHOP_STATIC)

    #define SHOP_DEFAULT_DECLARE
    #define SHOP_VISIBLE

    #if defined(BUILDING_SHOP_EXPORT)

        #define SHOP_HIDDEN_DECLARE

    #else  // !defined(BUILDING_SHOP_EXPORT)

        #define SHOP_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_SHOP_EXPORT

#else  // !defined(BUILDING_SHOP_NO_IMPORT) && !defined(BUILDING_SHOP_STATIC)

    #if defined(BUILDING_SHOP_EXPORT)

        #define SHOP_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define SHOP_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_SHOP_EXPORT)

        #define SHOP_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define SHOP_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_SHOP_EXPORT

    #define SHOP_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_SHOP_NO_IMPORT) || defined(BUILDING_SHOP_STATIC)

#endif  // SHOP_DLL_H
