// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.3.0.1 (2020/05/30 15:40)

#ifndef MAIN_FUNCTION_HELPER_BASE1_H
#define MAIN_FUNCTION_HELPER_BASE1_H

#include "Framework/MainFunctionHelper/MainFunctionHelperBase.h"

namespace Framework
{
	class MainFunctionHelperBase1 final : public MainFunctionHelperBase
	{
	public:
		using ClassType = MainFunctionHelperBase1;
		using ParentType = MainFunctionHelperBase; 

	public:
		MainFunctionHelperBase1(int argc, char** argv, const String& consoleTitle,const EnvironmentDirectory& environmentDirectory);
		
		CLASS_INVARIANT_FINAL_DECLARE;	
	
		int DoRun() final;	
	};
}

#endif // MAIN_FUNCTION_HELPER_BASE1_H