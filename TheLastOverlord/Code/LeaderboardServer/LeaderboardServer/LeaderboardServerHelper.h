// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 15:25)

#ifndef LEADERBOARD_SERVER_LEADERBOARD_SERVER_HELPER_H
#define LEADERBOARD_SERVER_LEADERBOARD_SERVER_HELPER_H

#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"
#include "Framework/WindowProcess/WindowProcess.h"
#include "LeaderboardServerMessage.h"

namespace LeaderboardServer
{
	using WindowMainFunctionHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild,LeaderboardServerMessageWindowProcessHandle>;

	class LeaderboardServerHelper : public WindowMainFunctionHelperBase
	{
	public:
		using ClassType = LeaderboardServerHelper;
		using ParentType = WindowMainFunctionHelperBase;
		using WindowApplicationInformation = Framework::WindowApplicationInformation;
		using EnvironmentDirectory = Framework::EnvironmentDirectory;

	public:
		LeaderboardServerHelper(HInstance instance,char* commandLine,const WindowApplicationInformation& information,const EnvironmentDirectory& environmentDirectory);
		virtual ~LeaderboardServerHelper();
		
		CLASS_INVARIANT_OVERRIDE_DECLARE;	
	};
}

#endif // LEADERBOARD_SERVER_LEADERBOARD_SERVER_HELPER_H
