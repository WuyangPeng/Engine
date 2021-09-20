// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 14:09)

#include "OfflineServerMiddleLayerExport.h"

#include "OfflineServerMiddleLayer.h"

#include "CoreTools/CoreToolsLib.h"
#include "Framework/FrameworkLib.h"

#ifndef BUILDING_OFFLINE_SERVER_MIDDLE_LAYER_STATIC

	#include "DllLib.h"

#else // !BUILDING_OFFLINE_SERVER_MIDDLE_LAYER_STATIC

	namespace OfflineServerMiddleLayer
	{
		void StaticDllLib()
		{
			
		}
	}

#endif // !BUILDING_OFFLINE_SERVER_MIDDLE_LAYER_STATIC
