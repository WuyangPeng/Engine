// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∏®÷˙∞Ê±æ£∫0.3.0.1 (2020/05/26 17:15)

#ifndef ANDROID_MAIN_ENTRY_POINT2_H
#define ANDROID_MAIN_ENTRY_POINT2_H

#include "Framework/AndroidFrame/AndroidProcess.h"
#include "Framework/AndroidFrame/AndroidFrameBuild.h"
#include "Framework/MainFunctionHelper/AndroidMainFunctionHelper.h"

namespace Framework
{  
	using BaseType = AndroidMainFunctionHelper<AndroidFrameBuild, AndroidProcessInterface>;

	class AndroidMainEntryPoint2 : public BaseType
	{
	public:
		using ClassType = AndroidMainEntryPoint2;
		using ParentType = BaseType;

	public:
		AndroidMainEntryPoint2(AndroidApp* state, const EnvironmentDirectory& environmentDirectory);

		CLASS_INVARIANT_FINAL_DECLARE;
	};
}

#endif // ANDROID_MAIN_ENTRY_POINT2_H
