// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.0 (2020/01/08 21:34)

#include "Toolset/UserInterface/UserInterfaceToolset/UserInterfaceToolsetExport.h"

#include "Toolset/UserInterface/UserInterfaceToolset/UserInterfaceToolsetFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_USER_INTERFACE_STATIC

	DLL_MAIN_FUNCTION(UserInterface);

#else // !BUILDING_USER_INTERFACE_STATIC

	CORE_TOOLS_MUTEX_INIT(UserInterface);

#endif // !BUILDING_USER_INTERFACE_STATIC