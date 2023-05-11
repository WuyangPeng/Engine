///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	��ʷ������汾��0.8.1.0 (2022/08/03 10:55)

#ifndef RISE_OF_HISTORY_RISE_OF_HISTORY_HELPER_H
#define RISE_OF_HISTORY_RISE_OF_HISTORY_HELPER_H

#include "RiseOfHistoryMiddleLayerMessage.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace RiseOfHistory
{
    using HelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, RiseOfHistoryProcess>;

    class RiseOfHistoryHelper final : public HelperBase
    {
    public:
        using ClassType = RiseOfHistoryHelper;
        using ParentType = HelperBase;

        using EnvironmentDirectory = Framework::EnvironmentDirectory;
        using WindowApplicationInformation = Framework::WindowApplicationInformation;

    public:
        RiseOfHistoryHelper(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;
    };
}

#endif  // RISE_OF_HISTORY_RISE_OF_HISTORY_HELPER_H