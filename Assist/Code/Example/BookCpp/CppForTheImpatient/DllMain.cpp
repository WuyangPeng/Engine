///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/26 21:29)

#include "Example/BookCpp/CppForTheImpatient/CppForTheImpatientExport.h"

#include "CppForTheImpatientFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CPP_FOR_THE_IMPATIENT_STATIC

DLL_MAIN_FUNCTION(CppForTheImpatient);

#else  // BUILDING_CPP_FOR_THE_IMPATIENT_STATIC

CORE_TOOLS_MUTEX_INIT(CppForTheImpatient);

#endif  // !BUILDING_CPP_FOR_THE_IMPATIENT_STATIC
