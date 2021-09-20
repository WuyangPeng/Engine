// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 13:05)

#ifndef WORLD_SERVER_WORLD_SERVER_HELPER_H
#define WORLD_SERVER_WORLD_SERVER_HELPER_H

#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"
#include "Framework/WindowProcess/WindowProcess.h"
#include "WorldServerMessage.h"

namespace WorldServer
{
	using WindowMainFunctionHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild,WorldServerMessageWindowProcessHandle>;

	class WorldServerHelper : public WindowMainFunctionHelperBase
	{
	public:
		using ClassType = WorldServerHelper;
		using ParentType = WindowMainFunctionHelperBase;
		using WindowApplicationInformation = Framework::WindowApplicationInformation;
		using EnvironmentDirectory = Framework::EnvironmentDirectory;

	public:
		WorldServerHelper(HInstance instance,char* commandLine,const WindowApplicationInformation& information,const EnvironmentDirectory& environmentDirectory);
		virtual ~WorldServerHelper();
		
		CLASS_INVARIANT_OVERRIDE_DECLARE;	
	};
}

#endif // WORLD_SERVER_WORLD_SERVER_HELPER_H
