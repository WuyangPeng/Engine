///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 20:02)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_MIDDLE_LAYER_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_MIDDLE_LAYER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/DataTypes/Transform.h"

namespace Framework
{
    class WindowSize;

    class CameraMiddleLayerTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = CameraMiddleLayerTesting;
        using ParentType = UnitTest;
        using APointf = Mathematics::APointF;
        using AVectorf = Mathematics::AVectorF;
        using Matrixf = Mathematics::MatrixF;
        using NumericalValueSymbol = Mathematics::NumericalValueSymbol;
        using Transform = Rendering::TransformF;

    public:
        explicit CameraMiddleLayerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        NODISCARD float CalculateMultiplier(const WindowSize& windowSize);
        NODISCARD float GetXTrack(int x, float multiplier, const WindowSize& windowSize) const noexcept;
        NODISCARD float GetYTrack(int y, float multiplier, const WindowSize& windowSize) const noexcept;
        NODISCARD Transform CalculateTransform(const Transform& original, NumericalValueSymbol doValue, float speed, const AVectorf& axis);
        NODISCARD AVectorf Calculate3DVector(float xTrack, float yTrack) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        NODISCARD float CalculateAngle(const AVectorf& axis, float dot) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        NODISCARD AVectorf CalculateAxis(const AVectorf& axis, float dot, float xBeginTrack, float yBeginTrack);

        void APointTest(const APointf& lhs, const APointf& rhs, const std::string& functionName, int index);
        void AVectorTest(const AVectorf& lhs, const AVectorf& rhs, const std::string& functionName, int index);
        void TransformTest(const Transform& lhs, const Transform& rhs, const std::string& functionName, int index);
        void MatrixTest(const Matrixf& lhs, const Matrixf& rhs, const std::string& functionName, int index);
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_MIDDLE_LAYER_TESTING_H