/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/10 19:35)

#include "Animation/AnimationExport.h"

#include "Animation/AnimationFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ANIMATION_STATIC

DLL_MAIN_FUNCTION(Animation);

#else  // !BUILDING_ANIMATION_STATIC

CORE_TOOLS_MUTEX_INIT(Animation);

#endif  // BUILDING_ANIMATION_STATIC