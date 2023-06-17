///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/16 14:43)

#include "Rendering/RenderingExport.h"

#include "TextureCubeArray.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/OpenGLRenderer/Resources/Textures/OpenGLTextureCubeArray.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "Rendering/Resources/DataFormat.h"
#include "Rendering/Resources/Detail/Textures/TextureCubeImpl.h"
#include "Rendering/Resources/Flags/CubeFaceType.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, TextureCubeArray)

CORE_TOOLS_RTTI_DEFINE(Rendering, TextureCubeArray);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, TextureCubeArray);
CORE_TOOLS_FACTORY_DEFINE(Rendering, TextureCubeArray);

Rendering::TextureCubeArray::TextureCubeArray(int numCubes, DataFormatType format, int length, bool hasMipmaps)
    : ParentType{ ImplType::GetTotalElements(numCubes * System::EnumCastUnderlying(CubeFaceType::Count), length, length, 1, hasMipmaps),
                  DataFormat::GetNumBytesPerStruct(format),
                  GraphicsObjectType::TextureCubeArray },
      impl{ numCubes, format, length, hasMipmaps },
      numCubes{ numCubes }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TextureCubeArray)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TextureCubeArray, GetNumItems, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TextureCubeArray, GetFormat, Rendering::DataFormatType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TextureCubeArray, GetNumLevels, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, TextureCubeArray, GetDimension, int, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TextureCubeArray, GetNumDimensions, int)

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

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, TextureCubeArray, GetNumLevelBytes, int, int)

void Rendering::TextureCubeArray::SaveToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    ParentType::SaveTypeToFile(outFile);

    impl->SaveToFile(outFile);

    ParentType::SaveResourceDataToFile(outFile);

    outFile.Write(sizeof(int32_t), &numCubes);

    ParentType::SaveStorageDataToFile(outFile);
}

void Rendering::TextureCubeArray::ReadFromFile(ReadFileManager& inFile)
{
    RENDERING_CLASS_IS_VALID_1;

    impl->ReadFromFile(inFile);

    ParentType::ReadResourceDataFromFile(inFile);

    inFile.Read(sizeof(int32_t), &numCubes);

    ParentType::ReadStorageDataFromFile(inFile);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, TextureCubeArray, GetWidth, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, TextureCubeArray, GetHeight, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TextureCubeArray, HasMipmaps, bool)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TextureCubeArray, AutogenerateMipmaps, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TextureCubeArray, WantAutogenerateMipmaps, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TextureCubeArray, GetNumSubresources, int)

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
    RENDERING_CLASS_IS_VALID_CONST_9;

    switch (rendererTypes)
    {
        case RendererTypes::OpenGL:
            return std::make_shared<OpenGLTextureCubeArray>(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()), GetName());
        default:
            return ParentType::CreateRendererObject(rendererTypes);
    }
}