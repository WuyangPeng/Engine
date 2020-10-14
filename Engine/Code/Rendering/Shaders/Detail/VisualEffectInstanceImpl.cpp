// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 16:40)

#include "Rendering/RenderingExport.h"

#include "VisualEffectInstanceImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h" 
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"

#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26487)
#include SYSTEM_WARNING_DISABLE(26489)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26418)
#include SYSTEM_WARNING_DISABLE(26415) 
using std::string;
using std::vector;
using std::swap;

Rendering::VisualEffectInstanceImpl
	::VisualEffectInstanceImpl()
	: m_Effect{},m_TechniqueIndex{ 0 },m_NumPasses{ 0 },m_VertexParameters{},m_PixelParameters{}
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisualEffectInstanceImpl
	::VisualEffectInstanceImpl(const VisualEffectSharedPtr& effect, int techniqueIndex)
	: m_Effect{ effect }, m_TechniqueIndex{ techniqueIndex }, m_NumPasses{ effect->GetNumPasses(techniqueIndex) },
	  m_VertexParameters{ m_NumPasses },m_PixelParameters{ m_NumPasses }
{
	for (auto passIndex = 0; passIndex < m_NumPasses; ++passIndex)
	{
		auto pass = m_Effect->GetPass(techniqueIndex, passIndex);
            m_VertexParameters[passIndex] = ShaderParametersSharedPtr{ std::make_shared < ShaderParameters>(pass->GetVertexShader()) };
                m_PixelParameters[passIndex] = ShaderParametersSharedPtr{ std::make_shared < ShaderParameters>(pass->GetPixelShader()) };
	}

	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::VisualEffectInstanceImpl
	::VisualEffectInstanceImpl(const VisualEffectInstanceImpl& rhs)
	: m_Effect{ rhs.m_Effect },m_TechniqueIndex{ rhs.m_TechniqueIndex },m_NumPasses{ m_Effect->GetNumPasses(m_TechniqueIndex) },
	  m_VertexParameters{ m_NumPasses },m_PixelParameters{ m_NumPasses }
{
	for (auto passIndex = 0; passIndex < m_NumPasses; ++passIndex)
	{
		auto pass = m_Effect->GetPass(m_TechniqueIndex, passIndex);
            m_VertexParameters[passIndex] = ShaderParametersSharedPtr{ std::make_shared < ShaderParameters>(*rhs.m_VertexParameters[passIndex]) };
                m_PixelParameters[passIndex] = ShaderParametersSharedPtr{ std::make_shared < ShaderParameters>(*rhs.m_PixelParameters[passIndex]) };
	}

	RENDERING_SELF_CLASS_IS_VALID_1;
}


Rendering::VisualEffectInstanceImpl& Rendering::VisualEffectInstanceImpl
	::operator=(const VisualEffectInstanceImpl& rhs)
{
	RENDERING_CLASS_IS_VALID_1;

	VisualEffectInstanceImpl result{ rhs };

	Swap(result);

	return *this;
}

// private
void Rendering::VisualEffectInstanceImpl
	::Swap(VisualEffectInstanceImpl& rhs)
{
	swap(m_Effect, rhs.m_Effect);
	swap(m_TechniqueIndex, rhs.m_TechniqueIndex);
	swap(m_NumPasses, rhs.m_NumPasses);
	m_VertexParameters.swap(rhs.m_VertexParameters);
	m_PixelParameters.swap(rhs.m_PixelParameters);
}


#ifdef OPEN_CLASS_INVARIANT
bool Rendering::VisualEffectInstanceImpl
	::IsValid() const noexcept
{
	if (m_NumPasses == static_cast<int>(m_VertexParameters.size()) &&
		m_NumPasses == static_cast<int>(m_PixelParameters.size()))
	{
		return true;
	}	
	else
	{
		return false;
	}		
}
#endif // OPEN_CLASS_INVARIANT

int Rendering::VisualEffectInstanceImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto size = CORE_TOOLS_STREAM_SIZE(m_Effect);

	size += CORE_TOOLS_STREAM_SIZE(m_TechniqueIndex);
	size += CORE_TOOLS_STREAM_SIZE(m_NumPasses);
	size += CORE_TOOLS_STREAM_SIZE(m_VertexParameters);
	size += CORE_TOOLS_STREAM_SIZE(m_PixelParameters);

	return size;
}

void Rendering::VisualEffectInstanceImpl
	::Save(const CoreTools::BufferTargetSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	//target.WriteSharedPtr(m_Effect);
	target->Write(m_TechniqueIndex);
	target->Write(m_NumPasses);
	//target.WriteSharedPtr(m_VertexParameters);
	//target.WriteSharedPtr(m_PixelParameters);
}

void Rendering::VisualEffectInstanceImpl
	::Load(const CoreTools::BufferSourceSharedPtr& source)
{
	RENDERING_CLASS_IS_VALID_1;

	//source.ReadSharedPtr(m_Effect);
	source->Read(m_TechniqueIndex);
	source->Read(m_NumPasses);
	//source.ReadSharedPtr(m_VertexParameters);
	//source.ReadSharedPtr(m_PixelParameters);
}

void Rendering::VisualEffectInstanceImpl ::Link(const CoreTools::ObjectLinkSharedPtr& source)
{
	RENDERING_CLASS_IS_VALID_1;
    source;
	//source.ResolveObjectSharedPtrLink(m_Effect);

	if (!m_VertexParameters.empty())
	{
		//source.ResolveObjectSharedPtrLink(boost::numeric_cast<int>(m_VertexParameters.size()), &m_VertexParameters[0]);
	}		
	
	if (!m_PixelParameters.empty())
	{
		//source.ResolveObjectSharedPtrLink(boost::numeric_cast<int>(m_PixelParameters.size()), &m_PixelParameters[0]);
	}		
}

void Rendering::VisualEffectInstanceImpl ::Register(const CoreTools::ObjectRegisterSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    target;
	//target.RegisterSharedPtr(m_Effect);

	if (!m_VertexParameters.empty())
	{
		//target.RegisterSharedPtr(boost::numeric_cast<int>(m_VertexParameters.size()), &m_VertexParameters[0]);
	}		

	if (!m_PixelParameters.empty())
	{
		//target.RegisterSharedPtr(boost::numeric_cast<int>(m_PixelParameters.size()), &m_PixelParameters[0]);
	}		
}


const CoreTools::ObjectSharedPtr Rendering::VisualEffectInstanceImpl
	::GetObjectByName( const string& name )
{
	RENDERING_CLASS_IS_VALID_1;

	CoreTools::ObjectSharedPtr found = m_Effect->GetObjectByName(name);

	for(auto& pointer: m_VertexParameters)
	{
		auto found2 = pointer->GetObjectByName(name);
		if (found2 != nullptr)
		{
			return found2;
		}
	}

	for (auto& pointer: m_PixelParameters)
	{
		auto found2 = pointer->GetObjectByName(name);
		if (found2 != nullptr)
		{
			return found2;
		}
	}

	return CoreTools::ObjectSharedPtr();
}

const vector<CoreTools::ObjectSharedPtr> Rendering::VisualEffectInstanceImpl
	::GetAllObjectsByName( const string& name )
{
	RENDERING_CLASS_IS_VALID_1;

	vector<CoreTools::ObjectSharedPtr> objects = m_Effect->GetAllObjectsByName(name);

	for(auto& pointer: m_VertexParameters)
	{		
		auto singleObjects = pointer->GetAllObjectsByName(name);

		objects.insert(objects.end(), singleObjects.begin(), singleObjects.end());
	}

	for (auto& pointer: m_PixelParameters)
	{
		auto singleObjects = pointer->GetAllObjectsByName(name);

		objects.insert(objects.end(), singleObjects.begin(), singleObjects.end());
	}

	return objects;
}

const CoreTools::ConstObjectSharedPtr Rendering::VisualEffectInstanceImpl
	::GetConstObjectByName( const string& name ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto found = m_Effect->GetConstObjectByName(name);

	for (const auto& pointer: m_VertexParameters)
	{
		auto found2 = pointer->GetConstObjectByName(name);
		if (found2 != nullptr)
		{
			return found2;
		}
	}

	for (const auto& pointer: m_PixelParameters)
	{
		auto found2 = pointer->GetConstObjectByName(name);
		if (found2 != nullptr)
		{
			return found2;
		}
	}

 

	return CoreTools::ConstObjectSharedPtr();
}

const vector<CoreTools::ConstObjectSharedPtr> Rendering::VisualEffectInstanceImpl
	::GetAllConstObjectsByName( const string& name ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto objects = m_Effect->GetAllConstObjectsByName(name);

	for (const auto& pointer: m_VertexParameters)
	{
		auto singleObjects = pointer->GetAllConstObjectsByName(name);

		objects.insert(objects.end(), singleObjects.begin(), singleObjects.end());
	}

	for (const auto& pointer: m_PixelParameters)
	{
		auto singleObjects = pointer->GetAllConstObjectsByName(name);

		objects.insert(objects.end(), singleObjects.begin(), singleObjects.end());
	}

	return objects;
}

const Rendering::ConstVisualEffectSharedPtr Rendering::VisualEffectInstanceImpl
	::GetEffect() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Effect ;
}

int Rendering::VisualEffectInstanceImpl
	::GetTechniqueIndex() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_TechniqueIndex;
}

int Rendering::VisualEffectInstanceImpl
	::GetNumPasses() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_NumPasses;
}

const Rendering::ConstVisualPassSharedPtr Rendering::VisualEffectInstanceImpl
	::GetConstPass(int pass) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	
	return m_Effect->GetPass(m_TechniqueIndex, pass);
}

const Rendering::ConstShaderParametersSharedPtr Rendering::VisualEffectInstanceImpl
	::GetConstVertexParameters(int pass) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_VertexParameters[pass] ;
}

const Rendering::ConstShaderParametersSharedPtr Rendering::VisualEffectInstanceImpl
	::GetConstPixelParameters(int pass) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_PixelParameters[pass] ;
}

int Rendering::VisualEffectInstanceImpl
	::SetVertexConstant(int pass, const std::string& name, const ShaderFloatSharedPtr& shaderFloat)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_VertexParameters[pass]->SetConstant(name, shaderFloat);
}

void Rendering::VisualEffectInstanceImpl
	::SetVertexConstant(int pass, int handle, const ShaderFloatSharedPtr& shaderFloat)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_VertexParameters[pass]->SetConstant(handle, shaderFloat);
}

void Rendering::VisualEffectInstanceImpl
	::SetPixelConstant(int pass, int handle, const ShaderFloatSharedPtr& shaderFloat)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_PixelParameters[pass]->SetConstant(handle, shaderFloat);
}

void Rendering::VisualEffectInstanceImpl
	::SetVertexTexture(int pass, int handle, const TextureSharedPtr& texture)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_VertexParameters[pass]->SetTexture(handle, texture);
}

void Rendering::VisualEffectInstanceImpl
	::SetPixelTexture(int pass, int handle, const TextureSharedPtr& texture)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_PixelParameters[pass]->SetTexture(handle, texture);
}

int Rendering::VisualEffectInstanceImpl
	::SetPixelConstant(int pass, const std::string& name, const ShaderFloatSharedPtr& shaderFloat)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_PixelParameters[pass]->SetConstant(name, shaderFloat);
}

int Rendering::VisualEffectInstanceImpl
	::SetVertexTexture(int pass, const std::string& name, const TextureSharedPtr& texture)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_VertexParameters[pass]->SetTexture(name, texture);
}

int Rendering::VisualEffectInstanceImpl
	::SetPixelTexture(int pass, const std::string& name, const TextureSharedPtr& texture)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_PixelParameters[pass]->SetTexture(name, texture);
}

const Rendering::ConstShaderFloatSharedPtr Rendering::VisualEffectInstanceImpl
	::GetVertexConstant(int pass, const std::string& name) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_VertexParameters[pass]->GetConstant(name);
}

const Rendering::ConstShaderFloatSharedPtr Rendering::VisualEffectInstanceImpl
	::GetPixelConstant(int pass, int handle) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_PixelParameters[pass]->GetConstant(handle);
}

const Rendering::ConstTextureSharedPtr Rendering::VisualEffectInstanceImpl
	::GetVertexTexture(int pass, int handle) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_VertexParameters[pass]->GetTexture(handle);
}

const Rendering::ConstTextureSharedPtr Rendering::VisualEffectInstanceImpl
	::GetPixelTexture(int pass, int handle) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_PixelParameters[pass]->GetTexture(handle);
}

const Rendering::ConstShaderFloatSharedPtr Rendering::VisualEffectInstanceImpl
	::GetPixelConstant(int pass, const std::string& name) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_PixelParameters[pass]->GetConstant(name);
}

const Rendering::ConstTextureSharedPtr Rendering::VisualEffectInstanceImpl
	::GetVertexTexture(int pass, const std::string& name) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_VertexParameters[pass]->GetTexture(name);
}

const Rendering::ConstTextureSharedPtr Rendering::VisualEffectInstanceImpl
	::GetPixelTexture(int pass, const std::string& name) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_PixelParameters[pass]->GetTexture(name);
}

const Rendering::ConstShaderFloatSharedPtr Rendering::VisualEffectInstanceImpl
	::GetVertexConstant(int pass, int handle) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_VertexParameters[pass]->GetConstant(handle);
}

const Rendering::ShaderParametersSharedPtr Rendering::VisualEffectInstanceImpl
	::GetVertexParameters(int pass) 
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_VertexParameters[pass];
}

const Rendering::ShaderParametersSharedPtr Rendering::VisualEffectInstanceImpl
	::GetPixelParameters(int pass) 
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_PixelParameters[pass];
}
#include STSTEM_WARNING_POP

 