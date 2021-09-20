// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ¸¨Öú°æ±¾£º0.3.0.1 (2020/05/25 13:46)

#include "GlutMainEntryPoint1.h"
#include "Framework/Helper/MainFunctionMacro.h" 
#include "Framework/OpenGLGlutFrame/Flags/FrameParameter.h"

#include <vld.h> 

int main(int argc, char** argv)
{
	return Framework::GlutMainEntryPoint<Framework::GlutMainEntryPoint1>(argc, argv, SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT(""), 3,0,Framework::FrameParameter::SixtyFrame);
} 