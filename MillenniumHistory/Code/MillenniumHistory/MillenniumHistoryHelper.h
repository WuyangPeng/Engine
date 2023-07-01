///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/17 23:40)

#ifndef MILLENNIUM_HISTORY_MILLENNIUM_HISTORY_HELPER_H
#define MILLENNIUM_HISTORY_MILLENNIUM_HISTORY_HELPER_H

#include "MillenniumHistoryMiddleLayerMessage.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace MillenniumHistory
{
    using HelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, MillenniumHistoryProcess>;

    class MillenniumHistoryHelper final : public HelperBase
    {
    public:
        using ClassType = MillenniumHistoryHelper;
        using ParentType = HelperBase;

        using EnvironmentDirectory = Framework::EnvironmentDirectory;
        using WindowApplicationInformation = Framework::WindowApplicationInformation;

    public:
        MillenniumHistoryHelper(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;
    };
}

#endif  // MILLENNIUM_HISTORY_MILLENNIUM_HISTORY_HELPER_H