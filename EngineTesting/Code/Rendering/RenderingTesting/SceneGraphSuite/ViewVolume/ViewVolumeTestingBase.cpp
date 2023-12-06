/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/22 16:50)

#include "ViewVolumeTestingBase.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

Rendering::ViewVolumeTestingBase::ViewVolumeTestingBase(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ViewVolumeTestingBase)

Rendering::ViewVolumeTestingBase::Container Rendering::ViewVolumeTestingBase::GetFrustum(float upFieldOfViewDegrees, float aspectRatio, float directionMin, float directionMax) noexcept
{
    const auto halfAngleRadians = 0.5f * upFieldOfViewDegrees * Mathematics::MathF::GetDegreeToRadian();

    const auto upMax = directionMin * Mathematics::MathF::Tan(halfAngleRadians);
    const auto rightMax = aspectRatio * upMax;
    const auto upMin = -upMax;
    const auto rightMin = -rightMax;

    const auto invDirectionDiff = 1.0f / (directionMax - directionMin);
    const auto invUpDiff = 1.0f / (upMax - upMin);
    const auto invRightDiff = 1.0f / (rightMax - rightMin);

    return Container{ directionMin, directionMax, upMin, upMax, rightMin, rightMax, invDirectionDiff, invUpDiff, invRightDiff };
}
