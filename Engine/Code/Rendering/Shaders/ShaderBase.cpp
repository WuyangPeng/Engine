// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 16:57)

#include "Rendering/RenderingExport.h"

#include "ShaderBase.h"
#include "Detail/ShaderBaseImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
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

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering,ShaderBase);

CORE_TOOLS_IMPL_OBJECT_PTR_DEFAULT_STREAM(Rendering, ShaderBase);

Rendering::ShaderBase
    ::ShaderBase (const string& programName, int numInputs,
              int numOutputs,int numConstants,
              int numSamplers)
	:ParentType{ programName },m_Impl{ make_shared<ImplType>(numInputs,numOutputs,numConstants,numSamplers) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ShaderBase
    ::~ShaderBase ()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, ShaderBase)

void Rendering::ShaderBase
    ::SetInput (int index, const string& name,ShaderFlags::VariableType type,ShaderFlags::VariableSemantic semantic)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
  
    return m_Impl->SetInput(index,name,type,semantic);
}

void Rendering::ShaderBase
   ::SetOutput (int index, const string& name,ShaderFlags::VariableType type,ShaderFlags::VariableSemantic semantic)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
  
    return m_Impl->SetOutput(index,name,type,semantic);
}

void Rendering::ShaderBase
    ::SetConstant (int index, const string& name,int numRegistersUsed)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->SetConstant(index,name,numRegistersUsed);
}

void Rendering::ShaderBase
    ::SetSampler (int index, const string& name,ShaderFlags::SamplerType type)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    return m_Impl->SetSampler(index,name,type);
}

void Rendering::ShaderBase
    ::SetFilter (int index, ShaderFlags::SamplerFilter filter)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	    
    return m_Impl->SetFilter(index,filter);
}

void Rendering::ShaderBase
    ::SetCoordinate (int index, int dimension,ShaderFlags::SamplerCoordinate coordinate)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	return m_Impl->SetCoordinate(index, dimension, coordinate);
}

void Rendering::ShaderBase
    ::SetLodBias (int index, float lodBias)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    return m_Impl->SetLodBias(index,lodBias);
}

void Rendering::ShaderBase
    ::SetAnisotropy (int index, float anisotropy)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
       
    return m_Impl->SetAnisotropy(index,anisotropy);
}

void Rendering::ShaderBase
    ::SetBorderColor (int index, const Colour& borderColor)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    return m_Impl->SetBorderColor(index,borderColor);
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
    
    return m_Impl->GetCoordinate(index,dim);
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

	return m_Impl->SaveShader(manager);
}

void Rendering::ShaderBase
	::LoadShader(ReadFileManager& manager, int numProfiles)
{
    RENDERING_CLASS_IS_VALID_1;

	return m_Impl->LoadShader(manager, numProfiles);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ShaderBase,GetProfile,const Rendering::ConstShaderProfileDataSmartPointer)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ShaderBase, GetProfile, Rendering::ShaderProfileDataSmartPointer)
									  
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, ShaderBase, SetProfile, ShaderProfileDataSmartPointer, void)							
									
 
#include STSTEM_WARNING_POP