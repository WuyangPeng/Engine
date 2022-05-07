///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
///	ÁªÏµ×÷Õß£º94458936@qq.com
///
///	±ê×¼£ºstd:c++20
///	ÒýÇæ°æ±¾£º0.8.0.6 (2022/04/12 14:32)

#include "Rendering/RenderingExport.h"

#include "ShaderSamplerDataImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

#include <algorithm>

using std::string;

Rendering::ShaderSamplerDataImpl::ShaderSamplerDataImpl(int numSamplers)
    : singleShaderSamplerData{ numSamplers, SingleShaderSamplerData{ CoreTools::DisableNotThrow::Disable } }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ShaderSamplerDataImpl::ShaderSamplerDataImpl() noexcept
    : singleShaderSamplerData{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ShaderSamplerDataImpl)

void Rendering::ShaderSamplerDataImpl::SetSampler(int index, const string& name, ShaderFlags::SamplerType type)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_0(0 <= index && index < GetNumSamplers(), "Ë÷Òý´íÎó");

    singleShaderSamplerData.at(index).SetSampler(name, type);
}

void Rendering::ShaderSamplerDataImpl::SetFilter(int index, ShaderFlags::SamplerFilter filter)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_0(0 <= index && index < GetNumSamplers(), "Ë÷Òý´íÎó");

    singleShaderSamplerData.at(index).SetFilter(filter);
}

void Rendering::ShaderSamplerDataImpl::SetCoordinate(int index, int dimension, ShaderFlags::SamplerCoordinate coordinate)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_0(0 <= index && index < GetNumSamplers(), "Ë÷Òý´íÎó");

    singleShaderSamplerData.at(index).SetCoordinate(dimension, coordinate);
}

void Rendering::ShaderSamplerDataImpl::SetLodBias(int index, float lodBias)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_0(0 <= index && index < GetNumSamplers(), "Ë÷Òý´íÎó");

    singleShaderSamplerData.at(index).SetLodBias(lodBias);
}

void Rendering::ShaderSamplerDataImpl::SetAnisotropy(int index, float anisotropy)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_0(0 <= index && index < GetNumSamplers(), "Ë÷Òý´íÎó");

    singleShaderSamplerData.at(index).SetAnisotropy(anisotropy);
}

void Rendering::ShaderSamplerDataImpl::SetBorderColor(int index, const Colour& borderColor)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_0(0 <= index && index < GetNumSamplers(), "Ë÷Òý´íÎó");

    singleShaderSamplerData.at(index).SetBorderColor(borderColor);
}

int Rendering::ShaderSamplerDataImpl::GetNumSamplers() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(singleShaderSamplerData.size());
}

string Rendering::ShaderSamplerDataImpl::GetSamplerName(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= index && index < GetNumSamplers(), "Ë÷Òý´íÎó");

    return singleShaderSamplerData.at(index).GetSamplerName();
}

Rendering::ShaderFlags::SamplerType Rendering::ShaderSamplerDataImpl::GetSamplerType(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= index && index < GetNumSamplers(), "Ë÷Òý´íÎó");

    return singleShaderSamplerData.at(index).GetSamplerType();
}

Rendering::ShaderFlags::SamplerFilter Rendering::ShaderSamplerDataImpl::GetFilter(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= index && index < GetNumSamplers(), "Ë÷Òý´íÎó");

    return singleShaderSamplerData.at(index).GetFilter();
}

Rendering::ShaderFlags::SamplerCoordinate Rendering::ShaderSamplerDataImpl::GetCoordinate(int index, int dimension) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= index && index < GetNumSamplers(), "Ë÷Òý´íÎó");

    return singleShaderSamplerData.at(index).GetCoordinate(dimension);
}

float Rendering::ShaderSamplerDataImpl::GetLodBias(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= index && index < GetNumSamplers(), "Ë÷Òý´íÎó");

    return singleShaderSamplerData.at(index).GetLodBias();
}

float Rendering::ShaderSamplerDataImpl::GetAnisotropy(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= index && index < GetNumSamplers(), "Ë÷Òý´íÎó");

    return singleShaderSamplerData.at(index).GetAnisotropy();
}

Rendering::ShaderSamplerDataImpl::Colour Rendering::ShaderSamplerDataImpl::GetBorderColor(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= index && index < GetNumSamplers(), "Ë÷Òý´íÎó");

    return singleShaderSamplerData.at(index).GetBorderColor();
}

void Rendering::ShaderSamplerDataImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    int32_t number{ 0 };
    source.Read(number);
    singleShaderSamplerData.resize(number, SingleShaderSamplerData{ CoreTools::DisableNotThrow::Disable });

    for_each(singleShaderSamplerData.begin(), singleShaderSamplerData.end(), std::bind(&SingleShaderSamplerData::Load, std::placeholders::_1, std::ref(source)));
}

void Rendering::ShaderSamplerDataImpl::Save(CoreTools::BufferTarget& target) const
{
    target.Write(boost::numeric_cast<int32_t>(singleShaderSamplerData.size()));

    for_each(singleShaderSamplerData.begin(), singleShaderSamplerData.end(), std::bind(&SingleShaderSamplerData::Save, std::placeholders::_1, std::ref(target)));
}

int Rendering::ShaderSamplerDataImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CORE_TOOLS_STREAM_SIZE(int32_t{});
    for (const auto& data : singleShaderSamplerData)
    {
        size += data.GetStreamingSize();
    }

    return size;
}

void Rendering::ShaderSamplerDataImpl::Resize(int number)
{
    RENDERING_CLASS_IS_VALID_9;

    singleShaderSamplerData.resize(number, SingleShaderSamplerData{ CoreTools::DisableNotThrow::Disable });
}
