///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/18 16:32)

#include "Framework/FrameworkExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Framework/FrameworkFwd.h"

#ifndef BUILDING_FRAMEWORK_STATIC

DLL_MAIN_FUNCTION(Framework);

#else  // !BUILDING_FRAMEWORK_STATIC

CORE_TOOLS_MUTEX_INIT(Framework);

#endif  // !BUILDING_FRAMEWORK_STATIC
