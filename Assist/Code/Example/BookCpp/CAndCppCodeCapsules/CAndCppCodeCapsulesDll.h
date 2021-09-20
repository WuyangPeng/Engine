///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/01 14:25)

#ifndef C_AND_CPP_CODE_CAPSULES_DLL_H
#define C_AND_CPP_CODE_CAPSULES_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_C_AND_CPP_CODE_CAPSULES_NO_IMPORT) || defined(BUILDING_C_AND_CPP_CODE_CAPSULES_STATIC)

    #define C_AND_CPP_CODE_CAPSULES_DEFAULT_DECLARE
    #define C_AND_CPP_CODE_CAPSULES_HIDDEN_DECLARE
    #define C_AND_CPP_CODE_CAPSULES_VISIBLE

#else  // !defined(BUILDING_C_AND_CPP_CODE_CAPSULES_NO_IMPORT) && !defined(BUILDING_C_AND_CPP_CODE_CAPSULES_STATIC)

    #if defined(BUILDING_C_AND_CPP_CODE_CAPSULES_EXPORT)

        #define C_AND_CPP_CODE_CAPSULES_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define C_AND_CPP_CODE_CAPSULES_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_C_AND_CPP_CODE_CAPSULES_EXPORT)

        #define C_AND_CPP_CODE_CAPSULES_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define C_AND_CPP_CODE_CAPSULES_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_C_AND_CPP_CODE_CAPSULES_EXPORT

    #define C_AND_CPP_CODE_CAPSULES_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_C_AND_CPP_CODE_CAPSULES_NO_IMPORT) || defined(BUILDING_C_AND_CPP_CODE_CAPSULES_STATIC)

#endif  // C_AND_CPP_CODE_CAPSULES_DLL_H
