///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 13:58)

#ifndef FRAMEWORK_DLL_H
#define FRAMEWORK_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Framework/Helper/UserMacro.h"

#if defined(BUILDING_FRAMEWORK_NO_IMPORT) || defined(BUILDING_FRAMEWORK_STATIC)

    #define FRAMEWORK_DEFAULT_DECLARE
    #define FRAMEWORK_VISIBLE

    #if defined(BUILDING_FRAMEWORK_EXPORT)

        #define FRAMEWORK_HIDDEN_DECLARE

    #else  // !defined(BUILDING_FRAMEWORK_EXPORT)

        #define FRAMEWORK_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_FRAMEWORK_EXPORT

#else  // !defined(BUILDING_FRAMEWORK_NO_IMPORT) && !defined(BUILDING_FRAMEWORK_STATIC)

    #if defined(BUILDING_FRAMEWORK_EXPORT)

        #define FRAMEWORK_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define FRAMEWORK_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_FRAMEWORK_EXPORT)

        #define FRAMEWORK_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define FRAMEWORK_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_FRAMEWORK_EXPORT

    #define FRAMEWORK_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_FRAMEWORK_NO_IMPORT) || defined(BUILDING_FRAMEWORK_STATIC)

#endif  // FRAMEWORK_DLL_H
