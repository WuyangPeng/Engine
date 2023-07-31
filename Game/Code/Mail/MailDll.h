///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 16:06)

#ifndef MAIL_DLL_H
#define MAIL_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_MAIL_NO_IMPORT) || defined(BUILDING_MAIL_STATIC)

    #define MAIL_DEFAULT_DECLARE
    #define MAIL_VISIBLE

    #if defined(BUILDING_MAIL_EXPORT)

        #define MAIL_HIDDEN_DECLARE

    #else  // !defined(BUILDING_MAIL_EXPORT)

        #define MAIL_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_MAIL_EXPORT

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
