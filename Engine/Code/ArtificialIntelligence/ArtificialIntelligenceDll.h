///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 19:29)

#ifndef ARTIFICIAL_INTELLIGENCE_DLL_H
#define ARTIFICIAL_INTELLIGENCE_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_ARTIFICIAL_INTELLIGENCE_NO_IMPORT) || defined(BUILDING_ARTIFICIAL_INTELLIGENCE_STATIC)

    #define ARTIFICIAL_INTELLIGENCE_DEFAULT_DECLARE
    #define ARTIFICIAL_INTELLIGENCE_VISIBLE

    #if defined(BUILDING_ARTIFICIAL_INTELLIGENCE_EXPORT)

        #define ARTIFICIAL_INTELLIGENCE_HIDDEN_DECLARE

    #else  // !defined(BUILDING_ARTIFICIAL_INTELLIGENCE_EXPORT)

        #define ARTIFICIAL_INTELLIGENCE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_ARTIFICIAL_INTELLIGENCE_EXPORT

#else  // !defined(BUILDING_ARTIFICIAL_INTELLIGENCE_NO_IMPORT) && !defined(BUILDING_ARTIFICIAL_INTELLIGENCE_STATIC)

    #if defined(BUILDING_ARTIFICIAL_INTELLIGENCE_EXPORT)

        #define ARTIFICIAL_INTELLIGENCE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define ARTIFICIAL_INTELLIGENCE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_ARTIFICIAL_INTELLIGENCE_EXPORT)

        #define ARTIFICIAL_INTELLIGENCE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define ARTIFICIAL_INTELLIGENCE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_ARTIFICIAL_INTELLIGENCE_EXPORT

    #define ARTIFICIAL_INTELLIGENCE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_ARTIFICIAL_INTELLIGENCE_NO_IMPORT) || defined(BUILDING_ARTIFICIAL_INTELLIGENCE_STATIC)

#endif  // ARTIFICIAL_INTELLIGENCE_DLL_H