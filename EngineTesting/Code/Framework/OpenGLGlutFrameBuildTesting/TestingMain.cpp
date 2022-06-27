///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 16:56)

#include "System/Helper/GLExtensionsMacro.h"
#include "Framework/Helper/MainFunctionMacro.h"
#include "Framework/OpenGLGlutFrame/Flags/FrameParameter.h"
#include "Framework/OpenGLGlutFrameBuildTesting/TestingHelper.h"
#include "Framework/WindowCreate/WindowSize.h"

#include <vld.h>

using Framework::GLUTApplicationInformation;
using Framework::WindowSize;

GLUT_CONSOLE_MAIN_FUNCTION(OpenGLGlutFrameBuildTesting, TestingHelper, SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT(""), 3, 0, Framework::FrameParameter::SixtyFrame);
