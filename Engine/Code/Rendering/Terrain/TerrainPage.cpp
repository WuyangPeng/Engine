///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:24)

#include "Rendering/RenderingExport.h"

#include "TerrainPage.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/SceneGraph/StandardMesh.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, TerrainPage);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, TerrainPage);
CORE_TOOLS_FACTORY_DEFINE(Rendering, TerrainPage);

Rendering::TerrainPage::TerrainPage(const VertexFormatSharedPtr& vformat, int size, const std::vector<uint16_t>& heights, const Mathematics::Float2& origin, float minElevation, float maxElevation, float spacing)
    : ParentType{ vformat, nullptr, nullptr },
      pageSize{ size },
      sizeM1{ size - 1 },
      heights{ heights },
      origin{ origin },
      minElevation{ minElevation },
      maxElevation{ maxElevation },
      spacing{ spacing },
      invSpacing{ 1.0f / spacing },
      multiplier{ (maxElevation - minElevation) / 65535.0f }
{
    RENDERING_ASSERTION_0(size == 3 || size == 5 || size == 9 || size == 17 || size == 33 || size == 65 || size == 129, "页面大小无效\n");

    const auto ext = spacing * sizeM1;
    auto mesh = StandardMesh(vformat).Rectangle(pageSize, pageSize, ext, ext);
    SetVertexFormat(vformat);
    SetVertexBuffer(mesh->GetVertexBuffer());
    SetIndexBuffer(mesh->GetIndexBuffer());

    const auto numVertices = GetVertexBuffer()->GetNumElements();
    for (auto i = 0; i < numVertices; ++i)
    {
        MAYBE_UNUSED const auto x = i % pageSize;
        MAYBE_UNUSED const auto y = i / pageSize;
    }

    UpdateModelSpace(VisualUpdateType::Normals);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, TerrainPage)

float Rendering::TerrainPage::GetHeight(float x, float y) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto xGrid = (x - origin[0]) * invSpacing;
    if (xGrid < 0.0f || xGrid >= (float)sizeM1)
    {
        return Mathematics::MathF::maxReal;
    }

    const auto yGrid = (y - origin[1]) * invSpacing;
    if (yGrid < 0.0f || yGrid >= (float)sizeM1)
    {
        return Mathematics::MathF::maxReal;
    }

    const auto fCol = Mathematics::MathF::Floor(xGrid);
    const auto iCol = boost::numeric_cast<int>(fCol);
    const auto fRow = Mathematics::MathF::Floor(yGrid);
    const auto iRow = boost::numeric_cast<int>(fRow);

    const auto index = iCol + pageSize * iRow;
    const auto dx = xGrid - fCol;
    const auto dy = yGrid - fRow;
    auto height = 0.0f;

    if ((iCol & 1) == (iRow & 1))
    {
        const auto diff = dx - dy;
        const auto h00 = minElevation + multiplier * heights.at(index);
        const auto nextIndex = index + 1 + pageSize;
        const auto h11 = minElevation + multiplier * heights.at(nextIndex);
        if (diff > 0.0f)
        {
            const auto index1 = index + 1;
            const auto h10 = minElevation + multiplier * heights.at(index1);
            height = (1.0f - diff - dy) * h00 + diff * h10 + dy * h11;
        }
        else
        {
            const auto index1 = index + pageSize;
            const auto h01 = minElevation + multiplier * heights.at(index1);
            height = (1.0f + diff - dx) * h00 - diff * h01 + dx * h11;
        }
    }
    else
    {
        const auto sum = dx + dy;
        const auto index0 = index + 1;
        const auto index1 = index + pageSize;
        const auto h10 = minElevation + multiplier * heights.at(index0);
        const auto h01 = minElevation + multiplier * heights.at(index1);
        if (sum <= 1.0f)
        {
            const auto h00 = minElevation + multiplier * heights.at(index);
            height = (1.0f - sum) * h00 + dx * h10 + dy * h01;
        }
        else
        {
            const auto nextIndex = index + 1 + pageSize;
            const auto h11 = minElevation + multiplier * heights.at(nextIndex);
            height = (sum - 1.0f) * h11 + (1.0f - dy) * h10 + (1.0f - dx) * h01;
        }
    }

    return height;
}

Rendering::TerrainPage::TerrainPage(LoadConstructor value)
    : ParentType{ value },
      pageSize{ 0 },
      sizeM1{ 0 },
      heights{ 0 },
      origin{ Mathematics::Float2{ 0.0f, 0.0f } },
      minElevation{ 0.0f },
      maxElevation{ 0.0f },
      spacing{ 0.0f },
      invSpacing{ 0.0f },
      multiplier{ 0.0f }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::TerrainPage::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    source.Read(pageSize);

    heights = source.ReadContainerUseNumber<std::vector<uint16_t>>(pageSize * pageSize);
    source.ReadAggregate(origin);
    source.Read(minElevation);
    source.Read(maxElevation);
    source.Read(spacing);

    sizeM1 = pageSize - 1;
    invSpacing = 1.0f / spacing;
    multiplier = (maxElevation - minElevation) / 65535.0f;

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::TerrainPage::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::TerrainPage::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

int64_t Rendering::TerrainPage::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::Register(target);
}

void Rendering::TerrainPage::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    target.Write(pageSize);

    target.WriteContainerWithoutNumber(heights);
    target.WriteAggregate(origin);
    target.Write(minElevation);
    target.Write(maxElevation);
    target.Write(spacing);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::TerrainPage::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = ParentType::GetStreamingSize();
    size += CoreTools::GetStreamSize(pageSize);
    size += pageSize * pageSize * CoreTools::GetStreamSize(heights.at(0));
    size += CoreTools::GetStreamSize(origin);
    size += CoreTools::GetStreamSize(minElevation);
    size += CoreTools::GetStreamSize(maxElevation);
    size += CoreTools::GetStreamSize(spacing);
    return size;
}

int Rendering::TerrainPage::GetSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return pageSize;
}

std::vector<uint16_t> Rendering::TerrainPage::GetHeights() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return heights;
}

const Mathematics::Float2& Rendering::TerrainPage::GetOrigin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return origin;
}

float Rendering::TerrainPage::GetMinElevation() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return minElevation;
}

float Rendering::TerrainPage::GetMaxElevation() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return maxElevation;
}

float Rendering::TerrainPage::GetSpacing() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return spacing;
}

float Rendering::TerrainPage::GetX(int x) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return origin[0] + spacing * boost::numeric_cast<float>(x);
}

float Rendering::TerrainPage::GetY(int y) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return origin[1] + spacing * boost::numeric_cast<float>(y);
}

float Rendering::TerrainPage::GetHeight(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return minElevation + multiplier * boost::numeric_cast<float>(heights.at(index));
}
