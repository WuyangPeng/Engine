// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/24 16:46)

#include "Rendering/RenderingExport.h"

#include "VisualPassImpl.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;
using std::vector;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26455)
Rendering::VisualPassImpl::VisualPassImpl()
    : m_VertexShader{}, m_PixelShader{}, m_AlphaState{}, m_CullState{},
      m_DepthState{}, m_OffsetState{}, m_StencilState{}, m_WireState{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VisualPassImpl)

int Rendering::VisualPassImpl::GetStreamingSize() const
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

void Rendering::VisualPassImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    target;
    //target.WriteSharedPtr(m_VertexShader);
    //target.WriteSharedPtr(m_PixelShader);
    //target.WriteSharedPtr(m_AlphaState);
    //target.WriteSharedPtr(m_CullState);
    //target.WriteSharedPtr(m_DepthState);
    //target.WriteSharedPtr(m_OffsetState);
    //target.WriteSharedPtr(m_StencilState);
    //target.WriteSharedPtr(m_WireState);
}

void Rendering::VisualPassImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;
    source;
    //source.ReadSharedPtr(m_VertexShader);
    //source.ReadSharedPtr(m_PixelShader);
    //source.ReadSharedPtr(m_AlphaState);
    //source.ReadSharedPtr(m_CullState);
    //source.ReadSharedPtr(m_DepthState);
    //source.ReadSharedPtr(m_OffsetState);
    //source.ReadSharedPtr(m_StencilState);
    //source.ReadSharedPtr(m_WireState);
}

void Rendering::VisualPassImpl::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;
    source;
    //source.ResolveObjectSharedPtrLink(m_VertexShader);
    //source.ResolveObjectSharedPtrLink(m_PixelShader);
    //source.ResolveObjectSharedPtrLink(m_AlphaState);
    //source.ResolveObjectSharedPtrLink(m_CullState);
    //source.ResolveObjectSharedPtrLink(m_DepthState);
    //source.ResolveObjectSharedPtrLink(m_OffsetState);
    //source.ResolveObjectSharedPtrLink(m_StencilState);
    //source.ResolveObjectSharedPtrLink(m_WireState);
}

void Rendering::VisualPassImpl::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    target;
    //target.RegisterSharedPtr(m_VertexShader);
    //target.RegisterSharedPtr(m_PixelShader);
    //target.RegisterSharedPtr(m_AlphaState);
    //target.RegisterSharedPtr(m_CullState);
    //target.RegisterSharedPtr(m_DepthState);
    //target.RegisterSharedPtr(m_OffsetState);
    //target.RegisterSharedPtr(m_StencilState);
    //target.RegisterSharedPtr(m_WireState);
}

CoreTools::ObjectSharedPtr Rendering::VisualPassImpl::GetObjectByName(const string& name)
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

    return CoreTools::ObjectSharedPtr();
}

vector<CoreTools::ObjectSharedPtr> Rendering::VisualPassImpl::GetAllObjectsByName(const string& name)
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

CoreTools::ConstObjectSharedPtr Rendering::VisualPassImpl::GetConstObjectByName(const string& name) const
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

    return CoreTools::ConstObjectSharedPtr();
}

vector<CoreTools::ConstObjectSharedPtr> Rendering::VisualPassImpl::GetAllConstObjectsByName(const string& name) const
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

void Rendering::VisualPassImpl::SetVertexShader(const VertexShaderSharedPtr& vertexShader)
{
    RENDERING_CLASS_IS_VALID_9;

    m_VertexShader = vertexShader;
}

void Rendering::VisualPassImpl::SetPixelShader(const PixelShaderSharedPtr& pixelShader)
{
    RENDERING_CLASS_IS_VALID_9;

    m_PixelShader = pixelShader;
}

void Rendering::VisualPassImpl::SetAlphaState(const AlphaStateSharedPtr& alphaState)
{
    RENDERING_CLASS_IS_VALID_9;

    m_AlphaState = alphaState;
}

void Rendering::VisualPassImpl::SetCullState(const CullStateSharedPtr& cullState)
{
    RENDERING_CLASS_IS_VALID_9;

    m_CullState = cullState;
}

void Rendering::VisualPassImpl::SetDepthState(const DepthStateSharedPtr& depthState)
{
    RENDERING_CLASS_IS_VALID_9;

    m_DepthState = depthState;
}

void Rendering::VisualPassImpl::SetOffsetState(const OffsetStateSharedPtr& offsetState)
{
    RENDERING_CLASS_IS_VALID_9;

    m_OffsetState = offsetState;
}

void Rendering::VisualPassImpl::SetStencilState(const StencilStateSharedPtr& stencilState)
{
    RENDERING_CLASS_IS_VALID_9;

    m_StencilState = stencilState;
}

void Rendering::VisualPassImpl::SetWireState(const WireStateSharedPtr& wireState)
{
    RENDERING_CLASS_IS_VALID_9;

    m_WireState = wireState;
}

const Rendering::ConstVertexShaderSharedPtr Rendering::VisualPassImpl::GetVertexShader() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return m_VertexShader;
}

const Rendering::ConstPixelShaderSharedPtr Rendering::VisualPassImpl::GetPixelShader() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return m_PixelShader;
}

const Rendering::ConstAlphaStateSharedPtr Rendering::VisualPassImpl::GetAlphaState() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return m_AlphaState;
}

const Rendering::ConstCullStateSharedPtr Rendering::VisualPassImpl::GetCullState() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return m_CullState;
}

const Rendering::ConstDepthStateSharedPtr Rendering::VisualPassImpl::GetDepthState() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return m_DepthState;
}

const Rendering::ConstOffsetStateSharedPtr Rendering::VisualPassImpl::GetOffsetState() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return m_OffsetState;
}

const Rendering::ConstStencilStateSharedPtr Rendering::VisualPassImpl::GetStencilState() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return m_StencilState;
}

const Rendering::ConstWireStateSharedPtr Rendering::VisualPassImpl::GetWireState() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return m_WireState;
}

void Rendering::VisualPassImpl::SaveShader(WriteFileManager& manager) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    m_VertexShader->SaveShader(manager);
    m_PixelShader->SaveShader(manager);
}

void Rendering::VisualPassImpl::SaveState(WriteFileManager& manager) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    m_AlphaState->SaveState(manager);
    m_CullState->SaveState(manager);
    m_DepthState->SaveState(manager);
    m_OffsetState->SaveState(manager);
    m_StencilState->SaveState(manager);
    m_WireState->SaveState(manager);
}

void Rendering::VisualPassImpl::LoadShader(ReadFileManager& manager)
{
    LoadVertexShader(manager);
    LoadPixelShader(manager);
}

void Rendering::VisualPassImpl::LoadState(ReadFileManager& manager)
{
    LoadAlphaState(manager);
    LoadCullState(manager);
    LoadDepthState(manager);
    LoadOffsetState(manager);
    LoadStencilState(manager);
    LoadWireState(manager);
}

void Rendering::VisualPassImpl::LoadVertexShader(ReadFileManager& manager)
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

    VertexShaderSharedPtr vertexShader{ std::make_shared<VertexShader>(programName, numInputs, numOutputs, numConstants, numSamplers) };
    vertexShader->LoadShader(manager, numProfiles);
    SetVertexShader(vertexShader);
}

void Rendering::VisualPassImpl::LoadPixelShader(ReadFileManager& manager)
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

    PixelShaderSharedPtr pixelShader{ std::make_shared<PixelShader>(programName, numInputs, numOutputs, numConstants, numSamplers) };
    pixelShader->LoadShader(manager, numProfiles);
    SetPixelShader(pixelShader);
}

void Rendering::VisualPassImpl::LoadAlphaState(ReadFileManager& manager)
{
    AlphaStateSharedPtr alphaState{ std::make_shared<AlphaState>() };
    alphaState->LoadState(manager);
    SetAlphaState(alphaState);
}

void Rendering::VisualPassImpl::LoadCullState(ReadFileManager& manager)
{
    CullStateSharedPtr cullState{ std::make_shared<CullState>() };
    cullState->LoadState(manager);
    SetCullState(cullState);
}

void Rendering::VisualPassImpl::LoadDepthState(ReadFileManager& manager)
{
    DepthStateSharedPtr depthState{ std::make_shared<DepthState>() };
    depthState->LoadState(manager);
    SetDepthState(depthState);
}

void Rendering::VisualPassImpl::LoadOffsetState(ReadFileManager& manager)
{
    OffsetStateSharedPtr offsetState{ std::make_shared<OffsetState>() };
    offsetState->LoadState(manager);
    SetOffsetState(offsetState);
}

void Rendering::VisualPassImpl::LoadStencilState(ReadFileManager& manager)
{
    StencilStateSharedPtr stencilState{ std::make_shared<StencilState>() };
    stencilState->LoadState(manager);
    SetStencilState(stencilState);
}

void Rendering::VisualPassImpl::LoadWireState(ReadFileManager& manager)
{
    WireStateSharedPtr wireState{ std::make_shared<WireState>() };
    wireState->LoadState(manager);
    SetWireState(wireState);
}
#include STSTEM_WARNING_POP