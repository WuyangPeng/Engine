// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/17 10:58)

#include "UserInterface/UserInterfaceExport.h"

#include "UserInterface/UserInterfaceFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_RENDERING_STATIC

	DLL_MAIN_FUNCTION(Rendering);

#else // !BUILDING_RENDERING_STATIC

	CORE_TOOLS_MUTEX_INIT(Rendering);

#endif // !BUILDING_RENDERING_STATIC