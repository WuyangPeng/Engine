///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/16 14:28)

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