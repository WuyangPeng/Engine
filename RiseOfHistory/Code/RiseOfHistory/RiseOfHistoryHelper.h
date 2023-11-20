/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.0 (2023/11/19 00:20)

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