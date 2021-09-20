///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.1 (2021/03/23 17:12)

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