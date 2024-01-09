/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 14:09)

#include "Rendering/RenderingExport.h"

#include "Texture1D.h"
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
#include "Rendering/OpenGLRenderer/Resources/Textures/OpenGLTexture1.h"
#include "Rendering/RendererEngine/Flags/RendererTypes.h"
#include "Rendering/Resources/DataFormat.h"
#include "Rendering/Resources/Detail/Textures/Texture1DImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Texture1D)

CORE_TOOLS_RTTI_DEFINE(Rendering, Texture1D)
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Texture1D);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Texture1D);

Rendering::Texture1D::Texture1D(const std::string& name, DataFormatType format, int length, bool hasMipMaps, bool createStorage)
    : ParentType{ name,
                  ImplType::GetTotalElements(1, length, 1, 1, hasMipMaps),
                  DataFormat::GetNumBytesPerStruct(format),
                  GraphicsObjectType::Texture1,
                  createStorage },
      impl{ format, length, hasMipMaps }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Texture1D)

int Rendering::Texture1D::GetDimension(int index, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetDimension(index, level);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Texture1D, GetNumLevelBytes, int, int)

int Rendering::Texture1D::GetLevelOffset(int item, int level) const
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetLevelOffset(item, level);
}

int Rendering::Texture1D::GetNumElementsFor(int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumLevelBytes(level) / GetElementSize();
}

int Rendering::Texture1D::GetIndex(int item, int level) const
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetIndex(item, level);
}

Rendering::Texture1D::Texture1D(LoadConstructor value)
    : ParentType{ value }, impl{ CoreTools::DisableNotThrow::Disable }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Texture1D::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::Texture1D::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::Texture1D::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Texture1D::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::Texture1D::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::Texture1D::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

Rendering::TextureSharedPtr Rendering::Texture1D::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::Texture1D::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return Clone();
}

Rendering::Texture1D::RendererObjectSharedPtr Rendering::Texture1D::CreateRendererObject(RendererTypes rendererTypes)
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    switch (rendererTypes)
    {
        case RendererTypes::OpenGL:
        {
            return std::make_shared<OpenGLTexture1>(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()), GetName());
        }
        default:
        {
            THROW_EXCEPTION(SYSTEM_TEXT("渲染类型不存在。"s))
        }
    }
}
int Rendering::Texture1D::GetNumItems() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumItems();
}

int Rendering::Texture1D::GetDimension(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetDimension(index);
}

Rendering::DataFormatType Rendering::Texture1D::GetFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetFormat();
}

int Rendering::Texture1D::GetNumLevels() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumLevels();
}

int Rendering::Texture1D::GetNumDimensions() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumDimensions();
}

bool Rendering::Texture1D::HasMipMaps() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->HasMipMaps();
}

int Rendering::Texture1D::GetLength() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetLength();
}

void Rendering::Texture1D::AutoGenerateMipMaps() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->AutoGenerateMipMaps();
}

bool Rendering::Texture1D::WantAutoGenerateMipMaps() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->WantAutoGenerateMipMaps();
}

int Rendering::Texture1D::GetNumSubResources() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumSubResources();
}