///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 18:41)

#include "System/Helper/WindowsMacro.h"
#include "Framework/Application/WindowApplicationInformation.h"
#include "Framework/Helper/MainFunctionMacro.h"
#include "Framework/WindowsAPIFrameTesting/TestingHelper.h"

#include <vld.h>

using Framework::WindowApplicationInformation;
using Framework::WindowSize;

WINDOWS_MAIN_FUNCTION_WITH_INFORMATION(WindowsAPIFrameTesting, TestingHelper, SYSTEM_TEXT("WindowsAPIFrameTesting"), SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT(""), 1024, 768)
