///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/08 21:29)

#ifndef IMPERFECT_CPP_DLL_H
#define IMPERFECT_CPP_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_IMPERFECT_CPP_NO_IMPORT) || defined(BUILDING_IMPERFECT_CPP_STATIC)

    #define IMPERFECT_CPP_DEFAULT_DECLARE
    #define IMPERFECT_CPP_HIDDEN_DECLARE
    #define IMPERFECT_CPP_VISIBLE

#else  // !defined(BUILDING_IMPERFECT_CPP_NO_IMPORT) && !defined(BUILDING_IMPERFECT_CPP_STATIC)

    #if defined(BUILDING_IMPERFECT_CPP_EXPORT)

        #define IMPERFECT_CPP_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define IMPERFECT_CPP_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_IMPERFECT_CPP_EXPORT)

        #define IMPERFECT_CPP_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define IMPERFECT_CPP_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_IMPERFECT_CPP_EXPORT

    #define IMPERFECT_CPP_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_IMPERFECT_CPP_NO_IMPORT) || defined(BUILDING_IMPERFECT_CPP_STATIC)

#endif  // IMPERFECT_CPP_DLL_H