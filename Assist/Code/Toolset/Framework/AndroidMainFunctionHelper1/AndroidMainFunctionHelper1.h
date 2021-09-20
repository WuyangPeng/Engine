// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∏®÷˙∞Ê±æ£∫0.3.0.2 (2020/06/02 14:07)

#ifndef ANDROID_MAIN_FUNCTION_HELPER1_H
#define ANDROID_MAIN_FUNCTION_HELPER1_H

#include "Framework/AndroidFrame/AndroidProcess.h"
#include "Framework/AndroidFrame/AndroidFrameBuild.h"
#include "Framework/MainFunctionHelper/AndroidMainFunctionHelper.h"

namespace Framework
{
	using BaseType = AndroidMainFunctionHelper<AndroidFrameBuild,AndroidProcessInterface>;
	
	class AndroidMainFunctionHelper1 final : public BaseType
	{
	public:
		using ClassType = AndroidMainFunctionHelper1;
		using ParentType = BaseType;

	public:
		AndroidMainFunctionHelper1(AndroidApp* state,const EnvironmentDirectory& environmentDirectory);
		
		CLASS_INVARIANT_FINAL_DECLARE;	
	};
}

#endif // ANDROID_MAIN_FUNCTION_HELPER1_H
