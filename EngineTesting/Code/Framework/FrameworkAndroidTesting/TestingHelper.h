// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 20:07)

#ifndef FRAMEWORK_TESTING_TESTING_HELPER_H
#define FRAMEWORK_TESTING_TESTING_HELPER_H

#include "Framework/MainFunctionHelper/AndroidMainFunctionHelperDetail.h"
#include "Framework/AndroidFrame/AndroidFrameBuildDetail.h"
#include "FrameworkTestingAndroidCallBack.h"

namespace Framework
{
	using TestingHelperBase = AndroidMainFunctionHelper<AndroidFrameBuild,AndroidProcessFrameworkTesting>; 

	class TestingHelper : public TestingHelperBase
	{
	public:
		typedef TestingHelper ClassType;
		typedef TestingHelperBase ParentType;

	public:
        explicit TestingHelper(AndroidApp* state,const Framework::EnvironmentDirectory& environmentDirectory);
		virtual ~TestingHelper();

		CLASS_INVARIANT_OVERRIDE_DECLARE;
	};
}

#endif // FRAMEWORK_TESTING_TESTING_HELPER_H
