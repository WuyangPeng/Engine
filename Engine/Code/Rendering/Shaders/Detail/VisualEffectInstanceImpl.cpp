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
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
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
	::VisualEffectInstanceImpl(const VisualEffectSmartPointer& effect, int techniqueIndex)
	: m_Effect{ effect }, m_TechniqueIndex{ techniqueIndex }, m_NumPasses{ effect->GetNumPasses(techniqueIndex) },
	  m_VertexParameters{ m_NumPasses },m_PixelParameters{ m_NumPasses }
{
	for (auto passIndex = 0; passIndex < m_NumPasses; ++passIndex)
	{
		auto pass = m_Effect->GetPass(techniqueIndex, passIndex);
            m_VertexParameters[passIndex] = ShaderParametersSmartPointer{ std::make_shared < ShaderParameters>(pass->GetVertexShader()) };
                m_PixelParameters[passIndex] = ShaderParametersSmartPointer{ std::make_shared < ShaderParameters>(pass->GetPixelShader()) };
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
            m_VertexParameters[passIndex] = ShaderParametersSmartPointer{ std::make_shared < ShaderParameters>(*rhs.m_VertexParameters[passIndex]) };
                m_PixelParameters[passIndex] = ShaderParametersSmartPointer{ std::make_shared < ShaderParameters>(*rhs.m_PixelParameters[passIndex]) };
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
	::Save(BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	//target.WriteSmartPointer(m_Effect);
	target.Write(m_TechniqueIndex);
	target.Write(m_NumPasses);
	//target.WriteSmartPointer(m_VertexParameters);
	//target.WriteSmartPointer(m_PixelParameters);
}

void Rendering::VisualEffectInstanceImpl
	::Load(BufferSource& source)
{
	RENDERING_CLASS_IS_VALID_1;

	//source.ReadSmartPointer(m_Effect);
	source.Read(m_TechniqueIndex);
	source.Read(m_NumPasses);
	//source.ReadSmartPointer(m_VertexParameters);
	//source.ReadSmartPointer(m_PixelParameters);
}

void Rendering::VisualEffectInstanceImpl
	::Link(ObjectLink& source)
{
	RENDERING_CLASS_IS_VALID_1;
    source;
	//source.ResolveObjectSmartPointerLink(m_Effect);

	if (!m_VertexParameters.empty())
	{
		//source.ResolveObjectSmartPointerLink(boost::numeric_cast<int>(m_VertexParameters.size()), &m_VertexParameters[0]);
	}		
	
	if (!m_PixelParameters.empty())
	{
		//source.ResolveObjectSmartPointerLink(boost::numeric_cast<int>(m_PixelParameters.size()), &m_PixelParameters[0]);
	}		
}

void Rendering::VisualEffectInstanceImpl
	::Register(ObjectRegister& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    target;
	//target.RegisterSmartPointer(m_Effect);

	if (!m_VertexParameters.empty())
	{
		//target.RegisterSmartPointer(boost::numeric_cast<int>(m_VertexParameters.size()), &m_VertexParameters[0]);
	}		

	if (!m_PixelParameters.empty())
	{
		//target.RegisterSmartPointer(boost::numeric_cast<int>(m_PixelParameters.size()), &m_PixelParameters[0]);
	}		
}


const CoreTools::ObjectSmartPointer Rendering::VisualEffectInstanceImpl
	::GetObjectByName( const string& name )
{
	RENDERING_CLASS_IS_VALID_1;

	CoreTools::ObjectSmartPointer found = m_Effect->GetObjectByName(name);

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

	return CoreTools::ObjectSmartPointer();
}

const vector<CoreTools::ObjectSmartPointer> Rendering::VisualEffectInstanceImpl
	::GetAllObjectsByName( const string& name )
{
	RENDERING_CLASS_IS_VALID_1;

	vector<CoreTools::ObjectSmartPointer> objects = m_Effect->GetAllObjectsByName(name);

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

const CoreTools::ConstObjectSmartPointer Rendering::VisualEffectInstanceImpl
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

 

	return CoreTools::ConstObjectSmartPointer();
}

const vector<CoreTools::ConstObjectSmartPointer> Rendering::VisualEffectInstanceImpl
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

const Rendering::ConstVisualEffectSmartPointer Rendering::VisualEffectInstanceImpl
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

const Rendering::ConstVisualPassSmartPointer Rendering::VisualEffectInstanceImpl
	::GetConstPass(int pass) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	
	return m_Effect->GetPass(m_TechniqueIndex, pass);
}

const Rendering::ConstShaderParametersSmartPointer Rendering::VisualEffectInstanceImpl
	::GetConstVertexParameters(int pass) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_VertexParameters[pass] ;
}

const Rendering::ConstShaderParametersSmartPointer Rendering::VisualEffectInstanceImpl
	::GetConstPixelParameters(int pass) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_PixelParameters[pass] ;
}

int Rendering::VisualEffectInstanceImpl
	::SetVertexConstant(int pass, const std::string& name, const ShaderFloatSmartPointer& shaderFloat)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_VertexParameters[pass]->SetConstant(name, shaderFloat);
}

void Rendering::VisualEffectInstanceImpl
	::SetVertexConstant(int pass, int handle, const ShaderFloatSmartPointer& shaderFloat)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_VertexParameters[pass]->SetConstant(handle, shaderFloat);
}

void Rendering::VisualEffectInstanceImpl
	::SetPixelConstant(int pass, int handle, const ShaderFloatSmartPointer& shaderFloat)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_PixelParameters[pass]->SetConstant(handle, shaderFloat);
}

void Rendering::VisualEffectInstanceImpl
	::SetVertexTexture(int pass, int handle, const TextureSmartPointer& texture)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_VertexParameters[pass]->SetTexture(handle, texture);
}

void Rendering::VisualEffectInstanceImpl
	::SetPixelTexture(int pass, int handle, const TextureSmartPointer& texture)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_PixelParameters[pass]->SetTexture(handle, texture);
}

int Rendering::VisualEffectInstanceImpl
	::SetPixelConstant(int pass, const std::string& name, const ShaderFloatSmartPointer& shaderFloat)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_PixelParameters[pass]->SetConstant(name, shaderFloat);
}

int Rendering::VisualEffectInstanceImpl
	::SetVertexTexture(int pass, const std::string& name, const TextureSmartPointer& texture)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_VertexParameters[pass]->SetTexture(name, texture);
}

int Rendering::VisualEffectInstanceImpl
	::SetPixelTexture(int pass, const std::string& name, const TextureSmartPointer& texture)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_PixelParameters[pass]->SetTexture(name, texture);
}

const Rendering::ConstShaderFloatSmartPointer Rendering::VisualEffectInstanceImpl
	::GetVertexConstant(int pass, const std::string& name) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_VertexParameters[pass]->GetConstant(name);
}

const Rendering::ConstShaderFloatSmartPointer Rendering::VisualEffectInstanceImpl
	::GetPixelConstant(int pass, int handle) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_PixelParameters[pass]->GetConstant(handle);
}

const Rendering::ConstTextureSmartPointer Rendering::VisualEffectInstanceImpl
	::GetVertexTexture(int pass, int handle) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_VertexParameters[pass]->GetTexture(handle);
}

const Rendering::ConstTextureSmartPointer Rendering::VisualEffectInstanceImpl
	::GetPixelTexture(int pass, int handle) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_PixelParameters[pass]->GetTexture(handle);
}

const Rendering::ConstShaderFloatSmartPointer Rendering::VisualEffectInstanceImpl
	::GetPixelConstant(int pass, const std::string& name) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_PixelParameters[pass]->GetConstant(name);
}

const Rendering::ConstTextureSmartPointer Rendering::VisualEffectInstanceImpl
	::GetVertexTexture(int pass, const std::string& name) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_VertexParameters[pass]->GetTexture(name);
}

const Rendering::ConstTextureSmartPointer Rendering::VisualEffectInstanceImpl
	::GetPixelTexture(int pass, const std::string& name) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_PixelParameters[pass]->GetTexture(name);
}

const Rendering::ConstShaderFloatSmartPointer Rendering::VisualEffectInstanceImpl
	::GetVertexConstant(int pass, int handle) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_VertexParameters[pass]->GetConstant(handle);
}

const Rendering::ShaderParametersSmartPointer Rendering::VisualEffectInstanceImpl
	::GetVertexParameters(int pass) 
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_VertexParameters[pass];
}

const Rendering::ShaderParametersSmartPointer Rendering::VisualEffectInstanceImpl
	::GetPixelParameters(int pass) 
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= pass && pass < m_NumPasses, "索引越界！\n");

	return m_PixelParameters[pass];
}
#include STSTEM_WARNING_POP

 