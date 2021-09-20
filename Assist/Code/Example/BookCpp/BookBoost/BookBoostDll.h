///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/21 19:15)

#ifndef BOOK_BOOST_DLL_H
#define BOOK_BOOST_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_BOOK_BOOST_NO_IMPORT) || defined(BUILDING_BOOK_BOOST_STATIC)

    #define BOOK_BOOST_DEFAULT_DECLARE
    #define BOOK_BOOST_VISIBLE

    #if defined(BUILDING_BOOK_BOOST_EXPORT)

        #define BOOK_BOOST_HIDDEN_DECLARE

    #else  // !defined(BUILDING_BOOK_BOOST_EXPORT)

        #define BOOK_BOOST_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_BOOK_BOOST_EXPORT

#else  // !defined(BUILDING_BOOK_BOOST_NO_IMPORT) && !defined(BUILDING_BOOK_BOOST_STATIC)

    #if defined(BUILDING_BOOK_BOOST_EXPORT)

        #define BOOK_BOOST_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define BOOK_BOOST_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_BOOK_BOOST_EXPORT)

        #define BOOK_BOOST_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define BOOK_BOOST_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_BOOK_BOOST_EXPORT

    #define BOOK_BOOST_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_BOOK_BOOST_NO_IMPORT) || defined(BUILDING_BOOK_BOOST_STATIC)

#endif  // BOOK_BOOST_DLL_H
