///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���İ����汾��0.7.0.1 (2021/02/18 14:42)

#ifndef THE_LAST_OVERLORD_THE_LAST_OVERLORD_HELPER_H
#define THE_LAST_OVERLORD_THE_LAST_OVERLORD_HELPER_H

#include "TheLastOverlordMiddleLayerMessage.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace TheLastOverlord
{
    using HelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, TheLastOverlordProcess>;

    class TheLastOverlordHelper final : public HelperBase
    {
    public:
        using ClassType = TheLastOverlordHelper;
        using ParentType = HelperBase;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;
        using WindowApplicationInformation = Framework::WindowApplicationInformation;

    public:
        TheLastOverlordHelper(HInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;
    };
}

#endif  // THE_LAST_OVERLORD_THE_LAST_OVERLORD_HELPER_H