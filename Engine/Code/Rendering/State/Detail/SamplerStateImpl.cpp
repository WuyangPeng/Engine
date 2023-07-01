///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/29 11:16)

#include "Rendering/RenderingExport.h"

#include "SamplerStateImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Rendering/State/Flags/SamplerStateComparison.h"
#include "Rendering/State/Flags/SamplerStateFilter.h"
#include "Rendering/State/Flags/SamplerStateMode.h"

Rendering::SamplerStateImpl::SamplerStateImpl() noexcept
    : filter{ SamplerStateFilter::MinPMagPMipP },
      mode{ SamplerStateMode::Clamp, SamplerStateMode::Clamp, SamplerStateMode::Clamp },
      mipLODBias{ 0.0f },
      maxAnisotropy{ 1 },
      comparison{ SamplerStateComparison::Never },
      borderColor{ 1.0f, 1.0f, 1.0f, 1.0f },
      minLOD{ -std::numeric_limits<float>::max() },
      maxLOD{ std::numeric_limits<float>::max() }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, SamplerStateImpl)

void Rendering::SamplerStateImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadEnum(filter);
    source.ReadEnumContainer(mode);

    source.Read(mipLODBias);
    source.Read(maxAnisotropy);

    source.ReadEnum(comparison);
    source.ReadAggregate(borderColor);

    source.Read(minLOD);
    source.Read(maxLOD);
}

void Rendering::SamplerStateImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteEnum(filter);
    target.WriteEnumContainer(mode);

    target.Write(mipLODBias);
    target.Write(maxAnisotropy);

    target.WriteEnum(comparison);
    target.WriteAggregate(borderColor);

    target.Write(minLOD);
    target.Write(maxLOD);
}

int Rendering::SamplerStateImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = RENDERING_STREAM_SIZE(filter);

    size += RENDERING_STREAM_SIZE(mode);

    size += RENDERING_STREAM_SIZE(mipLODBias);
    size += RENDERING_STREAM_SIZE(maxAnisotropy);

    size += RENDERING_STREAM_SIZE(comparison);
    size += RENDERING_STREAM_SIZE(borderColor);

    size += RENDERING_STREAM_SIZE(minLOD);
    size += RENDERING_STREAM_SIZE(maxLOD);

    return size;
}

Rendering::SamplerStateFilter Rendering::SamplerStateImpl::GetFilter() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return filter;
}

Rendering::SamplerStateMode Rendering::SamplerStateImpl::GetMode(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return mode.at(index);
}

float Rendering::SamplerStateImpl::GetMipLODBias() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return mipLODBias;
}

int Rendering::SamplerStateImpl::GetMaxAnisotropy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return maxAnisotropy;
}

Rendering::SamplerStateComparison Rendering::SamplerStateImpl::GetComparison() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return comparison;
}

Rendering::SamplerStateImpl::Colour Rendering::SamplerStateImpl::GetBorderColor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return borderColor;
}

float Rendering::SamplerStateImpl::GetMinLOD() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return minLOD;
}

float Rendering::SamplerStateImpl::GetMaxLOD() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return maxLOD;
}
