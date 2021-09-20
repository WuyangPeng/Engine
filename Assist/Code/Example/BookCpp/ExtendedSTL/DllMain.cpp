///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/02/28 19:36)

#include "Example/BookCpp/ExtendedSTL/ExtendedSTLExport.h"

#include "ExtendedSTLFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_EXTENDED_STL_STATIC

DLL_MAIN_FUNCTION(ExtendedSTL);

#else  // BUILDING_EXTENDED_STL_STATIC

CORE_TOOLS_MUTEX_INIT(ExtendedSTL);

#endif  // !BUILDING_EXTENDED_STL_STATIC
