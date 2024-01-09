/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 14:20)

#include "Rendering/RenderingExport.h"

#include "Texture3D.h"
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
#include "Rendering/OpenGLRenderer/Resources/Textures/OpenGLTexture3.h"
#include "Rendering/RendererEngine/Flags/RendererTypes.h"
#include "Rendering/Resources/DataFormat.h"
#include "Rendering/Resources/Detail/Textures/Texture3DImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Texture3D)

CORE_TOOLS_RTTI_DEFINE(Rendering, Texture3D)
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Texture3D);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Texture3D);

Rendering::Texture3D::Texture3D(const std::string& name, DataFormatType format, int width, int height, int thickness, bool hasMipMaps, bool createStorage)
    : ParentType{ name,
                  ImplType::GetTotalElements(1, width, height, thickness, hasMipMaps),
                  DataFormat::GetNumBytesPerStruct(format),
                  GraphicsObjectType::Texture3,
                  createStorage },
      impl{ format, width, height, thickness, hasMipMaps }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Texture3D)

int Rendering::Texture3D::GetDimension(int index, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetDimension(index, level);
}

int Rendering::Texture3D::GetLevelOffset(int item, int level) const
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetLevelOffset(item, level);
}

int Rendering::Texture3D::GetIndex(int item, int level) const
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetIndex(item, level);
}

Rendering::Texture3D::Texture3D(LoadConstructor value)
    : ParentType{ value }, impl{ CoreTools::DisableNotThrow::Disable }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Texture3D::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::Texture3D::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::Texture3D::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Texture3D::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::Texture3D::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::Texture3D::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

Rendering::TextureSharedPtr Rendering::Texture3D::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::Texture3D::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return Clone();
}

int Rendering::Texture3D::GetNumElementsFor(int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumLevelBytes(level) / GetElementSize();
}

Rendering::Texture3D::RendererObjectSharedPtr Rendering::Texture3D::CreateRendererObject(RendererTypes rendererTypes)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    switch (rendererTypes)
    {
        case RendererTypes::OpenGL:
        {
            return std::make_shared<OpenGLTexture3>(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()), GetName());
        }
        default:
        {
            THROW_EXCEPTION(SYSTEM_TEXT("渲染类型不存在。"s))
        }
    }
}

int Rendering::Texture3D::GetNumItems() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetNumItems();
}

int Rendering::Texture3D::GetDimension(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetDimension(index);
}

Rendering::DataFormatType Rendering::Texture3D::GetFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetFormat();
}

int Rendering::Texture3D::GetNumLevels() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetNumLevels();
}

int Rendering::Texture3D::GetNumDimensions() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetNumDimensions();
}

int Rendering::Texture3D::GetNumLevelBytes(int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetNumLevelBytes(level);
}

bool Rendering::Texture3D::HasMipMaps() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->HasMipMaps();
}

int Rendering::Texture3D::GetWidth() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetWidth();
}

int Rendering::Texture3D::GetHeight() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetHeight();
}

int Rendering::Texture3D::GetThickness() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetThickness();
}

void Rendering::Texture3D::AutoGenerateMipMaps() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->AutoGenerateMipMaps();
}

bool Rendering::Texture3D::WantAutoGenerateMipMaps() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->WantAutoGenerateMipMaps();
}

int Rendering::Texture3D::GetNumSubResources() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetNumSubResources();
}