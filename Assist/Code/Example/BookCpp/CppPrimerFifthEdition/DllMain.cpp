///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/24 22:45)

#include "Example/BookCpp/CppPrimerFifthEdition/CppPrimerFifthEditionExport.h"

#include "CppPrimerFifthEditionFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CPP_PRIMER_FIFTH_EDITION_STATIC

DLL_MAIN_FUNCTION(CppPrimerFifthEdition);

#else  // BUILDING_CPP_PRIMER_FIFTH_EDITION_STATIC

CORE_TOOLS_MUTEX_INIT(CppPrimerFifthEdition);

#endif  // !BUILDING_CPP_PRIMER_FIFTH_EDITION_STATIC
