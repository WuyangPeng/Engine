///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/19 21:25)

#ifndef BOOK_CPP_DLL_H
#define BOOK_CPP_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_BOOK_CPP_NO_IMPORT) || defined(BUILDING_BOOK_CPP_STATIC)

    #define BOOK_CPP_DEFAULT_DECLARE
    #define BOOK_CPP_HIDDEN_DECLARE
    #define BOOK_CPP_VISIBLE

#else  // !defined(BUILDING_BOOK_CPP_NO_IMPORT) && !defined(BUILDING_BOOK_CPP_STATIC)

    #if defined(BUILDING_BOOK_CPP_EXPORT)

        #define BOOK_CPP_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define BOOK_CPP_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_BOOK_CPP_EXPORT)

        #define BOOK_CPP_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define BOOK_CPP_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_BOOK_CPP_EXPORT

    #define BOOK_CPP_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_BOOK_CPP_NO_IMPORT) || defined(BUILDING_BOOK_CPP_STATIC)

#endif  // BOOK_CPP_DLL_H
