///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/07 23:22)

#ifndef DEBUGGING_CPP_DLL_H
#define DEBUGGING_CPP_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_DEBUGGING_CPP_NO_IMPORT) || defined(BUILDING_DEBUGGING_CPP_STATIC)

    #define DEBUGGING_CPP_DEFAULT_DECLARE
    #define DEBUGGING_CPP_VISIBLE

    #if defined(BUILDING_DEBUGGING_CPP_EXPORT)

        #define DEBUGGING_CPP_HIDDEN_DECLARE

    #else  // !defined(BUILDING_DEBUGGING_CPP_EXPORT)

        #define DEBUGGING_CPP_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_DEBUGGING_CPP_EXPORT

#else  // !defined(BUILDING_DEBUGGING_CPP_NO_IMPORT) && !defined(BUILDING_DEBUGGING_CPP_STATIC)

    #if defined(BUILDING_DEBUGGING_CPP_EXPORT)

        #define DEBUGGING_CPP_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define DEBUGGING_CPP_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_DEBUGGING_CPP_EXPORT)

        #define DEBUGGING_CPP_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define DEBUGGING_CPP_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_DEBUGGING_CPP_EXPORT

    #define DEBUGGING_CPP_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_DEBUGGING_CPP_NO_IMPORT) || defined(BUILDING_DEBUGGING_CPP_STATIC)

#endif  // DEBUGGING_CPP_DLL_H
