///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/12 16:41)

#include "Rendering/RenderingExport.h"

#include "VisualEffectInstanceImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

#include <gsl/util>

using std::string;
using std::swap;
using std::vector;

Rendering::VisualEffectInstanceImpl::VisualEffectInstanceImpl() noexcept
    : visualEffect{}, techniqueIndex{ 0 }, numPasses{ 0 }, vertexParameters{}, pixelParameters{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisualEffectInstanceImpl::VisualEffectInstanceImpl(const VisualEffectSharedPtr& effect, int techniqueIndex)
    : visualEffect{ effect },
      techniqueIndex{ techniqueIndex },
      numPasses{ effect->GetNumPasses(techniqueIndex) },
      vertexParameters{ numPasses },
      pixelParameters{ numPasses }
{
    for (auto passIndex = 0; passIndex < numPasses; ++passIndex)
    {
        auto pass = visualEffect.object->GetPass(techniqueIndex, passIndex);
        vertexParameters.at(passIndex).object = std::make_shared<ShaderParameters>(pass->GetVertexShader());
        pixelParameters.at(passIndex).object = std::make_shared<ShaderParameters>(pass->GetPixelShader());
    }

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::VisualEffectInstanceImpl::VisualEffectInstanceImpl(const VisualEffectInstanceImpl& rhs)
    : visualEffect{ rhs.visualEffect },
      techniqueIndex{ rhs.techniqueIndex },
      numPasses{ visualEffect.object->GetNumPasses(techniqueIndex) },
      vertexParameters{ numPasses },
      pixelParameters{ numPasses }
{
    for (auto passIndex = 0; passIndex < numPasses; ++passIndex)
    {
        auto pass = visualEffect.object->GetPass(techniqueIndex, passIndex);
        vertexParameters.at(passIndex).object = std::make_shared<ShaderParameters>(*rhs.vertexParameters.at(passIndex).object);
        pixelParameters.at(passIndex).object = std::make_shared<ShaderParameters>(*rhs.pixelParameters.at(passIndex).object);
    }

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::VisualEffectInstanceImpl& Rendering::VisualEffectInstanceImpl::operator=(const VisualEffectInstanceImpl& rhs)
{
    RENDERING_CLASS_IS_VALID_1;

    VisualEffectInstanceImpl result{ rhs };

    Swap(result);

    return *this;
}

Rendering::VisualEffectInstanceImpl::VisualEffectInstanceImpl(VisualEffectInstanceImpl&& rhs) noexcept
    : visualEffect{ std::move(rhs.visualEffect) },
      techniqueIndex{ std::move(rhs.techniqueIndex) },
      numPasses{ std::move(rhs.numPasses) },
      vertexParameters{ std::move(rhs.vertexParameters) },
      pixelParameters{ std::move(rhs.pixelParameters) }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::VisualEffectInstanceImpl& Rendering::VisualEffectInstanceImpl::operator=(VisualEffectInstanceImpl&& rhs) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    VisualEffectInstanceImpl result{ std::move(rhs) };

    Swap(result);

    return *this;
}

// private
void Rendering::VisualEffectInstanceImpl::Swap(VisualEffectInstanceImpl& rhs) noexcept
{
    swap(visualEffect, rhs.visualEffect);
    swap(techniqueIndex, rhs.techniqueIndex);
    swap(numPasses, rhs.numPasses);
    vertexParameters.swap(rhs.vertexParameters);
    pixelParameters.swap(rhs.pixelParameters);
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::VisualEffectInstanceImpl::IsValid() const noexcept
{
    if (numPasses == gsl::narrow_cast<int>(vertexParameters.size()) &&
        numPasses == gsl::narrow_cast<int>(pixelParameters.size()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

int Rendering::VisualEffectInstanceImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = CORE_TOOLS_STREAM_SIZE(visualEffect);

    size += CORE_TOOLS_STREAM_SIZE(techniqueIndex);
    size += CORE_TOOLS_STREAM_SIZE(numPasses);
    size += CORE_TOOLS_STREAM_SIZE(vertexParameters);
    size += CORE_TOOLS_STREAM_SIZE(pixelParameters);

    return size;
}

void Rendering::VisualEffectInstanceImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.WriteObjectAssociated(visualEffect);
    target.Write(techniqueIndex);
    target.Write(numPasses);
    target.WriteObjectAssociatedContainerWithNumber(vertexParameters);
    target.WriteObjectAssociatedContainerWithNumber(pixelParameters);
}

void Rendering::VisualEffectInstanceImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.ReadObjectAssociated(visualEffect);
    source.Read(techniqueIndex);
    source.Read(numPasses);
    source.ReadObjectAssociatedContainer(vertexParameters);
    source.ReadObjectAssociatedContainer(pixelParameters);
}

void Rendering::VisualEffectInstanceImpl::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.ResolveLink(visualEffect);

    source.ResolveLinkContainer(vertexParameters);
    source.ResolveLinkContainer(pixelParameters);
}

void Rendering::VisualEffectInstanceImpl::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.Register(visualEffect);

    target.RegisterContainer(vertexParameters);
    target.RegisterContainer(pixelParameters);
}

CoreTools::ObjectSharedPtr Rendering::VisualEffectInstanceImpl::GetObjectByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    CoreTools::ObjectSharedPtr found = visualEffect.object->GetObjectByName(name);

    for (auto& pointer : vertexParameters)
    {
        auto found2 = pointer.object->GetObjectByName(name);
        if (found2 != nullptr)
        {
            return found2;
        }
    }

    for (auto& pointer : pixelParameters)
    {
        auto found2 = pointer.object->GetObjectByName(name);
        if (found2 != nullptr)
        {
            return found2;
        }
    }

    return nullptr;
}

vector<CoreTools::ObjectSharedPtr> Rendering::VisualEffectInstanceImpl::GetAllObjectsByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    auto objects = visualEffect.object->GetAllObjectsByName(name);

    for (auto& pointer : vertexParameters)
    {
        auto singleObjects = pointer.object->GetAllObjectsByName(name);

        objects.insert(objects.end(), singleObjects.begin(), singleObjects.end());
    }

    for (auto& pointer : pixelParameters)
    {
        auto singleObjects = pointer.object->GetAllObjectsByName(name);

        objects.insert(objects.end(), singleObjects.begin(), singleObjects.end());
    }

    return objects;
}

CoreTools::ConstObjectSharedPtr Rendering::VisualEffectInstanceImpl::GetConstObjectByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto found = visualEffect.object->GetConstObjectByName(name);

    for (const auto& pointer : vertexParameters)
    {
        auto found2 = pointer.object->GetConstObjectByName(name);
        if (found2 != nullptr)
        {
            return found2;
        }
    }

    for (const auto& pointer : pixelParameters)
    {
        auto found2 = pointer.object->GetConstObjectByName(name);
        if (found2 != nullptr)
        {
            return found2;
        }
    }

    return nullptr;
}

vector<CoreTools::ConstObjectSharedPtr> Rendering::VisualEffectInstanceImpl::GetAllConstObjectsByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto objects = visualEffect.object->GetAllConstObjectsByName(name);

    for (const auto& pointer : vertexParameters)
    {
        auto singleObjects = pointer.object->GetAllConstObjectsByName(name);

        objects.insert(objects.end(), singleObjects.begin(), singleObjects.end());
    }

    for (const auto& pointer : pixelParameters)
    {
        auto singleObjects = pointer.object->GetAllConstObjectsByName(name);

        objects.insert(objects.end(), singleObjects.begin(), singleObjects.end());
    }

    return objects;
}

Rendering::ConstVisualEffectSharedPtr Rendering::VisualEffectInstanceImpl::GetEffect() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return visualEffect.object;
}

int Rendering::VisualEffectInstanceImpl::GetTechniqueIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return techniqueIndex;
}

int Rendering::VisualEffectInstanceImpl::GetNumPasses() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numPasses;
}

Rendering::ConstVisualPassSharedPtr Rendering::VisualEffectInstanceImpl::GetConstPass(int pass) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return visualEffect.object->GetPass(techniqueIndex, pass);
}

Rendering::ConstShaderParametersSharedPtr Rendering::VisualEffectInstanceImpl::GetConstVertexParameters(int pass) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= pass && pass < numPasses, "索引越界！\n");

    return vertexParameters.at(pass).object;
}

Rendering::ConstShaderParametersSharedPtr Rendering::VisualEffectInstanceImpl::GetConstPixelParameters(int pass) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= pass && pass < numPasses, "索引越界！\n");

    return pixelParameters.at(pass).object;
}

int Rendering::VisualEffectInstanceImpl::SetVertexConstant(int pass, const std::string& name, const ShaderFloatSharedPtr& shaderFloat)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= pass && pass < numPasses, "索引越界！\n");

    return vertexParameters.at(pass).object->SetConstant(name, shaderFloat);
}

void Rendering::VisualEffectInstanceImpl::SetVertexConstant(int pass, int handle, const ShaderFloatSharedPtr& shaderFloat)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= pass && pass < numPasses, "索引越界！\n");

    return vertexParameters.at(pass).object->SetConstant(handle, shaderFloat);
}

void Rendering::VisualEffectInstanceImpl::SetPixelConstant(int pass, int handle, const ShaderFloatSharedPtr& shaderFloat)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= pass && pass < numPasses, "索引越界！\n");

    return pixelParameters.at(pass).object->SetConstant(handle, shaderFloat);
}

void Rendering::VisualEffectInstanceImpl::SetVertexTexture(int pass, int handle, const TextureSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= pass && pass < numPasses, "索引越界！\n");

    return vertexParameters.at(pass).object->SetTexture(handle, texture);
}

void Rendering::VisualEffectInstanceImpl::SetPixelTexture(int pass, int handle, const TextureSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= pass && pass < numPasses, "索引越界！\n");

    return pixelParameters.at(pass).object->SetTexture(handle, texture);
}

int Rendering::VisualEffectInstanceImpl::SetPixelConstant(int pass, const std::string& name, const ShaderFloatSharedPtr& shaderFloat)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= pass && pass < numPasses, "索引越界！\n");

    return pixelParameters.at(pass).object->SetConstant(name, shaderFloat);
}

int Rendering::VisualEffectInstanceImpl::SetVertexTexture(int pass, const std::string& name, const TextureSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= pass && pass < numPasses, "索引越界！\n");

    return vertexParameters.at(pass).object->SetTexture(name, texture);
}

int Rendering::VisualEffectInstanceImpl::SetPixelTexture(int pass, const std::string& name, const TextureSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= pass && pass < numPasses, "索引越界！\n");

    return pixelParameters.at(pass).object->SetTexture(name, texture);
}

Rendering::ConstShaderFloatSharedPtr Rendering::VisualEffectInstanceImpl::GetVertexConstant(int pass, const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= pass && pass < numPasses, "索引越界！\n");

    return vertexParameters.at(pass).object->GetConstant(name);
}

Rendering::ConstShaderFloatSharedPtr Rendering::VisualEffectInstanceImpl::GetPixelConstant(int pass, int handle) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= pass && pass < numPasses, "索引越界！\n");

    return pixelParameters.at(pass).object->GetConstant(handle);
}

Rendering::ConstTextureSharedPtr Rendering::VisualEffectInstanceImpl::GetVertexTexture(int pass, int handle) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= pass && pass < numPasses, "索引越界！\n");

    return vertexParameters.at(pass).object->GetTexture(handle);
}

Rendering::ConstTextureSharedPtr Rendering::VisualEffectInstanceImpl::GetPixelTexture(int pass, int handle) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= pass && pass < numPasses, "索引越界！\n");

    return pixelParameters.at(pass).object->GetTexture(handle);
}

Rendering::ConstShaderFloatSharedPtr Rendering::VisualEffectInstanceImpl::GetPixelConstant(int pass, const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= pass && pass < numPasses, "索引越界！\n");

    return pixelParameters.at(pass).object->GetConstant(name);
}

Rendering::ConstTextureSharedPtr Rendering::VisualEffectInstanceImpl::GetVertexTexture(int pass, const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= pass && pass < numPasses, "索引越界！\n");

    return vertexParameters.at(pass).object->GetTexture(name);
}

Rendering::ConstTextureSharedPtr Rendering::VisualEffectInstanceImpl::GetPixelTexture(int pass, const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= pass && pass < numPasses, "索引越界！\n");

    return pixelParameters.at(pass).object->GetTexture(name);
}

Rendering::ConstShaderFloatSharedPtr Rendering::VisualEffectInstanceImpl::GetVertexConstant(int pass, int handle) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= pass && pass < numPasses, "索引越界！\n");

    return vertexParameters.at(pass).object->GetConstant(handle);
}

Rendering::ShaderParametersSharedPtr Rendering::VisualEffectInstanceImpl::GetVertexParameters(int pass)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= pass && pass < numPasses, "索引越界！\n");

    return vertexParameters.at(pass).object;
}

Rendering::ShaderParametersSharedPtr Rendering::VisualEffectInstanceImpl::GetPixelParameters(int pass)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= pass && pass < numPasses, "索引越界！\n");

    return pixelParameters.at(pass).object;
}
