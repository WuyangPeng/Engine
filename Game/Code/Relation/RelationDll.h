///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/18 15:32)

#ifndef RELATION_DLL_H
#define RELATION_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_RELATION_NO_IMPORT) || defined(BUILDING_RELATION_STATIC)

    #define RELATION_DEFAULT_DECLARE
    #define RELATION_HIDDEN_DECLARE
    #define RELATION_VISIBLE

#else  // !defined(BUILDING_RELATION_NO_IMPORT) && !defined(BUILDING_RELATION_STATIC)

    #if defined(BUILDING_RELATION_EXPORT)

        #define RELATION_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define RELATION_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_RELATION_EXPORT)

        #define RELATION_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define RELATION_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_RELATION_EXPORT

    #define RELATION_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_RELATION_NO_IMPORT) || defined(BUILDING_RELATION_STATIC)

#endif  // RELATION_DLL_H
