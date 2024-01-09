/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 14:05)

#include "Rendering/RenderingExport.h"

#include "VertexFormatAttribute.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/Resources/Flags/DataFormatType.h"
#include "Rendering/Resources/Flags/VertexFormatFlags.h"

Rendering::VertexFormatAttribute::VertexFormatAttribute() noexcept
    : dataFormatType{ DataFormatType::Unknown }, semantic{ Semantic::None }, unit{ 0 }, offset{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VertexFormatAttribute::VertexFormatAttribute(DataFormatType type, Semantic semantic, int unit) noexcept
    : dataFormatType{ type }, semantic{ semantic }, unit{ unit }, offset{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VertexFormatAttribute::VertexFormatAttribute(DataFormatType type, Semantic semantic, int unit, int offset) noexcept
    : dataFormatType{ type }, semantic{ semantic }, unit{ unit }, offset{ offset }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VertexFormatAttribute)

Rendering::DataFormatType Rendering::VertexFormatAttribute::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return dataFormatType;
}

void Rendering::VertexFormatAttribute::SetType(DataFormatType type) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    dataFormatType = type;
}

Rendering::VertexFormatFlags::Semantic Rendering::VertexFormatAttribute::GetSemantic() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return semantic;
}

void Rendering::VertexFormatAttribute::SetSemantic(Semantic aSemantic) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    semantic = aSemantic;
}

int Rendering::VertexFormatAttribute::GetUnit() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return unit;
}

void Rendering::VertexFormatAttribute::SetUnit(int aUnit) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    unit = aUnit;
}

int Rendering::VertexFormatAttribute::GetOffset() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return offset;
}

void Rendering::VertexFormatAttribute::SetOffset(int aOffset) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    offset = aOffset;
}

void Rendering::VertexFormatAttribute::SetVertexFormatAttribute(DataFormatType type, Semantic aSemantic, int aUnit, int aOffset) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    dataFormatType = type;
    semantic = aSemantic;
    unit = aUnit;
    offset = aOffset;
}

void Rendering::VertexFormatAttribute::Clear() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    SetVertexFormatAttribute(DataFormatType::Unknown, Semantic::None, 0, 0);
}

int Rendering::VertexFormatAttribute::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CoreTools::GetStreamSize(dataFormatType);
    size += CoreTools::GetStreamSize(semantic);
    size += CoreTools::GetStreamSize(unit);
    size += CoreTools::GetStreamSize(offset);

    return size;
}

void Rendering::VertexFormatAttribute::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteEnum(dataFormatType);
    target.WriteEnum(semantic);
    target.Write(unit);
    target.Write(offset);
}

void Rendering::VertexFormatAttribute::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadEnum(dataFormatType);
    source.ReadEnum(semantic);
    source.Read(unit);
    source.Read(offset);
}
