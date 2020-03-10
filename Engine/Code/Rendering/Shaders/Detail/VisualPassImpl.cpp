// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/24 16:46)

#include "Rendering/RenderingExport.h"

#include "VisualPassImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h" 
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;
using std::vector;

Rendering::VisualPassImpl
	::VisualPassImpl()
	:m_VertexShader{},m_PixelShader{},m_AlphaState{},m_CullState{},
	 m_DepthState{},m_OffsetState{},m_StencilState{},m_WireState{}
{
	RENDERING_SELF_CLASS_IS_VALID_9;
} 

CLASS_INVARIANT_STUB_DEFINE(Rendering, VisualPassImpl)

int Rendering::VisualPassImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto size = CORE_TOOLS_STREAM_SIZE(m_VertexShader);
	
	size += CORE_TOOLS_STREAM_SIZE(m_PixelShader);
	size += CORE_TOOLS_STREAM_SIZE(m_AlphaState);
	size += CORE_TOOLS_STREAM_SIZE(m_CullState);
	size += CORE_TOOLS_STREAM_SIZE(m_DepthState);
	size += CORE_TOOLS_STREAM_SIZE(m_OffsetState);
	size += CORE_TOOLS_STREAM_SIZE(m_StencilState);
	size += CORE_TOOLS_STREAM_SIZE(m_WireState);

	return size;
}

void Rendering::VisualPassImpl
	::Save(BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	target.WriteSmartPointer(m_VertexShader);
	target.WriteSmartPointer(m_PixelShader);
	target.WriteSmartPointer(m_AlphaState);
	target.WriteSmartPointer(m_CullState);
	target.WriteSmartPointer(m_DepthState);
	target.WriteSmartPointer(m_OffsetState);
	target.WriteSmartPointer(m_StencilState);
	target.WriteSmartPointer(m_WireState);
}

void Rendering::VisualPassImpl
	::Load(BufferSource& source)
{
	RENDERING_CLASS_IS_VALID_9;

	source.ReadSmartPointer(m_VertexShader);
	source.ReadSmartPointer(m_PixelShader);
	source.ReadSmartPointer(m_AlphaState);
	source.ReadSmartPointer(m_CullState);
	source.ReadSmartPointer(m_DepthState);
	source.ReadSmartPointer(m_OffsetState);
	source.ReadSmartPointer(m_StencilState);
	source.ReadSmartPointer(m_WireState);
}

void Rendering::VisualPassImpl
	::Link(ObjectLink& source)
{
	RENDERING_CLASS_IS_VALID_9;

	source.ResolveObjectSmartPointerLink(m_VertexShader);
	source.ResolveObjectSmartPointerLink(m_PixelShader);
	source.ResolveObjectSmartPointerLink(m_AlphaState);
	source.ResolveObjectSmartPointerLink(m_CullState);
	source.ResolveObjectSmartPointerLink(m_DepthState);
	source.ResolveObjectSmartPointerLink(m_OffsetState);
	source.ResolveObjectSmartPointerLink(m_StencilState);
	source.ResolveObjectSmartPointerLink(m_WireState);
}

void Rendering::VisualPassImpl
	::Register(ObjectRegister& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	target.RegisterSmartPointer(m_VertexShader);
	target.RegisterSmartPointer(m_PixelShader);
	target.RegisterSmartPointer(m_AlphaState);
	target.RegisterSmartPointer(m_CullState);
	target.RegisterSmartPointer(m_DepthState);
	target.RegisterSmartPointer(m_OffsetState);
	target.RegisterSmartPointer(m_StencilState);
	target.RegisterSmartPointer(m_WireState);
}

const CoreTools::ObjectSmartPointer Rendering::VisualPassImpl
	::GetObjectByName(const string& name)
{
	RENDERING_CLASS_IS_VALID_1;

	auto found = m_VertexShader->GetObjectByName(name);
	if (found != nullptr)
	{
		return found;
	}

	found = m_PixelShader->GetObjectByName(name);
	if (found != nullptr)
	{
		return found;
	}

	found = m_AlphaState->GetObjectByName(name);
	if (found != nullptr)
	{
		return found;
	}

	found = m_CullState->GetObjectByName(name);
	if (found != nullptr)
	{
		return found;
	}

	found = m_DepthState->GetObjectByName(name);
	if (found != nullptr)
	{
		return found;
	}

	found = m_OffsetState->GetObjectByName(name);
	if (found != nullptr)
	{
		return found;
	}

	found = m_StencilState->GetObjectByName(name);
	if (found != nullptr)
	{
		return found;
	}

	found = m_WireState->GetObjectByName(name);
	if (found != nullptr)
	{
		return found;
	}

	return CoreTools::ObjectSmartPointer();
}

const vector<CoreTools::ObjectSmartPointer> Rendering::VisualPassImpl
	::GetAllObjectsByName(const string& name)
{
	RENDERING_CLASS_IS_VALID_1;
 
	auto vertexObjects = m_VertexShader->GetAllObjectsByName(name);
	auto pixelObjects = m_PixelShader->GetAllObjectsByName(name);
	auto alphaStateObjects = m_AlphaState->GetAllObjectsByName(name);
	auto cullStateObjects = m_CullState->GetAllObjectsByName(name);
	auto depthStateObjects = m_DepthState->GetAllObjectsByName(name);
	auto offsetStateObjects = m_OffsetState->GetAllObjectsByName(name);
	auto stencilStateObjects = m_StencilState->GetAllObjectsByName(name);
	auto wireStateObjects = m_WireState->GetAllObjectsByName(name);

	vertexObjects.insert(vertexObjects.end(), pixelObjects.begin(), pixelObjects.end());
	vertexObjects.insert(vertexObjects.end(), alphaStateObjects.begin(), alphaStateObjects.end());
	vertexObjects.insert(vertexObjects.end(), cullStateObjects.begin(), cullStateObjects.end());
	vertexObjects.insert(vertexObjects.end(), depthStateObjects.begin(), depthStateObjects.end());
	vertexObjects.insert(vertexObjects.end(), offsetStateObjects.begin(), offsetStateObjects.end());
	vertexObjects.insert(vertexObjects.end(), stencilStateObjects.begin(), stencilStateObjects.end());
	vertexObjects.insert(vertexObjects.end(), wireStateObjects.begin(), wireStateObjects.end());

	return vertexObjects;
}

const CoreTools::ConstObjectSmartPointer Rendering::VisualPassImpl
	::GetConstObjectByName(const string& name) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto found = m_VertexShader->GetConstObjectByName(name);
	if (found != nullptr)
	{
		return found;
	}

	found = m_PixelShader->GetConstObjectByName(name);
	if (found != nullptr)
	{
		return found;
	}

	found = m_AlphaState->GetConstObjectByName(name);
	if (found != nullptr)
	{
		return found;
	}

	found = m_CullState->GetConstObjectByName(name);
	if (found != nullptr)
	{
		return found;
	}

	found = m_DepthState->GetConstObjectByName(name);
	if (found != nullptr)
	{
		return found;
	}

	found = m_OffsetState->GetConstObjectByName(name);
	if (found != nullptr)
	{
		return found;
	}

	found = m_StencilState->GetConstObjectByName(name);
	if (found != nullptr)
	{
		return found;
	}

	found = m_WireState->GetConstObjectByName(name);
	if (found != nullptr)
	{
		return found;
	}

	return CoreTools::ConstObjectSmartPointer();
}

const vector<CoreTools::ConstObjectSmartPointer> Rendering::VisualPassImpl
	::GetAllConstObjectsByName(const string& name) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
 
	auto vertexObjects = m_VertexShader->GetAllConstObjectsByName(name);
	auto pixelObjects = m_PixelShader->GetAllConstObjectsByName(name);
	auto alphaStateObjects = m_AlphaState->GetAllConstObjectsByName(name);
	auto cullStateObjects = m_CullState->GetAllConstObjectsByName(name);
	auto depthStateObjects = m_DepthState->GetAllConstObjectsByName(name);
	auto offsetStateObjects = m_OffsetState->GetAllConstObjectsByName(name);
	auto stencilStateObjects = m_StencilState->GetAllConstObjectsByName(name);
	auto wireStateObjects = m_WireState->GetAllConstObjectsByName(name);

	vertexObjects.insert(vertexObjects.end(), pixelObjects.begin(), pixelObjects.end());
	vertexObjects.insert(vertexObjects.end(), alphaStateObjects.begin(), alphaStateObjects.end());
	vertexObjects.insert(vertexObjects.end(), cullStateObjects.begin(), cullStateObjects.end());
	vertexObjects.insert(vertexObjects.end(), depthStateObjects.begin(), depthStateObjects.end());
	vertexObjects.insert(vertexObjects.end(), offsetStateObjects.begin(), offsetStateObjects.end());
	vertexObjects.insert(vertexObjects.end(), stencilStateObjects.begin(), stencilStateObjects.end());
	vertexObjects.insert(vertexObjects.end(), wireStateObjects.begin(), wireStateObjects.end());

	return vertexObjects;
}

void Rendering::VisualPassImpl
	::SetVertexShader(const VertexShaderSmartPointer& vertexShader)
{
	RENDERING_CLASS_IS_VALID_9;

	m_VertexShader = vertexShader;
}
 
void Rendering::VisualPassImpl
	::SetPixelShader(const PixelShaderSmartPointer& pixelShader)
{
	RENDERING_CLASS_IS_VALID_9;

	m_PixelShader = pixelShader;
}

void Rendering::VisualPassImpl
	::SetAlphaState(const AlphaStateSmartPointer& alphaState)
{
	RENDERING_CLASS_IS_VALID_9;

	m_AlphaState = alphaState;
}

void Rendering::VisualPassImpl
	::SetCullState(const CullStateSmartPointer& cullState)
{
	RENDERING_CLASS_IS_VALID_9;

	m_CullState = cullState;
}

void Rendering::VisualPassImpl
	::SetDepthState(const DepthStateSmartPointer& depthState)
{
	RENDERING_CLASS_IS_VALID_9;

	m_DepthState = depthState;
}

void Rendering::VisualPassImpl
	::SetOffsetState(const OffsetStateSmartPointer& offsetState)
{
	RENDERING_CLASS_IS_VALID_9;

	m_OffsetState = offsetState;
}

void Rendering::VisualPassImpl
	::SetStencilState(const StencilStateSmartPointer& stencilState)
{
	RENDERING_CLASS_IS_VALID_9;

	m_StencilState = stencilState;
}

void Rendering::VisualPassImpl
	::SetWireState(const WireStateSmartPointer& wireState)
{
	RENDERING_CLASS_IS_VALID_9;

	m_WireState = wireState;
}

const Rendering::ConstVertexShaderSmartPointer Rendering::VisualPassImpl
	::GetVertexShader() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_VertexShader.GetConstSmartPointer();
}

const Rendering::ConstPixelShaderSmartPointer Rendering::VisualPassImpl
	::GetPixelShader() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_PixelShader.GetConstSmartPointer();
}

const Rendering::ConstAlphaStateSmartPointer Rendering::VisualPassImpl
	::GetAlphaState() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_AlphaState.GetConstSmartPointer();
}

const Rendering::ConstCullStateSmartPointer Rendering::VisualPassImpl
	::GetCullState() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_CullState.GetConstSmartPointer();
}

const Rendering::ConstDepthStateSmartPointer Rendering::VisualPassImpl
	::GetDepthState() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_DepthState.GetConstSmartPointer();

}

const Rendering::ConstOffsetStateSmartPointer Rendering::VisualPassImpl
	::GetOffsetState() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_OffsetState.GetConstSmartPointer();
}

const Rendering::ConstStencilStateSmartPointer Rendering::VisualPassImpl
	::GetStencilState() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_StencilState.GetConstSmartPointer();
}

const Rendering::ConstWireStateSmartPointer Rendering::VisualPassImpl
	::GetWireState() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_WireState.GetConstSmartPointer();

}

void Rendering::VisualPassImpl
	::SaveShader(WriteFileManager& manager) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	m_VertexShader->SaveShader(manager);
	m_PixelShader->SaveShader(manager);
}

void Rendering::VisualPassImpl
	::SaveState(WriteFileManager& manager) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	m_AlphaState->SaveState(manager);
	m_CullState->SaveState(manager);
	m_DepthState->SaveState(manager);
	m_OffsetState->SaveState(manager);
	m_StencilState->SaveState(manager);
	m_WireState->SaveState(manager);
}

void Rendering::VisualPassImpl
	::LoadShader(ReadFileManager& manager)
{
	LoadVertexShader(manager);
	LoadPixelShader(manager);
}

void Rendering::VisualPassImpl
	::LoadState(ReadFileManager& manager)
{
	LoadAlphaState(manager);
	LoadCullState(manager);
	LoadDepthState(manager);
	LoadOffsetState(manager);
	LoadStencilState(manager);
	LoadWireState(manager);
}

void Rendering::VisualPassImpl
	::LoadVertexShader(ReadFileManager& manager)
{
	string programName = manager.LoadStdString();

	int numInputs{ 0 };
	int numOutputs{ 0 };
	int numConstants{ 0 };
	int numSamplers{ 0 };
	int numProfiles{ 0 };
	manager.Read(sizeof(int), &numInputs);
	manager.Read(sizeof(int), &numOutputs);
	manager.Read(sizeof(int), &numConstants);
	manager.Read(sizeof(int), &numSamplers);
	manager.Read(sizeof(int), &numProfiles);
 
	VertexShaderSmartPointer vertexShader{ NEW0 VertexShader(programName, numInputs, numOutputs, numConstants, numSamplers) };
	vertexShader->LoadShader(manager, numProfiles);
	SetVertexShader(vertexShader);
}

void Rendering::VisualPassImpl
	::LoadPixelShader(ReadFileManager& manager)
{
	auto programName = manager.LoadStdString();

	int numInputs{ 0 };
	int numOutputs{ 0 };
	int numConstants{ 0 };
	int numSamplers{ 0 };
	int numProfiles{ 0 };
	manager.Read(sizeof(int), &numInputs);
	manager.Read(sizeof(int), &numOutputs);
	manager.Read(sizeof(int), &numConstants);
	manager.Read(sizeof(int), &numSamplers);
	manager.Read(sizeof(int), &numProfiles);
 
	PixelShaderSmartPointer pixelShader{ NEW0 PixelShader(programName, numInputs, numOutputs, numConstants, numSamplers) };
	pixelShader->LoadShader(manager, numProfiles);
	SetPixelShader(pixelShader);
}

void Rendering::VisualPassImpl
	::LoadAlphaState(ReadFileManager& manager)
{
	AlphaStateSmartPointer alphaState{ NEW0 AlphaState };
	alphaState->LoadState(manager);
	SetAlphaState(alphaState);
}

void Rendering::VisualPassImpl
	::LoadCullState(ReadFileManager& manager)
{
	CullStateSmartPointer cullState{ NEW0 CullState };
	cullState->LoadState(manager);
	SetCullState(cullState);
}

void Rendering::VisualPassImpl
	::LoadDepthState(ReadFileManager& manager)
{
	DepthStateSmartPointer depthState{ NEW0 DepthState };
	depthState->LoadState(manager);
	SetDepthState(depthState);
}

void Rendering::VisualPassImpl
	::LoadOffsetState(ReadFileManager& manager)
{
	OffsetStateSmartPointer offsetState{ NEW0 OffsetState };
	offsetState->LoadState(manager);
	SetOffsetState(offsetState);
}

void Rendering::VisualPassImpl
	::LoadStencilState(ReadFileManager& manager)
{
	StencilStateSmartPointer stencilState{ NEW0 StencilState };
	stencilState->LoadState(manager);
	SetStencilState(stencilState);
}

void Rendering::VisualPassImpl
	::LoadWireState(ReadFileManager& manager)
{
	WireStateSmartPointer wireState{ NEW0 WireState };
	wireState->LoadState(manager);
	SetWireState(wireState);
}
