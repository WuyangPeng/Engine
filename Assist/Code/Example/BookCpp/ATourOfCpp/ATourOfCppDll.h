///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/26 21:31)

#ifndef A_TOUR_OF_CPP_DLL_H
#define A_TOUR_OF_CPP_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_A_TOUR_OF_CPP_NO_IMPORT) || defined(BUILDING_A_TOUR_OF_CPP_STATIC)

    #define A_TOUR_OF_CPP_DEFAULT_DECLARE
    #define A_TOUR_OF_CPP_HIDDEN_DECLARE
    #define A_TOUR_OF_CPP_VISIBLE

#else  // !defined(BUILDING_A_TOUR_OF_CPP_NO_IMPORT) && !defined(BUILDING_A_TOUR_OF_CPP_STATIC)

    #if defined(BUILDING_A_TOUR_OF_CPP_EXPORT)

        #define A_TOUR_OF_CPP_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define A_TOUR_OF_CPP_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_A_TOUR_OF_CPP_EXPORT)

        #define A_TOUR_OF_CPP_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define A_TOUR_OF_CPP_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_A_TOUR_OF_CPP_EXPORT

    #define A_TOUR_OF_CPP_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_A_TOUR_OF_CPP_NO_IMPORT) || defined(BUILDING_A_TOUR_OF_CPP_STATIC)

#endif  // A_TOUR_OF_CPP_DLL_H
