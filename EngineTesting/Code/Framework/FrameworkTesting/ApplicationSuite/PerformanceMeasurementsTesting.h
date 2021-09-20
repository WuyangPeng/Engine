// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/13 1:01)

#ifndef FRAMEWORK_APPLICATION_SUITE_PERFORMANCE_MEASUREMENTS_TESTING_H
#define FRAMEWORK_APPLICATION_SUITE_PERFORMANCE_MEASUREMENTS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class PerformanceMeasurementsTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = PerformanceMeasurementsTesting;
		using ParentType = UnitTest;

	public:
		explicit PerformanceMeasurementsTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void PerformanceMeasurementsTest();
	};
}

#endif // FRAMEWORK_APPLICATION_SUITE_PERFORMANCE_MEASUREMENTS_TESTING_H