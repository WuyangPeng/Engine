// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 17:59)

#ifndef RECHARGE_SERVER_RECHARGE_SERVER_HELPER_H
#define RECHARGE_SERVER_RECHARGE_SERVER_HELPER_H

#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"
#include "Framework/WindowProcess/WindowProcess.h"
#include "RechargeServerMessage.h"

namespace RechargeServer
{
	using WindowMainFunctionHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild,RechargeServerMessageWindowProcessHandle>;

	class RechargeServerHelper : public WindowMainFunctionHelperBase
	{
	public:
		using ClassType = RechargeServerHelper;
		using ParentType = WindowMainFunctionHelperBase;
		using WindowApplicationInformation = Framework::WindowApplicationInformation;
		using EnvironmentDirectory = Framework::EnvironmentDirectory;

	public:
		RechargeServerHelper(HInstance instance,char* commandLine,const WindowApplicationInformation& information,const EnvironmentDirectory& environmentDirectory);
		virtual ~RechargeServerHelper();
		
		CLASS_INVARIANT_OVERRIDE_DECLARE;	
	};
}

#endif // RECHARGE_SERVER_RECHARGE_SERVER_HELPER_H
