///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	千年史策版本：0.9.0.12 (2023/06/15 22:53)

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