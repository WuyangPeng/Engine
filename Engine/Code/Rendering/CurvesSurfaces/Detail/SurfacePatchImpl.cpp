///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/15 15:38)

#include "Rendering/RenderingExport.h"

#include "SurfacePatchImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

Rendering::SurfacePatchImpl::SurfacePatchImpl() noexcept
    : uMin{ 0.0f }, uMax{ 0.0f }, vMin{ 0.0f }, vMax{ 0.0f }, rectangular{ true }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::SurfacePatchImpl::SurfacePatchImpl(float uMin, float uMax, float vMin, float vMax, bool rectangular) noexcept
    : uMin{ uMin }, uMax{ uMax }, vMin{ vMin }, vMax{ vMax }, rectangular{ rectangular }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::SurfacePatchImpl::IsValid() const noexcept
{
    if (uMin <= uMax && vMin <= vMin)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::SurfacePatchImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.Read(uMin);
    source.Read(uMax);
    source.Read(vMin);
    source.Read(vMax);
    rectangular = source.ReadBool();
}

void Rendering::SurfacePatchImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.Write(uMin);
    target.Write(uMax);
    target.Write(vMin);
    target.Write(vMax);
    target.Write(rectangular);
}

int Rendering::SurfacePatchImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = CORE_TOOLS_STREAM_SIZE(uMin);
    size += CORE_TOOLS_STREAM_SIZE(uMax);
    size += CORE_TOOLS_STREAM_SIZE(vMin);
    size += CORE_TOOLS_STREAM_SIZE(vMax);
    size += CORE_TOOLS_STREAM_SIZE(rectangular);

    return size;
}

float Rendering::SurfacePatchImpl::GetUMin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return uMin;
}

float Rendering::SurfacePatchImpl::GetUMax() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return uMax;
}

float Rendering::SurfacePatchImpl::GetVMin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return vMin;
}

float Rendering::SurfacePatchImpl::GetVMax() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return vMax;
}

bool Rendering::SurfacePatchImpl::IsRectangular() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return rectangular;
}
