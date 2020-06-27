// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 16:12)

#include "Rendering/RenderingExport.h"

#include "Detail/VertexFormatImpl.h"
#include "VertexFormat.h"
#include "Rendering/Renderers/RendererManager.h" 
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
 
using std::vector;
using std::make_shared;

CORE_TOOLS_RTTI_DEFINE(Rendering,VertexFormat);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering,VertexFormat);
CORE_TOOLS_FACTORY_DEFINE(Rendering,VertexFormat); 

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering,VertexFormat);

// private
Rendering::VertexFormat
	::VertexFormat( int numAttributes )
	:ParentType{ "VertexFormat" }, m_Impl{ make_shared<ImplType>(numAttributes) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::VertexFormat
	::~VertexFormat()
{
	RENDERER_MANAGE_SINGLETON.UnbindAll(this); 

	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Rendering,VertexFormat)

// static
Rendering::VertexFormat::VertexFormatSmartPointer Rendering::VertexFormat
	::Create(const vector<VertexFormatType> triple)
{
	auto numAttributes = boost::numeric_cast<int>(triple.size());

	VertexFormatSmartPointer vertexformat{ NEW0 VertexFormat(numAttributes) };

	auto offset = 0u;
	for (auto i = 0; i < numAttributes; ++i)
	{
		vertexformat->SetAttribute(i, 0, offset,triple[i]);
		offset += GetTypeSize(triple[i].GetType());
	}

	vertexformat->SetStride(boost::numeric_cast<int>(offset));

	return vertexformat;
}

Rendering::VertexFormat::VertexFormatSmartPointer Rendering::VertexFormat
	::Create(const std::vector<VertexFormatElement> triple) 
{
	auto numAttributes = boost::numeric_cast<int>(triple.size());

	VertexFormatSmartPointer vertexformat{ NEW0 VertexFormat(numAttributes) };

	auto offset = 0u;
	for (auto i = 0; i < numAttributes; ++i)
	{
		vertexformat->SetAttribute(i, triple[i]);
		offset += GetTypeSize(triple[i].GetType());
	}

	vertexformat->SetStride(boost::numeric_cast<int>(offset));

	return vertexformat;
}

void Rendering::VertexFormat
	::SetAttribute( int attribute, unsigned int streamIndex,unsigned int offset,AttributeType type,AttributeUsage usage, unsigned int usageIndex )
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetAttribute(attribute,streamIndex,offset,type,usage,usageIndex);
}

void Rendering::VertexFormat
    ::SetAttribute(int attribute, unsigned int streamIndex,unsigned int offset,const VertexFormatType& vertexFormatType)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetAttribute(attribute, streamIndex,offset, vertexFormatType);
}

void Rendering::VertexFormat
    ::SetAttribute(int attribute,const VertexFormatElement& vertexFormatElement) 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetAttribute(attribute, vertexFormatElement);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,VertexFormat,SetStride,int,void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,VertexFormat,GetNumAttributes,int)	
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,VertexFormat,GetStreamIndex,int,unsigned int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,VertexFormat,GetOffset,int,unsigned int)									
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,VertexFormat,GetAttributeType,int,Rendering::VertexFormatFlags::AttributeType)									
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,VertexFormat,GetAttributeUsage,int,Rendering::VertexFormatFlags::AttributeUsage)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,VertexFormat,GetUsageIndex,int,unsigned int)	
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,VertexFormat,GetStride,int)

int Rendering::VertexFormat
    ::GetIndex( AttributeUsage usage, unsigned int usageIndex ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetIndex(usage,usageIndex);
}

int Rendering::VertexFormat
	::GetComponentSize( AttributeType type )
{
	return ImplType::GetComponentSize(type);
}

int Rendering::VertexFormat
	::GetNumComponents( AttributeType type )
{
	return ImplType::GetNumComponents(type);
}

int Rendering::VertexFormat
	::GetTypeSize( AttributeType type )
{
	return ImplType::GetTypeSize(type);
}

Rendering::VertexFormat
	::VertexFormat (LoadConstructor value)
	:ParentType{ value }, m_Impl{ make_shared<ImplType>(1) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::VertexFormat
	::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto size = ParentType::GetStreamingSize();

	size += m_Impl->GetStreamingSize();

	return size;
}

uint64_t Rendering::VertexFormat
	::Register( CoreTools::ObjectRegister& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ParentType::Register(target);
}

void Rendering::VertexFormat
	::Save (CoreTools::BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

	ParentType::Save(target);
	
	m_Impl->Save(target);

	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::VertexFormat
	::Link (CoreTools::ObjectLink& source)
{	
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::Link(source);
}

void Rendering::VertexFormat
	::PostLink ()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::PostLink();
}

void Rendering::VertexFormat
	::Load (CoreTools::BufferSource& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);
	
	m_Impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::VertexFormat
	::SaveToFile( WriteFileManager& outFile ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	m_Impl->SaveToFile(outFile);
}

void Rendering::VertexFormat
	::ReadFromFile( ReadFileManager& inFile )
{
	RENDERING_CLASS_IS_VALID_1;

	m_Impl->ReadFromFile(inFile);
}

Rendering::VertexFormat::VertexFormatSmartPointer Rendering::VertexFormat
	::Clone() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return VertexFormatSmartPointer{ NEW0 ClassType(*this) };
}

Rendering::VertexFormatSmartPointer Rendering::VertexFormat
	::LoadFromFile(ReadFileManager& manager)
{
	auto numAttributes = 0;
	manager.Read(sizeof(int), &numAttributes);

	VertexFormatSmartPointer vertexFormat{ NEW0 VertexFormat(numAttributes) };

	vertexFormat->ReadFromFile(manager);

	return vertexFormat;
}

