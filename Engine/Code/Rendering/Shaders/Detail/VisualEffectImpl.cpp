// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 16:38)

#include "Rendering/RenderingExport.h"

#include "VisualEffectImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h" 
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;
using std::vector; 
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26414)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26418)
#include SYSTEM_WARNING_DISABLE(26440)

Rendering::VisualEffectImpl
	::VisualEffectImpl()
	:m_Techniques{}
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VisualEffectImpl)

int Rendering::VisualEffectImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return CORE_TOOLS_STREAM_SIZE(m_Techniques);
}

void Rendering::VisualEffectImpl
	::Save( const CoreTools::BufferTargetSharedPtr& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
    target;
    //	target.WriteSmartPointer(m_Techniques);
}

void Rendering::VisualEffectImpl
	::Load( BufferSource& source )
{
	RENDERING_CLASS_IS_VALID_9;
    source;
    //	source.ReadSmartPointer(m_Techniques);
}

void Rendering::VisualEffectImpl
	::Link( ObjectLink& source )
{
	RENDERING_CLASS_IS_VALID_9;
    source;
	if (!m_Techniques.empty())
	{
		//source.ResolveObjectSmartPointerLink(boost::numeric_cast<int>(m_Techniques.size()), &m_Techniques[0]);
	} 
}

void Rendering::VisualEffectImpl ::Register(const CoreTools::ObjectRegisterSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
    target;
	if (!m_Techniques.empty())
	{
		//target.RegisterSmartPointer(boost::numeric_cast<int>(m_Techniques.size()), &m_Techniques[0]);
	} 
}

const CoreTools::ObjectSmartPointer Rendering::VisualEffectImpl
	::GetObjectByName( const string& name )
{
	RENDERING_CLASS_IS_VALID_9;

	for(auto& pointer: m_Techniques)
	{
		auto found = pointer->GetObjectByName(name);
		if (found != nullptr)
		{
			return found;
		}
	}

	return CoreTools::ObjectSmartPointer();
}

const vector<CoreTools::ObjectSmartPointer> Rendering::VisualEffectImpl
	::GetAllObjectsByName( const string& name )
{
	RENDERING_CLASS_IS_VALID_9;

	vector<CoreTools::ObjectSmartPointer> objects;

	for(auto& pointer: m_Techniques)
	{		
		auto singleObjects = pointer->GetAllObjectsByName(name);

		objects.insert(objects.end(), singleObjects.begin(), singleObjects.end());
	}

	return objects;
}

const CoreTools::ConstObjectSmartPointer Rendering::VisualEffectImpl
	::GetConstObjectByName( const string& name ) const
{
	RENDERING_CLASS_IS_VALID_9;

	for(const auto& pointer: m_Techniques)
	{
		auto found = pointer->GetConstObjectByName(name);
		if (found != nullptr)
		{
			return found;
		}
	}

	return CoreTools::ConstObjectSmartPointer();
}

const vector<CoreTools::ConstObjectSmartPointer> Rendering::VisualEffectImpl
	::GetAllConstObjectsByName( const string& name ) const
{
	RENDERING_CLASS_IS_VALID_9;

	vector<CoreTools::ConstObjectSmartPointer> objects;

	for(const auto& pointer: m_Techniques)
	{		
		auto singleObjects = pointer->GetAllConstObjectsByName(name);

		objects.insert(objects.end(), singleObjects.begin(), singleObjects.end());
	}

	return objects;
}

void Rendering::VisualEffectImpl
	::InsertTechnique(const VisualTechniqueSmartPointer& technique)
{
	RENDERING_CLASS_IS_VALID_9;

	m_Techniques.push_back(technique);
}

int Rendering::VisualEffectImpl
	::GetNumTechniques() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(m_Techniques.size());
}

const Rendering::ConstVisualTechniqueSmartPointer Rendering::VisualEffectImpl
	::GetTechnique(int techniqueIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "À˜“˝¥ÌŒÛ£°");

	return m_Techniques[techniqueIndex];
}

int Rendering::VisualEffectImpl
	::GetNumPasses(int techniqueIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "À˜“˝¥ÌŒÛ£°");

	return m_Techniques[techniqueIndex]->GetNumPasses();
}

const Rendering::ConstVisualPassSmartPointer Rendering::VisualEffectImpl
	::GetPass(int techniqueIndex, int passIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "À˜“˝¥ÌŒÛ£°");

	return m_Techniques[techniqueIndex]->GetPass(passIndex);
}

const Rendering::ConstVertexShaderSmartPointer Rendering::VisualEffectImpl
	::GetVertexShader(int techniqueIndex, int passIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "À˜“˝¥ÌŒÛ£°");

	return m_Techniques[techniqueIndex]->GetVertexShader(passIndex);
}

const Rendering::ConstPixelShaderSmartPointer Rendering::VisualEffectImpl
	::GetPixelShader(int techniqueIndex, int passIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "À˜“˝¥ÌŒÛ£°");

	return m_Techniques[techniqueIndex]->GetPixelShader(passIndex);
}

const Rendering::ConstAlphaStateSmartPointer Rendering::VisualEffectImpl
	::GetAlphaState(int techniqueIndex, int passIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "À˜“˝¥ÌŒÛ£°");

	return m_Techniques[techniqueIndex]->GetAlphaState(passIndex);
}

const Rendering::ConstCullStateSmartPointer Rendering::VisualEffectImpl
	::GetCullState(int techniqueIndex, int passIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "À˜“˝¥ÌŒÛ£°");

	return m_Techniques[techniqueIndex]->GetCullState(passIndex);
}

const Rendering::ConstDepthStateSmartPointer Rendering::VisualEffectImpl
	::GetDepthState(int techniqueIndex, int passIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "À˜“˝¥ÌŒÛ£°");

	return m_Techniques[techniqueIndex]->GetDepthState(passIndex);
}


const Rendering::ConstOffsetStateSmartPointer Rendering::VisualEffectImpl
	::GetOffsetState(int techniqueIndex, int passIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "À˜“˝¥ÌŒÛ£°");

	return m_Techniques[techniqueIndex]->GetOffsetState(passIndex);
}

const Rendering::ConstStencilStateSmartPointer Rendering::VisualEffectImpl
	::GetStencilState(int techniqueIndex, int passIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "À˜“˝¥ÌŒÛ£°");

	return m_Techniques[techniqueIndex]->GetStencilState(passIndex);
}

const Rendering::ConstWireStateSmartPointer Rendering::VisualEffectImpl
	::GetWireState(int techniqueIndex, int passIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= techniqueIndex && techniqueIndex < GetNumTechniques(), "À˜“˝¥ÌŒÛ£°");

	return m_Techniques[techniqueIndex]->GetWireState(passIndex);
}

void Rendering::VisualEffectImpl
	::SaveVisualTechnique(WriteFileManager& manager) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	
	const auto numTechniques = GetNumTechniques();
	manager.Write(sizeof(int), &numTechniques);

	for (auto i = 0; i < numTechniques; ++i)
	{
		m_Techniques[i]->SaveVisualPass(manager);
	}
}

void Rendering::VisualEffectImpl
	::LoadVisualTechnique( ReadFileManager& manager )
{
	RENDERING_CLASS_IS_VALID_9;

	auto numTechniques = 0;
	manager.Read(sizeof(int), &numTechniques);

	for (auto i = 0; i < numTechniques; ++i)
	{
		VisualTechniqueSmartPointer technique{ std::make_shared< VisualTechnique>() };

		 technique->LoadVisualPass(manager);

		 InsertTechnique(technique);
	}
}
 
#include STSTEM_WARNING_POP