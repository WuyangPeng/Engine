///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/10/07 23:21)

#include "Example/BookOperatingSystem/SafeCpp/SafeCppExport.h"

#include "SafeCppFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SAFE_CPP_STATIC

DLL_MAIN_FUNCTION(SafeCpp);

#else  // !BUILDING_SAFE_CPP_STATIC

CORE_TOOLS_MUTEX_INIT(SafeCpp);

#endif  // BUILDING_SAFE_CPP_STATIC
