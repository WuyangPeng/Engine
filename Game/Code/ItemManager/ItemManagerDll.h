///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/15 11:06)

#ifndef ITEM_MANAGER_DLL_H
#define ITEM_MANAGER_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_ITEM_MANAGER_NO_IMPORT) || defined(BUILDING_ITEM_MANAGER_STATIC)

    #define ITEM_MANAGER_DEFAULT_DECLARE
    #define ITEM_MANAGER_HIDDEN_DECLARE
    #define ITEM_MANAGER_VISIBLE

#else  // !defined(BUILDING_ITEM_MANAGER_NO_IMPORT) && !defined(BUILDING_ITEM_MANAGER_STATIC)

    #if defined(BUILDING_ITEM_MANAGER_EXPORT)

        #define ITEM_MANAGER_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define ITEM_MANAGER_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_ITEM_MANAGER_EXPORT)

        #define ITEM_MANAGER_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define ITEM_MANAGER_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_ITEM_MANAGER_EXPORT

    #define ITEM_MANAGER_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_ITEM_MANAGER_NO_IMPORT) || defined(BUILDING_ITEM_MANAGER_STATIC)

#endif  // ITEM_MANAGER_DLL_H
