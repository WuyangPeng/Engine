///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/05/29 15:03)

#ifndef SCRIPT_DLL_H
#define SCRIPT_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_SCRIPT_NO_IMPORT) || defined(BUILDING_SCRIPT_STATIC)

    #define SCRIPT_DEFAULT_DECLARE
    #define SCRIPT_VISIBLE

    #if defined(BUILDING_SCRIPT_EXPORT)

        #define SCRIPT_HIDDEN_DECLARE

    #else  // !defined(BUILDING_SCRIPT_EXPORT)

        #define SCRIPT_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_SCRIPT_EXPORT

#else  // !defined(BUILDING_SCRIPT_NO_IMPORT) && !defined(BUILDING_SCRIPT_STATIC)

    #if defined(BUILDING_SCRIPT_EXPORT)

        #define SCRIPT_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define SCRIPT_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_SCRIPT_EXPORT)

        #define SCRIPT_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define SCRIPT_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_SCRIPT_EXPORT

    #define SCRIPT_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_SCRIPT_NO_IMPORT) || defined(BUILDING_SCRIPT_STATIC)

#endif  // SCRIPT_DLL_H