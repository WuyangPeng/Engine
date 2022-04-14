///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 10:52)

#include "Rendering/RenderingExport.h"

#include "Texture1D.h"
#include "Detail/Texture1DImpl.h"
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

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Texture1D)

CORE_TOOLS_RTTI_DEFINE(Rendering, Texture1D);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Texture1D);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Texture1D);

using std::make_shared;

Rendering::Texture1D::Texture1D(TextureFormat format, int dimension0, int numLevels, BufferUsage usage)
    : ParentType{ CoreTools::DisableNotThrow::Disable }, impl{ format, dimension0, numLevels, usage }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Texture1D)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture1D, GetFormat, Rendering::TextureFormat)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture1D, GetTextureType, Rendering::TextureFlags)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture1D, GetUsage, Rendering::BufferUsage)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture1D, GetNumLevels, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture1D, GetNumDimensions, int)

int Rendering::Texture1D::GetDimension(int index, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetDimension(index, level);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Texture1D, GetNumLevelBytes, int, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture1D, GetNumTotalBytes, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Texture1D, GetLevelOffset, int, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Texture1D, GetPixelSize, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture1D, IsCompressed, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Texture1D, IsMipmapable, bool)

void Rendering::Texture1D::SetUserField(int index, int userField)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetUserField(index, userField);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Texture1D, GetUserField, int, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Texture1D, GetLength, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Texture1D, HasMipmaps, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Texture1D, GetTextureData, int, char*)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Texture1D, GetTextureData, int, const char*)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Texture1D, SaveToFile, WriteFileManager&, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Texture1D, ReadFromFile, ReadFileManager&, void)

void Rendering::Texture1D::GenerateMipmaps()
{
    RENDERING_CLASS_IS_VALID_1;

    if (!impl->HasMipmaps())
    {
        // 如果没有最大miplevels，销毁纹理绑定。稍后重建后重新。
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

uint64_t Rendering::Texture1D::Register(CoreTools::ObjectRegister& target) const
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
