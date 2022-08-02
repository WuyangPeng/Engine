///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/19 16:54)

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
        TheLastOverlordHelper(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;
    };
}

#endif  // THE_LAST_OVERLORD_THE_LAST_OVERLORD_HELPER_H