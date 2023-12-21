/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/18 15:01)

#include "Rendering/RenderingExport.h"

#include "VertexFormat.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
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

Rendering::VertexFormat::VertexFormat(VertexFormatCreate vertexFormatCreate, const std::string& name, int numAttributes)
    : ParentType{ name }, impl{ numAttributes }
{
    System::UnusedFunction(vertexFormatCreate);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VertexFormat)

Rendering::VertexFormat::VertexFormatSharedPtr Rendering::VertexFormat::Create(const std::string& name, const AttributeContainer& triple)
{
    auto numAttributes = boost::numeric_cast<int>(triple.size());

    auto vertexFormat = std::make_shared<VertexFormat>(VertexFormatCreate::Init, name, numAttributes);

    auto vertexSize = 0;
    auto index = 0;
    for (const auto& attribute : triple)
    {
        vertexFormat->SetAttribute(index, attribute.GetType(), attribute.GetSemantic(), attribute.GetUnit(), vertexSize);
        vertexSize += DataFormat::GetNumBytesPerStruct(attribute.GetType());

        ++index;
    }

    vertexFormat->SetVertexSize(vertexSize);

    return vertexFormat;
}

Rendering::VertexFormat::VertexFormatSharedPtr Rendering::VertexFormat::Create(const std::string& name)
{
    return std::make_shared<VertexFormat>(VertexFormatCreate::Init, name, 0);
}

void Rendering::VertexFormat::SetAttribute(int attribute, DataFormatType type, Semantic semantic, int unit, int offset)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetAttribute(attribute, type, semantic, unit, offset);
}

int Rendering::VertexFormat::GetNumAttributes() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetNumAttributes();
}

int Rendering::VertexFormat::GetOffset(int attribute) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetOffset(attribute);
}

Rendering::DataFormatType Rendering::VertexFormat::GetAttributeType(int attribute) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetAttributeType(attribute);
}

Rendering::VertexFormat::Semantic Rendering::VertexFormat::GetSemantic(int attribute) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetSemantic(attribute);
}

int Rendering::VertexFormat::GetUnit(int attribute) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetUnit(attribute);
}

int Rendering::VertexFormat::GetVertexSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetVertexSize();
}

void Rendering::VertexFormat::SetVertexSize(int vertexSize)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetVertexSize(vertexSize);
}

void Rendering::VertexFormat::Reset() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Reset();
}

void Rendering::VertexFormat::SetAttribute(int attribute, const VertexFormatAttribute& vertexFormatElement)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetAttribute(attribute, vertexFormatElement);
}

int Rendering::VertexFormat::GetIndex(Semantic semantic, int unit) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetIndex(semantic, unit);
}

Rendering::VertexFormat::VertexFormat(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
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

void Rendering::VertexFormat::Bind(DataFormatType type, Semantic semantic, int unit)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    impl->Bind(type, semantic, unit);
}

Rendering::VertexFormat::VertexFormatSharedPtr Rendering::VertexFormat::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::VertexFormat::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return Clone();
}
