///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/10/30 13:19)

#include "Mathematics/MathematicsExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Mathematics/MathematicsFwd.h"

#ifndef BUILDING_MATHEMATICS_STATIC

DLL_MAIN_FUNCTION(Mathematics);

#else  // !BUILDING_MATHEMATICS_STATIC

CORE_TOOLS_MUTEX_INIT(Mathematics);

#endif  // !BUILDING_MATHEMATICS_STATIC