// Copyright (c) 2010-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.3.0.1 (2020/05/19 23:45)

#include "Framework/FrameworkExport.h"

#include "Framework/FrameworkFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_FRAMEWORK_STATIC

	DLL_MAIN_FUNCTION(Framework);

#else // !BUILDING_FRAMEWORK_STATIC

	CORE_TOOLS_MUTEX_INIT(Framework);

#endif // !BUILDING_FRAMEWORK_STATIC
