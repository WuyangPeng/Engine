/// Copyright (c) 2010-2025
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.2.1 (2025/04/28 16:48)

#ifndef THREADING_CORE_RENDER_ENGINE_ASSIST_ASSIST_HELPER_H
#define THREADING_CORE_RENDER_ENGINE_ASSIST_ASSIST_HELPER_H

#include "AssistMiddleLayerMessage.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace ThreadingCoreRenderEngineAssist
{
    using HelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, AssistProcess>;

    class AssistHelper final : public HelperBase
    {
    public:
        using ClassType = AssistHelper;
        using ParentType = HelperBase;

        using EnvironmentDirectory = Framework::EnvironmentDirectory;
        using WindowApplicationInformation = Framework::WindowApplicationInformation;

    public:
        AssistHelper(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;
    };
}

#endif  // THREADING_CORE_RENDER_ENGINE_ASSIST_ASSIST_HELPER_H