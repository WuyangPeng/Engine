// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.3.0.1 (2020/05/26 13:25)

#include "WinMainEntryPoint3.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"

Framework::WinMainEntryPoint3::WinMainEntryPoint3(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ instance, commandLine, information, environmentDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WinMainEntryPoint3)

std::shared_ptr<Framework::WinMainEntryPoint3> Framework::WinMainEntryPoint3::Create(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory)
{
    return std::make_shared<Framework::WinMainEntryPoint3>(instance, commandLine, information, environmentDirectory);
}
