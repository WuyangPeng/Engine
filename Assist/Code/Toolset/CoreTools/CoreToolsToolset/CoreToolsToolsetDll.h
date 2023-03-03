///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.3 (2023/03/02 11:26)

#ifndef CORE_TOOLS_TOOLSET_DLL_DLL_H
#define CORE_TOOLS_TOOLSET_DLL_DLL_H

#include "System/Helper/ExportMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#if defined(BUILDING_CORE_TOOLS_TOOLSET_NO_IMPORT) || defined(BUILDING_CORE_TOOLS_STATIC)

    #define CORE_TOOLS_TOOLSET_DEFAULT_DECLARE
    #define CORE_TOOLS_TOOLSET_VISIBLE

    #if defined(BUILDING_CORE_TOOLS_TOOLSET_EXPORT)

        #define CORE_TOOLS_TOOLSET_HIDDEN_DECLARE

    #else  // !defined(BUILDING_CORE_TOOLS_TOOLSET_EXPORT)

        #define CORE_TOOLS_TOOLSET_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_CORE_TOOLS_TOOLSET_EXPORT

#else  // !defined(BUILDING_CORE_TOOLS_TOOLSET_NO_IMPORT) && !defined(BUILDING_CORE_TOOLS_STATIC)

    #if defined(BUILDING_CORE_TOOLS_TOOLSET_EXPORT)

        #define CORE_TOOLS_TOOLSET_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define CORE_TOOLS_TOOLSET_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_CORE_TOOLS_TOOLSET_EXPORT)

        #define CORE_TOOLS_TOOLSET_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define CORE_TOOLS_TOOLSET_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_CORE_TOOLS_TOOLSET_EXPORT

    #define CORE_TOOLS_TOOLSET_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_CORE_TOOLS_TOOLSET_NO_IMPORT) || defined(BUILDING_CORE_TOOLS_STATIC)

#endif  // CORE_TOOLS_TOOLSET_DLL_DLL_H
