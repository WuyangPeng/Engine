///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.0 (2021/01/23 16:05)

#include "Example/BookCpp/ProfessionalCpp/ProfessionalCppExport.h"

#include "ProfessionalCppFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_PROFESSIONAL_CPP_STATIC

DLL_MAIN_FUNCTION(ProfessionalCpp);

#else  // BUILDING_PROFESSIONAL_CPP_STATIC

CORE_TOOLS_MUTEX_INIT(ProfessionalCpp);

#endif  // !BUILDING_PROFESSIONAL_CPP_STATIC
