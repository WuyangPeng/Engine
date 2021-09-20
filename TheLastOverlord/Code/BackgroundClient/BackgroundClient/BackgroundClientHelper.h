// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.0 (2019/10/10 17:47)

#ifndef BACKGROUND_CLIENT_BACKGROUND_CLIENT_HELPER_H
#define BACKGROUND_CLIENT_BACKGROUND_CLIENT_HELPER_H

#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"
#include "Framework/WindowProcess/WindowProcess.h"
#include "BackgroundClientMessage.h"

namespace BackgroundClient
{
	using WindowMainFunctionHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild,BackgroundClientMessageWindowProcessHandle>;

	class BackgroundClientHelper : public WindowMainFunctionHelperBase
	{
	public:
		using ClassType = BackgroundClientHelper;
		using ParentType = WindowMainFunctionHelperBase;
		using WindowApplicationInformation = Framework::WindowApplicationInformation;
		using EnvironmentDirectory = Framework::EnvironmentDirectory;

	public:
		BackgroundClientHelper(HInstance instance,char* commandLine,const WindowApplicationInformation& information,const EnvironmentDirectory& environmentDirectory);
		virtual ~BackgroundClientHelper();
		
		CLASS_INVARIANT_OVERRIDE_DECLARE;	
	};
}

#endif // BACKGROUND_CLIENT_BACKGROUND_CLIENT_HELPER_H
