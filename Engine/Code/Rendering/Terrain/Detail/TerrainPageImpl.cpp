/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/25 21:50)

#include "Rendering/RenderingExport.h"

#include "TerrainPageImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "Rendering/DataTypes/SpecializedIO.h"

Rendering::TerrainPageImpl::TerrainPageImpl() noexcept
    : size{},
      minElevation{},
      maxElevation{},
      spacing{},
      origin{},
      heights{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::TerrainPageImpl::TerrainPageImpl(int size,
                                            float minElevation,
                                            float maxElevation,
                                            float spacing,
                                            const Vector2& origin)
    : size{ size },
      minElevation{ minElevation },
      maxElevation{ maxElevation },
      spacing{ spacing },
      origin{ origin },
      heights(GetHeights(size))
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::TerrainPageImpl::HeightsType Rendering::TerrainPageImpl::GetHeights(int size)
{
    const auto heightsSize = size * size;
    return HeightsType(heightsSize);
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, TerrainPageImpl)

int Rendering::TerrainPageImpl::GetSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return size;
}

Rendering::TerrainPageImpl::HeightsType Rendering::TerrainPageImpl::GetHeights() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return heights;
}

Rendering::TerrainPageImpl::Vector2 Rendering::TerrainPageImpl::GetOrigin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return origin;
}

float Rendering::TerrainPageImpl::GetMinElevation() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return minElevation;
}

float Rendering::TerrainPageImpl::GetMaxElevation() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return maxElevation;
}

float Rendering::TerrainPageImpl::GetSpacing() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return spacing;
}

void Rendering::TerrainPageImpl::SetHeights(int index, uint16_t height)
{
    RENDERING_CLASS_IS_VALID_9;

    heights.at(index) = height;
}

float Rendering::TerrainPageImpl::GetHeight(float x, float y) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto xGrid = (x - origin[0]) / spacing;
    if (xGrid < 0.0f || static_cast<float>(size) <= xGrid + 1.0f)
    {
        return std::numeric_limits<float>::max();
    }

    const auto yGrid = (y - origin[1]) / spacing;
    if (yGrid < 0.0f || static_cast<float>(size) <= yGrid + 1.0f)
    {
        return std::numeric_limits<float>::max();
    }

    const auto xGri1dFloor = std::floor(xGrid);
    const auto column = static_cast<int>(xGri1dFloor);
    const auto yGridFloor = std::floor(yGrid);
    const auto row = static_cast<int>(yGridFloor);

    const auto dx = xGrid - xGri1dFloor;
    const auto dy = yGrid - yGridFloor;

    if ((column & 1) == (row & 1))
    {
        const auto diff = dx - dy;
        const auto h00 = GetHeight(row, column);
        const auto h11 = GetHeight(row + 1, column);
        if (0.0f < diff)
        {
            const auto h10 = GetHeight(row, column + 1);
            return (1.0f - diff - dy) * h00 + diff * h10 + dy * h11;
        }
        else
        {
            const auto h01 = GetHeight(row + 1, column);
            return (1.0f + diff - dx) * h00 - diff * h01 + dx * h11;
        }
    }
    else
    {
        const auto sum = dx + dy;
        const auto h10 = GetHeight(row, column + 1);
        const auto h01 = GetHeight(row + 1, column);
        if (sum <= 1.0f)
        {
            const auto h00 = GetHeight(row, column);
            return (1.0f - sum) * h00 + dx * h10 + dy * h01;
        }
        else
        {
            const auto h11 = GetHeight(row + 1, column + 1);
            return (sum - 1.0f) * h11 + (1.0f - dy) * h10 + (1.0f - dx) * h01;
        }
    }
}

void Rendering::TerrainPageImpl::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.Read(size);
    source.Read(minElevation);
    source.Read(maxElevation);
    source.Read(spacing);
    source.ReadAggregate(origin);
    heights = source.ReadContainerNotUseNumber<HeightsType>();
}

void Rendering::TerrainPageImpl::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Write(size);
    target.Write(minElevation);
    target.Write(maxElevation);
    target.Write(spacing);
    target.WriteAggregate(origin);
    target.WriteContainerWithNumber(heights);
}

int Rendering::TerrainPageImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto result = GetStreamSize(size);

    result += GetStreamSize(minElevation);
    result += GetStreamSize(maxElevation);
    result += GetStreamSize(spacing);
    result += Rendering::GetStreamSize(origin);
    result += GetStreamSize(heights);

    return result;
}

float Rendering::TerrainPageImpl::GetHeight(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto t = static_cast<float>(heights.at(index)) / 65535.0f;

    return (1.0f - t) * minElevation + t * maxElevation;
}

float Rendering::TerrainPageImpl::GetHeight(int row, int col) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GetHeight(col + size * row);
}
