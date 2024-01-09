/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 14:10)

#include "Rendering/RenderingExport.h"

#include "Texture1DArray.h"
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
#include "Rendering/OpenGLRenderer/Resources/Textures/OpenGLTexture1Array.h"
#include "Rendering/RendererEngine/Flags/RendererTypes.h"
#include "Rendering/Resources/DataFormat.h"
#include "Rendering/Resources/Detail/Textures/Texture1DImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Texture1DArray)

CORE_TOOLS_RTTI_DEFINE(Rendering, Texture1DArray)
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Texture1DArray);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Texture1DArray);

Rendering::Texture1DArray::Texture1DArray(const std::string& name, int numItems, DataFormatType format, int length, bool hasMipMaps, bool createStorage)
    : ParentType{ name,
                  ImplType::GetTotalElements(numItems, length, 1, 1, hasMipMaps),
                  DataFormat::GetNumBytesPerStruct(format),
                  GraphicsObjectType::Texture1Array,
                  createStorage },
      impl{ numItems, format, length, hasMipMaps }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Texture1DArray)

int Rendering::Texture1DArray::GetDimension(int index, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetDimension(index, level);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Texture1DArray, GetNumLevelBytes, int, int)

int Rendering::Texture1DArray::GetLevelOffset(int item, int level) const
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetLevelOffset(item, level);
}

int Rendering::Texture1DArray::GetNumElementsFor(int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumLevelBytes(level) / GetElementSize();
}

int Rendering::Texture1DArray::GetIndex(int item, int level) const
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetIndex(item, level);
}

Rendering::Texture1DArray::Texture1DArray(LoadConstructor value)
    : ParentType{ value }, impl{ CoreTools::DisableNotThrow::Disable }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Texture1DArray::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::Texture1DArray::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::Texture1DArray::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Texture1DArray::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::Texture1DArray::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::Texture1DArray::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

Rendering::TextureSharedPtr Rendering::Texture1DArray::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::Texture1DArray::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return Clone();
}

Rendering::Texture1DArray::RendererObjectSharedPtr Rendering::Texture1DArray::CreateRendererObject(RendererTypes rendererTypes)
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    switch (rendererTypes)
    {
        case RendererTypes::OpenGL:
        {
            return std::make_shared<OpenGLTexture1Array>(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()), GetName());
        }
        default:
        {
            THROW_EXCEPTION(SYSTEM_TEXT("渲染类型不存在。"s))
        }
    }
}

int Rendering::Texture1DArray::GetNumItems() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumItems();
}

int Rendering::Texture1DArray::GetDimension(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetDimension(index);
}

Rendering::DataFormatType Rendering::Texture1DArray::GetFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetFormat();
}

int Rendering::Texture1DArray::GetNumLevels() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumLevels();
}

int Rendering::Texture1DArray::GetNumDimensions() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumDimensions();
}

bool Rendering::Texture1DArray::HasMipMaps() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->HasMipMaps();
}

int Rendering::Texture1DArray::GetLength() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetLength();
}

void Rendering::Texture1DArray::AutoGenerateMipMaps() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->AutoGenerateMipMaps();
}

bool Rendering::Texture1DArray::WantAutoGenerateMipMaps() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->WantAutoGenerateMipMaps();
}

int Rendering::Texture1DArray::GetNumSubResources() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumSubResources();
}