// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 15:43)

#ifndef GAME_MASTER_SERVER_GAME_MASTER_SERVER_HELPER_H
#define GAME_MASTER_SERVER_GAME_MASTER_SERVER_HELPER_H

#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"
#include "Framework/WindowProcess/WindowProcess.h"
#include "GameMasterServerMessage.h"

namespace GameMasterServer
{
	using WindowMainFunctionHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild,GameMasterServerMessageWindowProcessHandle>;

	class GameMasterServerHelper : public WindowMainFunctionHelperBase
	{
	public:
		using ClassType = GameMasterServerHelper;
		using ParentType = WindowMainFunctionHelperBase;
		using WindowApplicationInformation = Framework::WindowApplicationInformation;
		using EnvironmentDirectory = Framework::EnvironmentDirectory;

	public:
		GameMasterServerHelper(HInstance instance,char* commandLine,const WindowApplicationInformation& information,const EnvironmentDirectory& environmentDirectory);
		virtual ~GameMasterServerHelper();
		
		CLASS_INVARIANT_OVERRIDE_DECLARE;	
	};
}

#endif // GAME_MASTER_SERVER_GAME_MASTER_SERVER_HELPER_H
