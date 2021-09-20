///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/26 1:16)

#include "Example/BookCpp/CppHowToProgramNinthEdition/CppHowToProgramNinthEditionExport.h"

#include "CppHowToProgramNinthEditionFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CPP_HOW_TO_PROGRAM_NINTH_EDITION_STATIC

DLL_MAIN_FUNCTION(CppHowToProgramNinthEdition);

#else  // BUILDING_CPP_HOW_TO_PROGRAM_NINTH_EDITION_STATIC

CORE_TOOLS_MUTEX_INIT(CppHowToProgramNinthEdition);

#endif  // !BUILDING_CPP_HOW_TO_PROGRAM_NINTH_EDITION_STATIC
