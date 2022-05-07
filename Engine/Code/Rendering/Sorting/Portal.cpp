///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/19 16:14)

#include "Rendering/RenderingExport.h"

#include "ConvexRegion.h"
#include "Portal.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, Portal);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Portal);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Portal);

Rendering::Portal::Portal(int numVertices, const std::vector<Mathematics::APointF>& modelVertices, const Mathematics::PlaneF& modelPlane, const std::shared_ptr<ConvexRegion>& adjacentRegion, bool open)
    : ParentType{ "Portal" },
      adjacentRegion{ adjacentRegion },
      open{ open },
      numVertices{ numVertices },
      modelVertices(modelVertices),
      worldVertices(numVertices),
      modelPlane{ modelPlane },
      worldPlane{ modelPlane }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, Portal)

CoreTools::ObjectInterfaceSharedPtr Rendering::Portal::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

void Rendering::Portal::UpdateWorldData(const TransformF& worldTransform)
{
    RENDERING_CLASS_IS_VALID_1;

    for (auto i = 0; i < numVertices; ++i)
    {
        worldVertices.at(i) = worldTransform * modelVertices.at(i);
    }

    worldPlane = modelPlane.GetHomogeneousPoint() * worldTransform.GetInverseMatrix();
}

bool Rendering::Portal::ReducedFrustum(const Culler& culler, std::array<float, 6>& reducedFrustum)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto camera = culler.GetCamera();
    const auto frustum = culler.GetFrustum();
    auto rmin = +Mathematics::MathF::maxReal;
    auto rmax = -Mathematics::MathF::maxReal;
    auto umin = +Mathematics::MathF::maxReal;
    auto umax = -Mathematics::MathF::maxReal;

    Mathematics::AVectorF diff{};
    Mathematics::APointF vertexCam{};

    if (camera->IsPerspective())
    {
        constexpr auto epsilon = 1e-6f;
        constexpr auto invEpsilon = 1e+6f;
        auto firstSign = 0;
        auto lastSign = 0;
        auto signChange = false;
        auto firstVertex = Mathematics::APointF::GetOrigin();
        auto lastVertex = Mathematics::APointF::GetOrigin();
        auto ndd = 0.0f;
        auto udd = 0.0f;
        auto rdd = 0.0f;
        auto t = 0.0f;

        for (auto i = 0; i < numVertices; i++)
        {
            diff = worldVertices.at(i) - camera->GetPosition();
            vertexCam[0] = Dot(diff, camera->GetDirectionVector());
            vertexCam[1] = Dot(diff, camera->GetUpVector());
            vertexCam[2] = Dot(diff, camera->GetRightVector());
            vertexCam[3] = 1.0f;

            if (vertexCam[0] > epsilon)
            {
                if (firstSign == 0)
                {
                    firstSign = 1;
                    firstVertex = vertexCam;
                }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                ndd = frustum[System::EnumCastUnderlying(ViewFrustum::DirectionMin)] / vertexCam[0];

#include STSTEM_WARNING_POP

                udd = vertexCam[1] * ndd;
                rdd = vertexCam[2] * ndd;

                if (udd < umin)
                {
                    umin = udd;
                }
                if (udd > umax)
                {
                    umax = udd;
                }

                if (rdd < rmin)
                {
                    rmin = rdd;
                }
                if (rdd > rmax)
                {
                    rmax = rdd;
                }

                if (lastSign < 0)
                {
                    signChange = true;
                }

                lastSign = 1;
            }
            else
            {
                if (firstSign == 0)
                {
                    firstSign = -1;
                    firstVertex = vertexCam;
                }

                if (lastSign > 0)
                {
                    signChange = true;
                }

                lastSign = -1;
            }

            if (signChange)
            {
                diff = vertexCam - lastVertex;
                t = (epsilon - lastVertex[0]) / diff[0];

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                ndd = frustum[System::EnumCastUnderlying(ViewFrustum::DirectionMin)] * invEpsilon;

#include STSTEM_WARNING_POP

                udd = (lastVertex[1] + t * diff[1]) * ndd;
                rdd = (lastVertex[2] + t * diff[2]) * ndd;

                if (udd < umin)
                {
                    umin = udd;
                }
                if (udd > umax)
                {
                    umax = udd;
                }

                if (rdd < rmin)
                {
                    rmin = rdd;
                }
                if (rdd > rmax)
                {
                    rmax = rdd;
                }

                signChange = false;
            }

            lastVertex = vertexCam;
        }

        if (firstSign * lastSign < 0)
        {
            diff = firstVertex - lastVertex;
            t = (epsilon - lastVertex[0]) / diff[0];
            udd = (lastVertex[1] + t * diff[1]) * invEpsilon;
            rdd = (lastVertex[2] + t * diff[2]) * invEpsilon;

            if (udd < umin)
            {
                umin = udd;
            }
            if (udd > umax)
            {
                umax = udd;
            }

            if (rdd < rmin)
            {
                rmin = rdd;
            }
            if (rdd > rmax)
            {
                rmax = rdd;
            }
        }
    }
    else
    {
        for (auto i = 0; i < numVertices; i++)
        {
            diff = worldVertices.at(i) - camera->GetPosition();
            vertexCam[1] = Dot(diff, camera->GetUpVector());
            vertexCam[2] = Dot(diff, camera->GetRightVector());

            if (vertexCam[1] < umin)
            {
                umin = vertexCam[1];
            }
            if (vertexCam[1] > umax)
            {
                umax = vertexCam[1];
            }

            if (vertexCam[2] < rmin)
            {
                rmin = vertexCam[2];
            }
            if (vertexCam[2] > rmax)
            {
                rmax = vertexCam[2];
            }
        }
    }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    if (frustum[System::EnumCastUnderlying(ViewFrustum::RightMin)] >= rmax ||
        frustum[System::EnumCastUnderlying(ViewFrustum::RightMax)] <= rmin ||
        frustum[System::EnumCastUnderlying(ViewFrustum::UpMin)] >= umax ||
        frustum[System::EnumCastUnderlying(ViewFrustum::UpMax)] <= umin)
    {
        return false;
    }

    for (auto j = 0; j < 6; ++j)
    {
        reducedFrustum.at(j) = frustum[j];
    }

#include STSTEM_WARNING_POP

    if (reducedFrustum.at(System::EnumCastUnderlying(ViewFrustum::RightMin)) < rmin)
    {
        reducedFrustum.at(System::EnumCastUnderlying(ViewFrustum::RightMin)) = rmin;
    }

    if (reducedFrustum.at(System::EnumCastUnderlying(ViewFrustum::RightMax)) > rmax)
    {
        reducedFrustum.at(System::EnumCastUnderlying(ViewFrustum::RightMax)) = rmax;
    }

    if (reducedFrustum.at(System::EnumCastUnderlying(ViewFrustum::UpMin)) < umin)
    {
        reducedFrustum.at(System::EnumCastUnderlying(ViewFrustum::UpMin)) = umin;
    }

    if (reducedFrustum.at(System::EnumCastUnderlying(ViewFrustum::UpMax)) > umax)
    {
        reducedFrustum.at(System::EnumCastUnderlying(ViewFrustum::UpMax)) = umax;
    }

    return true;
}

void Rendering::Portal::GetVisibleSet(Culler& culler, bool noCull)
{
    RENDERING_CLASS_IS_VALID_1;

    if (!open)
    {
        return;
    }

    if (!culler.IsVisible(numVertices, worldVertices.data(), true))
    {
        return;
    }

    const auto camera = culler.GetCamera();
    if (worldPlane.WhichSide(camera->GetPosition()) < Mathematics::NumericalValueSymbol::Zero)
    {
        return;
    }

    std::array<float, 6> saveFrustum{};
    const auto frustum = culler.GetFrustum();
    if (frustum == nullptr)
    {
        return;
    }

    for (auto j = 0; j < 6; ++j)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        saveFrustum.at(j) = frustum[j];

#include STSTEM_WARNING_POP
    }

    std::array<float, 6> reducedFrustum{};
    if (ReducedFrustum(culler, reducedFrustum))
    {
        culler.SetFrustum(reducedFrustum.data());

        adjacentRegion.object.lock()->GetVisibleSet(culler, noCull);

        culler.SetFrustum(saveFrustum.data());
    }
}

CoreTools::ObjectSharedPtr Rendering::Portal::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    auto found = ParentType::GetObjectByName(name);
    if (found)
    {
        return found;
    }

    found = adjacentRegion.object.lock()->GetObjectByName(name);
    if (found)
    {
        return found;
    }

    return nullptr;
}

std::vector<CoreTools::ObjectSharedPtr> Rendering::Portal::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    auto objects = ParentType::GetAllObjectsByName(name);

    auto pointerObjects = adjacentRegion.object.lock()->GetAllObjectsByName(name);
    objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());

    return objects;
}

CoreTools::ConstObjectSharedPtr Rendering::Portal::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto found = ParentType::GetConstObjectByName(name);
    if (found)
    {
        return found;
    }

    found = adjacentRegion.object.lock()->GetConstObjectByName(name);
    if (found)
    {
        return found;
    }

    return nullptr;
}

std::vector<CoreTools::ConstObjectSharedPtr> Rendering::Portal::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto objects = ParentType::GetAllConstObjectsByName(name);

    auto pointerObjects = adjacentRegion.object.lock()->GetAllConstObjectsByName(name);
    objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());

    return objects;
}

Rendering::Portal::Portal(LoadConstructor value)
    : ParentType{ value },
      adjacentRegion{},
      open{ false },
      numVertices{},
      modelVertices{},
      worldVertices{},
      modelPlane{ 0.0f, 0.0f, 0.0f, 0.0f },
      worldPlane{ 0.0f, 0.0f, 0.0f, 0.0f }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::Portal::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    source.ReadAggregateContainer(modelVertices);
    source.ReadAggregate(modelPlane);
    open = source.ReadBool();
    source.ReadObjectAssociated(adjacentRegion);

    worldVertices.resize(numVertices);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::Portal::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);

    source.ResolveLink(adjacentRegion);
}

void Rendering::Portal::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

uint64_t Rendering::Portal::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (ParentType::Register(target))
    {
        target.RegisterWeakPtr(adjacentRegion);
        return true;
    }
    return false;
}

void Rendering::Portal::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    target.WriteAggregateContainerWithNumber(modelVertices);
    target.WriteAggregate(modelPlane);
    target.Write(open);
    target.WriteWeakObjectAssociated(adjacentRegion);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::Portal::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();
    size += sizeof(numVertices);
    size += numVertices * sizeof(modelVertices[0]);
    size += sizeof(modelPlane);
    size += CORE_TOOLS_STREAM_SIZE(open);
    size += CORE_TOOLS_STREAM_SIZE(adjacentRegion);

    return size;
}
