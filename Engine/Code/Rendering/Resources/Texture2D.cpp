///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 11:26)

#include "Rendering/RenderingExport.h"

#include "Texture2D.h"
#include "Detail/Texture2DImpl.h"
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

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Texture2D)

CORE_TOOLS_RTTI_DEFINE(Rendering, Texture2D);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Texture2D);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Texture2D);

Rendering::Texture2D::Texture2D(TextureFormat format, int dimension0, int dimension1, int numLevels, BufferUsage usage)
    : ParentType{ CoreTools::DisableNotThrow::Disable }, impl{ format, dimension0, dimension1, numLevels, usage }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Texture2D)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture2D, GetFormat, Rendering::TextureFormat)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture2D, GetTextureType, Rendering::TextureFlags)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture2D, GetUsage, Rendering::BufferUsage)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture2D, GetNumLevels, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture2D, GetNumDimensions, int)

int Rendering::Texture2D::GetDimension(int index, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetDimension(index, level);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Texture2D, GetNumLevelBytes, int, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture2D, GetNumTotalBytes, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Texture2D, GetLevelOffset, int, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Texture2D, GetPixelSize, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture2D, IsCompressed, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Texture2D, IsMipmapable, bool)

void Rendering::Texture2D::SetUserField(int index, int userField)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetUserField(index, userField);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Texture2D, GetUserField, int, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Texture2D, GetWidth, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Texture2D, GetHeight, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Texture2D, HasMipmaps, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Texture2D, GetTextureData, int, char*)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Texture2D, GetTextureData, int, const char*)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Texture2D, SaveToFile, WriteFileManager&, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Texture2D, ReadFromFile, ReadFileManager&, void)

void Rendering::Texture2D::GenerateMipmaps()
{
    RENDERING_CLASS_IS_VALID_1;

    if (!impl->HasMipmaps())
    {
        RENDERER_MANAGE_SINGLETON.UnbindAll(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()));

        impl->GenerateMipmaps();

        const auto numLevels = impl->GetNumLevels();

        for (auto level = 0; level < numLevels; ++level)
        {
            RENDERER_MANAGE_SINGLETON.UpdateAll(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()), level);
        }
    }
    else
    {
        impl->GenerateMipmaps();
    }
}

Rendering::Texture2D::Texture2D(LoadConstructor value)
    : ParentType{ value }, impl{ CoreTools::DisableNotThrow::Disable }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Texture2D::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

uint64_t Rendering::Texture2D::Register(CoreTools::ObjectRegister& target) const
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

    return std::make_shared<ClassType>(*this);
}
