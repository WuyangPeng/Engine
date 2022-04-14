///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/01 10:27)

#include "Rendering/RenderingExport.h"

#include "CameraFrustumData.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::CameraFrustumData::CameraFrustumData() noexcept
    : upFieldOfViewDegrees{ 0.0f }, aspectRatio{ 0.0f }, directionMin{ 0.0f }, directionMax{ 0.0f }, symmetric{ false }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::CameraFrustumData::CameraFrustumData(float upFieldOfViewDegrees, float aspectRatio, float directionMin, float directionMax, bool symmetric) noexcept
    : upFieldOfViewDegrees{ upFieldOfViewDegrees },
      aspectRatio{ aspectRatio },
      directionMin{ directionMin },
      directionMax{ directionMax },
      symmetric{ symmetric }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, CameraFrustumData)

float Rendering::CameraFrustumData::GetUpFieldOfViewDegrees() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(symmetric, "参数是无效的。");

    return upFieldOfViewDegrees;
}

float Rendering::CameraFrustumData::GetAspectRatio() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(symmetric, "参数是无效的。");

    return aspectRatio;
}

float Rendering::CameraFrustumData::GetDirectionMin() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(symmetric, "参数是无效的。");

    return directionMin;
}

float Rendering::CameraFrustumData::GetDirectionMax() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(symmetric, "参数是无效的。");

    return directionMax;
}

bool Rendering::CameraFrustumData::IsSymmetric() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return symmetric;
}
