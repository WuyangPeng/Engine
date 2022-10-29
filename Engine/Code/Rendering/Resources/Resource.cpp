///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/08 15:56)

#include "Rendering/RenderingExport.h"

#include "Resource.h"
#include "Detail/ResourceImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "Rendering/Base/Flags/GraphicsObjectType.h"
#include "Rendering/Resources/Flags/CopyType.h"
#include "Rendering/Resources/Flags/UsageType.h"

#include <string>

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Resource)

CORE_TOOLS_RTTI_DEFINE(Rendering, Resource);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Resource);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, Resource);

Rendering::Resource::Resource(int numElements, int elementSize, GraphicsObjectType type)
    : ParentType{ "Resource", type },
      impl{ numElements, elementSize }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::Resource::Resource(int numElements, int elementSize, const StorageType& storage, GraphicsObjectType type)
    : ParentType{ "Resource", type },
      impl{ numElements, elementSize, storage }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Resource)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Resource, GetNumElements, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Resource, GetElementSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Resource, GetNumBytes, int)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, Resource, SetUsage, UsageType, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Resource, GetUsage, Rendering::UsageType)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, Resource, SetCopy, CopyType, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Resource, GetCopy, Rendering::CopyType)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Resource, GetData, Rendering::ResourceImpl::ConstSpanIterator)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Resource, GetData, int, Rendering::ResourceImpl::ConstSpanIterator)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Resource, GetData, Rendering::ResourceImpl::SpanIterator)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Resource, GetData, int, Rendering::ResourceImpl::SpanIterator)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Resource, GetOffset, int)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Resource, SetOffset, int, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Resource, GetNumActiveElements, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Resource, GetNumActiveBytes, int)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Resource, SetNumActiveElements, int, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Resource, SetNewData, StorageType, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Resource, GetOriginalData, const char*)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Resource, GetOriginalData, int, const char*)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Resource, GetOriginalData, int, char*)

Rendering::Resource::Resource(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ 0, 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

int Rendering::Resource::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::Resource::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::Register(target);
}

void Rendering::Resource::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Resource::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::Link(source);
}

void Rendering::Resource::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::PostLink();
}

void Rendering::Resource::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

Rendering::Resource::RendererObjectSharedPtr Rendering::Resource::CreateRendererObject(MAYBE_UNUSED RendererTypes rendererTypes)
{
    RENDERING_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("函数未实现"));
}