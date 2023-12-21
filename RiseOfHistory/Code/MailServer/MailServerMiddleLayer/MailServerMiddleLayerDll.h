/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/17 19:45)

#ifndef MAIL_SERVER_MIDDLE_LAYER_DLL_H
#define MAIL_SERVER_MIDDLE_LAYER_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_MAIL_SERVER_MIDDLE_LAYER_NO_IMPORT) || defined(BUILDING_MAIL_SERVER_MIDDLE_LAYER_STATIC)

    #define MAIL_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE
    #define MAIL_SERVER_MIDDLE_LAYER_VISIBLE

    #if defined(BUILDING_MAIL_SERVER_MIDDLE_LAYER_EXPORT)

        #define MAIL_SERVER_MIDDLE_LAYER_HIDDEN_DECLARE

    #else  // !defined(BUILDING_MAIL_SERVER_MIDDLE_LAYER_EXPORT)

        #define MAIL_SERVER_MIDDLE_LAYER_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_MAIL_SERVER_MIDDLE_LAYER_EXPORT

#else  // !defined(BUILDING_MAIL_SERVER_MIDDLE_LAYER_NO_IMPORT) && !defined(BUILDING_MAIL_SERVER_MIDDLE_LAYER_STATIC)

    #if defined(BUILDING_MAIL_SERVER_MIDDLE_LAYER_EXPORT)

        #define MAIL_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define MAIL_SERVER_MIDDLE_LAYER_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_MAIL_SERVER_MIDDLE_LAYER_EXPORT)

        #define MAIL_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define MAIL_SERVER_MIDDLE_LAYER_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_MAIL_SERVER_MIDDLE_LAYER_EXPORT

    #define MAIL_SERVER_MIDDLE_LAYER_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_MAIL_SERVER_MIDDLE_LAYER_NO_IMPORT) || defined(BUILDING_MAIL_SERVER_MIDDLE_LAYER_STATIC)

#endif  // MAIL_SERVER_MIDDLE_LAYER_DLL_H