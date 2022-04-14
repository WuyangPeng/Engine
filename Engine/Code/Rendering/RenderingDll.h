///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/03/28 16:11)

#ifndef RENDERING_DLL_H
#define RENDERING_DLL_H

#include "System/Helper/ExportMacro.h"

#include "Helper/UserMacro.h"

#if defined(BUILDING_RENDERING_NO_IMPORT) || defined(BUILDING_RENDERING_STATIC)

    #define RENDERING_DEFAULT_DECLARE
    #define RENDERING_VISIBLE

    #if defined(BUILDING_RENDERING_EXPORT)

        #define RENDERING_HIDDEN_DECLARE

    #else  // !defined(BUILDING_RENDERING_EXPORT)

        #define RENDERING_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_RENDERING_EXPORT

#else  // !defined(BUILDING_RENDERING_NO_IMPORT) && !defined(BUILDING_RENDERING_STATIC)

    #if defined(BUILDING_RENDERING_EXPORT)

        #define RENDERING_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define RENDERING_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_RENDERING_EXPORT)

        #define RENDERING_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define RENDERING_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_RENDERING_EXPORT

    #define RENDERING_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_RENDERING_NO_IMPORT) || defined(BUILDING_RENDERING_STATIC)

#endif  // RENDERING_DLL_H