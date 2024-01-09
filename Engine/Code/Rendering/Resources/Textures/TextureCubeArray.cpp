/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 14:25)

#include "Rendering/RenderingExport.h"

#include "TextureCubeArray.h"
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
#include "Rendering/OpenGLRenderer/Resources/Textures/OpenGLTextureCubeArray.h"
#include "Rendering/RendererEngine/Flags/RendererTypes.h"
#include "Rendering/Resources/DataFormat.h"
#include "Rendering/Resources/Detail/Textures/TextureCubeImpl.h"
#include "Rendering/Resources/Flags/CubeFaceType.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, TextureCubeArray)

CORE_TOOLS_RTTI_DEFINE(Rendering, TextureCubeArray)
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, TextureCubeArray);
CORE_TOOLS_FACTORY_DEFINE(Rendering, TextureCubeArray);

Rendering::TextureCubeArray::TextureCubeArray(const std::string& name, int numCubes, DataFormatType format, int length, bool hasMipMaps, bool createStorage)
    : ParentType{ name,
                  ImplType::GetTotalElements(numCubes * System::EnumCastUnderlying(CubeFaceType::Count), length, length, 1, hasMipMaps),
                  DataFormat::GetNumBytesPerStruct(format),
                  GraphicsObjectType::TextureCubeArray,
                  createStorage },
      impl{ numCubes, format, length, hasMipMaps },
      numCubes{ numCubes }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TextureCubeArray)

int Rendering::TextureCubeArray::GetDimension(int index, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetDimension(index, level);
}

int Rendering::TextureCubeArray::GetLevelOffset(int item, int level) const
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetLevelOffset(item, level);
}

int Rendering::TextureCubeArray::GetLength() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return GetWidth();
}

int Rendering::TextureCubeArray::GetIndex(int item, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetIndex(item, level);
}

Rendering::TextureCubeArray::TextureCubeArray(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::DisableNotThrow::Disable }, numCubes{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::TextureCubeArray::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    size += CoreTools::GetStreamSize(numCubes);

    return size;
}

int64_t Rendering::TextureCubeArray::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::TextureCubeArray::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    target.Write(numCubes);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::TextureCubeArray::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::TextureCubeArray::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::TextureCubeArray::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    source.Read(numCubes);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

Rendering::TextureSharedPtr Rendering::TextureCubeArray::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::TextureCubeArray::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return Clone();
}

int Rendering::TextureCubeArray::GetNumElementsFor(int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumLevelBytes(level) / GetElementSize();
}

int Rendering::TextureCubeArray::GetNumCubes() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numCubes;
}

int Rendering::TextureCubeArray::GetItemIndexFor(int cube, int face) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return cube * cubeFaceCount + face;
}

int Rendering::TextureCubeArray::GetCubeIndexFor(int item) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return item / cubeFaceCount;
}

int Rendering::TextureCubeArray::GetFaceIndexFor(int item) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return item % cubeFaceCount;
}

int Rendering::TextureCubeArray::GetOffsetForCubeArray(int cube, int face, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::GetOffsetFor(GetItemIndexFor(cube, face), level);
}

int Rendering::TextureCubeArray::GetIndex(int cube, int face, int level) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return GetNumLevels() * (cubeFaceCount * cube + face) + level;
}

Rendering::Resource::ConstSpanIterator Rendering::TextureCubeArray::GetDataForCubeArray(int cube, int face, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::GetDataForArray(GetItemIndexFor(cube, face), level);
}

Rendering::Resource::SpanIterator Rendering::TextureCubeArray::GetDataForCubeArray(int cube, int face, int level)
{
    RENDERING_CLASS_IS_VALID_1;

    return TextureArray::GetDataForArray(GetItemIndexFor(cube, face), level);
}

Rendering::TextureCubeArray::RendererObjectSharedPtr Rendering::TextureCubeArray::CreateRendererObject(RendererTypes rendererTypes)
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    switch (rendererTypes)
    {
        case RendererTypes::OpenGL:
        {
            return std::make_shared<OpenGLTextureCubeArray>(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()), GetName());
        }
        default:
        {
            THROW_EXCEPTION(SYSTEM_TEXT("渲染类型不存在。"s))
        }
    }
}

int Rendering::TextureCubeArray::GetNumItems() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumItems();
}

int Rendering::TextureCubeArray::GetDimension(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetDimension(index);
}

Rendering::DataFormatType Rendering::TextureCubeArray::GetFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetFormat();
}

int Rendering::TextureCubeArray::GetNumLevels() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumLevels();
}

int Rendering::TextureCubeArray::GetNumDimensions() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumDimensions();
}

int Rendering::TextureCubeArray::GetNumLevelBytes(int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumLevelBytes(level);
}

bool Rendering::TextureCubeArray::HasMipMaps() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->HasMipMaps();
}

int Rendering::TextureCubeArray::GetWidth() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetWidth();
}

int Rendering::TextureCubeArray::GetHeight() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetHeight();
}

void Rendering::TextureCubeArray::AutoGenerateMipMaps() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->AutoGenerateMipMaps();
}

bool Rendering::TextureCubeArray::WantAutoGenerateMipMaps() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->WantAutoGenerateMipMaps();
}

int Rendering::TextureCubeArray::GetNumSubResources() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumSubResources();
}