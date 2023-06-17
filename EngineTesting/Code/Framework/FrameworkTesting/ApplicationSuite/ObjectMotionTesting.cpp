///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 20:26)

#include "ObjectMotionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Rendering/SceneGraph/Node.h"
#include "Framework/Application/ObjectMotion.h"

#include <random>

namespace Framework
{
    using TestingType = ObjectMotion;
}

Framework::ObjectMotionTesting::ObjectMotionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ObjectMotionTesting)

void Framework::ObjectMotionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::ObjectMotionTesting::MainTest()
{
    Rendering::CameraManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(NoParentMoveObjectTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ParentMoveObjectTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TrackBallDownTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NoParentRotateTrackBallTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ParentRotateTrackBallTest);

    Rendering::CameraManager::Destroy();
}

void Framework::ObjectMotionTesting::NoParentMoveObjectTest() noexcept
{
}

void Framework::ObjectMotionTesting::ParentMoveObjectTest() noexcept
{
}

void Framework::ObjectMotionTesting::TrackBallDownTest() noexcept
{
}

void Framework::ObjectMotionTesting::NoParentRotateTrackBallTest() noexcept
{
}

void Framework::ObjectMotionTesting::ParentRotateTrackBallTest() noexcept
{
}

void Framework::ObjectMotionTesting::AssertRotate(const Matrixf& lhs, const Matrixf& rhs)
{
    using Approximate = bool (*)(const Matrixf&, const Matrixf&, float);
    Approximate approximate{ Mathematics::Approximate<float> };

    ASSERT_APPROXIMATE_USE_FUNCTION(approximate, lhs, rhs, Mathematics::MathF::epsilon);
}

Mathematics::AVectorF Framework::ObjectMotionTesting::GetSphereVector(float x, float y) const noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    auto length = Mathematics::MathF::Sqrt(x * x + y * y);
    auto z = 0.0f;

    if (1.0f < length)
    {
        x /= length;
        y /= length;
        z = 0.0f;
    }
    else
    {
        z = 1.0f - x * x - y * y;
        z = (z <= 0.0f ? 0.0f : Mathematics::MathF::Sqrt(z));
    }
    z *= -1.0f;

    return AVectorf{ z, y, x };
}
