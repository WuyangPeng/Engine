///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/21 11:17)

#include "DepthRangeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Rendering/RendererEngine/DepthRange.h"

Rendering::DepthRangeTesting::DepthRangeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, DepthRangeTesting)

void Rendering::DepthRangeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::DepthRangeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DepthRangeSuccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DepthRangeBoundaryTest);
    ASSERT_THROW_EXCEPTION_0(DepthRangeExceptionTest);
}

void Rendering::DepthRangeTesting::DepthRangeSuccessTest()
{
    constexpr auto zMin = -0.9f;
    constexpr auto zMax = 0.9f;

    const DepthRange depthRange{ zMin, zMax };

    ASSERT_APPROXIMATE(depthRange.GetZMin(), zMin, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE(depthRange.GetZMax(), zMax, Mathematics::MathF::GetZeroTolerance());
}

void Rendering::DepthRangeTesting::DepthRangeBoundaryTest()
{
    constexpr auto zMin = -1.0f;
    constexpr auto zMax = 1.0f;

    const DepthRange depthRange{ zMin, zMax };

    ASSERT_APPROXIMATE(depthRange.GetZMin(), zMin, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE(depthRange.GetZMax(), zMax, Mathematics::MathF::GetZeroTolerance());
}

void Rendering::DepthRangeTesting::DepthRangeExceptionTest()
{
    constexpr auto zMin = -1.1f;
    constexpr auto zMax = 1.0f;

    const DepthRange depthRange{ zMin, zMax };
}