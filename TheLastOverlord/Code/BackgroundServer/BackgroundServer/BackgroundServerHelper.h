// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 18:05)

#ifndef BACKGROUND_SERVER_BACKGROUND_SERVER_HELPER_H
#define BACKGROUND_SERVER_BACKGROUND_SERVER_HELPER_H

#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"
#include "Framework/WindowProcess/WindowProcess.h"
#include "BackgroundServerMessage.h"

namespace BackgroundServer
{
	using WindowMainFunctionHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild,BackgroundServerMessageWindowProcessHandle>;

	class BackgroundServerHelper : public WindowMainFunctionHelperBase
	{
	public:
		using ClassType = BackgroundServerHelper;
		using ParentType = WindowMainFunctionHelperBase;
		using WindowApplicationInformation = Framework::WindowApplicationInformation;
		using EnvironmentDirectory = Framework::EnvironmentDirectory;

	public:
		BackgroundServerHelper(HInstance instance,char* commandLine,const WindowApplicationInformation& information,const EnvironmentDirectory& environmentDirectory);
		virtual ~BackgroundServerHelper();
		
		CLASS_INVARIANT_OVERRIDE_DECLARE;	
	};
}

#endif // BACKGROUND_SERVER_BACKGROUND_SERVER_HELPER_H
