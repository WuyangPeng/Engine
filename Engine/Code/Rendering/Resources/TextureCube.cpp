///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 14:43)

#include "Rendering/RenderingExport.h"

#include "TextureCube.h"
#include "Detail/TextureCubeImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSource.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/Renderers/RendererManager.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, TextureCube)

CORE_TOOLS_RTTI_DEFINE(Rendering, TextureCube);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, TextureCube);
CORE_TOOLS_FACTORY_DEFINE(Rendering, TextureCube);

using std::make_shared;

Rendering::TextureCube::TextureCube(TextureFormat format, int dimension, int numLevels, BufferUsage usage)
    : ParentType{ CoreTools::DisableNotThrow::Disable }, impl{ format, dimension, numLevels, usage }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TextureCube)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TextureCube, GetFormat, Rendering::TextureFormat)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TextureCube, GetTextureType, Rendering::TextureFlags)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TextureCube, GetUsage, Rendering::BufferUsage)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TextureCube, GetNumLevels, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TextureCube, GetNumDimensions, int)

int Rendering::TextureCube::GetDimension(int index, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetDimension(index, level);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, TextureCube, GetNumLevelBytes, int, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TextureCube, GetNumTotalBytes, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, TextureCube, GetLevelOffset, int, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, TextureCube, GetPixelSize, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TextureCube, IsCompressed, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, TextureCube, IsMipmapable, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, TextureCube, SaveToFile, WriteFileManager&, void)

void Rendering::TextureCube::SetUserField(int index, int userField)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetUserField(index, userField);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, TextureCube, GetUserField, int, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, TextureCube, GetWidth, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, TextureCube, GetHeight, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, TextureCube, HasMipmaps, bool)

char* Rendering::TextureCube::GetTextureData(int face, int level)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetTextureData(face, level);
}

const char* Rendering::TextureCube::GetTextureData(int face, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetTextureData(face, level);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, TextureCube, ReadFromFile, ReadFileManager&, void)

void Rendering::TextureCube::GenerateMipmaps()
{
    RENDERING_CLASS_IS_VALID_1;

    if (!impl->HasMipmaps())
    {
        RENDERER_MANAGE_SINGLETON.UnbindAll(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()));

        impl->GenerateMipmaps();

        const auto numLevels = impl->GetNumLevels();

        for (auto face = 0; face < 6; ++face)
        {
            for (auto level = 0; level < numLevels; ++level)
            {
                RENDERER_MANAGE_SINGLETON.UpdateAll(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()), face, level);
            }
        }
    }
    else
    {
        impl->GenerateMipmaps();
    }
}

Rendering::TextureCube::TextureCube(LoadConstructor value)
    : ParentType{ value }, impl{ CoreTools::DisableNotThrow::Disable }
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

uint64_t Rendering::TextureCube::Register(CoreTools::ObjectRegister& target) const
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

    return std::make_shared<ClassType>(*this);
}
