///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/27 16:34)

#include "System/Helper/GLExtensionsMacro.h"
#include "Framework/OpenGLGlutCallBackUnitTestSuiteTesting/TestingHelper.h"
#include "Framework/Helper/MainFunctionMacro.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/OpenGLGlutFrame/Flags/FrameParameter.h"

#include <vld.h>

using Framework::GLUTApplicationInformation;
using Framework::WindowSize;

GLUT_CONSOLE_MAIN_FUNCTION(OpenGLGlutCallBackUnitTestSuiteTesting,TestingHelper,SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT(""),3,0,Framework::FrameParameter::SixtyFrame);
	
