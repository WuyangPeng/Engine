///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.0 (2021/02/16 17:45)

#ifndef CPP_CODING_STANDARDS_DLL_H
#define CPP_CODING_STANDARDS_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_CPP_CODING_STANDARDS_NO_IMPORT) || defined(BUILDING_CPP_CODING_STANDARDS_STATIC)

    #define CPP_CODING_STANDARDS_DEFAULT_DECLARE
    #define CPP_CODING_STANDARDS_HIDDEN_DECLARE
    #define CPP_CODING_STANDARDS_VISIBLE

#else  // !defined(BUILDING_CPP_CODING_STANDARDS_NO_IMPORT) && !defined(BUILDING_CPP_CODING_STANDARDS_STATIC)

    #if defined(BUILDING_CPP_CODING_STANDARDS_EXPORT)

        #define CPP_CODING_STANDARDS_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define CPP_CODING_STANDARDS_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_CPP_CODING_STANDARDS_EXPORT)

        #define CPP_CODING_STANDARDS_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define CPP_CODING_STANDARDS_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_CPP_CODING_STANDARDS_EXPORT

    #define CPP_CODING_STANDARDS_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_CPP_CODING_STANDARDS_NO_IMPORT) || defined(BUILDING_CPP_CODING_STANDARDS_STATIC)

#endif  // CPP_CODING_STANDARDS_DLL_H
