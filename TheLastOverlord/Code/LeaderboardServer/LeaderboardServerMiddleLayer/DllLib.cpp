// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 15:34)

#include "LeaderboardServerMiddleLayerExport.h"

#include "LeaderboardServerMiddleLayer.h"

#include "CoreTools/CoreToolsLib.h"
#include "Framework/FrameworkLib.h"

#ifndef BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_STATIC

	#include "DllLib.h"

#else // !BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_STATIC

	namespace LeaderboardServerMiddleLayer
	{
		void StaticDllLib()
		{
			
		}
	}

#endif // !BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_STATIC
