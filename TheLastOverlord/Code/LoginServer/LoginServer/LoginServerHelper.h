// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/11 14:00)

#ifndef LOGIN_SERVER_LOGIN_SERVER_HELPER_H
#define LOGIN_SERVER_LOGIN_SERVER_HELPER_H

#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"
#include "Framework/WindowProcess/WindowProcess.h"
#include "LoginServerMessage.h"

namespace LoginServer
{
	using WindowMainFunctionHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild,LoginServerMessageWindowProcessHandle>;

	class LoginServerHelper : public WindowMainFunctionHelperBase
	{
	public:
		using ClassType = LoginServerHelper;
		using ParentType = WindowMainFunctionHelperBase;
		using WindowApplicationInformation = Framework::WindowApplicationInformation;
		using EnvironmentDirectory = Framework::EnvironmentDirectory;

	public:
		LoginServerHelper(HInstance instance,char* commandLine,const WindowApplicationInformation& information,const EnvironmentDirectory& environmentDirectory);
		virtual ~LoginServerHelper();
		
		CLASS_INVARIANT_OVERRIDE_DECLARE;	
	};
}

#endif // LOGIN_SERVER_LOGIN_SERVER_HELPER_H
