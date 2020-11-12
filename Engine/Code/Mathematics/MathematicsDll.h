///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/10/30 13:18)

#ifndef MATHEMATICS_DLL_H
#define MATHEMATICS_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_MATHEMATICS_NO_IMPORT) || defined(BUILDING_MATHEMATICS_STATIC)

    #define MATHEMATICS_DEFAULT_DECLARE
    #define MATHEMATICS_HIDDEN_DECLARE
    #define MATHEMATICS_VISIBLE

#else  // !defined(BUILDING_MATHEMATICS_NO_IMPORT) && !defined(BUILDING_MATHEMATICS_STATIC)

    #if defined(BUILDING_MATHEMATICS_EXPORT)

        #define MATHEMATICS_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define MATHEMATICS_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_MATHEMATICS_EXPORT)

        #define MATHEMATICS_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define MATHEMATICS_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_MATHEMATICS_EXPORT

    #define MATHEMATICS_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_MATHEMATICS_NO_IMPORT) || defined(BUILDING_MATHEMATICS_STATIC)

#endif  // MATHEMATICS_DLL_H