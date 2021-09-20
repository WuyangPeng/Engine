///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 14:25)

#ifndef EXPORT_TEST_DLL_H
#define EXPORT_TEST_DLL_H

#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_STATIC)

    #define EXPORT_TEST_DEFAULT_DECLARE
    #define EXPORT_TEST_VISIBLE

    #if defined(BUILDING_EXPORT_TEST_EXPORT)

        #define EXPORT_TEST_HIDDEN_DECLARE

    #else  // !defined(BUILDING_EXPORT_TEST_EXPORT)

        #define EXPORT_TEST_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_EXPORT_TEST_EXPORT

#else  // !defined(BUILDING_STATIC)

    #if defined(BUILDING_EXPORT_TEST_EXPORT)

        #define EXPORT_TEST_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define EXPORT_TEST_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_EXPORT_TEST_EXPORT)

        #define EXPORT_TEST_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define EXPORT_TEST_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_EXPORT_TEST_EXPORT

    #define EXPORT_TEST_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_STATIC)

#endif  // EXPORT_TEST_DLL_H