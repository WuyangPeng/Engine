//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 19:26)

#ifndef DATABASE_DLL_H
#define DATABASE_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)

    #define DATABASE_DEFAULT_DECLARE
    #define DATABASE_HIDDEN_DECLARE
    #define DATABASE_VISIBLE

#else  // !defined(BUILDING_DATABASE_NO_IMPORT) && !defined(BUILDING_DATABASE_STATIC)

    #if defined(BUILDING_DATABASE_EXPORT)

        #define DATABASE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define DATABASE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_DATABASE_EXPORT)

        #define DATABASE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define DATABASE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_DATABASE_EXPORT

    #define DATABASE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)

#endif  // DATABASE_DLL_H