///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/28 09:58)

#include "Rendering/RenderingExport.h"

#include "GraphicsObject.h"
#include "RendererObjectBridge.h"
#include "Flags/GraphicsObjectType.h"
#include "Detail/GraphicsObjectImpl.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, GraphicsObject);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, GraphicsObject);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, GraphicsObject);

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, GraphicsObject)

Rendering::GraphicsObject::GraphicsObject(const std::string& name, GraphicsObjectType graphicsObjectType)
    : ParentType{ name }, impl{ graphicsObjectType }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::GraphicsObject::~GraphicsObject() noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_9;

    NoexceptNoReturn(*this, &ClassType::Release);
}

void Rendering::GraphicsObject::Release()
{
    const auto rendererObjectBridge = impl->GetRendererObjectBridge();

    rendererObjectBridge->UnbindRendererObject(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()));
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, GraphicsObject);

void Rendering::GraphicsObject::SetRendererObjectBridge(const RendererObjectBridgeSharedPtr& aRendererObjectBridge) noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_9;

    return impl->SetRendererObjectBridge(aRendererObjectBridge);
}

Rendering::GraphicsObjectType Rendering::GraphicsObject::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetType();
}

bool Rendering::GraphicsObject::IsBuffer() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->IsBuffer();
}

bool Rendering::GraphicsObject::IsTexture() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->IsTexture();
}

bool Rendering::GraphicsObject::IsTextureArray() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->IsTextureArray();
}

bool Rendering::GraphicsObject::IsShader() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->IsShader();
}

bool Rendering::GraphicsObject::IsDrawingState() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->IsDrawingState();
}

Rendering::GraphicsObject::GraphicsObject(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ GraphicsObjectType::None }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

int Rendering::GraphicsObject::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::GraphicsObject::Register(ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::Register(target);
}

void Rendering::GraphicsObject::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::GraphicsObject::Link(ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::Link(source);
}

void Rendering::GraphicsObject::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::PostLink();
}

void Rendering::GraphicsObject::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}