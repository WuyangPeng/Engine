///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/29 20:34)

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

CORE_TOOLS_RTTI_DEFINE(Rendering, TextureCube);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, TextureCube);
CORE_TOOLS_FACTORY_DEFINE(Rendering, TextureCube);

Rendering::TextureCube::TextureCube(DataFormatType format, int length, bool hasMipMaps)
    : ParentType{ ImplType::GetTotalElements(System::EnumCastUnderlying(CubeFaceType::Count), length, length, 1, hasMipMaps),
                  DataFormat::GetNumBytesPerStruct(format),
                  GraphicsObjectType::TextureCube },
      impl{ format, length, hasMipMaps }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TextureCube)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TextureCube, GetNumItems, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TextureCube, GetFormat, Rendering::DataFormatType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TextureCube, GetNumLevels, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, TextureCube, GetDimension, int, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TextureCube, GetNumDimensions, int)

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

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, TextureCube, GetNumLevelBytes, int, int)

void Rendering::TextureCube::ReadFromFile(ReadFileManager& inFile)
{
    RENDERING_CLASS_IS_VALID_1;

    impl->ReadFromFile(inFile);

    ParentType::ReadResourceDataFromFile(inFile);

    ParentType::ReadStorageDataFromFile(inFile);
}

void Rendering::TextureCube::SaveToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    ParentType::SaveTypeToFile(outFile);

    impl->SaveToFile(outFile);

    ParentType::SaveResourceDataToFile(outFile);

    ParentType::SaveStorageDataToFile(outFile);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, TextureCube, GetWidth, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, TextureCube, GetHeight, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TextureCube, HasMipMaps, bool)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TextureCube, AutoGenerateMipMaps, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TextureCube, WantAutoGenerateMipMaps, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TextureCube, GetNumSubResources, int)

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
    RENDERING_CLASS_IS_VALID_CONST_9;

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