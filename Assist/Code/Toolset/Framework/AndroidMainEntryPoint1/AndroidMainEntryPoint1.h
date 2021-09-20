// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∏®÷˙∞Ê±æ£∫0.3.0.1 (2020/05/25 14:42)

#ifndef ANDROID_MAIN_ENTRY_POINT1_H
#define ANDROID_MAIN_ENTRY_POINT1_H

#include "Framework/AndroidFrame/AndroidProcess.h"
#include "Framework/AndroidFrame/AndroidFrameBuild.h"
#include "Framework/MainFunctionHelper/AndroidMainFunctionHelper.h"

namespace Framework
{  
	using BaseType = AndroidMainFunctionHelper<AndroidFrameBuild, AndroidProcessInterface>;

	class AndroidMainEntryPoint1 final : public BaseType
	{
	public:
		using ClassType = AndroidMainEntryPoint1;
		using ParentType = BaseType;

	public:
		AndroidMainEntryPoint1(AndroidApp* state, const EnvironmentDirectory& environmentDirectory);

		CLASS_INVARIANT_FINAL_DECLARE;
	};
}

#endif // ANDROID_MAIN_ENTRY_POINT1_H
