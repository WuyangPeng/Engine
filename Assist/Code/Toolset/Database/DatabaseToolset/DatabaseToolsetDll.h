///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/04 11:25)

#ifndef DATABASE_TOOLSET_DLL_DLL_H
#define DATABASE_TOOLSET_DLL_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Database/Helper/UserMacro.h"

#if defined(BUILDING_DATABASE_TOOLSET_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)

    #define DATABASE_TOOLSET_DEFAULT_DECLARE
    #define DATABASE_TOOLSET_HIDDEN_DECLARE
    #define DATABASE_TOOLSET_VISIBLE

#else  // !defined(BUILDING_DATABASE_TOOLSET_NO_IMPORT) && !defined(BUILDING_DATABASE_STATIC)

    #if defined(BUILDING_DATABASE_TOOLSET_EXPORT)

        #define DATABASE_TOOLSET_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define DATABASE_TOOLSET_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_DATABASE_TOOLSET_EXPORT)

        #define DATABASE_TOOLSET_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define DATABASE_TOOLSET_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_DATABASE_TOOLSET_EXPORT

    #define DATABASE_TOOLSET_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_DATABASE_TOOLSET_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)

#endif  // DATABASE_TOOLSET_DLL_DLL_H
