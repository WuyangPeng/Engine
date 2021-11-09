///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/10/07 23:22)

#ifndef SAFE_CPP_DLL_H
#define SAFE_CPP_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_SAFE_CPP_NO_IMPORT) || defined(BUILDING_SAFE_CPP_STATIC)

    #define SAFE_CPP_DEFAULT_DECLARE
    #define SAFE_CPP_VISIBLE

    #if defined(BUILDING_SAFE_CPP_EXPORT)

        #define SAFE_CPP_HIDDEN_DECLARE

    #else  // !defined(BUILDING_SAFE_CPP_EXPORT)

        #define SAFE_CPP_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_SAFE_CPP_EXPORT

#else  // !defined(BUILDING_SAFE_CPP_NO_IMPORT) && !defined(BUILDING_SAFE_CPP_STATIC)

    #if defined(BUILDING_SAFE_CPP_EXPORT)

        #define SAFE_CPP_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define SAFE_CPP_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_SAFE_CPP_EXPORT)

        #define SAFE_CPP_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define SAFE_CPP_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_SAFE_CPP_EXPORT

    #define SAFE_CPP_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_SAFE_CPP_NO_IMPORT) || defined(BUILDING_SAFE_CPP_STATIC)

#endif  // SAFE_CPP_DLL_H
