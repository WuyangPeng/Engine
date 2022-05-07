///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/30 10:28)

#include "Rendering/RenderingExport.h"

#include "Buffer.h"
#include "Detail/BufferImpl.h"
#include "CoreTools/DataTypes/TupleDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Buffer)

CORE_TOOLS_RTTI_DEFINE(Rendering, Buffer);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Buffer);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, Buffer);

Rendering::Buffer::Buffer(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ "Buffer" }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Buffer::Buffer(int numElements, int elementSize, BufferUsage usage)
    : ParentType{ "Buffer" }, impl{ numElements, elementSize, usage }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Buffer::~Buffer()
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Buffer)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Buffer, GetNumElements, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Buffer, GetElementSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Buffer, GetUsage, Rendering::BufferUsage)

void Rendering::Buffer::SetNumElements(int numElements) noexcept(g_Assert < 1 || g_RenderingAssert < 1)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetNumElements(numElements);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Buffer, GetNumBytes, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Buffer, GetReadOnlyData, const char*)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Buffer, GetReadOnlyData, int, const char*)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Buffer, GetSpanIterator, Rendering::Buffer::SpanIterator)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Buffer, GetWriteSpanIterator, Rendering::Buffer::WriteSpanIterator)

Rendering::Buffer::Buffer(LoadConstructor value)
    : ParentType{ value }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Buffer::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

uint64_t Rendering::Buffer::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::Buffer::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Buffer::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::Buffer::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::Buffer::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Buffer, SaveBufferDataToFile, WriteFileManager&, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Buffer, ReadBufferDataFromFile, ReadFileManager&, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Buffer, SaveHeadToFile, WriteFileManager&, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Buffer, ReadHeadFromFile, ReadFileManager&, void)

void Rendering::Buffer::ReadBufferDataFromFile(ReadFileManager& inFile, const VertexFormat& vertexformat)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->ReadBufferDataFromFile(inFile, vertexformat);
}

void Rendering::Buffer::SaveBufferDataToFile(WriteFileManager& outFile, const VertexFormat& vertexformat) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->SaveBufferDataToFile(outFile, vertexformat);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Buffer, GetAccessWriteData, int, char*)

void Rendering::Buffer::SetNewData(const std::vector<char>& newData)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetNewData(newData);
}
