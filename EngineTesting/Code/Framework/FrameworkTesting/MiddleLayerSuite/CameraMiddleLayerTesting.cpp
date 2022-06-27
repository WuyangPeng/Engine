///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/26 22:44)

#include "CameraMiddleLayerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Rendering/DataTypes/TransformDetail.h"
#include "Rendering/DataTypes/TransformMatrixDetail.h"
#include "Framework/WindowCreate/WindowSize.h"

using std::min;
using std::string;
using std::to_string;

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

    const auto minValue = min(height, width);
    ASSERT_LESS_EQUAL_FAILURE_THROW(0, minValue, "�������");

    return 1.0f / minValue;
}

float Framework::CameraMiddleLayerTesting::GetXTrack(int x, float multiplier, const WindowSize& windowSize) const noexcept
{
    const auto width = windowSize.GetWindowWidth();

    return (2 * x - width) * multiplier;
}

float Framework::CameraMiddleLayerTesting::GetYTrack(int y, float multiplier, const WindowSize& windowSize) const noexcept
{
    const auto height = windowSize.GetWindowHeight();

    return (2 * (height - 1 - y) - height) * multiplier;
}

Rendering::TransformF Framework::CameraMiddleLayerTesting::CalculateTransform(const Transform& original, NumericalValueSymbol doValue, float speed, const AVectorf& axis)
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

Mathematics::AVectorF Framework::CameraMiddleLayerTesting::Calculate3DVector(float xTrack, float yTrack) noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
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

    return AVectorf{ zTrack, yTrack, xTrack };
}

float Framework::CameraMiddleLayerTesting::CalculateAngle(const AVectorf& axis, float dot) noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
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

Mathematics::AVectorF Framework::CameraMiddleLayerTesting::CalculateAxis(const AVectorf& axis, float dot, float xBeginTrack, float yBeginTrack)
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
            AVectorf result{ yBeginTrack * invLength, -xBeginTrack * invLength, 0.0f };
            return result;
        }
        else
        {
            return AVectorf::GetUnitX();
        }
    }
}

void Framework::CameraMiddleLayerTesting::APointTest(const APointf& lhs, const APointf& rhs, const string& functionName, int index)
{
    using ApproximateFunction = bool (*)(const APointf& lhs, const APointf& rhs, float epsilon);
    ApproximateFunction approximateFunction{ Mathematics::Approximate<float> };
    auto message = "������Ϊ��" + functionName + "����ţ�" + to_string(index);

    ASSERT_APPROXIMATE_USE_FUNCTION_AND_MESSAGE(approximateFunction, lhs, rhs, Mathematics::MathF::GetZeroTolerance(), message);
}

void Framework::CameraMiddleLayerTesting::AVectorTest(const AVectorf& lhs, const AVectorf& rhs, const string& functionName, int index)
{
    using ApproximateFunction = bool (*)(const AVectorf& lhs, const AVectorf& rhs, float epsilon);
    ApproximateFunction approximateFunction{ Mathematics::Approximate<float> };
    auto message = "������Ϊ��" + functionName + "����ţ�" + to_string(index);

    ASSERT_APPROXIMATE_USE_FUNCTION_AND_MESSAGE(approximateFunction, lhs, rhs, Mathematics::MathF::GetZeroTolerance(), message);
}

void Framework::CameraMiddleLayerTesting::TransformTest(const Transform& lhs, const Transform& rhs, const string& functionName, int index)
{
    using ApproximateFunction = bool (*)(const Transform& lhs, const Transform& rhs, float epsilon);
    ApproximateFunction approximateFunction{ Rendering::Approximate };
    auto message = "������Ϊ��" + functionName + "����ţ�" + to_string(index);

    ASSERT_APPROXIMATE_USE_FUNCTION_AND_MESSAGE(approximateFunction, lhs, rhs, Mathematics::MathF::GetZeroTolerance(), message);
}

void Framework::CameraMiddleLayerTesting::MatrixTest(const Matrixf& lhs, const Matrixf& rhs, const std::string& functionName, int index)
{
    using ApproximateFunction = bool (*)(const Matrixf& lhs, const Matrixf& rhs, float epsilon);
    ApproximateFunction approximateFunction{ Mathematics::Approximate };
    auto message = "������Ϊ��" + functionName + "����ţ�" + to_string(index);

    ASSERT_APPROXIMATE_USE_FUNCTION_AND_MESSAGE(approximateFunction, lhs, rhs, Mathematics::MathF::GetZeroTolerance(), message);
}
