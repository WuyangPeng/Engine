// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 17:39)

#include "Framework/FrameworkExport.h"

#include "Framework/FrameworkFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_FRAMEWORK_STATIC

	DLL_MAIN_FUNCTION(Framework);

#else // !BUILDING_FRAMEWORK_STATIC

	CORE_TOOLS_MUTEX_INIT(Framework);

#endif // !BUILDING_FRAMEWORK_STATIC