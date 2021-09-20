// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 14:49)

#ifndef ANDROID_FRAME_BUILD_TESTING_TESTING_HELPER_H
#define ANDROID_FRAME_BUILD_TESTING_TESTING_HELPER_H

#include "Framework/MainFunctionHelper/AndroidMainFunctionHelper.h"
#include "Framework/AndroidFrame/AndroidFrameBuild.h"
#include "Framework/AndroidFrame/AndroidProcess.h"

namespace AndroidFrameBuildTesting
{
	class TestingHelper : public Framework::AndroidMainFunctionHelper<Framework::AndroidFrameBuild, Framework::AndroidProcessInterface>
	{
	public:
		using ClassType = TestingHelper;
		using ParentType = AndroidMainFunctionHelper<Framework::AndroidFrameBuild,Framework::AndroidProcessInterface>;

	public:
		explicit TestingHelper(AndroidApp* state,const Framework::EnvironmentDirectory& environmentDirectory);
		virtual ~TestingHelper();

		CLASS_INVARIANT_OVERRIDE_DECLARE;
	};
}

#endif // ANDROID_FRAME_BUILD_TESTING_TESTING_HELPER_H
