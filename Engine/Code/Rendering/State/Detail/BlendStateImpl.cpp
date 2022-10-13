///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/18 18:07)

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
      target{},
      blendColor{ 0.0f, 0.0f, 0.0f, 0.0f },
      sampleMask{ 0xFFFFFFFFu }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, BlendStateImpl)

bool Rendering::BlendStateImpl::GetEnableAlphaToCoverage() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return enableAlphaToCoverage;
}

void Rendering::BlendStateImpl::SetEnableAlphaToCoverage(bool aEnableAlphaToCoverage) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    enableAlphaToCoverage = aEnableAlphaToCoverage;
}

bool Rendering::BlendStateImpl::GetEnableIndependentBlend() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return enableIndependentBlend;
}

void Rendering::BlendStateImpl::SetEnableIndependentBlend(bool aEnableIndependentBlend) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    enableIndependentBlend = aEnableIndependentBlend;
}

Rendering::BlendStateImpl::Colour Rendering::BlendStateImpl::GetBlendColor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return blendColor;
}

void Rendering::BlendStateImpl::SetBlendColor(Colour aBlendColor) noexcept
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

    return target.at(index);
}

void Rendering::BlendStateImpl::SetBlendStateTarget(int index, const BlendStateTarget& blendStateTarget)
{
    RENDERING_CLASS_IS_VALID_9;

    target.at(index) = blendStateTarget;
}

void Rendering::BlendStateImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    enableAlphaToCoverage = source.ReadBool();
    enableIndependentBlend = source.ReadBool();

    source.ReadAggregateContainer(target);
    source.ReadAggregate(blendColor);

    source.Read(sampleMask);
}

void Rendering::BlendStateImpl::Save(CoreTools::BufferTarget& aTarget) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    aTarget.Write(enableAlphaToCoverage);
    aTarget.Write(enableIndependentBlend);
    aTarget.WriteAggregateContainer(target);
    aTarget.WriteAggregate(blendColor);

    aTarget.Write(sampleMask);
}

int Rendering::BlendStateImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CORE_TOOLS_STREAM_SIZE(enableAlphaToCoverage);

    size += CORE_TOOLS_STREAM_SIZE(enableIndependentBlend);

    size += RENDERING_STREAM_SIZE(target);
    size += RENDERING_STREAM_SIZE(blendColor);

    size += CORE_TOOLS_STREAM_SIZE(sampleMask);

    return size;
}
