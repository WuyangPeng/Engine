/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 16:46)

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
                           Framework::FrameParameter::SixtyFrame)