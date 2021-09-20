///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/04/29 22:12)

#ifndef BOOK_ACE_DLL_H
#define BOOK_ACE_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_BOOK_ACE_NO_IMPORT) || defined(BUILDING_BOOK_ACE_STATIC)

    #define BOOK_ACE_DEFAULT_DECLARE
    #define BOOK_ACE_VISIBLE

    #if defined(BUILDING_BOOK_ACE_EXPORT)

        #define BOOK_ACE_HIDDEN_DECLARE

    #else  // !defined(BUILDING_BOOK_ACE_EXPORT)

        #define BOOK_ACE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_BOOK_ACE_EXPORT

#else  // !defined(BUILDING_BOOK_ACE_NO_IMPORT) && !defined(BUILDING_BOOK_ACE_STATIC)

    #if defined(BUILDING_BOOK_ACE_EXPORT)

        #define BOOK_ACE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define BOOK_ACE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_BOOK_ACE_EXPORT)

        #define BOOK_ACE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define BOOK_ACE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_BOOK_ACE_EXPORT

    #define BOOK_ACE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_BOOK_ACE_NO_IMPORT) || defined(BUILDING_BOOK_ACE_STATIC)

#endif  // BOOK_ACE_DLL_H
