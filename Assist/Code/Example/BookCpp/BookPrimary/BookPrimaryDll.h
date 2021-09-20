///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/21 20:51)

#ifndef BOOK_PRIMARY_DLL_H
#define BOOK_PRIMARY_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_BOOK_PRIMARY_NO_IMPORT) || defined(BUILDING_BOOK_PRIMARY_STATIC)

    #define BOOK_PRIMARY_DEFAULT_DECLARE
    #define BOOK_PRIMARY_HIDDEN_DECLARE
    #define BOOK_PRIMARY_VISIBLE

#else  // !defined(BUILDING_BOOK_PRIMARY_NO_IMPORT) && !defined(BUILDING_BOOK_PRIMARY_STATIC)

    #if defined(BUILDING_BOOK_PRIMARY_EXPORT)

        #define BOOK_PRIMARY_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define BOOK_PRIMARY_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_BOOK_PRIMARY_EXPORT)

        #define BOOK_PRIMARY_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define BOOK_PRIMARY_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_BOOK_PRIMARY_EXPORT

    #define BOOK_PRIMARY_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_BOOK_PRIMARY_NO_IMPORT) || defined(BUILDING_BOOK_PRIMARY_STATIC)

#endif  // BOOK_PRIMARY_DLL_H
