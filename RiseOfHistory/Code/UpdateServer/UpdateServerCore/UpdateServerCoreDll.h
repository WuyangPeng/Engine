/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.0 (2023/11/19 00:20)

#ifndef UPDATE_SERVER_CORE_DLL_H
#define UPDATE_SERVER_CORE_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_UPDATE_SERVER_CORE_NO_IMPORT) || defined(BUILDING_UPDATE_SERVER_CORE_STATIC)

    #define UPDATE_SERVER_CORE_DEFAULT_DECLARE
    #define UPDATE_SERVER_CORE_VISIBLE

    #if defined(BUILDING_UPDATE_SERVER_CORE_EXPORT)

        #define UPDATE_SERVER_CORE_HIDDEN_DECLARE

    #else  // !defined(BUILDING_UPDATE_SERVER_CORE_EXPORT)

        #define UPDATE_SERVER_CORE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_UPDATE_SERVER_CORE_EXPORT

#else  // !defined(BUILDING_UPDATE_SERVER_CORE_NO_IMPORT) && !defined(BUILDING_UPDATE_SERVER_CORE_STATIC)

    #if defined(BUILDING_UPDATE_SERVER_CORE_EXPORT)

        #define UPDATE_SERVER_CORE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define UPDATE_SERVER_CORE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_UPDATE_SERVER_CORE_EXPORT)

        #define UPDATE_SERVER_CORE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define UPDATE_SERVER_CORE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_UPDATE_SERVER_CORE_EXPORT

    #define UPDATE_SERVER_CORE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_UPDATE_SERVER_CORE_NO_IMPORT) || defined(BUILDING_UPDATE_SERVER_CORE_STATIC)

#endif  // UPDATE_SERVER_CORE_DLL_H