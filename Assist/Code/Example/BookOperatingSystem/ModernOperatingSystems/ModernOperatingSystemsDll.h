///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.7 (2021/12/06 21:22)

#ifndef MODERN_OPERATING_SYSTEMS_DLL_H
#define MODERN_OPERATING_SYSTEMS_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_MODERN_OPERATING_SYSTEMS_NO_IMPORT) || defined(BUILDING_MODERN_OPERATING_SYSTEMS_STATIC)

    #define MODERN_OPERATING_SYSTEMS_DEFAULT_DECLARE
    #define MODERN_OPERATING_SYSTEMS_VISIBLE

    #if defined(BUILDING_MODERN_OPERATING_SYSTEMS_EXPORT)

        #define MODERN_OPERATING_SYSTEMS_HIDDEN_DECLARE

    #else  // !defined(BUILDING_MODERN_OPERATING_SYSTEMS_EXPORT)

        #define MODERN_OPERATING_SYSTEMS_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_MODERN_OPERATING_SYSTEMS_EXPORT

#else  // !defined(BUILDING_MODERN_OPERATING_SYSTEMS_NO_IMPORT) && !defined(BUILDING_MODERN_OPERATING_SYSTEMS_STATIC)

    #if defined(BUILDING_MODERN_OPERATING_SYSTEMS_EXPORT)

        #define MODERN_OPERATING_SYSTEMS_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define MODERN_OPERATING_SYSTEMS_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_MODERN_OPERATING_SYSTEMS_EXPORT)

        #define MODERN_OPERATING_SYSTEMS_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define MODERN_OPERATING_SYSTEMS_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_MODERN_OPERATING_SYSTEMS_EXPORT

    #define MODERN_OPERATING_SYSTEMS_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_MODERN_OPERATING_SYSTEMS_NO_IMPORT) || defined(BUILDING_MODERN_OPERATING_SYSTEMS_STATIC)

#endif  // MODERN_OPERATING_SYSTEMS_DLL_H