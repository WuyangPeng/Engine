///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 16:58)

#include "Rendering/RenderingExport.h"

#include "VertexFormat.h"
#include "Detail/VertexFormatImpl.h"
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
#include "Rendering/Renderers/RendererManager.h"

using std::make_shared;
using std::vector;

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, VertexFormat)

CORE_TOOLS_RTTI_DEFINE(Rendering, VertexFormat);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, VertexFormat);
CORE_TOOLS_FACTORY_DEFINE(Rendering, VertexFormat);

// private
Rendering::VertexFormat::VertexFormat(MAYBE_UNUSED VertexFormatCreate vertexFormatCreate, int numAttributes)
    : ParentType{ "VertexFormat" }, impl{ numAttributes }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VertexFormat)

// static
Rendering::VertexFormat::VertexFormatSharedPtr Rendering::VertexFormat::Create(const vector<VertexFormatType>& triple)
{
    auto numAttributes = boost::numeric_cast<int>(triple.size());

    auto vertexformat = std::make_shared<VertexFormat>(VertexFormatCreate::Init, numAttributes);

    auto offset = 0;
    for (auto i = 0; i < numAttributes; ++i)
    {
        vertexformat->SetAttribute(i, 0, offset, triple.at(i));
        offset += GetTypeSize(triple.at(i).GetType());
    }

    vertexformat->SetStride(offset);

    return vertexformat;
}

Rendering::VertexFormat::VertexFormatSharedPtr Rendering::VertexFormat::Create(const std::vector<VertexFormatElement>& triple)
{
    auto numAttributes = boost::numeric_cast<int>(triple.size());

    auto vertexformat = std::make_shared<VertexFormat>(VertexFormatCreate::Init, numAttributes);

    auto offset = 0u;
    for (auto i = 0; i < numAttributes; ++i)
    {
        vertexformat->SetAttribute(i, triple.at(i));
        offset += GetTypeSize(triple.at(i).GetType());
    }

    vertexformat->SetStride(boost::numeric_cast<int>(offset));

    return vertexformat;
}

void Rendering::VertexFormat::SetAttribute(int attribute, int32_t streamIndex, int32_t offset, AttributeType type, AttributeUsage usage, int32_t usageIndex)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetAttribute(attribute, streamIndex, offset, type, usage, usageIndex);
}

void Rendering::VertexFormat::SetAttribute(int attribute, int32_t streamIndex, int32_t offset, const VertexFormatType& vertexFormatType)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetAttribute(attribute, streamIndex, offset, vertexFormatType);
}

void Rendering::VertexFormat::SetAttribute(int attribute, const VertexFormatElement& vertexFormatElement)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetAttribute(attribute, vertexFormatElement);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexFormat, SetStride, int, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VertexFormat, GetNumAttributes, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexFormat, GetStreamIndex, int, int32_t)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexFormat, GetOffset, int, int32_t)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexFormat, GetAttributeType, int, Rendering::VertexFormatFlags::AttributeType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexFormat, GetAttributeUsage, int, Rendering::VertexFormatFlags::AttributeUsage)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexFormat, GetUsageIndex, int, int32_t)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VertexFormat, GetStride, int)

int Rendering::VertexFormat::GetIndex(AttributeUsage usage, int32_t usageIndex) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetIndex(usage, usageIndex);
}

int Rendering::VertexFormat::GetComponentSize(AttributeType type) noexcept
{
    return ImplType::GetComponentSize(type);
}

int Rendering::VertexFormat::GetNumComponents(AttributeType type) noexcept
{
    return ImplType::GetNumComponents(type);
}

int Rendering::VertexFormat::GetTypeSize(AttributeType type) noexcept
{
    return ImplType::GetTypeSize(type);
}

Rendering::VertexFormat::VertexFormat(LoadConstructor value)
    : ParentType{ value }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::VertexFormat::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

uint64_t Rendering::VertexFormat::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::VertexFormat::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::VertexFormat::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::VertexFormat::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::VertexFormat::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::VertexFormat::SaveToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    impl->SaveToFile(outFile);
}

void Rendering::VertexFormat::ReadFromFile(ReadFileManager& inFile)
{
    RENDERING_CLASS_IS_VALID_1;

    impl->ReadFromFile(inFile);
}

Rendering::VertexFormat::VertexFormatSharedPtr Rendering::VertexFormat::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

Rendering::VertexFormatSharedPtr Rendering::VertexFormat::LoadFromFile(ReadFileManager& manager)
{
    auto numAttributes = 0;
    manager.Read(sizeof(int32_t), &numAttributes);

    auto vertexFormat = std::make_shared<VertexFormat>(VertexFormatCreate::Init, numAttributes);

    vertexFormat->ReadFromFile(manager);

    return vertexFormat;
}

CoreTools::ObjectInterfaceSharedPtr Rendering::VertexFormat::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
