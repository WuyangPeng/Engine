// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.0 (2019/10/09 23:36)

#ifndef ROBOT_CLIENT_ROBOT_CLIENT_HELPER_H
#define ROBOT_CLIENT_ROBOT_CLIENT_HELPER_H

#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"
#include "Framework/WindowProcess/WindowProcess.h"
#include "RobotClientMessage.h"

namespace RobotClient
{
	using WindowMainFunctionHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild,RobotClientMessageWindowProcessHandle>;

	class RobotClientHelper : public WindowMainFunctionHelperBase
	{
	public:
		using ClassType = RobotClientHelper;
		using ParentType = WindowMainFunctionHelperBase;
		using WindowApplicationInformation = Framework::WindowApplicationInformation;
		using EnvironmentDirectory = Framework::EnvironmentDirectory;

	public:
		RobotClientHelper(HInstance instance,char* commandLine,const WindowApplicationInformation& information,const EnvironmentDirectory& environmentDirectory);
		virtual ~RobotClientHelper();
		
		CLASS_INVARIANT_OVERRIDE_DECLARE;	
	};
}

#endif // ROBOT_CLIENT_ROBOT_CLIENT_HELPER_H
