///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/12 16:33)

#include "CameraMiddleLayerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Rendering/DataTypes/TransformDetail.h"
#include "Rendering/DataTypes/TransformMatrixDetail.h"
#include "Framework/WindowCreate/WindowSize.h"

Framework::CameraMiddleLayerTesting::CameraMiddleLayerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, CameraMiddleLayerTesting)

float Framework::CameraMiddleLayerTesting::CalculateMultiplier(const WindowSize& windowSize)
{
    const auto width = windowSize.GetWindowWidth();
    const auto height = windowSize.GetWindowHeight();

    const auto minValue = std::min(width, height);
    ASSERT_LESS_EQUAL_FAILURE_THROW(0, minValue, "除零错误。");

    return 1.0f / static_cast<float>(minValue);
}

float Framework::CameraMiddleLayerTesting::GetXTrack(int x, float multiplier, const WindowSize& windowSize) const noexcept
{
    const auto width = windowSize.GetWindowWidth();

    return static_cast<float>(2 * x - width) * multiplier;
}

float Framework::CameraMiddleLayerTesting::GetYTrack(int y, float multiplier, const WindowSize& windowSize) const noexcept
{
    const auto height = windowSize.GetWindowHeight();

    return static_cast<float>(2 * (height - 1 - y) - height) * multiplier;
}

Rendering::TransformF Framework::CameraMiddleLayerTesting::CalculateTransform(const Transform& original, NumericalValueSymbol doValue, float speed, const AVector& axis)
{
    auto result = original;
    auto rotate = result.GetRotate();

    const auto angle = System::EnumCastUnderlying<float>(doValue) * speed;
    const Mathematics::MatrixF transform{ axis, angle };
    rotate = transform * rotate;
    rotate.Orthonormalize();
    result.SetRotate(rotate);

    return result;
}

Mathematics::AVectorF Framework::CameraMiddleLayerTesting::Calculate3DVector(float xTrack, float yTrack) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    const auto length = Mathematics::MathF::Sqrt(xTrack * xTrack + yTrack * yTrack);
    auto zTrack = 0.0f;

    if (1.0f < length)
    {
        xTrack /= length;
        yTrack /= length;
        zTrack = 0.0f;
    }
    else
    {
        zTrack = 1.0f - xTrack * xTrack - yTrack * yTrack;
        zTrack = (zTrack <= 0.0f ? 0.0f : Mathematics::MathF::Sqrt(zTrack));
    }
    zTrack *= -1.0f;

    return AVector{ zTrack, yTrack, xTrack };
}

float Framework::CameraMiddleLayerTesting::CalculateAngle(const AVector& axis, float dot) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    if (!axis.IsZero())
    {
        return Mathematics::MathF::ACos(dot);
    }
    else
    {
        if (dot < 0.0f)
        {
            return Mathematics::MathF::GetPI();
        }
        else
        {
            return 0.0f;
        }
    }
}

Mathematics::AVectorF Framework::CameraMiddleLayerTesting::CalculateAxis(const AVector& axis, float dot, float xBeginTrack, float yBeginTrack)
{
    if (!axis.IsZero())
    {
        auto result = axis;
        result.Normalize();

        return result;
    }
    else
    {
        if (dot < 0.0f)
        {
            const auto invLength = Mathematics::MathF::InvSqrt(xBeginTrack * xBeginTrack + yBeginTrack * yBeginTrack);
            const AVector result{ yBeginTrack * invLength, -xBeginTrack * invLength, 0.0f };
            return result;
        }
        else
        {
            return AVector::GetUnitX();
        }
    }
}

void Framework::CameraMiddleLayerTesting::APointTest(const APoint& lhs, const APoint& rhs, const std::string& functionName, int index)
{
    using ApproximateFunction = bool (*)(const APoint&, const APoint&, float);
    ApproximateFunction approximateFunction{ Mathematics::Approximate<float> };
    const auto message = "函数名为：" + functionName + "，序号：" + std::to_string(index);

    ASSERT_APPROXIMATE_USE_FUNCTION_AND_MESSAGE(approximateFunction, lhs, rhs, Mathematics::MathF::GetZeroTolerance(), message);
}

void Framework::CameraMiddleLayerTesting::AVectorTest(const AVector& lhs, const AVector& rhs, const std::string& functionName, int index)
{
    using ApproximateFunction = bool (*)(const AVector&, const AVector&, float);
    ApproximateFunction approximateFunction{ Mathematics::Approximate<float> };
    const auto message = "函数名为：" + functionName + "，序号：" + std::to_string(index);

    ASSERT_APPROXIMATE_USE_FUNCTION_AND_MESSAGE(approximateFunction, lhs, rhs, Mathematics::MathF::GetZeroTolerance(), message);
}

void Framework::CameraMiddleLayerTesting::TransformTest(const Transform& lhs, const Transform& rhs, const std::string& functionName, int index)
{
    using ApproximateFunction = bool (*)(const Transform&, const Transform&, float);
    ApproximateFunction approximateFunction{ Rendering::Approximate };
    const auto message = "函数名为：" + functionName + "，序号：" + std::to_string(index);

    ASSERT_APPROXIMATE_USE_FUNCTION_AND_MESSAGE(approximateFunction, lhs, rhs, Mathematics::MathF::GetZeroTolerance(), message);
}

void Framework::CameraMiddleLayerTesting::MatrixTest(const Matrix& lhs, const Matrix& rhs, const std::string& functionName, int index)
{
    using ApproximateFunction = bool (*)(const Matrix&, const Matrix&, float);
    ApproximateFunction approximateFunction{ Mathematics::Approximate };
    const auto message = "函数名为：" + functionName + "，序号：" + std::to_string(index);

    ASSERT_APPROXIMATE_USE_FUNCTION_AND_MESSAGE(approximateFunction, lhs, rhs, Mathematics::MathF::GetZeroTolerance(), message);
}
