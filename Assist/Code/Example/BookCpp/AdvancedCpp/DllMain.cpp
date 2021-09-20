///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.1.0 (2021/01/21 23:03)

#include "Example/BookCpp/AdvancedCpp/AdvancedCppExport.h"

#include "AdvancedCppFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ADVANCED_CPP_STATIC

DLL_MAIN_FUNCTION(AdvancedCpp);

#else  // BUILDING_ADVANCED_CPP_STATIC

CORE_TOOLS_MUTEX_INIT(AdvancedCpp);

#endif  // !BUILDING_ADVANCED_CPP_STATIC
