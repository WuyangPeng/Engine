///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:29)

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
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/DataFormat.h"
#include "Rendering/Resources/Detail/Textures/Texture3DImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Texture3D)

CORE_TOOLS_RTTI_DEFINE(Rendering, Texture3D);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Texture3D);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Texture3D);

Rendering::Texture3D::Texture3D(DataFormatType format, int width, int height, int thickness, bool hasMipmaps)
    : ParentType{ ImplType::GetTotalElements(1, width, height, thickness, hasMipmaps),
                  DataFormat::GetNumBytesPerStruct(format),
                  GraphicsObjectType::Texture3 },
      impl{ format, width, height, thickness, hasMipmaps }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Texture3D)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture3D, GetNumItems, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture3D, GetFormat, Rendering::DataFormatType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture3D, GetNumLevels, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Texture3D, GetDimension, int, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture3D, GetNumDimensions, int)

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

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Texture3D, GetNumLevelBytes, int, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Texture3D, GetWidth, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Texture3D, GetHeight, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Texture3D, GetThickness, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture3D, HasMipmaps, bool)

void Rendering::Texture3D::ReadFromFile(ReadFileManager& inFile)
{
    RENDERING_CLASS_IS_VALID_1;

    impl->ReadFromFile(inFile);

    ParentType::ReadResourceDataFromFile(inFile);

    ParentType::ReadStorageDataFromFile(inFile);
}

void Rendering::Texture3D::SaveToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    ParentType::SaveTypeToFile(outFile);

    impl->SaveToFile(outFile);

    ParentType::SaveResourceDataToFile(outFile);

    ParentType::SaveStorageDataToFile(outFile);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture3D, AutogenerateMipmaps, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture3D, WantAutogenerateMipmaps, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture3D, GetNumSubresources, int)

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
            return std::make_shared<OpenGLTexture3>(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()), GetName());
        default:
            return ParentType::CreateRendererObject(rendererTypes);
    }
}