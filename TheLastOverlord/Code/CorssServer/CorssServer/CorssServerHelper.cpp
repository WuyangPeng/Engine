/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/17 19:10)

#include "CorssServer.h"
#include "CorssServer/CorssServerCore/Helper/CorssServerCoreClassInvariantMacro.h"
#include "CorssServerHelper.h" 
#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"

CorssServer::CorssServerHelper::CorssServerHelper(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ instance, commandLine, information, environmentDirectory }
{
    CORSS_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CorssServer, CorssServerHelper)
