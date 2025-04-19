///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/10 11:28)

#include "System/Helper/GLExtensionsMacro.h"
#include "Framework/Helper/MainFunctionMacro.h"
#include "Framework/OpenGLGlutCallBackUnitTestSuiteTesting/TestingHelper.h"
#include "Framework/OpenGLGlutFrame/Flags/FrameParameter.h"
#include "Framework/WindowCreate/WindowSize.h"

#include "System/Helper/PragmaWarning/Vld.h"

GLUT_CONSOLE_MAIN_FUNCTION(OpenGLGlutCallBackUnitTestSuiteTesting, TestingHelper, SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT(""), 3, 0, Framework::FrameParameter::SixtyFrame);
