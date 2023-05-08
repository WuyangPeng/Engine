///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.7 (2023/04/27 14:33)

#ifndef NETWORK_DLL_H
#define NETWORK_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_NETWORK_NO_IMPORT) || defined(BUILDING_NETWORK_STATIC)

    #define NETWORK_DEFAULT_DECLARE
    #define NETWORK_VISIBLE

    #if defined(BUILDING_NETWORK_EXPORT)

        #define NETWORK_HIDDEN_DECLARE

    #else  // !defined(BUILDING_NETWORK_EXPORT)

        #define NETWORK_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_NETWORK_EXPORT

#else  // !defined(BUILDING_NETWORK_NO_IMPORT) && !defined(BUILDING_NETWORK_STATIC)

    #if defined(BUILDING_NETWORK_EXPORT)

        #define NETWORK_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define NETWORK_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_NETWORK_EXPORT)

        #define NETWORK_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define NETWORK_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_NETWORK_EXPORT

    #define SYSTEM_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_NETWORK_NO_IMPORT) || defined(BUILDING_NETWORK_STATIC)

#endif  // NETWORK_DLL_H
