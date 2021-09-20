// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.3.1.0 (2020/06/27 10:57)

#include "CameraMiddleLayerTesting.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Rendering/DataTypes/TransformDetail.h"

using std::min;
using std::string;
using std::to_string;

Framework::CameraMiddleLayerTesting
	::CameraMiddleLayerTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, CameraMiddleLayerTesting)

float Framework::CameraMiddleLayerTesting
	::CalculateMultiplier(const WindowSize& windowSize)
{
	const auto width = windowSize.GetWindowWidth();
	const auto height = windowSize.GetWindowHeight();

	const auto minValue = min(height, width);
	ASSERT_LESS_EQUAL_FAILURE_THROW(0, minValue, "除零错误。");

	return 1.0f / minValue;
}

float Framework::CameraMiddleLayerTesting
	::GetXTrack(int x, float multiplier, const WindowSize& windowSize) const noexcept
{
	const auto width = windowSize.GetWindowWidth();

	return (2 * x - width) * multiplier;
}

float Framework::CameraMiddleLayerTesting
	::GetYTrack(int y, float multiplier, const WindowSize& windowSize) const noexcept
{
	const auto height = windowSize.GetWindowHeight();

	return (2 * (height - 1 - y) - height) * multiplier;
}

const Rendering::FloatTransform Framework::CameraMiddleLayerTesting
	::CalculateTransform(const Transform& original, NumericalValueSymbol doValue, float speed, const AVectorf& axis)
{
	auto result = original;
	auto rotate = result.GetRotate();

	const auto angle = System::EnumCastUnderlying<float>(doValue) * speed;
        const Mathematics::FloatMatrix transform{ axis, angle };
	rotate = transform * rotate;
	rotate.Orthonormalize();
	result.SetRotate(rotate);

	return result;
}

const Mathematics::FloatAVector Framework::CameraMiddleLayerTesting
	::Calculate3DVector(float xTrack, float yTrack)
{
    const auto length = Mathematics::FloatMath::Sqrt(xTrack * xTrack + yTrack * yTrack);
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
            zTrack = (zTrack <= 0.0f ? 0.0f : Mathematics::FloatMath::Sqrt(zTrack));
	}
	zTrack *= -1.0f;

	return AVectorf{ zTrack, yTrack, xTrack };
}

float Framework::CameraMiddleLayerTesting
	::CalculateAngle(const AVectorf& axis, float dot)
{
	if (!axis.IsZero())
	{
            return Mathematics::FloatMath::ACos(dot);
	}
	else  
	{
		if (dot < 0.0f)
		{
                    return Mathematics::FloatMath::GetPI();
		}
		else
		{
			return 0.0f;
		}
	}
}

const Mathematics::FloatAVector Framework::CameraMiddleLayerTesting
	::CalculateAxis(const AVectorf& axis, float dot, float xBeginTrack, float yBeginTrack)
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
			const auto invLength = Mathematics::FloatMath::InvSqrt(xBeginTrack * xBeginTrack + yBeginTrack * yBeginTrack);
			AVectorf result{ yBeginTrack * invLength, -xBeginTrack * invLength, 0.0f };
			return result;
		}
		else
		{ 
			return AVectorf::GetUnitX();
		}
	}
}

void Framework::CameraMiddleLayerTesting
	::APointTest(const APointf& lhs, const APointf& rhs, const string& functionName, int index)
{
	using ApproximateFunction = bool(*)(const APointf& lhs, const APointf& rhs, float epsilon);
	ApproximateFunction approximateFunction{ Mathematics::Approximate<float> };
	auto message = "函数名为：" + functionName + "，序号：" + to_string(index);

	ASSERT_APPROXIMATE_USE_FUNCTION_AND_MESSAGE(approximateFunction, lhs, rhs, Mathematics::FloatMath::GetZeroTolerance(), message);
}

void Framework::CameraMiddleLayerTesting
	::AVectorTest(const AVectorf& lhs, const AVectorf& rhs, const string& functionName, int index)
{
	using ApproximateFunction = bool(*)(const AVectorf& lhs, const AVectorf& rhs, float epsilon);
	ApproximateFunction approximateFunction{ Mathematics::Approximate<float> };
	auto message = "函数名为：" + functionName + "，序号：" + to_string(index);

	ASSERT_APPROXIMATE_USE_FUNCTION_AND_MESSAGE(approximateFunction, lhs, rhs, Mathematics::FloatMath::GetZeroTolerance(), message);
}

void Framework::CameraMiddleLayerTesting
	::TransformTest(const Transform& lhs, const Transform& rhs, const string& functionName, int index)
{
	using ApproximateFunction = bool(*)(const Transform& lhs, const Transform& rhs, float epsilon);
	ApproximateFunction approximateFunction{ Rendering::Approximate };
	auto message = "函数名为：" + functionName + "，序号：" + to_string(index);

	ASSERT_APPROXIMATE_USE_FUNCTION_AND_MESSAGE(approximateFunction, lhs, rhs, Mathematics::FloatMath::GetZeroTolerance(), message);
}

void Framework::CameraMiddleLayerTesting
	::MatrixTest(const Matrixf& lhs, const Matrixf& rhs, const std::string& functionName, int index)
{
	using ApproximateFunction = bool(*)(const Matrixf& lhs, const Matrixf& rhs, float epsilon);
	ApproximateFunction approximateFunction{ Mathematics::Approximate };
	auto message = "函数名为：" + functionName + "，序号：" + to_string(index);

	ASSERT_APPROXIMATE_USE_FUNCTION_AND_MESSAGE(approximateFunction, lhs, rhs, Mathematics::FloatMath::GetZeroTolerance(), message);
}
