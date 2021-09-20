///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/09 14:57)

#ifndef GROKKING_ALGORITHMS_DLL_H
#define GROKKING_ALGORITHMS_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_GROKKING_ALGORITHMS_NO_IMPORT) || defined(BUILDING_GROKKING_ALGORITHMS_STATIC)

    #define GROKKING_ALGORITHMS_DEFAULT_DECLARE
    #define GROKKING_ALGORITHMS_HIDDEN_DECLARE
    #define GROKKING_ALGORITHMS_VISIBLE

#else  // !defined(BUILDING_GROKKING_ALGORITHMS_NO_IMPORT) && !defined(BUILDING_GROKKING_ALGORITHMS_STATIC)

    #if defined(BUILDING_GROKKING_ALGORITHMS_EXPORT)

        #define GROKKING_ALGORITHMS_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define GROKKING_ALGORITHMS_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_GROKKING_ALGORITHMS_EXPORT)

        #define GROKKING_ALGORITHMS_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define GROKKING_ALGORITHMS_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_GROKKING_ALGORITHMS_EXPORT

    #define GROKKING_ALGORITHMS_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_GROKKING_ALGORITHMS_NO_IMPORT) || defined(BUILDING_GROKKING_ALGORITHMS_STATIC)

#endif  // GROKKING_ALGORITHMS_DLL_H