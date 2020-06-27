// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/18 19:02)

#include "Mathematics/MathematicsExport.h"

#include "Mathematics/MathematicsFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_MATHEMATICS_STATIC

	DLL_MAIN_FUNCTION(Mathematics);

#else // !BUILDING_MATHEMATICS_STATIC

	CORE_TOOLS_MUTEX_INIT(Mathematics);

#endif // !BUILDING_MATHEMATICS_STATIC