/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 19:36)

#include "Mathematics/MathematicsExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Mathematics/MathematicsFwd.h"

#ifndef BUILDING_MATHEMATICS_STATIC

DLL_MAIN_FUNCTION(Mathematics);

#else  // !BUILDING_MATHEMATICS_STATIC

CORE_TOOLS_MUTEX_INIT(Mathematics);

#endif  // !BUILDING_MATHEMATICS_STATIC