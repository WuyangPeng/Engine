///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/13 10:26)

#ifndef ASSIST_TOOLS_EXAMPLE_DLL_DLL_H
#define ASSIST_TOOLS_EXAMPLE_DLL_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_ASSIST_TOOLS_EXAMPLE_NO_IMPORT) || defined(BUILDING_ASSIST_TOOLS_EXAMPLE_STATIC)

    #define ASSIST_TOOLS_EXAMPLE_DEFAULT_DECLARE
    #define ASSIST_TOOLS_EXAMPLE_VISIBLE

    #if defined(BUILDING_ASSIST_TOOLS_EXAMPLE_EXPORT)

        #define ASSIST_TOOLS_EXAMPLE_HIDDEN_DECLARE

    #else  // !defined(BUILDING_ASSIST_TOOLS_EXAMPLE_EXPORT)

        #define ASSIST_TOOLS_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_ASSIST_TOOLS_EXAMPLE_EXPORT

#else  // !defined(BUILDING_ASSIST_TOOLS_EXAMPLE_NO_IMPORT) && !defined(BUILDING_ASSIST_TOOLS_EXAMPLE_STATIC)

    #if defined(BUILDING_ASSIST_TOOLS_EXAMPLE_EXPORT)

        #define ASSIST_TOOLS_EXAMPLE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define ASSIST_TOOLS_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_ASSIST_TOOLS_EXAMPLE_EXPORT)

        #define ASSIST_TOOLS_EXAMPLE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define ASSIST_TOOLS_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_ASSIST_TOOLS_EXAMPLE_EXPORT

    #define ASSIST_TOOLS_EXAMPLE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_ASSIST_TOOLS_EXAMPLE_NO_IMPORT) || defined(BUILDING_ASSIST_TOOLS_EXAMPLE_STATIC)

#endif  // ASSIST_TOOLS_EXAMPLE_DLL_DLL_H
