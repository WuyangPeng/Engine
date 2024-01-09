/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 14:16)

#include "Rendering/RenderingExport.h"

#include "Texture2DArray.h"
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
#include "Rendering/OpenGLRenderer/Resources/Textures/OpenGLTexture2Array.h"
#include "Rendering/RendererEngine/Flags/RendererTypes.h"
#include "Rendering/Resources/DataFormat.h"
#include "Rendering/Resources/Detail/Textures/Texture2DImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Texture2DArray)

CORE_TOOLS_RTTI_DEFINE(Rendering, Texture2DArray)
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Texture2DArray);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Texture2DArray);

Rendering::Texture2DArray::Texture2DArray(const std::string& name, int numItems, DataFormatType format, int width, int height, bool hasMipMaps, bool createStorage)
    : ParentType{ name,
                  ImplType::GetTotalElements(numItems, width, height, 1, hasMipMaps),
                  DataFormat::GetNumBytesPerStruct(format),
                  GraphicsObjectType::Texture2Array,
                  createStorage },
      impl{ numItems, format, width, height, hasMipMaps }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Texture2DArray)

int Rendering::Texture2DArray::GetDimension(int index, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetDimension(index, level);
}

int Rendering::Texture2DArray::GetLevelOffset(int item, int level) const
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetLevelOffset(item, level);
}

int Rendering::Texture2DArray::GetIndex(int item, int level) const
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetIndex(item, level);
}

Rendering::Texture2DArray::Texture2DArray(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::DisableNotThrow::Disable }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Texture2DArray::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::Texture2DArray::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::Texture2DArray::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Texture2DArray::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::Texture2DArray::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::Texture2DArray::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

Rendering::TextureSharedPtr Rendering::Texture2DArray::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::Texture2DArray::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return Clone();
}

int Rendering::Texture2DArray::GetNumElementsFor(int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumLevelBytes(level) / GetElementSize();
}

Rendering::Texture2DArray::RendererObjectSharedPtr Rendering::Texture2DArray::CreateRendererObject(RendererTypes rendererTypes)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    switch (rendererTypes)
    {
        case RendererTypes::OpenGL:
        {
            return std::make_shared<OpenGLTexture2Array>(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()), GetName());
        }
        default:
        {
            THROW_EXCEPTION(SYSTEM_TEXT("渲染类型不存在。"s))
        }
    }
}

int Rendering::Texture2DArray::GetNumItems() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetNumItems();
}

int Rendering::Texture2DArray::GetDimension(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetDimension(index);
}

Rendering::DataFormatType Rendering::Texture2DArray::GetFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetFormat();
}

int Rendering::Texture2DArray::GetNumLevels() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetNumLevels();
}

int Rendering::Texture2DArray::GetNumDimensions() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetNumDimensions();
}

int Rendering::Texture2DArray::GetNumLevelBytes(int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetNumLevelBytes(level);
}

bool Rendering::Texture2DArray::HasMipMaps() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->HasMipMaps();
}

int Rendering::Texture2DArray::GetWidth() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetWidth();
}

int Rendering::Texture2DArray::GetHeight() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetHeight();
}

void Rendering::Texture2DArray::AutoGenerateMipMaps() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->AutoGenerateMipMaps();
}

bool Rendering::Texture2DArray::WantAutoGenerateMipMaps() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->WantAutoGenerateMipMaps();
}

int Rendering::Texture2DArray::GetNumSubResources() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetNumSubResources();
}