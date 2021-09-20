// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.1.0 (2020/06/27 10:46)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_MIDDLE_LAYER_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_MIDDLE_LAYER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Mathematics/Algebra/AVector.h"
#include "Rendering/DataTypes/Transform.h"

namespace Framework
{
	class WindowSize;

	class CameraMiddleLayerTesting : public CoreTools::UnitTest
	{
	public:
		using ClassType = CameraMiddleLayerTesting;
		using ParentType = UnitTest;
		using APointf = Mathematics::FloatAPoint;
		using AVectorf = Mathematics::FloatAVector;
		using Matrixf = Mathematics::FloatMatrix;
		using NumericalValueSymbol = Mathematics::NumericalValueSymbol;
		using Transform = Rendering::FloatTransform;

	public:
		explicit CameraMiddleLayerTesting(const OStreamShared& stream);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	protected:
		float CalculateMultiplier(const WindowSize& windowSize);
		float GetXTrack(int x, float multiplier, const WindowSize& windowSize) const noexcept;
		float GetYTrack(int y, float multiplier, const WindowSize& windowSize) const noexcept;
		const Transform CalculateTransform(const Transform& original, NumericalValueSymbol doValue, float speed, const AVectorf& axis);
		const AVectorf Calculate3DVector(float xTrack, float yTrack);
		float CalculateAngle(const AVectorf& axis, float dot);
		const AVectorf CalculateAxis(const AVectorf& axis, float dot, float xBeginTrack, float yBeginTrack);

		void APointTest(const APointf& lhs, const APointf& rhs, const std::string& functionName, int index);
		void AVectorTest(const AVectorf& lhs, const AVectorf& rhs, const std::string& functionName, int index);
		void TransformTest(const Transform& lhs, const Transform& rhs, const std::string& functionName, int index);
		void MatrixTest(const Matrixf& lhs, const Matrixf& rhs, const std::string& functionName, int index);
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_MIDDLE_LAYER_TESTING_H