/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 15:17)

#include "Rendering/RenderingExport.h"

#include "ShaderData.h"
#include "Detail/ShaderDataImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, ShaderData)

Rendering::ShaderData::ShaderData(GraphicsObjectType inType, const std::string& inName, int inBindPoint, int inNumBytes, int inExtra, bool inIsGpuWritable)
    : impl{ inType, inName, inBindPoint, inNumBytes, inExtra, inIsGpuWritable }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ShaderData)

Rendering::GraphicsObjectType Rendering::ShaderData::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetType();
}

std::string Rendering::ShaderData::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetName();
}

int Rendering::ShaderData::GetBindPoint() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetBindPoint();
}

int Rendering::ShaderData::GetNumBytes() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetNumBytes();
}

int Rendering::ShaderData::GetExtra() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetExtra();
}

bool Rendering::ShaderData::IsGpuWritable() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->IsGpuWritable();
}

void Rendering::ShaderData::SetGraphicsObject(const GraphicsObjectSharedPtr& graphicsObject) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetGraphicsObject(graphicsObject);
}

Rendering::ConstGraphicsObjectSharedPtr Rendering::ShaderData::GetGraphicsObject() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetGraphicsObject();
}

Rendering::GraphicsObjectSharedPtr Rendering::ShaderData::GetGraphicsObject() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetGraphicsObject();
}

void Rendering::ShaderData::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    impl->Load(source);
}

void Rendering::ShaderData::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    impl->Save(target);
}

int Rendering::ShaderData::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetStreamingSize();
}

void Rendering::ShaderData::Link(ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    impl->Link(source);
}

void Rendering::ShaderData::Register(ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    impl->Register(target);
}

CoreTools::ObjectSharedPtr Rendering::ShaderData::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetObjectByName(name);
}

Rendering::ShaderData::ObjectSharedPtrContainer Rendering::ShaderData::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetAllObjectsByName(name);
}

CoreTools::ConstObjectSharedPtr Rendering::ShaderData::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetConstObjectByName(name);
}

Rendering::ShaderData::ConstObjectSharedPtrContainer Rendering::ShaderData::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetAllConstObjectsByName(name);
}