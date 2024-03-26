/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 16:37)

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