// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 15:26)

#ifndef LEADERBOARD_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define LEADERBOARD_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "LeaderboardServer/LeaderboardServerCore/LeaderboardServerCoreDll.h"

#include "LeaderboardServer/LeaderboardServerCore/Macro/ExportMacro.h"  

namespace LeaderboardServerCore
{
	class LEADERBOARD_SERVER_CORE_DEFAULT_DECLARE Placeholder
	{
	public:
		using ClassType = Placeholder;

	public:
		Placeholder();

		CLASS_INVARIANT_DECLARE;
	};
}

#endif // LEADERBOARD_SERVER_CORE_ENGINE_PLACEHOLDER_H
