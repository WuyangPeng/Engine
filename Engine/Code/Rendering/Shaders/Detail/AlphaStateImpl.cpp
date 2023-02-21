///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/11 13:44)

#include "Rendering/RenderingExport.h"

#include "AlphaStateImpl.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Rendering/DataTypes/SpecializedIO.h"

Rendering::AlphaStateImpl::AlphaStateImpl() noexcept
    : blendEnabled{ false },
      sourceBlend{ AlphaStateFlags::SourceBlendMode::SourceAlpha },
      destinationBlend{ AlphaStateFlags::DestinationBlendMode::OneMinusSourceAlpha },
      compareEnabled{ false },
      compare{ AlphaStateFlags::CompareMode::Always },
      reference{ 0.0f },
      constantColor{ 0.0f, 0.0f, 0.0f, 0.0f }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::AlphaStateImpl::IsValid() const noexcept
{
    if (0.0f <= reference && reference <= 1.0f)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

bool Rendering::AlphaStateImpl::IsBlendEnabled() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return blendEnabled;
}

void Rendering::AlphaStateImpl::SetBlendEnabled(bool aBlendEnabled) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    blendEnabled = aBlendEnabled;
}

Rendering::AlphaStateFlags::SourceBlendMode Rendering::AlphaStateImpl::GetSourceBlend() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return sourceBlend;
}

void Rendering::AlphaStateImpl::SetSourceBlend(AlphaStateFlags::SourceBlendMode mode) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    sourceBlend = mode;
}

Rendering::AlphaStateFlags::DestinationBlendMode Rendering::AlphaStateImpl::GetDestinationBlend() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return destinationBlend;
}

void Rendering::AlphaStateImpl::SetDestinationBlend(AlphaStateFlags::DestinationBlendMode mode) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    destinationBlend = mode;
}

bool Rendering::AlphaStateImpl::IsCompareEnabled() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return compareEnabled;
}

void Rendering::AlphaStateImpl::SetCompareEnabled(bool aCompareEnabled) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    compareEnabled = aCompareEnabled;
}

Rendering::AlphaStateFlags::CompareMode Rendering::AlphaStateImpl::GetCompare() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return compare;
}

void Rendering::AlphaStateImpl::SetCompare(AlphaStateFlags::CompareMode mode) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    compare = mode;
}

float Rendering::AlphaStateImpl::GetReference() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return reference;
}

void Rendering::AlphaStateImpl::SetReference(float aReference) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    reference = aReference;
}

Rendering::AlphaStateImpl::Colour Rendering::AlphaStateImpl::GetConstantColor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return constantColor;
}

void Rendering::AlphaStateImpl::SetConstantColor(const Colour& color) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    constantColor = color;
}

void Rendering::AlphaStateImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    blendEnabled = source.ReadBool();
    source.ReadEnum(sourceBlend);
    source.ReadEnum(destinationBlend);
    compareEnabled = source.ReadBool();
    source.ReadEnum(compare);
    source.Read(reference);
    source.ReadAggregate(constantColor);
}

void Rendering::AlphaStateImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.Write(blendEnabled);
    target.WriteEnum(sourceBlend);
    target.WriteEnum(destinationBlend);
    target.Write(compareEnabled);
    target.WriteEnum(compare);
    target.Write(reference);
    target.WriteAggregate(constantColor);
}

int Rendering::AlphaStateImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = CoreTools::GetStreamSize(blendEnabled);
    size += CoreTools::GetStreamSize(sourceBlend);
    size += CoreTools::GetStreamSize(destinationBlend);
    size += CoreTools::GetStreamSize(compareEnabled);
    size += CoreTools::GetStreamSize(compare);
    size += CoreTools::GetStreamSize(reference);
    size += RENDERING_STREAM_SIZE(constantColor);

    return size;
}

void Rendering::AlphaStateImpl::SaveState(WriteFileManager& manager) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto writeBlendEnabled = (blendEnabled ? 1 : 0);
    const auto wirteCompareEnabled = (compareEnabled ? 1 : 0);

    manager.Write(sizeof(int32_t), &writeBlendEnabled);
    manager.Write(sizeof(SourceBlendMode), &sourceBlend);
    manager.Write(sizeof(DestinationBlendMode), &destinationBlend);
    manager.Write(sizeof(int32_t), &wirteCompareEnabled);
    manager.Write(sizeof(CompareMode), &compare);
    manager.Write(sizeof(float), &reference);
    manager.Write(sizeof(float), 4, constantColor.GetPoint().data());
}

void Rendering::AlphaStateImpl::LoadState(ReadFileManager& manager)
{
    RENDERING_CLASS_IS_VALID_1;

    int32_t readBlendEnabled{ 0 };
    int32_t readCompareEnabled{ 0 };
    std::array<float, 4> color{};

    manager.Read(sizeof(int32_t), &readBlendEnabled);
    manager.Read(sizeof(SourceBlendMode), &sourceBlend);
    manager.Read(sizeof(DestinationBlendMode), &destinationBlend);
    manager.Read(sizeof(int32_t), &readCompareEnabled);
    manager.Read(sizeof(CompareMode), &compare);
    manager.Read(sizeof(float), &reference);
    manager.Read(sizeof(float), 4, color.data());

    blendEnabled = (readBlendEnabled == 1) ? true : false;
    compareEnabled = (readCompareEnabled == 1) ? true : false;
    constantColor.SetColour(color.at(0), color.at(1), color.at(2), color.at(3));
}
