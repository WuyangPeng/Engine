///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.0 (2021/02/16 17:44)

#include "Example/BookCpp/CppCodingStandards/CppCodingStandardsExport.h"

#include "CppCodingStandardsFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CPP_CODING_STANDARDS_STATIC

DLL_MAIN_FUNCTION(CppCodingStandards);

#else  // BUILDING_CPP_CODING_STANDARDS_STATIC

CORE_TOOLS_MUTEX_INIT(CppCodingStandards);

#endif  // !BUILDING_CPP_CODING_STANDARDS_STATIC
