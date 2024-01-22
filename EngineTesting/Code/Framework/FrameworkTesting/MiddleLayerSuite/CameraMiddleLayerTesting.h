///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/12 15:21)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_MIDDLE_LAYER_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_MIDDLE_LAYER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Mathematics/Algebra/Transform.h"

namespace Framework
{
    class WindowSize;

    class CameraMiddleLayerTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = CameraMiddleLayerTesting;
        using ParentType = UnitTest;

        using APoint = Mathematics::APointF;
        using AVector = Mathematics::AVectorF;
        using Matrix = Mathematics::MatrixF;
        using NumericalValueSymbol = Mathematics::NumericalValueSymbol;
        using Transform = Mathematics::TransformF;

    public:
        explicit CameraMiddleLayerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        NODISCARD float CalculateMultiplier(const WindowSize& windowSize);
        NODISCARD float GetXTrack(int x, float multiplier, const WindowSize& windowSize) const noexcept;
        NODISCARD float GetYTrack(int y, float multiplier, const WindowSize& windowSize) const noexcept;
        NODISCARD Transform CalculateTransform(const Transform& original, NumericalValueSymbol doValue, float speed, const AVector& axis);
        NODISCARD AVector Calculate3DVector(float xTrack, float yTrack) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        NODISCARD float CalculateAngle(const AVector& axis, float dot) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        NODISCARD AVector CalculateAxis(const AVector& axis, float dot, float xBeginTrack, float yBeginTrack);

        void APointTest(const APoint& lhs, const APoint& rhs, const std::string& functionName, int index);
        void AVectorTest(const AVector& lhs, const AVector& rhs, const std::string& functionName, int index);
        void TransformTest(const Transform& lhs, const Transform& rhs, const std::string& functionName, int index);
        void MatrixTest(const Matrix& lhs, const Matrix& rhs, const std::string& functionName, int index);
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_MIDDLE_LAYER_TESTING_H