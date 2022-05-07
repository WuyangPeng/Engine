///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/22 21:07)

#ifndef CRYPTOGRAPHY_AND_NETWORK_SECURITY_DLL_H
#define CRYPTOGRAPHY_AND_NETWORK_SECURITY_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_CRYPTOGRAPHY_AND_NETWORK_SECURITY_NO_IMPORT) || defined(BUILDING_CRYPTOGRAPHY_AND_NETWORK_SECURITY_STATIC)

    #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_DEFAULT_DECLARE
    #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_VISIBLE

    #if defined(BUILDING_CRYPTOGRAPHY_AND_NETWORK_SECURITY_EXPORT)

        #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_HIDDEN_DECLARE

    #else  // !defined(BUILDING_CRYPTOGRAPHY_AND_NETWORK_SECURITY_EXPORT)

        #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_CRYPTOGRAPHY_AND_NETWORK_SECURITY_EXPORT

#else  // !defined(BUILDING_CRYPTOGRAPHY_AND_NETWORK_SECURITY_NO_IMPORT) && !defined(BUILDING_CRYPTOGRAPHY_AND_NETWORK_SECURITY_STATIC)

    #if defined(BUILDING_CRYPTOGRAPHY_AND_NETWORK_SECURITY_EXPORT)

        #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_CRYPTOGRAPHY_AND_NETWORK_SECURITY_EXPORT)

        #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_CRYPTOGRAPHY_AND_NETWORK_SECURITY_EXPORT

    #define CRYPTOGRAPHY_AND_NETWORK_SECURITY_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_CRYPTOGRAPHY_AND_NETWORK_SECURITY_NO_IMPORT) || defined(BUILDING_CRYPTOGRAPHY_AND_NETWORK_SECURITY_STATIC)

#endif  // CRYPTOGRAPHY_AND_NETWORK_SECURITY_DLL_H