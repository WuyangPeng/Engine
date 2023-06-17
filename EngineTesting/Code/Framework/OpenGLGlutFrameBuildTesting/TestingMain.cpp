///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 23:30)

#include "System/Helper/GLExtensionsMacro.h"
#include "Framework/Helper/MainFunctionMacro.h"
#include "Framework/OpenGLGlutFrame/Flags/FrameParameter.h"
#include "Framework/OpenGLGlutFrameBuildTesting/TestingHelper.h"
#include "Framework/WindowCreate/WindowSize.h"

#include <vld.h>

GLUT_CONSOLE_MAIN_FUNCTION(OpenGLGlutFrameBuildTesting, TestingHelper, SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT(""), 3, 0, Framework::FrameParameter::SixtyFrame);
