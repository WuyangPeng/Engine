///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.8.0.11 (2022/07/18 18:17)

#ifndef MAIL_DLL_H
#define MAIL_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_MAIL_NO_IMPORT) || defined(BUILDING_MAIL_STATIC)

    #define MAIL_DEFAULT_DECLARE
    #define MAIL_HIDDEN_DECLARE
    #define MAIL_VISIBLE

#else  // !defined(BUILDING_MAIL_NO_IMPORT) && !defined(BUILDING_MAIL_STATIC)

    #if defined(BUILDING_MAIL_EXPORT)

        #define MAIL_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define MAIL_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_MAIL_EXPORT)

        #define MAIL_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define MAIL_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_MAIL_EXPORT

    #define MAIL_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_MAIL_NO_IMPORT) || defined(BUILDING_MAIL_STATIC)

#endif  // MAIL_DLL_H
