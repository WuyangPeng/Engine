///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/03/28 12:58)

#ifndef ALGORITHMS_DLL_H
#define ALGORITHMS_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_ALGORITHMS_NO_IMPORT) || defined(BUILDING_ALGORITHMS_STATIC)

    #define ALGORITHMS_DEFAULT_DECLARE
    #define ALGORITHMS_VISIBLE

    #if defined(BUILDING_ALGORITHMS_EXPORT)

        #define ALGORITHMS_HIDDEN_DECLARE

    #else  // !defined(BUILDING_ALGORITHMS_EXPORT)

        #define ALGORITHMS_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_ALGORITHMS_EXPORT

#else  // !defined(BUILDING_ALGORITHMS_NO_IMPORT) && !defined(BUILDING_ALGORITHMS_STATIC)

    #if defined(BUILDING_ALGORITHMS_EXPORT)

        #define ALGORITHMS_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define ALGORITHMS_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_ALGORITHMS_EXPORT)

        #define ALGORITHMS_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define ALGORITHMS_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_ALGORITHMS_EXPORT

    #define ALGORITHMS_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_ALGORITHMS_NO_IMPORT) || defined(BUILDING_ALGORITHMS_STATIC)

#endif  // ALGORITHMS_DLL_H
