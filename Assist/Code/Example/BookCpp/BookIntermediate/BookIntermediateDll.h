///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/05 0:34)

#ifndef BOOK_INTERMEDIATE_DLL_H
#define BOOK_INTERMEDIATE_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_BOOK_INTERMEDIATE_NO_IMPORT) || defined(BUILDING_BOOK_INTERMEDIATE_STATIC)

    #define BOOK_INTERMEDIATE_DEFAULT_DECLARE
    #define BOOK_INTERMEDIATE_HIDDEN_DECLARE
    #define BOOK_INTERMEDIATE_VISIBLE

#else  // !defined(BUILDING_BOOK_INTERMEDIATE_NO_IMPORT) && !defined(BUILDING_BOOK_INTERMEDIATE_STATIC)

    #if defined(BUILDING_BOOK_INTERMEDIATE_EXPORT)

        #define BOOK_INTERMEDIATE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define BOOK_INTERMEDIATE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_BOOK_INTERMEDIATE_EXPORT)

        #define BOOK_INTERMEDIATE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define BOOK_INTERMEDIATE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_BOOK_INTERMEDIATE_EXPORT

    #define BOOK_INTERMEDIATE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_BOOK_INTERMEDIATE_NO_IMPORT) || defined(BUILDING_BOOK_INTERMEDIATE_STATIC)

#endif  // BOOK_INTERMEDIATE_DLL_H
