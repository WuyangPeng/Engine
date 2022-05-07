///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/15 14:34)

#include "Rendering/RenderingExport.h"

#include "PlanarShadowEffect.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/SceneGraph/VisibleSet.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, PlanarShadowEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, PlanarShadowEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, PlanarShadowEffect);

Rendering::PlanarShadowEffect::PlanarShadowEffect(int numPlanes, const NodeSharedPtr& shadowCaster)
    : ParentType{ CoreTools::DisableNotThrow::Disable },
      numPlanes{ numPlanes },
      planes(numPlanes),
      projectors(numPlanes),
      shadowColors(numPlanes),
      shadowCaster{ shadowCaster },
      alphaState{ std::make_shared<AlphaState>(CoreTools::DisableNotThrow::Disable) },
      depthState{ std::make_shared<DepthState>(CoreTools::DisableNotThrow::Disable) },
      stencilState{ std::make_shared<StencilState>(CoreTools::DisableNotThrow::Disable) },
      material{ Material::Create() },
      materialEffect{ std::make_shared<MaterialEffect>(CoreTools::DisableNotThrow::Disable) },
      materialEffectInstance{ materialEffect->CreateInstance(material) }
{
    auto sfloat = materialEffectInstance->GetVertexConstant(0, "MaterialDiffuse");

    auto clonePShader = boost::polymorphic_pointer_cast<ShaderFloat>(sfloat->CloneObject());

    clonePShader->EnableUpdater();

    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, PlanarShadowEffect)

void Rendering::PlanarShadowEffect::Draw(Renderer& renderer, VisibleSet& visibleSet)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto numVisible = visibleSet.GetNumVisible();

    for (auto& value : visibleSet)
    {
        renderer.Draw(value);
    }

    const auto saveDState = renderer.GetOverrideDepthState();
    const auto saveSState = renderer.GetOverrideStencilState();

    renderer.SetOverrideDepthState(depthState);
    renderer.SetOverrideStencilState(stencilState);

    auto camera = renderer.GetCamera();

    for (auto i = 0; i < numPlanes; ++i)
    {
        depthState->SetEnabled(true);
        depthState->SetWritable(true);
        depthState->SetCompare(DepthStateFlags::CompareMode::LessEqual);

        stencilState->SetEnabled(true);
        stencilState->SetCompare(StencilStateFlags::CompareMode::Always);
        stencilState->SetReference(i + 1);
        stencilState->SetOnFail(StencilStateFlags::OperationType::Keep);
        stencilState->SetOnZFail(StencilStateFlags::OperationType::Keep);
        stencilState->SetOnZPass(StencilStateFlags::OperationType::Replace);

        renderer.Draw(planes.at(i).object);

        const auto saveAState = renderer.GetOverrideAlphaState();
        renderer.SetOverrideAlphaState(alphaState);
        alphaState->SetBlendEnabled(true);
        alphaState->SetSourceBlend(AlphaStateFlags::SourceBlendMode::SourceAlpha);
        alphaState->SetDestinationBlend(AlphaStateFlags::DestinationBlendMode::OneMinusSourceAlpha);
        material->SetDiffuse(Colour<float>{ shadowColors.at(i)[0], shadowColors.at(i)[1], shadowColors.at(i)[2], shadowColors.at(i)[3] });

        depthState->SetEnabled(false);

        stencilState->SetEnabled(true);
        stencilState->SetCompare(StencilStateFlags::CompareMode::Equal);
        stencilState->SetReference(i + 1);
        stencilState->SetOnFail(StencilStateFlags::OperationType::Keep);
        stencilState->SetOnZFail(StencilStateFlags::OperationType::Keep);
        stencilState->SetOnZPass(StencilStateFlags::OperationType::Zero);

        Mathematics::MatrixF projection{};
        if (!GetProjectionMatrix(i, projection))
        {
            continue;
        }

        camera->SetPreViewMatrix(projection);

        for (auto& visual : visibleSet)
        {
            ConstVisualEffectInstanceSharedPtr save = visual->GetConstEffectInstance();
            visual->SetEffectInstance(materialEffectInstance);
            renderer.Draw(visual);

            visual->SetEffectInstance(boost::polymorphic_pointer_cast<VisualEffectInstance>(save->CloneObject()));
        }

        camera->SetPreViewMatrix(Mathematics::MatrixF::GetIdentityMatrix());

        renderer.SetOverrideAlphaState(saveAState);
    }

    renderer.SetOverrideStencilState(saveSState);
    renderer.SetOverrideDepthState(saveDState);
}

bool Rendering::PlanarShadowEffect::GetProjectionMatrix(int i, Mathematics::MatrixF& projection)
{
    RENDERING_CLASS_IS_VALID_1;

    auto vertex = planes.at(i).object->GetWorldTriangle(0);
    const Mathematics::PlaneF worldPlane{ vertex.GetFirstPosition(), vertex.GetSecondPosition(), vertex.GetThirdPosition() };

    if (shadowCaster.object->GetWorldBound().WhichSide(worldPlane) < Mathematics::NumericalValueSymbol::Zero)
    {
        return false;
    }

    const auto& projector = projectors.at(i).object;
    const auto normal = worldPlane.GetNormal();
    if (projector->GetType() == LightType::Directional)
    {
        auto ndd = Dot(normal, projector->GetDirectionVector());
        if (ndd >= 0.0f)
        {
            return false;
        }

        projection.MakeObliqueProjection(vertex.GetFirstPosition(), normal, projector->GetDirectionVector());
    }
    else if (projector->GetType() == LightType::Point || projector->GetType() == LightType::Spot)
    {
        auto nde = Dot(projector->GetPosition(), normal);
        if (nde <= 0.0f)
        {
            return false;
        }

        projection.MakePerspectiveProjection(vertex.GetFirstPosition(), normal, projector->GetPosition());
    }
    else
    {
        return false;
    }

    return true;
}

CoreTools::ObjectSharedPtr Rendering::PlanarShadowEffect::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    auto found = ParentType::GetObjectByName(name);
    if (found)
    {
        return found;
    }

    for (auto i = 0; i < numPlanes; ++i)
    {
        auto found2 = planes.at(i).object->GetObjectByName(name);
        if (found2)
            return found2;

        found2 = projectors.at(i).object->GetObjectByName(name);
        if (found2)
            return found2;
    }

    return nullptr;
}

std::vector<CoreTools::ObjectSharedPtr> Rendering::PlanarShadowEffect::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    std::vector<CoreTools::ObjectSharedPtr> objects{};
    auto found = ParentType::GetObjectByName(name);
    if (found)
    {
        objects.emplace_back(found);
    }

    for (auto i = 0; i < numPlanes; ++i)
    {
        auto pointerObjects = planes.at(i).object->GetAllObjectsByName(name);

        objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());

        pointerObjects = projectors.at(i).object->GetAllObjectsByName(name);

        objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
    }

    return objects;
}

CoreTools::ConstObjectSharedPtr Rendering::PlanarShadowEffect::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_1;

    auto found = ParentType::GetConstObjectByName(name);
    if (found)
    {
        return found;
    }

    for (int i = 0; i < numPlanes; ++i)
    {
        auto found2 = planes.at(i).object->GetConstObjectByName(name);
        if (found2)
            return found2;

        found2 = projectors.at(i).object->GetObjectByName(name);
        if (found2)
            return found2;
    }

    return nullptr;
}

std::vector<CoreTools::ConstObjectSharedPtr> Rendering::PlanarShadowEffect::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_1;

    auto objects = ParentType::GetAllConstObjectsByName(name);

    for (int i = 0; i < numPlanes; ++i)
    {
        auto pointerObjects = planes.at(i).object->GetAllObjectsByName(name);

        objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());

        pointerObjects = projectors.at(i).object->GetAllObjectsByName(name);

        objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
    }

    return objects;
}

Rendering::PlanarShadowEffect::PlanarShadowEffect(LoadConstructor value)
    : ParentType{ value },
      numPlanes{ 0 },
      planes{},
      projectors{},
      shadowColors{},
      shadowCaster{},
      alphaState{},
      depthState{},
      stencilState{},
      material{},
      materialEffect{},
      materialEffectInstance{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::PlanarShadowEffect::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    GlobalEffect::Load(source);

    source.ReadAggregateContainer(shadowColors);
    source.ReadObjectAssociatedContainer(planes);
    source.ReadObjectAssociatedContainer(projectors);
    source.ReadObjectAssociated(shadowCaster);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::PlanarShadowEffect::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    GlobalEffect::Link(source);

    source.ResolveLinkContainer(planes);
    source.ResolveLinkContainer(projectors);
    source.ResolveLink(shadowCaster);
}

void Rendering::PlanarShadowEffect::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    GlobalEffect::PostLink();

    alphaState = std::make_shared<AlphaState>(CoreTools::DisableNotThrow::Disable);
    depthState = std::make_shared<DepthState>(CoreTools::DisableNotThrow::Disable);
    stencilState = std::make_shared<StencilState>(CoreTools::DisableNotThrow::Disable);
    material = Material::Create();
    materialEffect = std::make_shared<MaterialEffect>(CoreTools::DisableNotThrow::Disable);
    materialEffectInstance = materialEffect->CreateInstance(material);
}

uint64_t Rendering::PlanarShadowEffect::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const uint64_t id = GlobalEffect::Register(target);
    if (0 < id)
    {
        target.RegisterContainer(planes);
        target.RegisterContainer(projectors);
        target.Register(shadowCaster);
        return id;
    }
    return id;
}

void Rendering::PlanarShadowEffect::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    GlobalEffect::Save(target);

    target.WriteAggregateContainerWithNumber(shadowColors);
    target.WriteObjectAssociatedContainerWithNumber(planes);
    target.WriteObjectAssociatedContainerWithNumber(projectors);
    target.WriteObjectAssociated(shadowCaster);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::PlanarShadowEffect::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = GlobalEffect::GetStreamingSize();
    size += CORE_TOOLS_STREAM_SIZE(numPlanes);
    size += numPlanes * CORE_TOOLS_STREAM_SIZE(shadowCaster);
    size += numPlanes * RENDERING_STREAM_SIZE(planes.at(0));
    size += numPlanes * RENDERING_STREAM_SIZE(projectors.at(0));
    size += RENDERING_STREAM_SIZE(shadowCaster);

    return size;
}

int Rendering::PlanarShadowEffect::GetNumPlanes() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numPlanes;
}

void Rendering::PlanarShadowEffect::SetPlane(int i, const TrianglesMeshSharedPtr& plane)
{
    RENDERING_CLASS_IS_VALID_1;

    planes.at(i).object = plane;
    planes.at(i).object->SetCullingMode(CullingMode::Always);
}

Rendering::ConstTrianglesMeshSharedPtr Rendering::PlanarShadowEffect::GetPlane(int i) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return planes.at(i).object;
}

void Rendering::PlanarShadowEffect::SetProjector(int i, Light* projector)
{
    RENDERING_CLASS_IS_VALID_1;

    projectors.at(i).object.reset(projector);
}

Rendering::ConstLightSharedPtr Rendering::PlanarShadowEffect::GetProjector(int i) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return projectors.at(i).object;
}

void Rendering::PlanarShadowEffect::SetShadowColor(int i, const Mathematics::Float4& shadowColor)
{
    RENDERING_CLASS_IS_VALID_1;

    shadowColors.at(i) = shadowColor;
}

const Mathematics::Float4& Rendering::PlanarShadowEffect::GetShadowColor(int i) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return shadowColors.at(i);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::PlanarShadowEffect::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
