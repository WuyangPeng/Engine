// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/11 10:02)

#include "GatewayServerHelper.h"
#include "GatewayServer.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"

GatewayServer::GatewayServerHelper
	::GatewayServerHelper(HInstance instance,char* commandLine,const WindowApplicationInformation& information,const EnvironmentDirectory& environmentDirectory)
	:ParentType{ instance,commandLine,information,environmentDirectory }
{
	SELF_CLASS_IS_VALID_9;
}

GatewayServer::GatewayServerHelper
	::~GatewayServerHelper()
{
	SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(GatewayServer,GatewayServerHelper)





