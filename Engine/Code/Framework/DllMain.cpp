// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/07/31 17:39)

#include "Framework/FrameworkExport.h"

#include "Framework/FrameworkFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_FRAMEWORK_STATIC

	DLL_MAIN_FUNCTION(Framework);

#else // !BUILDING_FRAMEWORK_STATIC

	CORE_TOOLS_MUTEX_INIT(Framework);

#endif // !BUILDING_FRAMEWORK_STATIC