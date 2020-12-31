// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/19 23:45)

#include "Framework/FrameworkExport.h"

#include "Framework/FrameworkFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_FRAMEWORK_STATIC

	DLL_MAIN_FUNCTION(Framework);

#else // !BUILDING_FRAMEWORK_STATIC

	CORE_TOOLS_MUTEX_INIT(Framework);

#endif // !BUILDING_FRAMEWORK_STATIC
