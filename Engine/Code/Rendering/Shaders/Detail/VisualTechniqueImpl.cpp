// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 16:49)

#include "Rendering/RenderingExport.h"

#include "VisualTechniqueImpl.h"

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

Rendering::VisualTechniqueImpl
	::VisualTechniqueImpl()
	:m_Passes{}
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VisualTechniqueImpl)

int Rendering::VisualTechniqueImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return CORE_TOOLS_STREAM_SIZE(m_Passes);
}

void Rendering::VisualTechniqueImpl
	::Save( BufferTarget& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	target.WriteSmartPointer(m_Passes);
}

void Rendering::VisualTechniqueImpl
	::Load( BufferSource& source )
{
	RENDERING_CLASS_IS_VALID_9;

	source.ReadSmartPointer(m_Passes);
}

void Rendering::VisualTechniqueImpl
	::Link( ObjectLink& source )
{
	RENDERING_CLASS_IS_VALID_9;

	if (!m_Passes.empty())
	{
		source.ResolveObjectSmartPointerLink(boost::numeric_cast<int>(m_Passes.size()), &m_Passes[0]);
	} 
}

void Rendering::VisualTechniqueImpl
	::Register( ObjectRegister& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	if (!m_Passes.empty())
	{
		target.RegisterSmartPointer(boost::numeric_cast<int>(m_Passes.size()), &m_Passes[0]);
	} 
}

void Rendering::VisualTechniqueImpl
	::InsertPass( const VisualPassSmartPointer& pass )
{
	RENDERING_CLASS_IS_VALID_9;
	RENDERING_ASSERTION_2(pass.IsValidPtr(),"�����pass��������Ч�ġ�");
	
	m_Passes.push_back(pass);		
}

int Rendering::VisualTechniqueImpl
	::GetNumPasses() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(m_Passes.size());
}

const Rendering::ConstVisualPassSmartPointer Rendering::VisualTechniqueImpl
	::GetPass( int passIndex ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= passIndex && passIndex < GetNumPasses(),"��������");

	return m_Passes[passIndex].PolymorphicCastConstObjectSmartPointer<ConstVisualPassSmartPointer>();
}

const Rendering::ConstVertexShaderSmartPointer Rendering::VisualTechniqueImpl
	::GetVertexShader( int passIndex ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= passIndex && passIndex < GetNumPasses(),"��������");

	return m_Passes[passIndex]->GetVertexShader();
}

const Rendering::ConstPixelShaderSmartPointer Rendering::VisualTechniqueImpl
	::GetPixelShader( int passIndex ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= passIndex && passIndex < GetNumPasses(),"��������");

	return m_Passes[passIndex]->GetPixelShader();
}

const Rendering::ConstAlphaStateSmartPointer Rendering::VisualTechniqueImpl
	::GetAlphaState( int passIndex ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= passIndex && passIndex < GetNumPasses(),"��������");

	return m_Passes[passIndex]->GetAlphaState();
}

const Rendering::ConstCullStateSmartPointer Rendering::VisualTechniqueImpl
	::GetCullState( int passIndex ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= passIndex && passIndex < GetNumPasses(),"��������");

	return m_Passes[passIndex]->GetCullState();
}

const Rendering::ConstDepthStateSmartPointer Rendering::VisualTechniqueImpl
	::GetDepthState( int passIndex ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= passIndex && passIndex < GetNumPasses(),"��������");

	return m_Passes[passIndex]->GetDepthState();
}

const Rendering::ConstOffsetStateSmartPointer Rendering::VisualTechniqueImpl
	::GetOffsetState( int passIndex ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= passIndex && passIndex < GetNumPasses(),"��������");

	return m_Passes[passIndex]->GetOffsetState();
}

const Rendering::ConstStencilStateSmartPointer Rendering::VisualTechniqueImpl
	::GetStencilState( int passIndex ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= passIndex && passIndex < GetNumPasses(),"��������");

	return m_Passes[passIndex]->GetStencilState();
}

const Rendering::ConstWireStateSmartPointer Rendering::VisualTechniqueImpl
	::GetWireState( int passIndex ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= passIndex && passIndex < GetNumPasses(),"��������");

	return m_Passes[passIndex]->GetWireState();
}

const CoreTools::ObjectSmartPointer Rendering::VisualTechniqueImpl
	::GetObjectByName( const string& name )
{
	RENDERING_CLASS_IS_VALID_9;

	for(auto& pointer:m_Passes)
	{
		auto found = pointer->GetObjectByName(name);
		if (found != nullptr)
		{
			return found;
		}
	}

	return CoreTools::ObjectSmartPointer();
}

const vector<CoreTools::ObjectSmartPointer> Rendering::VisualTechniqueImpl
	::GetAllObjectsByName( const string& name )
{
	RENDERING_CLASS_IS_VALID_9;

	vector<CoreTools::ObjectSmartPointer> objects;

	for (auto& pointer:m_Passes)
	{		
		auto singleObjects = pointer->GetAllObjectsByName(name);

		objects.insert(objects.end(), singleObjects.begin(), singleObjects.end());
	}

	return objects;
}

const CoreTools::ConstObjectSmartPointer Rendering::VisualTechniqueImpl
	::GetConstObjectByName( const string& name ) const
{
	RENDERING_CLASS_IS_VALID_9;

	for (const auto& pointer:m_Passes)
	{
		auto found = pointer->GetConstObjectByName(name);
		if (found != nullptr)
		{
			return found;
		}
	}

	return CoreTools::ConstObjectSmartPointer();
}

const vector<CoreTools::ConstObjectSmartPointer> Rendering::VisualTechniqueImpl
	::GetAllConstObjectsByName( const string& name ) const
{
	RENDERING_CLASS_IS_VALID_9;

	vector<CoreTools::ConstObjectSmartPointer> objects;

	for (const auto& pointer:m_Passes)
	{		
		auto singleObjects = pointer->GetAllConstObjectsByName(name);

		objects.insert(objects.end(), singleObjects.begin(), singleObjects.end());
	}

	return objects;
}

void Rendering::VisualTechniqueImpl
	::SaveVisualPass(WriteFileManager& manager) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto numPasses = GetNumPasses();
	manager.Write(sizeof(int), &numPasses);
	for (auto i = 0; i < numPasses; ++i)
	{
		m_Passes[i]->SaveShader(manager);
		m_Passes[i]->SaveState(manager);
	}
}

void Rendering::VisualTechniqueImpl
	::LoadVisualPass(ReadFileManager& manager)
{
	RENDERING_CLASS_IS_VALID_9;

	auto numPasses = 0;
	manager.Read(sizeof(int), &numPasses);

	for (auto i = 0; i < numPasses; ++i)
	{
		VisualPassSmartPointer pass{ NEW0 VisualPass };

		pass->LoadShader(manager);
		pass->LoadState(manager);

		InsertPass(pass);
	}
}

 