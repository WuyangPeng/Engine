// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 16:57)

#include "Rendering/RenderingExport.h"

#include "ShaderBase.h"
#include "Detail/ShaderBaseImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/FileManager/WriteFileManager.h"

#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;
using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26456)
CORE_TOOLS_RTTI_DEFINE(Rendering,ShaderBase);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering,ShaderBase);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering,ShaderBase); 
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
COPY_CONSTRUCTION_DO_NOT_USE_SWAP_DEFINE_WITH_PARENT(Rendering, ShaderBase);

Rendering::ShaderBase::ShaderBase(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ make_shared<ImplType>() }
{
    SELF_CLASS_IS_VALID_0;
}
CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, ShaderBase)
CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, ShaderBase)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, ShaderBase)
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, ShaderBase)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, ShaderBase)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, ShaderBase)

Rendering::ShaderBase
::ShaderBase (const string& programName, int numInputs,
              int numOutputs,int numConstants,
              int numSamplers)
	:ParentType{ programName },impl{ make_shared<ImplType>(numInputs,numOutputs,numConstants,numSamplers) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ShaderBase
::~ShaderBase ()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}
 
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ShaderBase)

void Rendering::ShaderBase
::SetInput (int index, const string& name,ShaderFlags::VariableType type,ShaderFlags::VariableSemantic semantic)
{
	;
  
    return impl->SetInput(index,name,type,semantic);
}

void Rendering::ShaderBase
::SetOutput (int index, const string& name,ShaderFlags::VariableType type,ShaderFlags::VariableSemantic semantic)
{
	;
  
    return impl->SetOutput(index,name,type,semantic);
}

void Rendering::ShaderBase
::SetConstant (int index, const string& name,int numRegistersUsed)
{
	;

    return impl->SetConstant(index,name,numRegistersUsed);
}

void Rendering::ShaderBase
::SetSampler (int index, const string& name,ShaderFlags::SamplerType type)
{
	;
    
    return impl->SetSampler(index,name,type);
}

void Rendering::ShaderBase
::SetFilter (int index, ShaderFlags::SamplerFilter filter)
{
	;
	    
    return impl->SetFilter(index,filter);
}

void Rendering::ShaderBase
::SetCoordinate (int index, int dimension,ShaderFlags::SamplerCoordinate coordinate)
{
	;
    
	return impl->SetCoordinate(index, dimension, coordinate);
}

void Rendering::ShaderBase
::SetLodBias (int index, float lodBias)
{
	;
    
    return impl->SetLodBias(index,lodBias);
}

void Rendering::ShaderBase
::SetAnisotropy (int index, float anisotropy)
{
	;
       
    return impl->SetAnisotropy(index,anisotropy);
}

void Rendering::ShaderBase
::SetBorderColor (int index, const Colour& borderColor)
{
	;
    
    return impl->SetBorderColor(index,borderColor);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,ShaderBase,GetNumInputs,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,ShaderBase,GetInputName,int,const string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,ShaderBase,GetInputType,int,Rendering::ShaderFlags::VariableType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,ShaderBase, GetInputSemantic,int,Rendering::ShaderFlags::VariableSemantic)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,ShaderBase, GetNumOutputs,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,ShaderBase,GetOutputName,int,const string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,ShaderBase,GetOutputType,int,Rendering::ShaderFlags::VariableType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,ShaderBase,GetOutputSemantic,int,Rendering::ShaderFlags::VariableSemantic)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,ShaderBase,GetNumConstants,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,ShaderBase,GetConstantName,int,const string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,ShaderBase,GetNumRegistersUsed,int,int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,ShaderBase,GetNumSamplers,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,ShaderBase,GetSamplerName,int,const string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,ShaderBase,GetSamplerType,int,Rendering::ShaderFlags::SamplerType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,ShaderBase,GetFilter,int,Rendering::ShaderFlags::SamplerFilter)

Rendering::ShaderFlags::SamplerCoordinate Rendering::ShaderBase
::GetCoordinate (int index, int dim) const
{    
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return impl->GetCoordinate(index,dim);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,ShaderBase,GetLodBias,int,float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,ShaderBase,GetAnisotropy,int,float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,ShaderBase,GetBorderColor,int,Rendering::ShaderBase::Colour)

void Rendering::ShaderBase
	::SaveShader(WriteFileManager& manager) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

	auto programName = GetName();
	manager.SaveStdString(programName);

	return impl->SaveShader(manager);
}

void Rendering::ShaderBase
	::LoadShader(ReadFileManager& manager, int numProfiles)
{
    RENDERING_CLASS_IS_VALID_1;

	return impl->LoadShader(manager, numProfiles);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ShaderBase,GetProfile,const Rendering::ConstShaderProfileDataSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ShaderBase, GetProfile, Rendering::ShaderProfileDataSharedPtr)
									  
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, ShaderBase, SetProfile, ShaderProfileDataSharedPtr, void)							
									
 
#include STSTEM_WARNING_POP