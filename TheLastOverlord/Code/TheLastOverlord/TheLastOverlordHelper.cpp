///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���İ����汾��0.7.0.1 (2021/02/18 14:36)

#include "Helper/TheLastOverlordClassInvariantMacro.h"
#include "TheLastOverlordHelper.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"

TheLastOverlord::TheLastOverlordHelper::TheLastOverlordHelper(HInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ instance, commandLine, information, environmentDirectory }
{
    THE_LAST_OVERLORD_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(TheLastOverlord, TheLastOverlordHelper)