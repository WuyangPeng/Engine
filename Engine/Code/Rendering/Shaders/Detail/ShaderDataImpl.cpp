/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 15:07)

#include "Rendering/RenderingExport.h"

#include "ShaderDataImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"

Rendering::ShaderDataImpl::ShaderDataImpl(GraphicsObjectType inType, std::string inName, int inBindPoint, int inNumBytes, int inExtra, bool inIsGpuWritable) noexcept
    : object{},
      type{ inType },
      shaderName{ std::move(inName) },
      bindPoint{ inBindPoint },
      numBytes{ inNumBytes },
      extra{ inExtra },
      isGpuWritable{ inIsGpuWritable }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ShaderDataImpl::ShaderDataImpl(const ShaderDataImpl& rhs)
    : object{ boost::polymorphic_pointer_cast<GraphicsObject>(rhs.object->CloneObject()), rhs.object.associated },
      type{ rhs.type },
      shaderName{ rhs.shaderName },
      bindPoint{ rhs.bindPoint },
      numBytes{ rhs.numBytes },
      extra{ rhs.extra },
      isGpuWritable{ rhs.isGpuWritable }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ShaderDataImpl& Rendering::ShaderDataImpl::operator=(const ShaderDataImpl& rhs)
{
    RENDERING_CLASS_IS_VALID_9;

    object = GraphicsObjectObjectAssociated{ boost::polymorphic_pointer_cast<GraphicsObject>(rhs.object->CloneObject()), rhs.object.associated };
    type = rhs.type;
    shaderName = rhs.shaderName;
    bindPoint = rhs.bindPoint;
    numBytes = rhs.numBytes;
    extra = rhs.extra;
    isGpuWritable = rhs.isGpuWritable;

    return *this;
}

Rendering::ShaderDataImpl::ShaderDataImpl(ShaderDataImpl&& rhs) noexcept
    : object{ std::move(rhs.object) },
      type{ rhs.type },
      shaderName{ std::move(rhs.shaderName) },
      bindPoint{ rhs.bindPoint },
      numBytes{ rhs.numBytes },
      extra{ rhs.extra },
      isGpuWritable{ rhs.isGpuWritable }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ShaderDataImpl& Rendering::ShaderDataImpl::operator=(ShaderDataImpl&& rhs) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    object = std::move(rhs.object);
    type = rhs.type;
    shaderName = std::move(rhs.shaderName);
    bindPoint = rhs.bindPoint;
    numBytes = rhs.numBytes;
    extra = rhs.extra;
    isGpuWritable = rhs.isGpuWritable;

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ShaderDataImpl)

Rendering::GraphicsObjectType Rendering::ShaderDataImpl::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return type;
}

std::string Rendering::ShaderDataImpl::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return shaderName;
}

int Rendering::ShaderDataImpl::GetBindPoint() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return bindPoint;
}

int Rendering::ShaderDataImpl::GetNumBytes() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return numBytes;
}

int Rendering::ShaderDataImpl::GetExtra() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return extra;
}

bool Rendering::ShaderDataImpl::IsGpuWritable() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return isGpuWritable;
}

void Rendering::ShaderDataImpl::SetGraphicsObject(const GraphicsObjectSharedPtr& graphicsObject) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    object.object = graphicsObject;
}

Rendering::ConstGraphicsObjectSharedPtr Rendering::ShaderDataImpl::GetGraphicsObject() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return object.object;
}

Rendering::GraphicsObjectSharedPtr Rendering::ShaderDataImpl::GetGraphicsObject() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return object.object;
}

void Rendering::ShaderDataImpl::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadObjectAssociated(object);

    source.ReadEnum(type);
    shaderName = source.ReadString();
    source.Read(bindPoint);
    source.Read(numBytes);
    source.Read(extra);

    isGpuWritable = source.ReadBool();
}

void Rendering::ShaderDataImpl::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteObjectAssociated(object);

    target.WriteEnum(type);
    target.Write(shaderName);
    target.Write(bindPoint);
    target.Write(numBytes);
    target.Write(extra);
    target.Write(isGpuWritable);
}

int Rendering::ShaderDataImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CoreTools::GetStreamSize(object);

    size += CoreTools::GetStreamSize(type);
    size += CoreTools::GetStreamSize(shaderName);
    size += CoreTools::GetStreamSize(bindPoint);
    size += CoreTools::GetStreamSize(numBytes);
    size += CoreTools::GetStreamSize(extra);
    size += CoreTools::GetStreamSize(isGpuWritable);

    return size;
}

void Rendering::ShaderDataImpl::Link(ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ResolveLink(object);
}

void Rendering::ShaderDataImpl::Register(ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Register(object);
}

CoreTools::ObjectSharedPtr Rendering::ShaderDataImpl::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    if (object.object == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("object指针为空。"))
    }

    return object->GetObjectByName(name);
}

Rendering::ShaderDataImpl::ObjectSharedPtrContainer Rendering::ShaderDataImpl::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    if (object.object == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("object指针为空。"))
    }

    return object->GetAllObjectsByName(name);
}

CoreTools::ConstObjectSharedPtr Rendering::ShaderDataImpl::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (object.object == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("object指针为空。"))
    }

    return object->GetConstObjectByName(name);
}

Rendering::ShaderDataImpl::ConstObjectSharedPtrContainer Rendering::ShaderDataImpl::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (object.object == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("object指针为空。"))
    }

    return object->GetAllConstObjectsByName(name);
}