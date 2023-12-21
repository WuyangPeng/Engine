/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/17 19:45)

#include "RechargeServer.h"
#include "RechargeServer/RechargeServerCore/Helper/RechargeServerCoreClassInvariantMacro.h"
#include "RechargeServerHelper.h" 
#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"

RechargeServer::RechargeServerHelper::RechargeServerHelper(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ instance, commandLine, information, environmentDirectory }
{
    RECHARGE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(RechargeServer, RechargeServerHelper)
