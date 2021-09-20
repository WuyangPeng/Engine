// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∏®÷˙∞Ê±æ£∫0.3.0.2 (2020/06/02 15:34)

#ifndef MACINTOSH_MAIN_FUNCTION_HELPER1_H
#define MACINTOSH_MAIN_FUNCTION_HELPER1_H

#include "Framework/MacintoshFrame/MacintoshProcess.h"
#include "Framework/MacintoshFrame/MacintoshFrameBuild.h"
#include "Framework/MainFunctionHelper/MacintoshMainFunctionHelper.h"

namespace Framework
{
	using BaseType = MacintoshMainFunctionHelper<MacintoshFrameBuild, MacintoshProcessInterface>;
	
	class MacintoshMainFunctionHelper1 final : public BaseType
	{
	public:
		using ClassType = MacintoshMainFunctionHelper1;
		using ParentType = BaseType;

	public:
		MacintoshMainFunctionHelper1(const EnvironmentDirectory& environmentDirectory);
		
		CLASS_INVARIANT_FINAL_DECLARE;	
	};
}

#endif // MACINTOSH_MAIN_FUNCTION_HELPER1_H
