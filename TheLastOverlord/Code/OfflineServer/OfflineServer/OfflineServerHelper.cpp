// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 14:01)

#include "OfflineServerHelper.h"
#include "OfflineServer.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"

OfflineServer::OfflineServerHelper
	::OfflineServerHelper(HInstance instance,char* commandLine,const WindowApplicationInformation& information,const EnvironmentDirectory& environmentDirectory)
	:ParentType{ instance,commandLine,information,environmentDirectory }
{
	SELF_CLASS_IS_VALID_9;
}

OfflineServer::OfflineServerHelper
	::~OfflineServerHelper()
{
	SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(OfflineServer,OfflineServerHelper)





