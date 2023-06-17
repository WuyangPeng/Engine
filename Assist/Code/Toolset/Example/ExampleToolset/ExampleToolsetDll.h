///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/15 18:18)

#ifndef EXAMPLE_TOOLSET_DLL_DLL_H
#define EXAMPLE_TOOLSET_DLL_DLL_H

#include "Helper/Helper.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_EXAMPLE_TOOLSET_NO_IMPORT) || defined(BUILDING_EXAMPLE_STATIC)

    #define EXAMPLE_TOOLSET_DEFAULT_DECLARE
    #define EXAMPLE_TOOLSET_VISIBLE

    #if defined(BUILDING_EXAMPLE_TOOLSET_EXPORT)

        #define EXAMPLE_TOOLSET_HIDDEN_DECLARE

    #else  // !defined(BUILDING_EXAMPLE_TOOLSET_EXPORT)

        #define EXAMPLE_TOOLSET_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_EXAMPLE_TOOLSET_EXPORT

#else  // !defined(BUILDING_EXAMPLE_TOOLSET_NO_IMPORT) && !defined(BUILDING_EXAMPLE_STATIC)

    #if defined(BUILDING_EXAMPLE_TOOLSET_EXPORT)

        #define EXAMPLE_TOOLSET_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define EXAMPLE_TOOLSET_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_EXAMPLE_TOOLSET_EXPORT)

        #define EXAMPLE_TOOLSET_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define EXAMPLE_TOOLSET_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_EXAMPLE_TOOLSET_EXPORT

    #define EXAMPLE_TOOLSET_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_EXAMPLE_TOOLSET_NO_IMPORT) || defined(BUILDING_EXAMPLE_STATIC)

#endif  // EXAMPLE_TOOLSET_DLL_DLL_H
