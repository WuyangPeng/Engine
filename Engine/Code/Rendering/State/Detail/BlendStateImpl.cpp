/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 11:09)

#include "Rendering/RenderingExport.h"

#include "BlendStateImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Rendering/DataTypes/SpecializedIO.h"

Rendering::BlendStateImpl::BlendStateImpl() noexcept
    : enableAlphaToCoverage{ false },
      enableIndependentBlend{ false },
      blendStateTarget{},
      blendColor{ 0.0f, 0.0f, 0.0f, 0.0f },
      sampleMask{ 0xFFFFFFFFu }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, BlendStateImpl)

bool Rendering::BlendStateImpl::IsEnableAlphaToCoverage() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return enableAlphaToCoverage;
}

void Rendering::BlendStateImpl::SetEnableAlphaToCoverage(bool aEnableAlphaToCoverage) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    enableAlphaToCoverage = aEnableAlphaToCoverage;
}

bool Rendering::BlendStateImpl::IsEnableIndependentBlend() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return enableIndependentBlend;
}

void Rendering::BlendStateImpl::SetEnableIndependentBlend(bool aEnableIndependentBlend) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    enableIndependentBlend = aEnableIndependentBlend;
}

Rendering::BlendStateImpl::ColourType Rendering::BlendStateImpl::GetBlendColor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return blendColor;
}

void Rendering::BlendStateImpl::SetBlendColor(const ColourType& aBlendColor) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    blendColor = aBlendColor;
}

uint32_t Rendering::BlendStateImpl::GetSampleMask() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return sampleMask;
}

void Rendering::BlendStateImpl::SetSampleMask(uint32_t aSampleMask) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    sampleMask = aSampleMask;
}

Rendering::BlendStateTarget Rendering::BlendStateImpl::GetBlendStateTarget(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return blendStateTarget.at(index);
}

void Rendering::BlendStateImpl::SetBlendStateTarget(int index, const BlendStateTarget& aBlendStateTarget)
{
    RENDERING_CLASS_IS_VALID_9;

    blendStateTarget.at(index) = aBlendStateTarget;
}

void Rendering::BlendStateImpl::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.Read(enableAlphaToCoverage);
    source.Read(enableIndependentBlend);
    source.ReadAggregateContainer(blendStateTarget);
    source.ReadAggregate(blendColor);
    source.Read(sampleMask);
}

void Rendering::BlendStateImpl::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Write(enableAlphaToCoverage);
    target.Write(enableIndependentBlend);
    target.WriteAggregateContainer(blendStateTarget);
    target.WriteAggregate(blendColor);
    target.Write(sampleMask);
}

int Rendering::BlendStateImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = RENDERING_STREAM_SIZE(enableAlphaToCoverage);

    size += RENDERING_STREAM_SIZE(enableIndependentBlend);
    size += RENDERING_STREAM_SIZE(blendStateTarget);
    size += RENDERING_STREAM_SIZE(blendColor);
    size += RENDERING_STREAM_SIZE(sampleMask);

    return size;
}
