// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/17 10:58)

#include "UserInterface/UserInterfaceExport.h"

#include "UserInterface/UserInterfaceFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_RENDERING_STATIC

	DLL_MAIN_FUNCTION(Rendering);

#else // !BUILDING_RENDERING_STATIC

	CORE_TOOLS_MUTEX_INIT(Rendering);

#endif // !BUILDING_RENDERING_STATIC