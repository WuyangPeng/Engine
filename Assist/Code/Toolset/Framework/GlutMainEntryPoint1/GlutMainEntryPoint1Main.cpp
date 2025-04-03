///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 14:20) 

#include "GlutMainEntryPoint1.h"
#include "Framework/Helper/MainFunctionMacro.h"
#include "Framework/OpenGLGlutFrame/Flags/FrameParameter.h"

#include "System/Helper/PragmaWarning/Vld.h"

int main(int argc, char** argv)
{
    return Framework::GlutMainEntryPoint<Framework::GlutMainEntryPoint1>(argc, argv, SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT(""), 3, 0, Framework::FrameParameter::SixtyFrame);
}