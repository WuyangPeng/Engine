///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/18 17:12)

#ifndef TEAM_DLL_H
#define TEAM_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_TEAM_NO_IMPORT) || defined(BUILDING_TEAM_STATIC)

    #define TEAM_DEFAULT_DECLARE
    #define TEAM_HIDDEN_DECLARE
    #define TEAM_VISIBLE

#else  // !defined(BUILDING_TEAM_NO_IMPORT) && !defined(BUILDING_TEAM_STATIC)

    #if defined(BUILDING_TEAM_EXPORT)

        #define TEAM_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define TEAM_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_TEAM_EXPORT)

        #define TEAM_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define TEAM_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_TEAM_EXPORT

    #define TEAM_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_TEAM_NO_IMPORT) || defined(BUILDING_TEAM_STATIC)

#endif  // TEAM_DLL_H
