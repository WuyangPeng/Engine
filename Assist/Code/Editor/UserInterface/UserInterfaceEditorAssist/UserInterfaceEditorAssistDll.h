///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/15 13:33)

#ifndef USER_INTERFACE_EDITOR_DLL_DLL_H
#define USER_INTERFACE_EDITOR_DLL_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_USER_INTERFACE_EDITOR_NO_IMPORT) || defined(BUILDING_USER_INTERFACE_EDITOR_STATIC)

    #define USER_INTERFACE_EDITOR_DEFAULT_DECLARE
    #define USER_INTERFACE_EDITOR_VISIBLE

    #if defined(BUILDING_USER_INTERFACE_EDITOR_EXPORT)

        #define USER_INTERFACE_EDITOR_HIDDEN_DECLARE

    #else  // !defined(BUILDING_USER_INTERFACE_EDITOR_EXPORT)

        #define USER_INTERFACE_EDITOR_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_USER_INTERFACE_EDITOR_EXPORT

#else  // !defined(BUILDING_USER_INTERFACE_EDITOR_NO_IMPORT) && !defined(BUILDING_USER_INTERFACE_EDITOR_STATIC)

    #if defined(BUILDING_USER_INTERFACE_EDITOR_EXPORT)

        #define USER_INTERFACE_EDITOR_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define USER_INTERFACE_EDITOR_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_USER_INTERFACE_EDITOR_EXPORT)

        #define USER_INTERFACE_EDITOR_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define USER_INTERFACE_EDITOR_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_USER_INTERFACE_EDITOR_EXPORT

    #define USER_INTERFACE_EDITOR_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_USER_INTERFACE_EDITOR_NO_IMPORT) || defined(BUILDING_USER_INTERFACE_EDITOR_STATIC)

#endif  // USER_INTERFACE_EDITOR_DLL_DLL_H
