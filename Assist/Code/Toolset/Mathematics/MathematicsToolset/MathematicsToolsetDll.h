///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/09 10:33)

#ifndef MATHEMATICS_TOOLSET_DLL_DLL_H
#define MATHEMATICS_TOOLSET_DLL_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Mathematics/Helper/UserMacro.h"

#if defined(BUILDING_MATHEMATICS_TOOLSET_NO_IMPORT) || defined(BUILDING_MATHEMATICS_STATIC)

    #define MATHEMATICS_TOOLSET_DEFAULT_DECLARE
    #define MATHEMATICS_TOOLSET_VISIBLE

    #if defined(BUILDING_MATHEMATICS_TOOLSET_EXPORT)

        #define MATHEMATICS_TOOLSET_HIDDEN_DECLARE

    #else  // !defined(BUILDING_MATHEMATICS_TOOLSET_EXPORT)

        #define MATHEMATICS_TOOLSET_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_MATHEMATICS_TOOLSET_EXPORT

#else  // !defined(BUILDING_MATHEMATICS_TOOLSET_NO_IMPORT) && !defined(BUILDING_MATHEMATICS_STATIC)

    #if defined(BUILDING_MATHEMATICS_TOOLSET_EXPORT)

        #define MATHEMATICS_TOOLSET_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define MATHEMATICS_TOOLSET_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_MATHEMATICS_TOOLSET_EXPORT)

        #define MATHEMATICS_TOOLSET_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define MATHEMATICS_TOOLSET_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_MATHEMATICS_TOOLSET_EXPORT

    #define MATHEMATICS_TOOLSET_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_MATHEMATICS_TOOLSET_NO_IMPORT) || defined(BUILDING_MATHEMATICS_STATIC)

#endif  // MATHEMATICS_TOOLSET_DLL_DLL_H
