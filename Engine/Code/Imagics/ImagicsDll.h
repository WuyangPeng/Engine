///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/04/25 16:43)

#ifndef IMAGICS_DLL_H
#define IMAGICS_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_IMAGICS_NO_IMPORT) || defined(BUILDING_IMAGICS_STATIC)

    #define IMAGICS_DEFAULT_DECLARE
    #define IMAGICS_VISIBLE

    #if defined(BUILDING_IMAGICS_EXPORT)

        #define IMAGICS_HIDDEN_DECLARE

    #else  // !defined(BUILDING_IMAGICS_EXPORT)

        #define IMAGICS_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_IMAGICS_EXPORT

#else  // !defined(BUILDING_IMAGICS_NO_IMPORT) && !defined(BUILDING_IMAGICS_STATIC)

    #if defined(BUILDING_IMAGICS_EXPORT)

        #define IMAGICS_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define IMAGICS_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_IMAGICS_EXPORT)

        #define IMAGICS_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define IMAGICS_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_IMAGICS_EXPORT

    #define IMAGICS_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_IMAGICS_NO_IMPORT) || defined(BUILDING_IMAGICS_STATIC)

#endif  // IMAGICS_DLL_H