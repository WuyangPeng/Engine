// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 09:35)

#ifndef FIGHTING_SERVER_FIGHTING_SERVER_HELPER_H
#define FIGHTING_SERVER_FIGHTING_SERVER_HELPER_H

#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"
#include "Framework/WindowProcess/WindowProcess.h"
#include "FightingServerMessage.h"

namespace FightingServer
{
	using WindowMainFunctionHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild,FightingServerMessageWindowProcessHandle>;

	class FightingServerHelper : public WindowMainFunctionHelperBase
	{
	public:
		using ClassType = FightingServerHelper;
		using ParentType = WindowMainFunctionHelperBase;
		using WindowApplicationInformation = Framework::WindowApplicationInformation;
		using EnvironmentDirectory = Framework::EnvironmentDirectory;

	public:
		FightingServerHelper(HInstance instance,char* commandLine,const WindowApplicationInformation& information,const EnvironmentDirectory& environmentDirectory);
		virtual ~FightingServerHelper();
		
		CLASS_INVARIANT_OVERRIDE_DECLARE;	
	};
}

#endif // FIGHTING_SERVER_FIGHTING_SERVER_HELPER_H
