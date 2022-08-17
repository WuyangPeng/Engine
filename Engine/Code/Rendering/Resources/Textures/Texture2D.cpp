///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/16 10:28)

#include "Rendering/RenderingExport.h"

#include "Texture2D.h"
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
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/DataFormat.h"
#include "Rendering/Resources/Detail/Textures/Texture2DImpl.h"
#include "Rendering/Resources/Flags/UsageType.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Texture2D)

CORE_TOOLS_RTTI_DEFINE(Rendering, Texture2D);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Texture2D);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Texture2D);

Rendering::Texture2D::Texture2D(DataFormatType format, int width, int height, bool hasMipmaps)
    : ParentType{ ImplType::GetTotalElements(1, width, height, 1, hasMipmaps),
                  DataFormat::GetNumBytesPerStruct(format),
                  GraphicsObjectType::Texture2 },
      impl{ format, width, height, hasMipmaps },
      shared{ false }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Texture2D::Texture2D(DataFormatType format, int width, int height, bool hasMipmaps, GraphicsObjectType type)
    : ParentType{ ImplType::GetTotalElements(1, width, height, 1, hasMipmaps), DataFormat::GetNumBytesPerStruct(format), type },
      impl{ format, width, height, hasMipmaps },
      shared{ false }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Texture2D)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture2D, GetNumItems, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture2D, GetFormat, Rendering::DataFormatType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture2D, GetNumLevels, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Texture2D, GetDimension, int, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture2D, GetNumDimensions, int)

int Rendering::Texture2D::GetDimension(int index, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetDimension(index, level);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Texture2D, GetNumLevelBytes, int, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Texture2D, GetWidth, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Texture2D, GetHeight, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture2D, HasMipmaps, bool)

void Rendering::Texture2D::SaveToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    ParentType::SaveTypeToFile(outFile);

    impl->SaveToFile(outFile);

    ParentType::SaveResourceDataToFile(outFile);

    outFile.Write(sizeof(bool), &shared);

    ParentType::SaveStorageDataToFile(outFile);
}

void Rendering::Texture2D::ReadFromFile(ReadFileManager& inFile)
{
    RENDERING_CLASS_IS_VALID_1;

    impl->ReadFromFile(inFile);

    ParentType::ReadResourceDataFromFile(inFile);

    inFile.Read(sizeof(bool), &shared);

    ParentType::ReadStorageDataFromFile(inFile);
}

int Rendering::Texture2D::GetLevelOffset(int item, int level) const
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetLevelOffset(item, level);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture2D, AutogenerateMipmaps, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture2D, WantAutogenerateMipmaps, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture2D, GetNumSubresources, int)

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

    size += CORE_TOOLS_STREAM_SIZE(shared);

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