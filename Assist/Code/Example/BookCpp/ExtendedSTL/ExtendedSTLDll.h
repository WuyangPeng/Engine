///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/02/28 19:37)

#ifndef EXTENDED_STL_DLL_H
#define EXTENDED_STL_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_EXTENDED_STL_NO_IMPORT) || defined(BUILDING_EXTENDED_STL_STATIC)

    #define EXTENDED_STL_DEFAULT_DECLARE
    #define EXTENDED_STL_HIDDEN_DECLARE
    #define EXTENDED_STL_VISIBLE

#else  // !defined(BUILDING_EXTENDED_STL_NO_IMPORT) && !defined(BUILDING_EXTENDED_STL_STATIC)

    #if defined(BUILDING_EXTENDED_STL_EXPORT)

        #define EXTENDED_STL_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define EXTENDED_STL_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_EXTENDED_STL_EXPORT)

        #define EXTENDED_STL_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define EXTENDED_STL_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_EXTENDED_STL_EXPORT

    #define EXTENDED_STL_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_EXTENDED_STL_NO_IMPORT) || defined(BUILDING_EXTENDED_STL_STATIC)

#endif  // EXTENDED_STL_DLL_H
