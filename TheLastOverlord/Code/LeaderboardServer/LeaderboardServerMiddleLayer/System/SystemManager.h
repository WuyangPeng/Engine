// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 15:33)

#ifndef LEADERBOARD_SERVER_MIDDLE_LAYER_SYSTEM_MIDDLE_LAYER_SYSTEM_H
#define LEADERBOARD_SERVER_MIDDLE_LAYER_SYSTEM_MIDDLE_LAYER_SYSTEM_H

#include "LeaderboardServer/LeaderboardServerMiddleLayer/LeaderboardServerMiddleLayerDll.h"

#include "LeaderboardServer/LeaderboardServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/SystemManagerInterface.h" 

namespace LeaderboardServerMiddleLayer
{
	class LEADERBOARD_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE SystemManager : public Framework::SystemManagerInterface
	{
	public:
		using ClassType = SystemManager;
		using ParentType = Framework::SystemManagerInterface;
		
	public:
		SystemManager(Framework::MiddleLayerPlatform middleLayerPlatform);
		virtual ~SystemManager();

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // LEADERBOARD_SERVER_MIDDLE_LAYER_SYSTEM_MIDDLE_LAYER_SYSTEM_H
