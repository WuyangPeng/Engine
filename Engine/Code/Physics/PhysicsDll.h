///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 16:34)

#ifndef PHYSICS_DLL_H
#define PHYSICS_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_PHYSICS_NO_IMPORT) || defined(BUILDING_PHYSICS_STATIC)

    #define PHYSICS_DEFAULT_DECLARE
    #define PHYSICS_VISIBLE

    #if defined(BUILDING_PHYSICS_EXPORT)

        #define PHYSICS_HIDDEN_DECLARE

    #else  // !defined(BUILDING_PHYSICS_EXPORT)

        #define PHYSICS_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_PHYSICS_EXPORT

#else  // !defined(BUILDING_PHYSICS_NO_IMPORT) && !defined(BUILDING_PHYSICS_STATIC)

    #if defined(BUILDING_PHYSICS_EXPORT)

        #define PHYSICS_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define PHYSICS_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_PHYSICS_EXPORT)

        #define PHYSICS_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define PHYSICS_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_PHYSICS_EXPORT

    #define SYSTEM_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_PHYSICS_NO_IMPORT) || defined(BUILDING_PHYSICS_STATIC)

#endif  // PHYSICS_DLL_H
