// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 14:09)

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
