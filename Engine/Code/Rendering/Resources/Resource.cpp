/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 13:59)

#include "Rendering/RenderingExport.h"

#include "Resource.h"
#include "Detail/ResourceImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "Rendering/Base/Flags/GraphicsObjectType.h"
#include "Rendering/Resources/Flags/CopyType.h"
#include "Rendering/Resources/Flags/UsageType.h"

#include <string>

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Resource)

CORE_TOOLS_RTTI_DEFINE(Rendering, Resource)
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Resource);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, Resource);

Rendering::Resource::Resource(const std::string& name, GraphicsObjectType type)
    : ParentType{ name, type }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::Resource::Resource(const std::string& name, int numElements, int elementSize, GraphicsObjectType type, bool createStorage)
    : ParentType{ name, type }, impl{ numElements, elementSize, createStorage }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::Resource::Resource(const std::string& name, int numElements, int elementSize, const StorageType& storage, GraphicsObjectType type)
    : ParentType{ name, type }, impl{ numElements, elementSize, storage }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Resource)

bool Rendering::Resource::IsCreateStorage() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->IsCreateStorage();
}

void Rendering::Resource::CreateStorage()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CreateStorage();
}

void Rendering::Resource::DestroyStorage()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->DestroyStorage();
}

int Rendering::Resource::GetNumElements() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetNumElements();
}

int Rendering::Resource::GetElementSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetElementSize();
}

int Rendering::Resource::GetNumBytes() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetNumBytes();
}

void Rendering::Resource::SetUsage(UsageType usageType) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetUsage(usageType);
}

Rendering::UsageType Rendering::Resource::GetUsage() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetUsage();
}

void Rendering::Resource::SetCopy(CopyType copyType) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetCopy(copyType);
}

Rendering::CopyType Rendering::Resource::GetCopy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetCopy();
}

Rendering::Resource::ConstSpanIterator Rendering::Resource::GetStorage() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetStorage();
}

Rendering::Resource::SpanIterator Rendering::Resource::GetStorage() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetStorage();
}

Rendering::Resource::ConstSpanIterator Rendering::Resource::GetStorage(int offset) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetStorage(offset);
}

Rendering::Resource::SpanIterator Rendering::Resource::GetStorage(int offset)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetStorage(offset);
}

void Rendering::Resource::SetOffset(int offset)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetOffset(offset);
}

int Rendering::Resource::GetOffset() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetOffset();
}

void Rendering::Resource::SetNumActiveElements(int numActiveElements)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetNumActiveElements(numActiveElements);
}

int Rendering::Resource::GetNumActiveElements() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetNumActiveElements();
}

int Rendering::Resource::GetNumActiveBytes() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetNumActiveBytes();
}

void Rendering::Resource::SetStorage(const StorageType& storage)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetStorage(storage);
}

const char* Rendering::Resource::GetOriginalData() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetOriginalData();
}

const char* Rendering::Resource::GetOriginalData(int offset) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetOriginalData(offset);
}

char* Rendering::Resource::GetOriginalData()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetOriginalData();
}

char* Rendering::Resource::GetOriginalData(int offset)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetOriginalData(offset);
}

Rendering::Resource::Resource(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
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
