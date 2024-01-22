/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 19:36)

#include "Mathematics/MathematicsExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Mathematics/MathematicsFwd.h"

#ifndef BUILDING_MATHEMATICS_STATIC

DLL_MAIN_FUNCTION(Mathematics);

#else  // !BUILDING_MATHEMATICS_STATIC

CORE_TOOLS_MUTEX_INIT(Mathematics);

#endif  // !BUILDING_MATHEMATICS_STATIC