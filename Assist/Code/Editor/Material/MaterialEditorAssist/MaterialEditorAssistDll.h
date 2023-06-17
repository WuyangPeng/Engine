///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/15 15:28)

#ifndef MATERIAL_EDITOR_DLL_DLL_H
#define MATERIAL_EDITOR_DLL_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_MATERIAL_EDITOR_NO_IMPORT) || defined(BUILDING_MATERIAL_EDITOR_STATIC)

    #define MATERIAL_EDITOR_DEFAULT_DECLARE
    #define MATERIAL_EDITOR_VISIBLE

    #if defined(BUILDING_MATERIAL_EDITOR_EXPORT)

        #define MATERIAL_EDITOR_HIDDEN_DECLARE

    #else  // !defined(BUILDING_MATERIAL_EDITOR_EXPORT)

        #define MATERIAL_EDITOR_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_MATERIAL_EDITOR_EXPORT

#else  // !defined(BUILDING_MATERIAL_EDITOR_NO_IMPORT) && !defined(BUILDING_MATERIAL_EDITOR_STATIC)

    #if defined(BUILDING_MATERIAL_EDITOR_EXPORT)

        #define MATERIAL_EDITOR_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define MATERIAL_EDITOR_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_MATERIAL_EDITOR_EXPORT)

        #define MATERIAL_EDITOR_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define MATERIAL_EDITOR_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_MATERIAL_EDITOR_EXPORT

    #define MATERIAL_EDITOR_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_MATERIAL_EDITORNO_IMPORT) || defined(BUILDING_MATERIAL_EDITOR_STATIC)

#endif  // MATERIAL_EDITOR_DLL_DLL_H
