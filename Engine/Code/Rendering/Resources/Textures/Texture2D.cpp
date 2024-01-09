/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 14:11)

#include "Rendering/RenderingExport.h"

#include "Texture2D.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/OpenGLRenderer/Resources/Textures/OpenGLTexture2.h"
#include "Rendering/RendererEngine/Flags/RendererTypes.h"
#include "Rendering/Resources/DataFormat.h"
#include "Rendering/Resources/Detail/Textures/Texture2DImpl.h"
#include "Rendering/Resources/Flags/UsageType.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Texture2D)

CORE_TOOLS_RTTI_DEFINE(Rendering, Texture2D)

    ;
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Texture2D);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Texture2D);

Rendering::Texture2D::Texture2D(const std::string& name, DataFormatType format, int width, int height, bool hasMipMaps, bool createStorage)
    : ParentType{ name,
                  ImplType::GetTotalElements(1, width, height, 1, hasMipMaps),
                  DataFormat::GetNumBytesPerStruct(format),
                  GraphicsObjectType::Texture2,
                  createStorage },
      impl{ format, width, height, hasMipMaps },
      shared{ false }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Texture2D::Texture2D(const std::string& name, DataFormatType format, int width, int height, bool hasMipMaps, GraphicsObjectType type, bool createStorage)
    : ParentType{ name, ImplType::GetTotalElements(1, width, height, 1, hasMipMaps), DataFormat::GetNumBytesPerStruct(format), type, createStorage },
      impl{ format, width, height, hasMipMaps },
      shared{ false }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Texture2D)

int Rendering::Texture2D::GetDimension(int index, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetDimension(index, level);
}

int Rendering::Texture2D::GetLevelOffset(int item, int level) const
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetLevelOffset(item, level);
}

int Rendering::Texture2D::GetIndex(int item, int level) const
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetIndex(item, level);
}

Rendering::Texture2D::Texture2D(LoadConstructor value)
    : ParentType{ value }, impl{ CoreTools::DisableNotThrow::Disable }, shared{ false }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Texture2D::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    size += CoreTools::GetStreamSize(shared);

    return size;
}

int64_t Rendering::Texture2D::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::Texture2D::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    target.Write(shared);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Texture2D::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::Texture2D::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::Texture2D::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    source.Read(shared);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

Rendering::TextureSharedPtr Rendering::Texture2D::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::Texture2D::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return Clone();
}

int Rendering::Texture2D::GetNumElementsFor(int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumLevelBytes(level) / GetElementSize();
}

void Rendering::Texture2D::MakeShared() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    SetUsage(UsageType::ShaderOutput);
    shared = true;
}

bool Rendering::Texture2D::IsShared() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return shared;
}

Rendering::Texture2D::RendererObjectSharedPtr Rendering::Texture2D::CreateRendererObject(RendererTypes rendererTypes)
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    switch (rendererTypes)
    {
        case RendererTypes::OpenGL:
        {
            return std::make_shared<OpenGLTexture2>(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()), GetName());
        }
        default:
        {
            THROW_EXCEPTION(SYSTEM_TEXT("渲染类型不存在。"s))
        }
    }
}

int Rendering::Texture2D::GetNumItems() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumItems();
}

int Rendering::Texture2D::GetDimension(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetDimension(index);
}

Rendering::DataFormatType Rendering::Texture2D::GetFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetFormat();
}

int Rendering::Texture2D::GetNumLevels() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumLevels();
}

int Rendering::Texture2D::GetNumDimensions() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumDimensions();
}

int Rendering::Texture2D::GetNumLevelBytes(int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumLevelBytes(level);
}

bool Rendering::Texture2D::HasMipMaps() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->HasMipMaps();
}

int Rendering::Texture2D::GetWidth() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetWidth();
}

int Rendering::Texture2D::GetHeight() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetHeight();
}

void Rendering::Texture2D::AutoGenerateMipMaps() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->AutoGenerateMipMaps();
}

bool Rendering::Texture2D::WantAutoGenerateMipMaps() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->WantAutoGenerateMipMaps();
}

int Rendering::Texture2D::GetNumSubResources() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumSubResources();
}