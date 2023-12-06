/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/27 14:42)

#include "PickLineTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Rendering/SceneGraph/PickLine.h"

Rendering::PickLineTesting::PickLineTesting(const OStreamShared& stream)
    : ParentType{ stream },
      viewVolumeTool{ GetEngineRandomSeed() },
      aPointApproximateFunction{ Mathematics::Approximate<float> },
      aVectorApproximateFunction{ Mathematics::Approximate<float> }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, PickLineTesting)

void Rendering::PickLineTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::PickLineTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DataTest);
}

void Rendering::PickLineTesting::DataTest()
{
    const PickLine pickLine0{};

    ASSERT_FALSE(pickLine0.IsContain());

    constexpr auto epsilon = Mathematics::MathF::GetZeroTolerance();
    const auto origin = viewVolumeTool.ComputePosition();
    const auto direction = viewVolumeTool.ComputeVector();

    const PickLine pickLine1{ origin, direction, true };

    ASSERT_TRUE(pickLine1.IsContain());
    ASSERT_APPROXIMATE_USE_FUNCTION(aPointApproximateFunction, pickLine1.GetOrigin(), origin, epsilon);
    ASSERT_APPROXIMATE_USE_FUNCTION(aVectorApproximateFunction, pickLine1.GetDirection(), direction, epsilon);
}
