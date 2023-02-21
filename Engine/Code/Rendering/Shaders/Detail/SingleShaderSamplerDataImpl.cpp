///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/12 15:09)

#include "Rendering/RenderingExport.h"

#include "SingleShaderSamplerDataImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Rendering/DataTypes/SpecializedIO.h"

using std::string;

Rendering::SingleShaderSamplerDataImpl::SingleShaderSamplerDataImpl() noexcept
    : samplerName{},
      samplerType{ ShaderFlags::SamplerType::None },
      filter{ ShaderFlags::SamplerFilter::Nearest },
      coordinates{},
      lodBias{ 0.0f },
      anisotropy{ 1.0f },
      borderColor{ 0.0f, 0.0f, 0.0f, 0.0f }
{
    coordinates.fill(ShaderFlags::SamplerCoordinate::ClampEdge);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, SingleShaderSamplerDataImpl)

void Rendering::SingleShaderSamplerDataImpl::SetSampler(const string& name, ShaderFlags::SamplerType type)
{
    RENDERING_CLASS_IS_VALID_9;

    samplerName = name;
    samplerType = type;
}

void Rendering::SingleShaderSamplerDataImpl::SetFilter(ShaderFlags::SamplerFilter aFilter) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    filter = aFilter;
}

void Rendering::SingleShaderSamplerDataImpl::SetCoordinate(int dimension, ShaderFlags::SamplerCoordinate coordinate)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_0(0 <= dimension && dimension < samplerCoordinateSize, "索引错误");

    coordinates.at(dimension) = coordinate;
}

void Rendering::SingleShaderSamplerDataImpl::SetLodBias(float aLodBias) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    lodBias = aLodBias;
}

void Rendering::SingleShaderSamplerDataImpl::SetAnisotropy(float aAnisotropy) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    anisotropy = aAnisotropy;
}

void Rendering::SingleShaderSamplerDataImpl::SetBorderColor(const Colour& aBorderColor) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    borderColor = aBorderColor;
}

std::string Rendering::SingleShaderSamplerDataImpl::GetSamplerName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return samplerName;
}

Rendering::ShaderFlags::SamplerType Rendering::SingleShaderSamplerDataImpl::GetSamplerType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return samplerType;
}

Rendering::ShaderFlags::SamplerFilter Rendering::SingleShaderSamplerDataImpl::GetFilter() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return filter;
}

Rendering::ShaderFlags::SamplerCoordinate Rendering::SingleShaderSamplerDataImpl::GetCoordinate(int dimension) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= dimension && dimension < samplerCoordinateSize, "索引错误");

    return coordinates.at(dimension);
}

float Rendering::SingleShaderSamplerDataImpl::GetLodBias() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return lodBias;
}

float Rendering::SingleShaderSamplerDataImpl::GetAnisotropy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return anisotropy;
}

Rendering::SingleShaderSamplerDataImpl::Colour Rendering::SingleShaderSamplerDataImpl::GetBorderColor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return borderColor;
}

void Rendering::SingleShaderSamplerDataImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    samplerName = source.ReadString();
    source.ReadEnum(samplerType);
    source.ReadEnum(filter);
    source.ReadEnum(coordinates.at(0));
    source.ReadEnum(coordinates.at(1));
    source.ReadEnum(coordinates.at(2));
    source.Read(lodBias);
    source.Read(anisotropy);
    source.ReadAggregate(borderColor);
}

void Rendering::SingleShaderSamplerDataImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Write(samplerName);
    target.WriteEnum(samplerType);
    target.WriteEnum(filter);
    target.WriteEnum(coordinates.at(0));
    target.WriteEnum(coordinates.at(1));
    target.WriteEnum(coordinates.at(2));
    target.Write(lodBias);
    target.Write(anisotropy);
    target.WriteAggregate(borderColor);
}

int Rendering::SingleShaderSamplerDataImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CoreTools::GetStreamSize(samplerName);

    size += CoreTools::GetStreamSize(samplerType);
    size += CoreTools::GetStreamSize(filter);
    size += CoreTools::GetStreamSize(coordinates.at(0)) * samplerCoordinateSize;
    size += CoreTools::GetStreamSize(lodBias);
    size += CoreTools::GetStreamSize(anisotropy);
    size += CoreTools::GetStreamSize(borderColor);

    return size;
}
