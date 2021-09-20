///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/27 18:47)

#ifndef CPP_A_DIALOG_DLL_H
#define CPP_A_DIALOG_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_CPP_A_DIALOG_NO_IMPORT) || defined(BUILDING_CPP_A_DIALOG_STATIC)

    #define CPP_A_DIALOG_DEFAULT_DECLARE
    #define CPP_A_DIALOG_HIDDEN_DECLARE
    #define CPP_A_DIALOG_VISIBLE

#else  // !defined(BUILDING_CPP_A_DIALOG_NO_IMPORT) && !defined(BUILDING_CPP_A_DIALOG_STATIC)

    #if defined(BUILDING_CPP_A_DIALOG_EXPORT)

        #define CPP_A_DIALOG_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define CPP_A_DIALOG_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_CPP_A_DIALOG_EXPORT)

        #define CPP_A_DIALOG_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define CPP_A_DIALOG_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_CPP_A_DIALOG_EXPORT

    #define CPP_A_DIALOG_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_CPP_A_DIALOG_NO_IMPORT) || defined(BUILDING_CPP_A_DIALOG_STATIC)

#endif  // CPP_A_DIALOG_DLL_H
