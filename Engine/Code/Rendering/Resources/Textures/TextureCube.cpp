/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 14:22)

#include "Rendering/RenderingExport.h"

#include "TextureCube.h"
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
#include "Rendering/OpenGLRenderer/Resources/Textures/OpenGLTextureCube.h"
#include "Rendering/RendererEngine/Flags/RendererTypes.h"
#include "Rendering/Resources/DataFormat.h"
#include "Rendering/Resources/Detail/Textures/TextureCubeImpl.h"
#include "Rendering/Resources/Flags/CubeFaceType.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, TextureCube)

CORE_TOOLS_RTTI_DEFINE(Rendering, TextureCube)
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, TextureCube);
CORE_TOOLS_FACTORY_DEFINE(Rendering, TextureCube);

Rendering::TextureCube::TextureCube(const std::string& name, DataFormatType format, int length, bool hasMipMaps, bool createStorage)
    : ParentType{ name,
                  ImplType::GetTotalElements(System::EnumCastUnderlying(CubeFaceType::Count), length, length, 1, hasMipMaps),
                  DataFormat::GetNumBytesPerStruct(format),
                  GraphicsObjectType::TextureCube,
                  createStorage },
      impl{ format, length, hasMipMaps }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TextureCube)

int Rendering::TextureCube::GetDimension(int index, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetDimension(index, level);
}

int Rendering::TextureCube::GetLevelOffset(int item, int level) const
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetLevelOffset(item, level);
}

int Rendering::TextureCube::GetLength() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetWidth();
}

int Rendering::TextureCube::GetIndex(int item, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetIndex(item, level);
}

Rendering::TextureCube::TextureCube(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::DisableNotThrow::Disable }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::TextureCube::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::TextureCube::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::TextureCube::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::TextureCube::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::TextureCube::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::TextureCube::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

Rendering::TextureSharedPtr Rendering::TextureCube::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::TextureCube::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return Clone();
}

int Rendering::TextureCube::GetNumElementsFor(int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumLevelBytes(level) / GetElementSize();
}

Rendering::TextureCube::RendererObjectSharedPtr Rendering::TextureCube::CreateRendererObject(RendererTypes rendererTypes)
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    switch (rendererTypes)
    {
        case RendererTypes::OpenGL:
        {
            return std::make_shared<OpenGLTextureCube>(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()), GetName());
        }
        default:
        {
            THROW_EXCEPTION(SYSTEM_TEXT("渲染类型不存在。"s))
        }
    }
}

int Rendering::TextureCube::GetNumItems() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumItems();
}

int Rendering::TextureCube::GetDimension(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetDimension(index);
}

Rendering::DataFormatType Rendering::TextureCube::GetFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetFormat();
}

int Rendering::TextureCube::GetNumLevels() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumLevels();
}

int Rendering::TextureCube::GetNumDimensions() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumDimensions();
}

int Rendering::TextureCube::GetNumLevelBytes(int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumLevelBytes(level);
}

bool Rendering::TextureCube::HasMipMaps() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->HasMipMaps();
}

int Rendering::TextureCube::GetWidth() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetWidth();
}

int Rendering::TextureCube::GetHeight() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetHeight();
}

void Rendering::TextureCube::AutoGenerateMipMaps() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->AutoGenerateMipMaps();
}

bool Rendering::TextureCube::WantAutoGenerateMipMaps() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->WantAutoGenerateMipMaps();
}

int Rendering::TextureCube::GetNumSubResources() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumSubResources();
}