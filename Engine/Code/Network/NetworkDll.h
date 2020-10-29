//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/26 17:04)

#ifndef NETWORK_DLL_H
#define NETWORK_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_NETWORK_NO_IMPORT) || defined(BUILDING_NETWORK_STATIC)

    #define NETWORK_DEFAULT_DECLARE
    #define NETWORK_HIDDEN_DECLARE
    #define NETWORK_VISIBLE

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
