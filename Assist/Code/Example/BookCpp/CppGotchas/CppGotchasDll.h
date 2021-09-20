///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.1 (2021/01/08 21:29)

#ifndef CPP_GOTCHAS_DLL_H
#define CPP_GOTCHAS_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_CPP_GOTCHAS_NO_IMPORT) || defined(BUILDING_CPP_GOTCHAS_STATIC)

    #define CPP_GOTCHAS_DEFAULT_DECLARE
    #define CPP_GOTCHAS_HIDDEN_DECLARE
    #define CPP_GOTCHAS_VISIBLE

#else  // !defined(BUILDING_CPP_GOTCHAS_NO_IMPORT) && !defined(BUILDING_CPP_GOTCHAS_STATIC)

    #if defined(BUILDING_CPP_GOTCHAS_EXPORT)

        #define CPP_GOTCHAS_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define CPP_GOTCHAS_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_CPP_GOTCHAS_EXPORT)

        #define CPP_GOTCHAS_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define CPP_GOTCHAS_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_CPP_GOTCHAS_EXPORT

    #define CPP_GOTCHAS_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_CPP_GOTCHAS_NO_IMPORT) || defined(BUILDING_CPP_GOTCHAS_STATIC)

#endif  // CPP_GOTCHAS_DLL_H
