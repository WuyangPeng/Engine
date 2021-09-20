///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/07/28 15:19)

#ifndef CORE_TOOLS_EXAMPLE_DLL_DLL_H
#define CORE_TOOLS_EXAMPLE_DLL_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_CORE_TOOLS_EXAMPLE_NO_IMPORT) || defined(BUILDING_CORE_TOOLS_EXAMPLE_STATIC)

    #define CORE_TOOLS_EXAMPLE_DEFAULT_DECLARE
    #define CORE_TOOLS_EXAMPLE_VISIBLE

    #if defined(BUILDING_CORE_TOOLS_EXAMPLE_EXPORT)

        #define CORE_TOOLS_EXAMPLE_HIDDEN_DECLARE

    #else  // !defined(BUILDING_CORE_TOOLS_EXAMPLE_EXPORT)

        #define CORE_TOOLS_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_CORE_TOOLS_EXAMPLE_EXPORT

#else  // !defined(BUILDING_CORE_TOOLS_EXAMPLE_NO_IMPORT) && !defined(BUILDING_CORE_TOOLS_EXAMPLE_STATIC)

    #if defined(BUILDING_CORE_TOOLS_EXAMPLE_EXPORT)

        #define CORE_TOOLS_EXAMPLE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define CORE_TOOLS_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_CORE_TOOLS_EXAMPLE_EXPORT)

        #define CORE_TOOLS_EXAMPLE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define CORE_TOOLS_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_CORE_TOOLS_EXAMPLE_EXPORT

    #define CORE_TOOLS_EXAMPLE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_CORE_TOOLS_EXAMPLE_NO_IMPORT) || defined(BUILDING_CORE_TOOLS_EXAMPLE_STATIC)

#endif  // CORE_TOOLS_EXAMPLE_DLL_DLL_H