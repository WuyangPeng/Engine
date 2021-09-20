// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 17:59)

#include "RechargeServerHelper.h"
#include "RechargeServer.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"

RechargeServer::RechargeServerHelper
	::RechargeServerHelper(HInstance instance,char* commandLine,const WindowApplicationInformation& information,const EnvironmentDirectory& environmentDirectory)
	:ParentType{ instance,commandLine,information,environmentDirectory }
{
	SELF_CLASS_IS_VALID_9;
}

RechargeServer::RechargeServerHelper
	::~RechargeServerHelper()
{
	SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(RechargeServer,RechargeServerHelper)





