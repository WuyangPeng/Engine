///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/16 14:28)

#ifndef SYSTEM_WINDOWS_TESTING_TESTING_HELPER_H
#define SYSTEM_WINDOWS_TESTING_TESTING_HELPER_H

#include "TestingWindowsMessage.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"

namespace System
{
    using WindowProcessSystemWindowsTesting = Framework::WindowProcessHandle<TestingWindowsMessage>;
    using TestingHelper = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, WindowProcessSystemWindowsTesting>;
}

#endif  // SYSTEM_TESTING_TESTING_HELPER_H