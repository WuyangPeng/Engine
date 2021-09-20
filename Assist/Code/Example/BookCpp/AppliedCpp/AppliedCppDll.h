///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.1 (2021/01/08 21:29)

#ifndef APPLIED_CPP_DLL_H
#define APPLIED_CPP_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_APPLIED_CPP_NO_IMPORT) || defined(BUILDING_APPLIED_CPP_STATIC)

    #define APPLIED_CPP_DEFAULT_DECLARE
    #define APPLIED_CPP_HIDDEN_DECLARE
    #define APPLIED_CPP_VISIBLE

#else  // !defined(BUILDING_APPLIED_CPP_NO_IMPORT) && !defined(BUILDING_APPLIED_CPP_STATIC)

    #if defined(BUILDING_APPLIED_CPP_EXPORT)

        #define APPLIED_CPP_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define APPLIED_CPP_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_APPLIED_CPP_EXPORT)

        #define APPLIED_CPP_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define APPLIED_CPP_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_APPLIED_CPP_EXPORT

    #define APPLIED_CPP_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_APPLIED_CPP_NO_IMPORT) || defined(BUILDING_APPLIED_CPP_STATIC)

#endif  // APPLIED_CPP_DLL_H
