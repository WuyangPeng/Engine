// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ¸¨Öú°æ±¾£º0.3.0.1 (2020/05/25 11:37)

#include "MainEntryPoint1.h"
#include "Framework/Helper/MainFunctionMacro.h" 

#include <vld.h> 

int main(int argc, char** argv)
{
	return Framework::MainEntryPoint<Framework::MainEntryPoint1>(argc, argv, SYSTEM_TEXT("MainEntryPoint1"), SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT(""));
}
