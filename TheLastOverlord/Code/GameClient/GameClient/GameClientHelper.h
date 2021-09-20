// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.2.0 (2020/01/09 22:52)

#ifndef GAME_CLIENT_GAME_CLIENT_HELPER_H
#define GAME_CLIENT_GAME_CLIENT_HELPER_H

#include "GameClientMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"

namespace GameClient
{
	using WindowMainFunctionHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild,GameClientMessageWindowProcessHandle>;

	class GameClientHelper : public WindowMainFunctionHelperBase
	{
	public:
		using ClassType = GameClientHelper;
		using ParentType = WindowMainFunctionHelperBase;
		using EnvironmentDirectory = Framework::EnvironmentDirectory;
		using WindowApplicationInformation = Framework::WindowApplicationInformation;		

	public:
		GameClientHelper(HInstance instance,char* commandLine,const WindowApplicationInformation& information,const EnvironmentDirectory& environmentDirectory);
		virtual ~GameClientHelper();
		
		CLASS_INVARIANT_OVERRIDE_DECLARE;	
	};
}

#endif // GAME_CLIENT_GAME_CLIENT_HELPER_H
