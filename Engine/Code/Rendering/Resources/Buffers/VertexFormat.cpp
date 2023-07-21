///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/29 17:11)

#include "Rendering/RenderingExport.h"

#include "VertexFormat.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/Resources/DataFormat.h"
#include "Rendering/Resources/Detail/Buffers/VertexFormatImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, VertexFormat)

CORE_TOOLS_RTTI_DEFINE(Rendering, VertexFormat);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, VertexFormat);
CORE_TOOLS_FACTORY_DEFINE(Rendering, VertexFormat);

Rendering::VertexFormat::VertexFormat(VertexFormatCreate vertexFormatCreate, int numAttributes)
    : ParentType{ "VertexFormat" }, impl{ numAttributes }
{
    System::UnusedFunction(vertexFormatCreate);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VertexFormat)

Rendering::VertexFormat::VertexFormatSharedPtr Rendering::VertexFormat::Create(const AttributeContainer& triple)
{
    auto numAttributes = boost::numeric_cast<int>(triple.size());

    auto vertexFormat = std::make_shared<VertexFormat>(VertexFormatCreate::Init, numAttributes);

    auto offset = 0;
    for (auto i = 0; i < numAttributes; ++i)
    {
        const auto& attribute = triple.at(i);
        vertexFormat->SetAttribute(i, attribute.GetType(), attribute.GetUsage(), attribute.GetUsageIndex(), offset);
        offset += DataFormat::GetNumBytesPerStruct(attribute.GetType());
    }

    vertexFormat->SetStride(offset);

    return vertexFormat;
}

Rendering::VertexFormat::VertexFormatSharedPtr Rendering::VertexFormat::Create()
{
    return std::make_shared<VertexFormat>(VertexFormatCreate::Init, 1);
}

void Rendering::VertexFormat::SetAttribute(int attribute, DataFormatType type, Semantic usage, int usageIndex, int offset)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetAttribute(attribute, type, usage, usageIndex, offset);
}

void Rendering::VertexFormat::SetAttribute(int attribute, const VertexFormatAttribute& vertexFormatElement)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetAttribute(attribute, vertexFormatElement);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexFormat, SetStride, int, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VertexFormat, GetNumAttributes, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexFormat, GetOffset, int, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexFormat, GetAttributeType, int, Rendering::DataFormatType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexFormat, GetAttributeUsage, int, Rendering::VertexFormatFlags::Semantic)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexFormat, GetUsageIndex, int, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VertexFormat, GetStride, int)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VertexFormat, Reset, void)

int Rendering::VertexFormat::GetIndex(Semantic usage, int usageIndex) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetIndex(usage, usageIndex);
}

Rendering::VertexFormat::VertexFormat(LoadConstructor value)
    : ParentType{ value }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

int Rendering::VertexFormat::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::VertexFormat::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::Register(target);
}

void Rendering::VertexFormat::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::VertexFormat::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::Link(source);
}

void Rendering::VertexFormat::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::PostLink();
}

void Rendering::VertexFormat::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::VertexFormat::Bind(Semantic semantic, DataFormatType type, int unit)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    impl->Bind(semantic, type, unit);
}

void Rendering::VertexFormat::SaveToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    impl->SaveToFile(outFile);
}

void Rendering::VertexFormat::ReadFromFile(ReadFileManager& inFile)
{
    RENDERING_CLASS_IS_VALID_9;

    impl->ReadFromFile(inFile);
}

Rendering::VertexFormat::VertexFormatSharedPtr Rendering::VertexFormat::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

Rendering::VertexFormatSharedPtr Rendering::VertexFormat::LoadFromFile(ReadFileManager& manager)
{
    RENDERING_CLASS_IS_VALID_9;

    auto numAttributes = 0;
    manager.Read(sizeof(int32_t), &numAttributes);

    auto vertexFormat = std::make_shared<VertexFormat>(VertexFormatCreate::Init, numAttributes);

    vertexFormat->ReadFromFile(manager);

    return vertexFormat;
}

CoreTools::ObjectInterfaceSharedPtr Rendering::VertexFormat::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return Clone();
}
