///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 23:36)

#include "System/Helper/WindowsMacro.h"
#include "Framework/Application/WindowApplicationInformation.h"
#include "Framework/Helper/MainFunctionMacro.h"
#include "Framework/WindowsAPIFrameTesting/TestingHelper.h"

#include <vld.h>

WINDOWS_MAIN_FUNCTION_WITH_INFORMATION(WindowsAPIFrameTesting, TestingHelper, SYSTEM_TEXT("WindowsAPIFrameTesting"), SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT(""), 1024, 768)
