///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.8.0.11 (2022/07/18 14:34)

#ifndef STATUSDLL_H
#define STATUSDLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_STATUSNO_IMPORT) || defined(BUILDING_STATUSSTATIC)

    #define STATUSDEFAULT_DECLARE
    #define STATUSHIDDEN_DECLARE
    #define STATUSVISIBLE

#else  // !defined(BUILDING_STATUSNO_IMPORT) && !defined(BUILDING_STATUSSTATIC)

    #if defined(BUILDING_STATUSEXPORT)

        #define STATUSDEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define STATUSHIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_STATUSEXPORT)

        #define STATUSDEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define STATUSHIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_STATUSEXPORT

    #define STATUSVISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_STATUSNO_IMPORT) || defined(BUILDING_STATUSSTATIC)

#endif  // STATUSDLL_H
