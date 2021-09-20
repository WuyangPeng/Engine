// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.2.0 (2020/01/08 23:50)

#include "GameClientCoreExport.h"

#include "GameClientCore.h"

#include "CoreTools/CoreToolsLib.h"
#include "Framework/FrameworkLib.h"

#ifndef BUILDING_GAME_CLIENT_CORE_STATIC

	#include "DllLib.h"

#else // !BUILDING_GAME_CLIENT_CORE_STATIC

	namespace GameClientCore
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_GAME_CLIENT_CORE_STATIC