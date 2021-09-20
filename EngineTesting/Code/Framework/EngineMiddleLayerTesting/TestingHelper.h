// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 19:40)

#ifndef ENGINE_MIDDLE_LAYER_TESTING_TESTING_HELPER_H
#define ENGINE_MIDDLE_LAYER_TESTING_TESTING_HELPER_H

#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"
#include "EngineMiddleLayerMessage.h"

namespace EngineMiddleLayer
{
	using TestingHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, EngineMiddleLayerTesting>;

	class TestingHelper : public TestingHelperBase
	{
	public:
		using ClassType = TestingHelper;
		using ParentType = TestingHelperBase;
		using WindowApplicationInformation = Framework::WindowApplicationInformation;
		using EnvironmentDirectory = Framework::EnvironmentDirectory;

	public:
		TestingHelper(HInstance instance, const char* commandLine,const WindowApplicationInformation& information,const EnvironmentDirectory& environmentDirectory);
		virtual ~TestingHelper();

		CLASS_INVARIANT_OVERRIDE_DECLARE;
	};
}

#endif // ENGINE_MIDDLE_LAYER_TESTING_TESTING_HELPER_H
