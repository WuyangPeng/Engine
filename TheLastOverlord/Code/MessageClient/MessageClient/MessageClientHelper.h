// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.0 (2019/10/10 16:26)

#ifndef MESSAGE_CLIENT_MESSAGE_CLIENT_HELPER_H
#define MESSAGE_CLIENT_MESSAGE_CLIENT_HELPER_H

#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"
#include "Framework/WindowProcess/WindowProcess.h"
#include "MessageClientMessage.h"

namespace MessageClient
{
	using WindowMainFunctionHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild,MessageClientMessageWindowProcessHandle>;

	class MessageClientHelper : public WindowMainFunctionHelperBase
	{
	public:
		using ClassType = MessageClientHelper;
		using ParentType = WindowMainFunctionHelperBase;
		using WindowApplicationInformation = Framework::WindowApplicationInformation;
		using EnvironmentDirectory = Framework::EnvironmentDirectory;

	public:
		MessageClientHelper(HInstance instance,char* commandLine,const WindowApplicationInformation& information,const EnvironmentDirectory& environmentDirectory);
		virtual ~MessageClientHelper();
		
		CLASS_INVARIANT_OVERRIDE_DECLARE;	
	};
}

#endif // MESSAGE_CLIENT_MESSAGE_CLIENT_HELPER_H
