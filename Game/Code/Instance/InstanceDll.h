///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 15:48)

#ifndef INSTANCE_DLL_H
#define INSTANCE_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_INSTANCE_NO_IMPORT) || defined(BUILDING_INSTANCE_STATIC)

    #define INSTANCE_DEFAULT_DECLARE
    #define INSTANCE_VISIBLE

    #if defined(BUILDING_INSTANCE_EXPORT)

        #define INSTANCE_HIDDEN_DECLARE

    #else  // !defined(BUILDING_INSTANCE_EXPORT)

        #define INSTANCE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_INSTANCE_EXPORT

#else  // !defined(BUILDING_INSTANCE_NO_IMPORT) && !defined(BUILDING_INSTANCE_STATIC)

    #if defined(BUILDING_INSTANCE_EXPORT)

        #define INSTANCE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define INSTANCE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_INSTANCE_EXPORT)

        #define INSTANCE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define INSTANCE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_INSTANCE_EXPORT

    #define INSTANCE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_INSTANCE_NO_IMPORT) || defined(BUILDING_INSTANCE_STATIC)

#endif  // INSTANCE_DLL_H
