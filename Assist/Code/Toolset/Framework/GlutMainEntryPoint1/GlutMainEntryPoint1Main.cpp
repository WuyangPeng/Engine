///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 14:20) 

#include "GlutMainEntryPoint1.h"
#include "Framework/Helper/MainFunctionMacro.h"
#include "Framework/OpenGLGlutFrame/Flags/FrameParameter.h"

#include "System/Helper/PragmaWarning/Vld.h"

int main(int argc, char** argv)
{
    return Framework::GlutMainEntryPoint<Framework::GlutMainEntryPoint1>(argc, argv, SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT(""), 3, 0, Framework::FrameParameter::SixtyFrame);
}