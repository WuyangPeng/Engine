///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/19 15:42)

#include "Rendering/RenderingExport.h"

#include "ShaderImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Rendering/Resources/Buffers/ConstantBuffer.h"
#include "Rendering/Resources/Buffers/StructuredBuffer.h"
#include "Rendering/Resources/Buffers/TextureBuffer.h"

Rendering::ShaderImpl::ShaderImpl() noexcept
    : lookupData{},
      compiledCode{},
      numXThreads{ 0 },
      numYThreads{ 0 },
      numZThreads{ 0 },
      constantBufferLayouts{},
      textureBufferLayouts{},
      structuredBufferLayouts{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ShaderImpl)

int Rendering::ShaderImpl::Get(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    for (const auto& lookup : lookupData)
    {
        auto handle = 0;
        for (const auto& data : lookup)
        {
            if (name == data.GetName())
            {
                return handle;
            }
            ++handle;
        }
    }
    return -1;
}

int Rendering::ShaderImpl::GetConstantBufferSize(int handle) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return lookupData.at(ConstantBuffer::GetShaderDataLookup()).at(handle).GetNumBytes();
}

int Rendering::ShaderImpl::GetConstantBufferSize(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto handle = 0;
    for (const auto& data : lookupData.at(ConstantBuffer::GetShaderDataLookup()))
    {
        if (name == data.GetName())
        {
            return data.GetNumBytes();
        }
        ++handle;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("无法找到对象"s));
}

int Rendering::ShaderImpl::GetTextureBufferSize(int handle) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return lookupData.at(TextureBuffer::GetShaderDataLookup()).at(handle).GetNumBytes();
}

int Rendering::ShaderImpl::GetTextureBufferSize(std::string const& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto handle = 0;
    for (const auto& data : lookupData.at(TextureBuffer::GetShaderDataLookup()))
    {
        if (name == data.GetName())
        {
            return data.GetNumBytes();
        }
        ++handle;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("无法找到对象"s));
}

int Rendering::ShaderImpl::GetStructuredBufferSize(int handle) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return lookupData.at(StructuredBuffer::GetShaderDataLookup()).at(handle).GetNumBytes();
}

int Rendering::ShaderImpl::GetStructuredBufferSize(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto handle = 0;
    for (const auto& data : lookupData.at(StructuredBuffer::GetShaderDataLookup()))
    {
        if (name == data.GetName())
        {
            return data.GetNumBytes();
        }
        ++handle;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("无法找到对象"s));
}

Rendering::ShaderImpl::MemberLayoutContainer Rendering::ShaderImpl::GetConstantBufferLayout(int handle) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return constantBufferLayouts.at(handle).GetLayout();
}

Rendering::ShaderImpl::MemberLayoutContainer Rendering::ShaderImpl::GetConstantBufferLayout(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto handle = 0;
    for (const auto& data : lookupData.at(ConstantBuffer::GetShaderDataLookup()))
    {
        if (name == data.GetName())
        {
            return constantBufferLayouts.at(handle).GetLayout();
        }
        ++handle;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("无法找到对象"s));
}

Rendering::ShaderImpl::MemberLayoutContainer Rendering::ShaderImpl::GetTextureBufferLayout(int handle) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureBufferLayouts.at(handle).GetLayout();
}

Rendering::ShaderImpl::MemberLayoutContainer Rendering::ShaderImpl::GetTextureBufferLayout(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto handle = 0;
    for (const auto& data : lookupData.at(TextureBuffer::GetShaderDataLookup()))
    {
        if (name == data.GetName())
        {
            return textureBufferLayouts.at(handle).GetLayout();
        }
        ++handle;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("无法找到对象"s));
}

Rendering::ShaderImpl::MemberLayoutContainer Rendering::ShaderImpl::GetStructuredBufferLayout(int handle) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return structuredBufferLayouts.at(handle).GetLayout();
}

Rendering::ShaderImpl::MemberLayoutContainer Rendering::ShaderImpl::GetStructuredBufferLayout(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto handle = 0;
    for (const auto& data : lookupData.at(StructuredBuffer::GetShaderDataLookup()))
    {
        if (name == data.GetName())
        {
            return structuredBufferLayouts.at(handle).GetLayout();
        }
        ++handle;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("无法找到对象"s));
}

int Rendering::ShaderImpl::GetNumXThreads() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return numXThreads;
}

int Rendering::ShaderImpl::GetNumYThreads() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return numYThreads;
}

int Rendering::ShaderImpl::GetNumZThreads() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return numZThreads;
}

Rendering::ShaderImpl::CompiledCodeContainer Rendering::ShaderImpl::GetCompiledCode() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return compiledCode;
}

Rendering::ShaderImpl::ShaderDataContainer Rendering::ShaderImpl::GetData(int lookup) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return lookupData.at(lookup);
}

void Rendering::ShaderImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto& value : lookupData)
    {
        source.ReadAggregateContainer(value);
    }

    source.ReadContainer(compiledCode);

    source.Read(numXThreads);
    source.Read(numYThreads);
    source.Read(numZThreads);

    auto size = source.Read<int32_t>();
    constantBufferLayouts.resize(size);
    for (auto& value : constantBufferLayouts)
    {
        value.Load(source);
    }

    size = source.Read<int32_t>();
    textureBufferLayouts.resize(size);
    for (auto& value : textureBufferLayouts)
    {
        value.Load(source);
    }

    size = source.Read<int32_t>();
    structuredBufferLayouts.resize(size);
    for (auto& value : structuredBufferLayouts)
    {
        value.Load(source);
    }
}

void Rendering::ShaderImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    for (const auto& value : lookupData)
    {
        target.WriteAggregateContainerWithNumber(value);
    }

    target.WriteContainerWithNumber(compiledCode);

    target.Write(numXThreads);
    target.Write(numYThreads);
    target.Write(numZThreads);

    target.Write(boost::numeric_cast<int32_t>(constantBufferLayouts.size()));
    for (const auto& value : constantBufferLayouts)
    {
        value.Save(target);
    }

    target.Write(boost::numeric_cast<int32_t>(textureBufferLayouts.size()));
    for (const auto& value : textureBufferLayouts)
    {
        value.Save(target);
    }

    target.Write(boost::numeric_cast<int32_t>(structuredBufferLayouts.size()));
    for (const auto& value : structuredBufferLayouts)
    {
        value.Save(target);
    }
}

int Rendering::ShaderImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = 0;

    for (const auto& value : lookupData)
    {
        size += RENDERING_STREAM_SIZE(value);
    }

    size += RENDERING_STREAM_SIZE(compiledCode);

    size += RENDERING_STREAM_SIZE(numXThreads);
    size += RENDERING_STREAM_SIZE(numYThreads);
    size += RENDERING_STREAM_SIZE(numZThreads);

    size += CoreTools::GetStreamSize<int32_t>();
    for (const auto& value : constantBufferLayouts)
    {
        size += value.GetStreamingSize();
    }

    size += CoreTools::GetStreamSize<int32_t>();
    for (const auto& value : textureBufferLayouts)
    {
        size += value.GetStreamingSize();
    }

    size += CoreTools::GetStreamSize<int32_t>();
    for (const auto& value : structuredBufferLayouts)
    {
        size += value.GetStreamingSize();
    }

    return size;
}

void Rendering::ShaderImpl::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto& value : lookupData)
    {
        for (auto& shaderData : value)
        {
            shaderData.Link(source);
        }
    }
}

void Rendering::ShaderImpl::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    for (const auto& value : lookupData)
    {
        for (const auto& shaderData : value)
        {
            shaderData.Register(target);
        }
    }
}

Rendering::ShaderImpl::ConstShaderDataContainerIter Rendering::ShaderImpl::GetShaderDataBegin(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return lookupData.at(index).cbegin();
}

Rendering::ShaderImpl::ConstShaderDataContainerIter Rendering::ShaderImpl::GetShaderDataEnd(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return lookupData.at(index).cend();
}

Rendering::ShaderImpl::ShaderDataContainerIter Rendering::ShaderImpl::GetShaderDataBegin(int index)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return lookupData.at(index).begin();
}

Rendering::ShaderImpl::ShaderDataContainerIter Rendering::ShaderImpl::GetShaderDataEnd(int index)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return lookupData.at(index).end();
}

Rendering::ConstGraphicsObjectSharedPtr Rendering::ShaderImpl::GetGraphicsObject(int index, int handle) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return lookupData.at(index).at(handle).GetGraphicsObject();
}

void Rendering::ShaderImpl::SetNumThreads(int x, int y, int z) noexcept
{
    numXThreads = x;
    numYThreads = y;
    numZThreads = z;
}

void Rendering::ShaderImpl::AddLookupData(int index, GraphicsObjectType inType, const std::string& inName, int inBindPoint, int inNumBytes, int inExtra, bool inIsGpuWritable)
{
    lookupData.at(index).emplace_back(inType, inName, inBindPoint, inNumBytes, inExtra, inIsGpuWritable);
}

void Rendering::ShaderImpl::ResizeConstantBufferLayouts(int size)
{
    constantBufferLayouts.resize(size);
}

void Rendering::ShaderImpl::AddConstantBufferLayouts(int layoutIndex, const MemberLayout& item)
{
    constantBufferLayouts.at(layoutIndex).AddLayout(item);
}

void Rendering::ShaderImpl::ResizeStructuredBufferLayouts(int size)
{
    structuredBufferLayouts.resize(size);
}

void Rendering::ShaderImpl::AddStructuredBufferLayouts(int layoutIndex, const MemberLayout& item)
{
    structuredBufferLayouts.at(layoutIndex).AddLayout(item);
}

int Rendering::ShaderImpl::GetStructuredBufferCounter(int layoutIndex) const
{
    return structuredBufferLayouts.at(layoutIndex).GetSize();
}

void Rendering::ShaderImpl::SortConstantBufferLayouts(int layoutIndex)
{
    structuredBufferLayouts.at(layoutIndex).SortLayouts();
}
