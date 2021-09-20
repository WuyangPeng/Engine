// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.4 (2019/09/17 10:08)

#ifndef PIXEL_MODEL_VIEW_CONTROLLER_TESTING_TESTING_HELPER_H
#define PIXEL_MODEL_VIEW_CONTROLLER_TESTING_TESTING_HELPER_H

#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"
#include "PixelModelViewControllerMessage.h"

namespace PixelModelViewController
{
	using TestingHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, PixelModelViewControllerTesting>;

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

#endif // PIXEL_MODEL_VIEW_CONTROLLER_TESTING_TESTING_HELPER_H
