// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.0.1 (2019/10/13 15:52)

#include "GameMasterServerMiddleLayerExport.h"

#include "GameMasterServerMiddleLayer.h"

#include "CoreTools/CoreToolsLib.h"
#include "Framework/FrameworkLib.h"

#ifndef BUILDING_GAME_MASTER_SERVER_MIDDLE_LAYER_STATIC

	#include "DllLib.h"

#else // !BUILDING_GAME_MASTER_SERVER_MIDDLE_LAYER_STATIC

	namespace GameMasterServerMiddleLayer
	{
		void StaticDllLib()
		{
			
		}
	}

#endif // !BUILDING_GAME_MASTER_SERVER_MIDDLE_LAYER_STATIC
