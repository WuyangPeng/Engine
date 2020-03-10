// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/15 11:58)

#include "CoreToolsExport.h"

#include "CoreToolsFwd.h" 

#include "Helper/MainFunctionMacro.h"

#if !defined(BUILDING_CORE_TOOLS_STATIC) 

	DLL_MAIN_FUNCTION(CoreTools);

#else // defined(BUILDING_CORE_TOOLS_STATIC)

	CORE_TOOLS_MUTEX_INIT(CoreTools);

#endif // !defined(BUILDING_CORE_TOOLS_STATIC) 