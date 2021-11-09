///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.5 (2021/10/28 22:19)

#include "Example/BookOperatingSystem/CppMultithreadingCookbook/CppMultithreadingCookbookExport.h"

#include "CppMultithreadingCookbookFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CPP_MULTITHREADING_COOKBOOK_STATIC

DLL_MAIN_FUNCTION(CppMultithreadingCookbook);

#else  // !BUILDING_CPP_MULTITHREADING_COOKBOOK_STATIC

CORE_TOOLS_MUTEX_INIT(CppMultithreadingCookbook);

#endif  // BUILDING_CPP_MULTITHREADING_COOKBOOK_STATIC
