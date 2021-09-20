///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.1 (2021/01/13 23:17)

#include "Example/BookCpp/CppCookbook/CppCookbookExport.h"

#include "CppCookbookFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CPP_COOKBOOK_STATIC

DLL_MAIN_FUNCTION(CppCookbook);

#else  // BUILDING_CPP_COOKBOOK_STATIC

CORE_TOOLS_MUTEX_INIT(CppCookbook);

#endif  // !BUILDING_CPP_COOKBOOK_STATIC
