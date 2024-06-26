///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 13:46)

#ifndef FRAMEWORK_EXAMPLE_DLL_DLL_H
#define FRAMEWORK_EXAMPLE_DLL_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_FRAMEWORK_EXAMPLE_NO_IMPORT) || defined(BUILDING_FRAMEWORK_EXAMPLE_STATIC)

    #define FRAMEWORK_EXAMPLE_DEFAULT_DECLARE
    #define FRAMEWORK_EXAMPLE_VISIBLE

    #if defined(BUILDING_FRAMEWORK_EXAMPLE_EXPORT)

        #define FRAMEWORK_EXAMPLE_HIDDEN_DECLARE

    #else  // !defined(BUILDING_FRAMEWORK_EXAMPLE_EXPORT)

        #define FRAMEWORK_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_FRAMEWORK_EXAMPLE_EXPORT

#else  // !defined(BUILDING_FRAMEWORK_EXAMPLE_NO_IMPORT) && !defined(BUILDING_FRAMEWORK_EXAMPLE_STATIC)

    #if defined(BUILDING_FRAMEWORK_EXAMPLE_EXPORT)

        #define FRAMEWORK_EXAMPLE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define FRAMEWORK_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_FRAMEWORK_EXAMPLE_EXPORT)

        #define FRAMEWORK_EXAMPLE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define FRAMEWORK_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_FRAMEWORK_EXAMPLE_EXPORT

    #define FRAMEWORK_EXAMPLE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_FRAMEWORK_EXAMPLE_NO_IMPORT) || defined(BUILDING_FRAMEWORK_EXAMPLE_STATIC)

#endif  // FRAMEWORK_EXAMPLE_DLL_DLL_H
