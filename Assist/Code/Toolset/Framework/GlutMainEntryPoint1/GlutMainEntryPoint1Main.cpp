///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/05 10:07)

#include "GlutMainEntryPoint1.h"
#include "Framework/Helper/MainFunctionMacro.h"
#include "Framework/OpenGLGlutFrame/Flags/FrameParameter.h"

#include <vld.h>

int main(int argc, char** argv)
{
    return Framework::GlutMainEntryPoint<Framework::GlutMainEntryPoint1>(argc, argv, SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT(""), 3, 0, Framework::FrameParameter::SixtyFrame);
}