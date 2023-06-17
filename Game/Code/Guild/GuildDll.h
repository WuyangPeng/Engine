///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.9.0.12 (2023/06/16 16:56)

#ifndef GUILD_DLL_H
#define GUILD_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_GUILD_NO_IMPORT) || defined(BUILDING_GUILD_STATIC)

    #define GUILD_DEFAULT_DECLARE
    #define GUILD_VISIBLE

    #if defined(BUILDING_GUILD_EXPORT)

        #define GUILD_HIDDEN_DECLARE

    #else  // !defined(BUILDING_GUILD_EXPORT)

        #define GUILD_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_GUILD_EXPORT

#else  // !defined(BUILDING_GUILD_NO_IMPORT) && !defined(BUILDING_GUILD_STATIC)

    #if defined(BUILDING_GUILD_EXPORT)

        #define GUILD_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define GUILD_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_GUILD_EXPORT)

        #define GUILD_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define GUILD_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_GUILD_EXPORT

    #define GUILD_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_GUILD_NO_IMPORT) || defined(BUILDING_GUILD_STATIC)

#endif  // GUILD_DLL_H
