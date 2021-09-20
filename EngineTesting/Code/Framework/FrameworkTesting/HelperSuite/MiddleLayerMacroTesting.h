// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.1 (2020/05/26 23:52)

#ifndef FRAMEWORK_HELPER_SUITE_MIDDLE_LAYER_MACRO_TESTING_H
#define FRAMEWORK_HELPER_SUITE_MIDDLE_LAYER_MACRO_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h" 

namespace Framework
{
	class MiddleLayerMacroTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = MiddleLayerMacroTesting;
		using ParentType = UnitTest;		

	public:
		explicit MiddleLayerMacroTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;	 

	private:
		void DoRunUnitTest() final;

		void MainTest();		

		void HelperManagerSuccessTest();
		void ChildHelperManagerSuccessTest();

		void HelperManagerNetworkExceptionTest();
		void HelperManagerPhysicalModellingExceptionTest();
		void HelperManagerSystemExceptionTest();
		void HelperManagerGUIExceptionTest();

		void ChildHelperManagerNetworkExceptionTest();
		void ChildHelperManagerPhysicalModellingExceptionTest();
		void ChildHelperManagerSystemExceptionTest();
		void ChildHelperManagerGUIExceptionTest();
	};
}

#endif // FRAMEWORK_HELPER_SUITE_MIDDLE_LAYER_MACRO_TESTING_H