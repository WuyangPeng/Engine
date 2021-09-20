///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.1 (2020/12/31 23:05)

#include "Example/BookCpp/CppProgramming/CppProgrammingExport.h"

#include "CppProgrammingFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CPP_PROGRAMMING_STATIC

DLL_MAIN_FUNCTION(CppProgramming);

#else  // BUILDING_CPP_PROGRAMMING_STATIC

CORE_TOOLS_MUTEX_INIT(CppProgramming);

#endif  // !BUILDING_CPP_PROGRAMMING_STATIC
