///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.1.0 (2021/01/21 23:03)

#ifndef ADVANCED_CPP_DLL_H
#define ADVANCED_CPP_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_ADVANCED_CPP_NO_IMPORT) || defined(BUILDING_ADVANCED_CPP_STATIC)

    #define ADVANCED_CPP_DEFAULT_DECLARE
    #define ADVANCED_CPP_HIDDEN_DECLARE
    #define ADVANCED_CPP_VISIBLE

#else  // !defined(BUILDING_ADVANCED_CPP_NO_IMPORT) && !defined(BUILDING_ADVANCED_CPP_STATIC)

    #if defined(BUILDING_ADVANCED_CPP_EXPORT)

        #define ADVANCED_CPP_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define ADVANCED_CPP_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_ADVANCED_CPP_EXPORT)

        #define ADVANCED_CPP_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define ADVANCED_CPP_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_ADVANCED_CPP_EXPORT

    #define ADVANCED_CPP_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_ADVANCED_CPP_NO_IMPORT) || defined(BUILDING_ADVANCED_CPP_STATIC)

#endif  // ADVANCED_CPP_DLL_H
