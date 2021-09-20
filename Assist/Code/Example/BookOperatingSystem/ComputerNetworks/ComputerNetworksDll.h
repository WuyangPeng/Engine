///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.2 (2021/08/27 22:22)

#ifndef COMPUTER_NETWORKS_DLL_H
#define COMPUTER_NETWORKS_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_COMPUTER_NETWORKS_NO_IMPORT) || defined(BUILDING_COMPUTER_NETWORKS_STATIC)

    #define COMPUTER_NETWORKS_DEFAULT_DECLARE
    #define COMPUTER_NETWORKS_VISIBLE

    #if defined(BUILDING_COMPUTER_NETWORKS_EXPORT)

        #define COMPUTER_NETWORKS_HIDDEN_DECLARE

    #else  // !defined(BUILDING_COMPUTER_NETWORKS_EXPORT)

        #define COMPUTER_NETWORKS_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_COMPUTER_NETWORKS_EXPORT

#else  // !defined(BUILDING_COMPUTER_NETWORKS_NO_IMPORT) && !defined(BUILDING_COMPUTER_NETWORKS_STATIC)

    #if defined(BUILDING_COMPUTER_NETWORKS_EXPORT)

        #define COMPUTER_NETWORKS_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define COMPUTER_NETWORKS_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_COMPUTER_NETWORKS_EXPORT)

        #define COMPUTER_NETWORKS_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define COMPUTER_NETWORKS_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_COMPUTER_NETWORKS_EXPORT

    #define COMPUTER_NETWORKS_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_COMPUTER_NETWORKS_NO_IMPORT) || defined(BUILDING_COMPUTER_NETWORKS_STATIC)

#endif  // COMPUTER_NETWORKS_DLL_H