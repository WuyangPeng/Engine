///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.6 (2021/06/28 18:39)

#include "System/SystemOpenGLTesting/TestingHelper.h"
#include "Framework/Helper/MainFunctionMacro.h"
#include "Framework/OpenGLGlutFrame/Flags/FrameParameter.h"

#include <vld.h>

GLUT_CONSOLE_MAIN_FUNCTION(System,
                           TestingHelper,
                           SYSTEM_TEXT("DefaultEnvironment"),
                           SYSTEM_TEXT(""),
                           4,
                           6,
                           Framework::FrameParameter::SixtyFrame);
