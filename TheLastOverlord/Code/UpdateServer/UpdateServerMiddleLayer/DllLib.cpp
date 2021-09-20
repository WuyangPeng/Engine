// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 19:03)

#include "UpdateServerMiddleLayerExport.h"

#include "UpdateServerMiddleLayer.h"

#include "CoreTools/CoreToolsLib.h"
#include "Framework/FrameworkLib.h"

#ifndef BUILDING_UPDATE_SERVER_MIDDLE_LAYER_STATIC

	#include "DllLib.h"

#else // !BUILDING_UPDATE_SERVER_MIDDLE_LAYER_STATIC

	namespace UpdateServerMiddleLayer
	{
		void StaticDllLib()
		{
			
		}
	}

#endif // !BUILDING_UPDATE_SERVER_MIDDLE_LAYER_STATIC
