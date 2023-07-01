///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:48)

#include "Rendering/RenderingExport.h"

#include "PlanarReflectionEffect.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/PlaneDetail.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Rendering/RendererEngine/BaseRenderer.h"
#include "Rendering/SceneGraph/VisibleSet.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, PlanarReflectionEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, PlanarReflectionEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, PlanarReflectionEffect);

Rendering::PlanarReflectionEffect::PlanarReflectionEffect(int numPlanes)
    : ParentType{ CoreTools::DisableNotThrow::Disable },
      numPlanes{ numPlanes },
      planes(numPlanes),
      reflectances(numPlanes)
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, PlanarReflectionEffect)

void Rendering::PlanarReflectionEffect::Draw(BaseRenderer& renderer, VisibleSet& visibleSet) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
    renderer;
    visibleSet;
    /*  const auto saveDState = renderer.GetOverrideDepthState();
      const auto saveSState = renderer.GetOverrideStencilState();

      renderer.SetOverrideDepthState(depthState.object);
      renderer.SetOverrideStencilState(stencilState.object);

      const auto depthRange = renderer.GetDepthRange();

      auto camera = renderer.GetCamera();

      const auto numVisible = visibleSet.GetNumVisible();

      for (auto i = 0; i < numPlanes; ++i)
      {
          stencilState.object->SetEnabled(true);
          stencilState.object->SetCompare(StencilStateFlags::CompareMode::Always);
          stencilState.object->SetReference(boost::numeric_cast<uint32_t>(i + 1));
          stencilState.object->SetOnFail(StencilStateFlags::OperationType::Keep);
          stencilState.object->SetOnZFail(StencilStateFlags::OperationType::Keep);
          stencilState.object->SetOnZPass(StencilStateFlags::OperationType::Replace);

          depthState.object->SetEnabled(true);
          depthState.object->SetWritable(false);
          depthState.object->SetCompare(DepthStateFlags::CompareMode::LessEqual);

          renderer.SetColorMask(false, false, false, false);

          renderer.Draw(planes.at(i).object);

          renderer.SetColorMask(true, true, true, true);

          stencilState.object->SetEnabled(true);
          stencilState.object->SetCompare(StencilStateFlags::CompareMode::Equal);
          stencilState.object->SetReference(i + 1);
          stencilState.object->SetOnFail(StencilStateFlags::OperationType::Keep);
          stencilState.object->SetOnZFail(StencilStateFlags::OperationType::Keep);
          stencilState.object->SetOnZPass(StencilStateFlags::OperationType::Keep);

          renderer.SetDepthRange(DepthRange{ 1.0f, 1.0f });
          depthState.object->SetEnabled(true);
          depthState.object->SetWritable(true);
          depthState.object->SetCompare(DepthStateFlags::CompareMode::Always);

          renderer.Draw(planes.at(i).object);

          depthState.object->SetCompare(DepthStateFlags::CompareMode::LessEqual);
          renderer.SetDepthRange(depthRange);

          Mathematics::MatrixF reflection{};
          Mathematics::PlaneF modelPlane{};
          GetReflectionMatrixAndModelPlane(i, reflection, modelPlane);

          camera->SetPreViewMatrix(reflection);

          renderer.SetReverseCullOrder(true);

          for (auto& value : visibleSet)
          {
              renderer.Draw(value);
          }

          renderer.SetReverseCullOrder(false);

          camera->SetPreViewMatrix(Mathematics::MatrixF::GetIdentityMatrix());

          const auto saveAState = renderer.GetOverrideAlphaState();
          renderer.SetOverrideAlphaState(alphaState.object);
          alphaState.object->SetBlendEnabled(true);
          alphaState.object->SetSourceBlend(AlphaStateFlags::SourceBlendMode::OneMinusConstantAlpha);
          alphaState.object->SetDestinationBlend(AlphaStateFlags::DestinationBlendMode::ConstantAlpha);
          alphaState.object->SetConstantColor(Colour<float>{ 0.0f, 0.0f, 0.0f, reflectances.at(i) });

          stencilState.object->SetCompare(StencilStateFlags::CompareMode::Equal);
          stencilState.object->SetReference(i + 1);
          stencilState.object->SetOnFail(StencilStateFlags::OperationType::Keep);
          stencilState.object->SetOnZFail(StencilStateFlags::OperationType::Keep);
          stencilState.object->SetOnZPass(StencilStateFlags::OperationType::Invert);

          renderer.Draw(planes.at(i).object);

          renderer.SetOverrideAlphaState(saveAState);
      }

      renderer.SetOverrideStencilState(saveSState);
      renderer.SetOverrideDepthState(saveDState);

      for (auto& value : visibleSet)
      {
          renderer.Draw(value);
      }*/
}

void Rendering::PlanarReflectionEffect::GetReflectionMatrixAndModelPlane(int i, Mathematics::MatrixF& reflection, Mathematics::PlaneF& modelPlane)
{
    RENDERING_CLASS_IS_VALID_1;

    auto vertex = planes.at(i).object->GetWorldTriangle(0);
    const Mathematics::PlaneF worldPlane{ vertex.GetFirstPosition(), vertex.GetSecondPosition(), vertex.GetThirdPosition() };

    reflection.MakeReflection(vertex.GetFirstPosition(), worldPlane.GetNormal());

    vertex = planes.at(i).object->GetModelTriangle(0);
    modelPlane = Mathematics::PlaneF{ vertex.GetFirstPosition(), vertex.GetSecondPosition(), vertex.GetThirdPosition() };
}

CoreTools::ObjectSharedPtr Rendering::PlanarReflectionEffect::GetObjectByName(const std::string& name)
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
        {
            return found2;
        }
    }

    return nullptr;
}

std::vector<CoreTools::ObjectSharedPtr> Rendering::PlanarReflectionEffect::GetAllObjectsByName(const std::string& name)
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
    }

    return objects;
}

CoreTools::ConstObjectSharedPtr Rendering::PlanarReflectionEffect::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto found = ParentType::GetConstObjectByName(name);
    if (found)
    {
        return found;
    }

    for (int i = 0; i < numPlanes; ++i)
    {
        auto found2 = planes.at(i).object->GetConstObjectByName(name);
        if (found2)
        {
            return found2;
        }
    }

    return nullptr;
}

std::vector<CoreTools::ConstObjectSharedPtr> Rendering::PlanarReflectionEffect::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto objects = ParentType::GetAllConstObjectsByName(name);

    for (auto i = 0; i < numPlanes; ++i)
    {
        auto pointerObjects = planes.at(i).object->GetAllObjectsByName(name);

        objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
    }

    return objects;
}

Rendering::PlanarReflectionEffect::PlanarReflectionEffect(LoadConstructor value)
    : ParentType{ value },
      numPlanes{ 0 },
      planes{},
      reflectances{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::PlanarReflectionEffect::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();
    size += CoreTools::GetStreamSize(numPlanes);
    size += numPlanes * CoreTools::GetStreamSize(reflectances.at(0));
    size += numPlanes * RENDERING_STREAM_SIZE(planes.at(0));
    return size;
}

int64_t Rendering::PlanarReflectionEffect::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto id = ParentType::Register(target);
    if (0 < id)
    {
        target.RegisterContainer(planes);
        return id;
    }

    return id;
}

void Rendering::PlanarReflectionEffect::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    target.WriteContainerWithNumber(reflectances);
    target.WriteObjectAssociatedContainerWithNumber(planes);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::PlanarReflectionEffect::Link(MAYBE_UNUSED CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.ResolveLinkContainer(planes);
}

void Rendering::PlanarReflectionEffect::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    CoreTools::DisableNoexcept();
}

void Rendering::PlanarReflectionEffect::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    source.ReadContainer(reflectances);
    source.ReadObjectAssociatedContainer(planes);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

int Rendering::PlanarReflectionEffect::GetNumPlanes() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numPlanes;
}

void Rendering::PlanarReflectionEffect::SetPlane(int i, const TrianglesMeshSharedPtr& plane)
{
    RENDERING_CLASS_IS_VALID_1;

    planes.at(i).object = plane;
    planes.at(i).object->SetCullingMode(CullingMode::Always);
}

Rendering::ConstTrianglesMeshSharedPtr Rendering::PlanarReflectionEffect::GetPlane(int i) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return planes.at(i).object;
}

void Rendering::PlanarReflectionEffect::SetReflectance(int i, float reflectance)
{
    RENDERING_CLASS_IS_VALID_1;

    reflectances.at(i) = reflectance;
}

float Rendering::PlanarReflectionEffect::GetReflectance(int i) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return reflectances.at(i);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::PlanarReflectionEffect::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
