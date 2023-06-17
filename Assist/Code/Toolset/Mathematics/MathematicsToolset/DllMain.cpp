///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.12 (2023/06/09 10:32)

#include "Toolset/Mathematics/MathematicsToolset/MathematicsToolsetExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Toolset/Mathematics/MathematicsToolset/MathematicsToolsetFwd.h"

#ifndef BUILDING_MATHEMATICS_STATIC

DLL_MAIN_FUNCTION(Mathematics);

#else  // !BUILDING_MATHEMATICS_STATIC

CORE_TOOLS_MUTEX_INIT(Mathematics);

#endif  // !BUILDING_MATHEMATICS_STATIC