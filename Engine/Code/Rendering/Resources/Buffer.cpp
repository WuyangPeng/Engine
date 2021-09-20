// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 15:20)

#include "Rendering/RenderingExport.h"

#include "Detail/BufferImpl.h"
#include "Buffer.h"
#include "CoreTools/DataTypes/TupleDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26456)
CORE_TOOLS_RTTI_DEFINE(Rendering,Buffer);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering,Buffer);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering,Buffer); 
#define COPY_CONSTRUCTION_DO_NOT_USE_SWAP_DEFINE_WITH_PARENT(namespaceName, className)      \
    namespaceName::className::className(const className& rhs)                               \
        : ParentType{ rhs }, impl{ std::make_shared<ImplType>(*rhs.impl) }                  \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        SELF_CLASS_IS_VALID_0;                                                              \
    }                                                                                       \
    namespaceName::className& namespaceName::className::operator=(const className& rhs)     \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        ParentType::operator=(rhs);                                                         \
        impl = std::make_shared<ImplType>(*rhs.impl);                                       \
        return *this;                                                                       \
    }                                                                                       \
    void namespaceName::className::Swap(className& rhs) noexcept                            \
    {                                                                                       \
        ;                                       \
        std::swap(impl, rhs.impl);                                                          \
    }                                                                                       \
    namespaceName::className::className(className&& rhs) noexcept                           \
        : ParentType{ std::move(rhs) }, impl{ std::move(rhs.impl) }                         \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
    }                                                                                       \
    namespaceName::className& namespaceName::className::operator=(className&& rhs) noexcept \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        ParentType::operator=(std::move(rhs));                                              \
        impl = std::move(rhs.impl);                                                         \
        return *this;                                                                       \
    }
COPY_CONSTRUCTION_DO_NOT_USE_SWAP_DEFINE_WITH_PARENT(Rendering, Buffer);

Rendering::Buffer
    ::Buffer()
	:ParentType{ "Buffer" }, impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Buffer
	::Buffer(int numElements, int elementSize, BufferUsage usage)
	:ParentType{ "Buffer" }, impl{ make_shared<ImplType>(numElements, elementSize, usage) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Buffer
	::~Buffer()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering,Buffer)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering,Buffer,GetNumElements,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Buffer, GetElementSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Buffer, GetUsage, Rendering::BufferUsage)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,Buffer,SetNumElements,int,void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Buffer,GetNumBytes,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Buffer, GetReadOnlyData, const char*)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Buffer,GetReadOnlyData, int,const char*)

Rendering::Buffer
    ::Buffer (LoadConstructor value)
	:ParentType{ value }, impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Buffer
	::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto size = ParentType::GetStreamingSize();

	size += impl->GetStreamingSize();

	return size;
}

uint64_t Rendering::Buffer
	::Register( const CoreTools::ObjectRegisterSharedPtr& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ParentType::Register(target);
}

void Rendering::Buffer
	::Save (const CoreTools::BufferTargetSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

	ParentType::Save(target);
	
	impl->Save(target);

	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Buffer
	::Link (const CoreTools::ObjectLinkSharedPtr& source)
{	
	;

	ParentType::Link(source);
}

void Rendering::Buffer
	::PostLink ()
{
	;

	ParentType::PostLink();
}

void Rendering::Buffer
	::Load (const CoreTools::BufferSourceSharedPtr& source)
{
	;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);
	
	impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,Buffer,SaveBufferDataToFile,WriteFileManager&,void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,Buffer,ReadBufferDataFromFile,ReadFileManager&,void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,Buffer,SaveHeadToFile,WriteFileManager&,void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Buffer,ReadHeadFromFile, ReadFileManager&, void)
										  
void Rendering::Buffer
	::ReadBufferDataFromFile(ReadFileManager& inFile, const ConstVertexFormatSharedPtr& vertexformat)
{
	;

	return impl->ReadBufferDataFromFile(inFile, vertexformat);
}


void Rendering::Buffer
	::SaveBufferDataToFile(WriteFileManager& outFile,const ConstVertexFormatSharedPtr& vertexformat) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return impl->SaveBufferDataToFile(outFile, vertexformat);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Buffer,GetAccessWriteData, int, char*)

										  
void Rendering::Buffer
	::SetNewData(const std::vector<char>& newData)
{
	;

	return impl->SetNewData(newData);
}


										  

 


#include STSTEM_WARNING_POP