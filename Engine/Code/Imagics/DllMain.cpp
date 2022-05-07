///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/25 16:45)

#include "Imagics/ImagicsExport.h"

#include "Imagics/ImagicsFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_IMAGICS_STATIC

	DLL_MAIN_FUNCTION(Imagics);

#else // BUILDING_IMAGICS_STATIC

	CORE_TOOLS_MUTEX_INIT(Imagics);
	 
#endif // !BUILDING_IMAGICS_STATIC