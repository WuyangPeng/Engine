// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 15:55)

#include "Rendering/RenderingExport.h"

#include "AlphaStateImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26493)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26485)
Rendering::AlphaStateImpl ::AlphaStateImpl()
    : m_BlendEnabled{ false }, m_SourceBlend{ AlphaStateFlags::SourceBlendMode::SourceAlpha },
      m_DestinationBlend{ AlphaStateFlags::DestinationBlendMode::OneMinusSourceAlpha }, m_CompareEnabled{ false },
      m_Compare{ AlphaStateFlags::CompareMode::Always }, m_Reference{ 0.0f }, m_ConstantColor{ 0.0f, 0.0f, 0.0f, 0.0f }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::AlphaStateImpl ::IsValid() const noexcept
{
    if (0.0f <= m_Reference && m_Reference <= 1.0f)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

bool Rendering::AlphaStateImpl ::IsBlendEnabled() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_BlendEnabled;
}

void Rendering::AlphaStateImpl ::SetBlendEnabled(bool blendEnabled)
{
    RENDERING_CLASS_IS_VALID_1;

    m_BlendEnabled = blendEnabled;
}

Rendering::AlphaStateFlags::SourceBlendMode Rendering::AlphaStateImpl ::GetSourceBlend() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_SourceBlend;
}

void Rendering::AlphaStateImpl ::SetSourceBlend(AlphaStateFlags::SourceBlendMode mode)
{
    RENDERING_CLASS_IS_VALID_1;

    m_SourceBlend = mode;
}

Rendering::AlphaStateFlags::DestinationBlendMode Rendering::AlphaStateImpl ::GetDestinationBlend() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_DestinationBlend;
}

void Rendering::AlphaStateImpl ::SetDestinationBlend(AlphaStateFlags::DestinationBlendMode mode)
{
    RENDERING_CLASS_IS_VALID_1;

    m_DestinationBlend = mode;
}

bool Rendering::AlphaStateImpl ::IsCompareEnabled() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_CompareEnabled;
}

void Rendering::AlphaStateImpl ::SetCompareEnabled(bool compareEnabled)
{
    RENDERING_CLASS_IS_VALID_1;

    m_CompareEnabled = compareEnabled;
}

Rendering::AlphaStateFlags::CompareMode Rendering::AlphaStateImpl ::GetCompare() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Compare;
}

void Rendering::AlphaStateImpl ::SetCompare(AlphaStateFlags::CompareMode mode)
{
    RENDERING_CLASS_IS_VALID_1;

    m_Compare = mode;
}

float Rendering::AlphaStateImpl ::GetReference() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Reference;
}

void Rendering::AlphaStateImpl ::SetReference(float reference)
{
    RENDERING_CLASS_IS_VALID_1;

    m_Reference = reference;
}

const Rendering::AlphaStateImpl::Colour Rendering::AlphaStateImpl ::GetConstantColor() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_ConstantColor;
}

void Rendering::AlphaStateImpl ::SetConstantColor(const Colour& color)
{
    RENDERING_CLASS_IS_VALID_1;

    m_ConstantColor = color;
}

void Rendering::AlphaStateImpl ::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    m_BlendEnabled = source.ReadBool();
    source.ReadEnum(m_SourceBlend);
    source.ReadEnum(m_DestinationBlend);
    m_CompareEnabled = source.ReadBool();
    source.ReadEnum(m_Compare);
    source.Read(m_Reference);
    source.ReadAggregate(m_ConstantColor);
}

void Rendering::AlphaStateImpl ::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.WriteBool(m_BlendEnabled);
    target.WriteEnum(m_SourceBlend);
    target.WriteEnum(m_DestinationBlend);
    target.WriteBool(m_CompareEnabled);
    target.WriteEnum(m_Compare);
    target.Write(m_Reference);
    target.WriteAggregate(m_ConstantColor);
}

int Rendering::AlphaStateImpl ::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = CORE_TOOLS_STREAM_SIZE(m_BlendEnabled);
    size += CORE_TOOLS_STREAM_SIZE(m_SourceBlend);
    size += CORE_TOOLS_STREAM_SIZE(m_DestinationBlend);
    size += CORE_TOOLS_STREAM_SIZE(m_CompareEnabled);
    size += CORE_TOOLS_STREAM_SIZE(m_Compare);
    size += CORE_TOOLS_STREAM_SIZE(m_Reference);
    size += RENDERING_STREAM_SIZE(m_ConstantColor);

    return size;
}

void Rendering::AlphaStateImpl ::SaveState(WriteFileManager& manager) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto blendEnabled = (m_BlendEnabled ? 1 : 0);
    const auto srcBlend = System::EnumCastUnderlying(m_SourceBlend);
    const auto dstBlend = System::EnumCastUnderlying(m_DestinationBlend);
    const auto compareEnabled = (m_CompareEnabled ? 1 : 0);
    const auto compare = System::EnumCastUnderlying(m_Compare);
    const auto reference = m_Reference;
    const auto constantColor = m_ConstantColor;

    manager.Write(sizeof(int), &blendEnabled);
    manager.Write(sizeof(int), &srcBlend);
    manager.Write(sizeof(int), &dstBlend);
    manager.Write(sizeof(int), &compareEnabled);
    manager.Write(sizeof(int), &compare);
    manager.Write(sizeof(float), &reference);
    manager.Write(sizeof(float), 4, constantColor.GetPoint());
}

void Rendering::AlphaStateImpl ::LoadState(ReadFileManager& manager)
{
    RENDERING_CLASS_IS_VALID_1;

    int blendEnabled{ 0 };
    int srcBlend{ 0 };
    int dstBlend{ 0 };
    int compareEnabled{ 0 };
    int compare{ 0 };
    float reference{ 0.0f };
    float constantColor[4]{ 0.0f, 0.0f, 0.0f, 0.0f };
    manager.Read(sizeof(int), &blendEnabled);
    manager.Read(sizeof(int), &srcBlend);
    manager.Read(sizeof(int), &dstBlend);
    manager.Read(sizeof(int), &compareEnabled);
    manager.Read(sizeof(int), &compare);
    manager.Read(sizeof(float), &reference);
    manager.Read(sizeof(float), 4, constantColor);

    m_BlendEnabled = (blendEnabled == 1) ? true : false;
    m_SourceBlend = SourceBlendMode(srcBlend);
    m_DestinationBlend = DestinationBlendMode(dstBlend);
    m_CompareEnabled = (compareEnabled == 1) ? true : false;
    m_Compare = CompareMode(compare);
    m_Reference = reference;
    m_ConstantColor.SetColour(constantColor[0], constantColor[1], constantColor[2], constantColor[3]);
}

#include STSTEM_WARNING_POP