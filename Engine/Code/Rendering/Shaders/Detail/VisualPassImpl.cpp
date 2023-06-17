///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:50)

#include "Rendering/RenderingExport.h"

#include "VisualPassImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

Rendering::VisualPassImpl::VisualPassImpl() noexcept
    : vertexShader{},
      pixelShader{},
      alphaState{},
      cullState{},
      depthState{},
      offsetState{},
      stencilState{},
      wireState{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VisualPassImpl)

int Rendering::VisualPassImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CoreTools::GetStreamSize(vertexShader);

    size += CoreTools::GetStreamSize(pixelShader);
    size += CoreTools::GetStreamSize(alphaState);
    size += CoreTools::GetStreamSize(cullState);
    size += CoreTools::GetStreamSize(depthState);
    size += CoreTools::GetStreamSize(offsetState);
    size += CoreTools::GetStreamSize(stencilState);
    size += CoreTools::GetStreamSize(wireState);

    return size;
}

void Rendering::VisualPassImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteObjectAssociated(vertexShader);
    target.WriteObjectAssociated(pixelShader);
    target.WriteObjectAssociated(alphaState);
    target.WriteObjectAssociated(cullState);
    target.WriteObjectAssociated(depthState);
    target.WriteObjectAssociated(offsetState);
    target.WriteObjectAssociated(stencilState);
    target.WriteObjectAssociated(wireState);
}

void Rendering::VisualPassImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadObjectAssociated(vertexShader);
    source.ReadObjectAssociated(pixelShader);
    source.ReadObjectAssociated(alphaState);
    source.ReadObjectAssociated(cullState);
    source.ReadObjectAssociated(depthState);
    source.ReadObjectAssociated(offsetState);
    source.ReadObjectAssociated(stencilState);
    source.ReadObjectAssociated(wireState);
}

void Rendering::VisualPassImpl::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ResolveLink(vertexShader);
    source.ResolveLink(pixelShader);
    source.ResolveLink(alphaState);
    source.ResolveLink(cullState);
    source.ResolveLink(depthState);
    source.ResolveLink(offsetState);
    source.ResolveLink(stencilState);
    source.ResolveLink(wireState);
}

void Rendering::VisualPassImpl::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Register(vertexShader);
    target.Register(pixelShader);
    target.Register(alphaState);
    target.Register(cullState);
    target.Register(depthState);
    target.Register(offsetState);
    target.Register(stencilState);
    target.Register(wireState);
}

CoreTools::ObjectSharedPtr Rendering::VisualPassImpl::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    auto found = vertexShader.object->GetObjectByName(name);
    if (found != nullptr)
    {
        return found;
    }

    found = pixelShader.object->GetObjectByName(name);
    if (found != nullptr)
    {
        return found;
    }

    found = alphaState.object->GetObjectByName(name);
    if (found != nullptr)
    {
        return found;
    }

    found = cullState.object->GetObjectByName(name);
    if (found != nullptr)
    {
        return found;
    }

    found = depthState.object->GetObjectByName(name);
    if (found != nullptr)
    {
        return found;
    }

    found = offsetState.object->GetObjectByName(name);
    if (found != nullptr)
    {
        return found;
    }

    found = stencilState.object->GetObjectByName(name);
    if (found != nullptr)
    {
        return found;
    }

    found = wireState.object->GetObjectByName(name);
    if (found != nullptr)
    {
        return found;
    }

    return nullptr;
}

std::vector<CoreTools::ObjectSharedPtr> Rendering::VisualPassImpl::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    auto vertexObjects = vertexShader.object->GetAllObjectsByName(name);
    auto pixelObjects = pixelShader.object->GetAllObjectsByName(name);
    auto alphaStateObjects = alphaState.object->GetAllObjectsByName(name);
    auto cullStateObjects = cullState.object->GetAllObjectsByName(name);
    auto depthStateObjects = depthState.object->GetAllObjectsByName(name);
    auto offsetStateObjects = offsetState.object->GetAllObjectsByName(name);
    auto stencilStateObjects = stencilState.object->GetAllObjectsByName(name);
    auto wireStateObjects = wireState.object->GetAllObjectsByName(name);

    vertexObjects.insert(vertexObjects.end(), pixelObjects.begin(), pixelObjects.end());
    vertexObjects.insert(vertexObjects.end(), alphaStateObjects.begin(), alphaStateObjects.end());
    vertexObjects.insert(vertexObjects.end(), cullStateObjects.begin(), cullStateObjects.end());
    vertexObjects.insert(vertexObjects.end(), depthStateObjects.begin(), depthStateObjects.end());
    vertexObjects.insert(vertexObjects.end(), offsetStateObjects.begin(), offsetStateObjects.end());
    vertexObjects.insert(vertexObjects.end(), stencilStateObjects.begin(), stencilStateObjects.end());
    vertexObjects.insert(vertexObjects.end(), wireStateObjects.begin(), wireStateObjects.end());

    return vertexObjects;
}

CoreTools::ConstObjectSharedPtr Rendering::VisualPassImpl::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto found = vertexShader.object->GetConstObjectByName(name);
    if (found != nullptr)
    {
        return found;
    }

    found = pixelShader.object->GetConstObjectByName(name);
    if (found != nullptr)
    {
        return found;
    }

    found = alphaState.object->GetConstObjectByName(name);
    if (found != nullptr)
    {
        return found;
    }

    found = cullState.object->GetConstObjectByName(name);
    if (found != nullptr)
    {
        return found;
    }

    found = depthState.object->GetConstObjectByName(name);
    if (found != nullptr)
    {
        return found;
    }

    found = offsetState.object->GetConstObjectByName(name);
    if (found != nullptr)
    {
        return found;
    }

    found = stencilState.object->GetConstObjectByName(name);
    if (found != nullptr)
    {
        return found;
    }

    found = wireState.object->GetConstObjectByName(name);
    if (found != nullptr)
    {
        return found;
    }

    return nullptr;
}

std::vector<CoreTools::ConstObjectSharedPtr> Rendering::VisualPassImpl::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto vertexObjects = vertexShader.object->GetAllConstObjectsByName(name);
    auto pixelObjects = pixelShader.object->GetAllConstObjectsByName(name);
    auto alphaStateObjects = alphaState.object->GetAllConstObjectsByName(name);
    auto cullStateObjects = cullState.object->GetAllConstObjectsByName(name);
    auto depthStateObjects = depthState.object->GetAllConstObjectsByName(name);
    auto offsetStateObjects = offsetState.object->GetAllConstObjectsByName(name);
    auto stencilStateObjects = stencilState.object->GetAllConstObjectsByName(name);
    auto wireStateObjects = wireState.object->GetAllConstObjectsByName(name);

    vertexObjects.insert(vertexObjects.end(), pixelObjects.begin(), pixelObjects.end());
    vertexObjects.insert(vertexObjects.end(), alphaStateObjects.begin(), alphaStateObjects.end());
    vertexObjects.insert(vertexObjects.end(), cullStateObjects.begin(), cullStateObjects.end());
    vertexObjects.insert(vertexObjects.end(), depthStateObjects.begin(), depthStateObjects.end());
    vertexObjects.insert(vertexObjects.end(), offsetStateObjects.begin(), offsetStateObjects.end());
    vertexObjects.insert(vertexObjects.end(), stencilStateObjects.begin(), stencilStateObjects.end());
    vertexObjects.insert(vertexObjects.end(), wireStateObjects.begin(), wireStateObjects.end());

    return vertexObjects;
}

void Rendering::VisualPassImpl::SetVertexShader(const VertexShaderSharedPtr& aVertexShader) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    vertexShader.object = aVertexShader;
}

void Rendering::VisualPassImpl::SetPixelShader(const PixelShaderSharedPtr& aPixelShader) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    pixelShader.object = aPixelShader;
}

void Rendering::VisualPassImpl::SetAlphaState(const AlphaStateSharedPtr& aAlphaState) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    alphaState.object = aAlphaState;
}

void Rendering::VisualPassImpl::SetCullState(const CullStateSharedPtr& aCullState) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    cullState.object = aCullState;
}

void Rendering::VisualPassImpl::SetDepthState(const DepthStateSharedPtr& aDepthState) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    depthState.object = aDepthState;
}

void Rendering::VisualPassImpl::SetOffsetState(const OffsetStateSharedPtr& aOffsetState) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    offsetState.object = aOffsetState;
}

void Rendering::VisualPassImpl::SetStencilState(const StencilStateSharedPtr& aStencilState) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    stencilState.object = aStencilState;
}

void Rendering::VisualPassImpl::SetWireState(const WireStateSharedPtr& aWireState) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    wireState.object = aWireState;
}

Rendering::ConstVertexShaderSharedPtr Rendering::VisualPassImpl::GetVertexShader() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return vertexShader.object;
}

Rendering::ConstPixelShaderSharedPtr Rendering::VisualPassImpl::GetPixelShader() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return pixelShader.object;
}

Rendering::ConstAlphaStateSharedPtr Rendering::VisualPassImpl::GetAlphaState() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return alphaState.object;
}

Rendering::ConstCullStateSharedPtr Rendering::VisualPassImpl::GetCullState() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cullState.object;
}

Rendering::ConstDepthStateSharedPtr Rendering::VisualPassImpl::GetDepthState() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return depthState.object;
}

Rendering::ConstOffsetStateSharedPtr Rendering::VisualPassImpl::GetOffsetState() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return offsetState.object;
}

Rendering::ConstStencilStateSharedPtr Rendering::VisualPassImpl::GetStencilState() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return stencilState.object;
}

Rendering::ConstWireStateSharedPtr Rendering::VisualPassImpl::GetWireState() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return wireState.object;
}

void Rendering::VisualPassImpl::SaveShader(WriteFileManager& manager) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    vertexShader.object->SaveShader(manager);
    pixelShader.object->SaveShader(manager);
}

void Rendering::VisualPassImpl::SaveState(WriteFileManager& manager) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    alphaState.object->SaveState(manager);
    cullState.object->SaveState(manager);
    depthState.object->SaveState(manager);
    offsetState.object->SaveState(manager);
    stencilState.object->SaveState(manager);
    wireState.object->SaveState(manager);
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
    auto programName = manager.LoadStdString();

    int32_t numInputs{ 0 };
    int32_t numOutputs{ 0 };
    int32_t numConstants{ 0 };
    int32_t numSamplers{ 0 };
    int32_t numProfiles{ 0 };
    manager.Read(sizeof(int32_t), &numInputs);
    manager.Read(sizeof(int32_t), &numOutputs);
    manager.Read(sizeof(int32_t), &numConstants);
    manager.Read(sizeof(int32_t), &numSamplers);
    manager.Read(sizeof(int32_t), &numProfiles);

    auto result = std::make_shared<VertexShader>(programName, numInputs, numOutputs, numConstants, numSamplers);
    result->LoadShader(manager, numProfiles);
    SetVertexShader(result);
}

void Rendering::VisualPassImpl::LoadPixelShader(ReadFileManager& manager)
{
    auto programName = manager.LoadStdString();

    int32_t numInputs{ 0 };
    int32_t numOutputs{ 0 };
    int32_t numConstants{ 0 };
    int32_t numSamplers{ 0 };
    int32_t numProfiles{ 0 };
    manager.Read(sizeof(int32_t), &numInputs);
    manager.Read(sizeof(int32_t), &numOutputs);
    manager.Read(sizeof(int32_t), &numConstants);
    manager.Read(sizeof(int32_t), &numSamplers);
    manager.Read(sizeof(int32_t), &numProfiles);

    auto result = std::make_shared<PixelShader>(programName, numInputs, numOutputs, numConstants, numSamplers);
    result->LoadShader(manager, numProfiles);
    SetPixelShader(result);
}

void Rendering::VisualPassImpl::LoadAlphaState(ReadFileManager& manager)
{
    auto result = std::make_shared<AlphaState>(CoreTools::DisableNotThrow::Disable);
    result->LoadState(manager);
    SetAlphaState(result);
}

void Rendering::VisualPassImpl::LoadCullState(ReadFileManager& manager)
{
    auto result = std::make_shared<CullState>(CoreTools::DisableNotThrow::Disable);
    result->LoadState(manager);
    SetCullState(result);
}

void Rendering::VisualPassImpl::LoadDepthState(ReadFileManager& manager)
{
    auto result = std::make_shared<DepthState>(CoreTools::DisableNotThrow::Disable);
    result->LoadState(manager);
    SetDepthState(result);
}

void Rendering::VisualPassImpl::LoadOffsetState(ReadFileManager& manager)
{
    auto result = std::make_shared<OffsetState>(CoreTools::DisableNotThrow::Disable);
    result->LoadState(manager);
    SetOffsetState(result);
}

void Rendering::VisualPassImpl::LoadStencilState(ReadFileManager& manager)
{
    auto result = std::make_shared<StencilState>(CoreTools::DisableNotThrow::Disable);
    result->LoadState(manager);
    SetStencilState(result);
}

void Rendering::VisualPassImpl::LoadWireState(ReadFileManager& manager)
{
    auto result = std::make_shared<WireState>(CoreTools::DisableNotThrow::Disable);
    result->LoadState(manager);
    SetWireState(result);
}
