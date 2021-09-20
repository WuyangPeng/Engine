///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/11 17:52)

#ifndef THE_ART_OF_CPP_DLL_H
#define THE_ART_OF_CPP_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_THE_ART_OF_CPP_NO_IMPORT) || defined(BUILDING_THE_ART_OF_CPP_STATIC)

    #define THE_ART_OF_CPP_DEFAULT_DECLARE
    #define THE_ART_OF_CPP_VISIBLE

    #if defined(BUILDING_THE_ART_OF_CPP_EXPORT)

        #define THE_ART_OF_CPP_HIDDEN_DECLARE

    #else  // !defined(BUILDING_THE_ART_OF_CPP_EXPORT)

        #define THE_ART_OF_CPP_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_THE_ART_OF_CPP_EXPORT

#else  // !defined(BUILDING_THE_ART_OF_CPP_NO_IMPORT) && !defined(BUILDING_THE_ART_OF_CPP_STATIC)

    #if defined(BUILDING_THE_ART_OF_CPP_EXPORT)

        #define THE_ART_OF_CPP_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define THE_ART_OF_CPP_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_THE_ART_OF_CPP_EXPORT)

        #define THE_ART_OF_CPP_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define THE_ART_OF_CPP_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_THE_ART_OF_CPP_EXPORT

    #define THE_ART_OF_CPP_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_THE_ART_OF_CPP_NO_IMPORT) || defined(BUILDING_THE_ART_OF_CPP_STATIC)

#endif  // THE_ART_OF_CPP_DLL_H
