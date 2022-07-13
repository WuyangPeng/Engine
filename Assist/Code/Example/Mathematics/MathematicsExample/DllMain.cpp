///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/12 15:06)

#include "Example/Mathematics/MathematicsExample/MathematicsExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/Mathematics/MathematicsExample/MathematicsExampleFwd.h"

#ifndef BUILDING_MATHEMATICS_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(MathematicsExample);

#else  // !BUILDING_MATHEMATICS_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(MathematicsExample);

#endif  // !BUILDING_MATHEMATICS_EXAMPLE_STATIC
