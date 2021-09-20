// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/24 22:32)

#ifndef FRAMEWORK_APPLICATION_SUITE_OBJECT_MOTION_TESTING_H
#define FRAMEWORK_APPLICATION_SUITE_OBJECT_MOTION_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Mathematics/Algebra/AVector.h"

namespace Framework
{
	class ObjectMotionTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = ObjectMotionTesting;
		using ParentType = UnitTest;		
		using Matrixf = Mathematics::FloatMatrix;
		using AVectorf = Mathematics::FloatAVector;

	public:
		explicit ObjectMotionTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void NoParentMoveObjectTest();
		void ParentMoveObjectTest();
		void TrackBallDownTest();
		void NoParentRotateTrackBallTest();
		void ParentRotateTrackBallTest();

		void AssertRotate(const Matrixf& lhs, const Matrixf& rhs);

		AVectorf GetSphereVector(float x, float y) const;
	};
}

#endif // FRAMEWORK_APPLICATION_SUITE_OBJECT_MOTION_TESTING_H
