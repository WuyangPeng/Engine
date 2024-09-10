/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/09 21:58)

#include "CoreToolsExport.h"

#include "CoreToolsFwd.h"
#include "Helper/MainFunctionMacro.h"

#if !defined(BUILDING_CORE_TOOLS_STATIC)

DLL_MAIN_FUNCTION(CoreTools);

#else  // defined(BUILDING_CORE_TOOLS_STATIC)

CORE_TOOLS_MUTEX_INIT(CoreTools);

#endif  // !defined(BUILDING_CORE_TOOLS_STATIC)