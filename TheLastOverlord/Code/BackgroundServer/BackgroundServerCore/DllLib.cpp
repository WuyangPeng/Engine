// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 18:06)

#include "BackgroundServerCoreExport.h"

#include "BackgroundServerCore.h"

#include "CoreTools/CoreToolsLib.h"
#include "Framework/FrameworkLib.h"

#ifndef BUILDING_BACKGROUND_SERVER_CORE_STATIC

	#include "DllLib.h"

#else // !BUILDING_BACKGROUND_SERVER_CORE_STATIC

	namespace BackgroundServerCore
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_BACKGROUND_SERVER_CORE_STATIC
