// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 09:47)

#include "Animation/AnimationExport.h"

#include "Animation/AnimationFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ANIMATION_STATIC

	DLL_MAIN_FUNCTION(Animation);

#else // !BUILDING_ANIMATION_STATIC

	CORE_TOOLS_MUTEX_INIT(Animation);

#endif // !BUILDING_ANIMATION_STATIC