// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 16:16)

#include "Rendering/RenderingExport.h"

#include "ShaderParametersImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h" 

using std::string;
using std::vector;
using std::swap;
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26415)
 #include SYSTEM_WARNING_DISABLE(26418)
 #include SYSTEM_WARNING_DISABLE(26418)
 #include SYSTEM_WARNING_DISABLE(26487)
 #include SYSTEM_WARNING_DISABLE(26489)
 #include SYSTEM_WARNING_DISABLE(26440)
Rendering::ShaderParametersImpl
	::ShaderParametersImpl(const ConstShaderBaseSmartPointer& shader)
	:m_Shader{ shader }, m_Constants{}, m_Textures{}
{
    const auto numConstants = m_Shader->GetNumConstants();
	if (0 < numConstants)
	{
		m_Constants.resize(numConstants);
	}

const auto numSamplers = m_Shader->GetNumSamplers();
	if (0 < numSamplers)
	{
		m_Textures.resize(numSamplers);
	}

	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ShaderParametersImpl ::ShaderParametersImpl() noexcept
    : m_Shader{}, m_Constants{}, m_Textures{}
{
	RENDERING_SELF_CLASS_IS_VALID_9;	
}

Rendering::ShaderParametersImpl
	::ShaderParametersImpl(const ShaderParametersImpl& rhs)
	:m_Shader{ rhs.m_Shader }, m_Constants{}, m_Textures{}
{
	for(const auto& pointer: rhs.m_Constants)
	{
		m_Constants.push_back(pointer->Clone());
	}

	for (const auto& pointer: rhs.m_Textures)
	{
		m_Textures.push_back(pointer->Clone());
	}

	RENDERING_SELF_CLASS_IS_VALID_9;
}


Rendering::ShaderParametersImpl& Rendering::ShaderParametersImpl
	::operator=(const ShaderParametersImpl& rhs)
{
	ShaderParametersImpl result{ rhs };

	Swap(result);

	return *this;
}


void Rendering::ShaderParametersImpl
	::Swap(ShaderParametersImpl& rhs)
{
	swap(m_Shader, rhs.m_Shader);
	m_Constants.swap(rhs.m_Constants);
	m_Textures.swap(rhs.m_Textures);
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,ShaderParametersImpl)

void Rendering::ShaderParametersImpl
	::Load( BufferSource& source )
{
	RENDERING_CLASS_IS_VALID_9;
    source;
	//source.ReadSmartPointer(m_Shader);
	//source.ReadSmartPointer(m_Constants);
	//source.ReadSmartPointer(m_Textures);
}

void Rendering::ShaderParametersImpl
	::Save( BufferTarget& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
    target;
	//target.WriteSmartPointer(m_Shader);
	//target.WriteSmartPointer(m_Constants);
	//target.WriteSmartPointer(m_Textures);
}

int Rendering::ShaderParametersImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto size = CORE_TOOLS_STREAM_SIZE(m_Shader);

	size += CORE_TOOLS_STREAM_SIZE(m_Constants);
	size += CORE_TOOLS_STREAM_SIZE(m_Textures);

	return size;
}

void Rendering::ShaderParametersImpl
	::Link(ObjectLink& source)
{
	RENDERING_CLASS_IS_VALID_9;
    source;
	//source.ResolveObjectConstSmartPointerLink(m_Shader);

	if (0 < m_Constants.size())
	{
		//source.ResolveObjectSmartPointerLink(boost::numeric_cast<int>(m_Constants.size()),&m_Constants[0]);
	}

	if (0 < m_Textures.size())
	{
		//source.ResolveObjectSmartPointerLink(boost::numeric_cast<int>(m_Textures.size()), &m_Textures[0]);
	}
}

void Rendering::ShaderParametersImpl
	::Register(ObjectRegister& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
    target;
	//target.RegisterSmartPointer(m_Shader);

	if (0 < m_Constants.size())
	{
		//target.RegisterSmartPointer(boost::numeric_cast<int>(m_Constants.size()), &m_Constants[0]);
	}

	if (0 < m_Textures.size())
	{
		//target.RegisterSmartPointer(boost::numeric_cast<int>(m_Textures.size()), &m_Textures[0]);
	}
}

const CoreTools::ObjectSmartPointer Rendering::ShaderParametersImpl
	::GetObjectByName(const string& name)
{
	RENDERING_CLASS_IS_VALID_9;

	for(auto& pointer: m_Constants)
	{
		auto object = pointer->GetObjectByName(name);
		if (object != nullptr)
		{
			return object;
		}			
	}
	
	for (auto& pointer: m_Textures)
	{
		auto object = pointer->GetObjectByName(name);
		if (object != nullptr)
		{
			return object;
		}
	}
	
	return CoreTools::ObjectSmartPointer();
}

const vector<CoreTools::ObjectSmartPointer> Rendering::ShaderParametersImpl
	::GetAllObjectsByName(const string& name)
{
	RENDERING_CLASS_IS_VALID_9;

	vector<CoreTools::ObjectSmartPointer> objects;

	for (auto& pointer: m_Constants)
	{
		auto pointerObjects = pointer->GetAllObjectsByName(name);
		objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
	}

	for (auto& pointer: m_Textures)
	{
		auto pointerObjects = pointer->GetAllObjectsByName(name);
		objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
	}

	return objects;
}

const CoreTools::ConstObjectSmartPointer Rendering::ShaderParametersImpl
	::GetConstObjectByName(const string& name) const
{
	RENDERING_CLASS_IS_VALID_9;

	auto object = m_Shader->GetConstObjectByName(name);

	if (object != nullptr)
	{
		return object;
	}
	else
	{
		for (const auto& pointer: m_Constants)
		{
			object = pointer->GetConstObjectByName(name);
			if (object != nullptr)
			{
				return object;
			}			
		}

		for (const auto& pointer: m_Textures)
		{
			object = pointer->GetConstObjectByName(name);
			if (object != nullptr)
			{
				return object;
			}
		}
	}

	return CoreTools::ConstObjectSmartPointer{};
}

const vector<CoreTools::ConstObjectSmartPointer> Rendering::ShaderParametersImpl
	::GetAllConstObjectsByName(const string& name) const
{
	RENDERING_CLASS_IS_VALID_9;

	auto objects = m_Shader->GetAllConstObjectsByName(name);

	for (const auto& pointer: m_Constants)
	{
		auto pointerObjects = pointer->GetAllConstObjectsByName(name);
		objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
	}

	for (const auto& pointer: m_Textures)
	{
		auto pointerObjects = pointer->GetAllConstObjectsByName(name);
		objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
	}

	return objects;
}

int Rendering::ShaderParametersImpl
	::GetNumConstants() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(m_Constants.size());
}

int Rendering::ShaderParametersImpl
	::GetNumTextures() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(m_Textures.size());
}

const Rendering::ShaderParametersImpl::ConstShaderFloatSmartPointerGather Rendering::ShaderParametersImpl
	::GetConstants() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	ConstShaderFloatSmartPointerGather gather;

	for (const auto& pointer: m_Constants)
	{
		gather.push_back(pointer );
	}

	return gather;
}

const Rendering::ShaderParametersImpl::ConstTextureSmartPointerGather Rendering::ShaderParametersImpl
	::GetTextures() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	ConstTextureSmartPointerGather gather;

	for (const auto& pointer: m_Textures)
	{
		gather.push_back(pointer );
	}

	return gather;
}

int Rendering::ShaderParametersImpl
	::SetConstant(const string& name, const ShaderFloatSmartPointer& shaderFloat)
{
	RENDERING_CLASS_IS_VALID_9;

const auto numConstants = GetNumConstants();

	for (auto index = 0; index < numConstants; ++index)
	{
		if (m_Shader->GetConstantName(index) == name)
		{
			m_Constants[index] = shaderFloat;
			return index;
		}
	}

	THROW_EXCEPTION(SYSTEM_TEXT("找不到常量！\n"s));
}

void Rendering::ShaderParametersImpl
	::SetConstant(int handle, const ShaderFloatSmartPointer& shaderFloat)
{
	RENDERING_CLASS_IS_VALID_9;
	RENDERING_ASSERTION_0(0 <= handle && handle < GetNumConstants(), "索引越界！\n");

	m_Constants[handle] = shaderFloat;
}

int Rendering::ShaderParametersImpl
	::SetTexture(const string& name, const TextureSmartPointer& texture)
{
	RENDERING_CLASS_IS_VALID_9;

const auto numTextures = GetNumTextures();

	for (auto index = 0; index < numTextures; ++index)
    {
        if (m_Shader->GetSamplerName(index) == name)
        {
            m_Textures[index] = texture;
            return index;
        }
    }

	THROW_EXCEPTION(SYSTEM_TEXT("找不到纹理！\n"s));
}

void Rendering::ShaderParametersImpl
	::SetTexture(int handle, const TextureSmartPointer& texture)
{
	RENDERING_CLASS_IS_VALID_9;
	RENDERING_ASSERTION_0(0 <= handle && handle < GetNumTextures(), "索引越界！\n");

	m_Textures[handle] = texture;
}

const Rendering::ConstShaderFloatSmartPointer Rendering::ShaderParametersImpl
	::GetConstant(const string& name) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

const auto numConstants = GetNumConstants();

	for (auto index = 0; index < numConstants; ++index)
	{
		if (m_Shader->GetConstantName(index) == name)
		{
			return GetConstant(index);
		}
	}

	THROW_EXCEPTION(SYSTEM_TEXT("找不到常量！\n"s));
}

const Rendering::ConstShaderFloatSmartPointer Rendering::ShaderParametersImpl
	::GetConstant(int handle) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= handle && handle < GetNumConstants(), "索引越界！\n");

	return m_Constants[handle] ;
}

const Rendering::ConstTextureSmartPointer Rendering::ShaderParametersImpl
	::GetTexture(const std::string& name) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	const auto numTextures = GetNumTextures();

	for (auto index = 0; index < numTextures; ++index)
	{
		if (m_Shader->GetSamplerName(index) == name)
		{
			return GetTexture(index);
		}
	}

	THROW_EXCEPTION(SYSTEM_TEXT("找不到纹理！\n"s));
}

const Rendering::ConstTextureSmartPointer Rendering::ShaderParametersImpl
	::GetTexture(int handle) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= handle && handle < GetNumTextures(), "索引越界！\n");

	return m_Textures[handle] ;
}

void Rendering::ShaderParametersImpl
	::UpdateConstants(const VisualSmartPointer& visual, const CameraSmartPointer& camera)
{
	RENDERING_CLASS_IS_VALID_9;

	for (auto& constant: m_Constants)
	{
		if (constant->AllowUpdater())
		{
			constant->Update(visual.get(), camera.get());
		}
	}	 
}
#include STSTEM_WARNING_POP