///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/18 11:07)

#include "Rendering/RenderingExport.h"

#include "RevolutionSurface.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/CurvesSurfacesVolumes/Curve2Detail.h"
#include "Rendering/DataTypes/TransformDetail.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/SceneGraph/StandardMesh.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, RevolutionSurface);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, RevolutionSurface);
CORE_TOOLS_FACTORY_DEFINE(Rendering, RevolutionSurface);

Rendering::RevolutionSurface::RevolutionSurface(const std::shared_ptr<Mathematics::Curve2<float>>& curve,
                                                float xCenter,
                                                TopologyType topology,
                                                int numCurveSamples,
                                                int numRadialSamples,
                                                bool sampleByArcLength,
                                                bool outsideView,
                                                const VertexFormatSharedPtr& vformat)
    : ParentType{ vformat, nullptr, nullptr },
      curve{ curve },
      xCenter{ xCenter },
      topology{ topology },
      numCurveSamples{ numCurveSamples },
      numRadialSamples{ numRadialSamples },
      sin{},
      cos{},
      samples{},
      sampleByArcLength{ sampleByArcLength }
{
    ComputeSampleData();

    StandardMesh stdmesh{ vformat, !outsideView };
    TrianglesMeshSharedPtr mesh{ nullptr };
    switch (topology)
    {
        case TopologyType::RevDiskTopology:
        {
            mesh = stdmesh.Disk(numCurveSamples, numRadialSamples, 1.0f);
        }
        break;
        case TopologyType::RevCylinderTopology:
        {
            mesh = stdmesh.CylinderIncludedEndDisks(numCurveSamples, numRadialSamples, 1.0f, 1.0f);
        }
        break;
        case TopologyType::RevSphereTopology:
        {
            mesh = stdmesh.Sphere(numCurveSamples, numRadialSamples, 1.0f);
        }
        break;
        case TopologyType::RevTorusTopology:
        {
            mesh = stdmesh.Torus(numCurveSamples, numRadialSamples, 1.0f, 0.25f);
        }

        break;
        default:
        {
            RENDERING_ASSERTION_0(false, "意外情况。\n");
        }

        break;
    }

    SetVertexFormat(vformat);
    SetVertexBuffer(mesh->GetVertexBuffer());

    SetIndexBuffer(nullptr);
    UpdateSurface();

    SetIndexBuffer(mesh->GetIndexBuffer());

    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RevolutionSurface)

void Rendering::RevolutionSurface::ComputeSampleData()
{
    RENDERING_CLASS_IS_VALID_1;

    const auto size = numRadialSamples + 1;

    sin.resize(size);
    cos.resize(size);

    const auto invNumRadialSamples = 1.0f / boost::numeric_cast<float>(numRadialSamples);
    for (auto i = 0; i < numRadialSamples; ++i)
    {
        const auto angle = Mathematics::MathF::GetTwoPI() * invNumRadialSamples * i;
        cos.at(i) = Mathematics::MathF::Cos(angle);
        sin.at(i) = Mathematics::MathF::Sin(angle);
    }

    sin.at(numRadialSamples) = sin.at(0);
    cos.at(numRadialSamples) = cos.at(0);

    samples.resize(numCurveSamples);
}

void Rendering::RevolutionSurface::UpdateSurface()
{
    RENDERING_CLASS_IS_VALID_1;

    const auto tMin = curve->GetMinTime();
    const auto tRange = curve->GetMaxTime() - tMin;

    auto totalLength = 0.0f;
    if (sampleByArcLength)
    {
        totalLength = curve->GetTotalLength();
    }
    else
    {
        totalLength = 0.0f;
    }

    const auto invNumCurveSamplesM1 = 1.0f / boost::numeric_cast<float>(numCurveSamples - 1);
    for (auto i = 0; i < numCurveSamples; ++i)
    {
        auto t = 0.0f;
        if (sampleByArcLength)
        {
            t = curve->GetTime(i * totalLength * invNumCurveSamplesM1);
        }
        else
        {
            t = tMin + i * tRange * invNumCurveSamplesM1;
        }

        const auto position = curve->GetPosition(t);
        samples.at(i)[0] = (position.GetX());
        samples.at(i)[1] = (0.0f);
        samples.at(i)[2] = (position.GetY());
    }

    switch (topology)
    {
        case TopologyType::RevDiskTopology:
            UpdateDisk();
            break;
        case TopologyType::RevCylinderTopology:
            UpdateCylinder();
            break;
        case TopologyType::RevSphereTopology:
            UpdateSphere();
            break;
        case TopologyType::RevTorusTopology:
            UpdateTorus();
            break;
        default:
            RENDERING_ASSERTION_0(false, "意外情况\n");
            break;
    }

    UpdateModelSpace(VisualUpdateType::Normals);

    if (GetIndexBuffer() != nullptr)
    {
        RENDERER_MANAGE_SINGLETON.UpdateAll(GetVertexBuffer());
    }
}

CoreTools::ObjectInterface::ObjectInterfaceSharedPtr Rendering::RevolutionSurface::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

void Rendering::RevolutionSurface::UpdateDisk()
{
    RENDERING_CLASS_IS_VALID_1;

    const auto numCurveSamplesM1 = numCurveSamples - 1;
    for (auto r = 1; r < numRadialSamples; ++r)
    {
        for (auto c = 1; c < numCurveSamples; ++c)
        {
            auto radius = samples.at(c)[0] - xCenter;
            if (radius < 0.0f)
            {
                radius = 0.0f;
            }
            const auto i = c + numCurveSamplesM1 * r;

            const Mathematics::Vector3F position{ xCenter + radius * cos.at(r), radius * sin.at(r), samples.at(i)[2] };
        }
    }
}

void Rendering::RevolutionSurface::UpdateSphere()
{
    RENDERING_CLASS_IS_VALID_1;

    const auto index = numCurveSamples - 1;

    for (auto c = 1; c <= numCurveSamples - 2; ++c)
    {
        auto i = (c - 1) * (numRadialSamples + 1);

        i += numRadialSamples;
    }

    for (auto r = 1; r < numRadialSamples; ++r)
    {
        for (auto c = 1; c <= numCurveSamples - 2; ++c)
        {
            auto radius = samples.at(c)[0] - xCenter;
            if (radius < 0.0f)
            {
                radius = 0.0f;
            }
            const auto i = (c - 1) * (numRadialSamples + 1) + r;

            const Mathematics::Vector3F position{ xCenter + radius * cos.at(r), radius * sin.at(r), samples.at(c)[2] };
        }
    }
}

void Rendering::RevolutionSurface::UpdateCylinder()
{
    RENDERING_CLASS_IS_VALID_1;

    for (auto c = 0; c < numCurveSamples; ++c)
    {
        auto i = c * (numRadialSamples + 1);

        i += numRadialSamples;
    }

    for (auto r = 1; r < numRadialSamples; ++r)
    {
        for (auto c = 0; c < numCurveSamples; ++c)
        {
            auto radius = samples.at(c)[0] - xCenter;
            if (radius < 0.0f)
            {
                radius = 0.0f;
            }
            const auto i = c * (numRadialSamples + 1) + r;

            const Mathematics::Vector3F position{ xCenter + radius * cos.at(r), radius * sin.at(r), samples.at(c)[2] };
        }
    }
}

void Rendering::RevolutionSurface::UpdateTorus()
{
    RENDERING_CLASS_IS_VALID_1;

    auto numVertices = GetVertexBuffer()->GetNumElements();

    for (auto c = 0; c < numCurveSamples; ++c)
    {
        auto i = c * (numRadialSamples + 1);

        i += numRadialSamples;
    }

    for (auto r = 1; r < numRadialSamples; ++r)
    {
        for (auto c = 0; c < numCurveSamples; ++c)
        {
            auto radius = samples.at(c)[0] - xCenter;
            if (radius < 0.0f)
            {
                radius = 0.0f;
            }
            const auto i = c * (numRadialSamples + 1) + r;

            const Mathematics::Vector3F position{ xCenter + radius * cos.at(r), radius * sin.at(r), samples.at(c)[2] };
        }
    }

    auto i = numVertices - (numRadialSamples + 1);
    for (auto r = 0; r <= numRadialSamples; ++r, ++i)
    {
    }
}

Rendering::RevolutionSurface::RevolutionSurface(LoadConstructor value)
    : ParentType{ value },
      curve{},
      xCenter{ 0.0f },
      topology{ TopologyType::MaxTopologyTypes },
      numCurveSamples{ 0 },
      numRadialSamples{ 0 },
      sin{},
      cos{},
      samples{},
      sampleByArcLength{ false }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::RevolutionSurface::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    source.Read(xCenter);
    source.ReadEnum(topology);
    source.Read(numCurveSamples);
    source.Read(numRadialSamples);
    sin = source.ReadContainerUseNumber<std::vector<float>>(numRadialSamples + 1);
    cos = source.ReadContainerUseNumber<std::vector<float>>(numRadialSamples + 1);
    sampleByArcLength = source.ReadBool();

    curve = nullptr;

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::RevolutionSurface::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::RevolutionSurface::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

int64_t Rendering::RevolutionSurface::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::Register(target);
}

void Rendering::RevolutionSurface::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    target.Write(xCenter);
    target.WriteEnum(topology);
    target.Write(numCurveSamples);
    target.Write(numRadialSamples);
    target.WriteContainerWithoutNumber(sin);
    target.WriteContainerWithoutNumber(cos);
    target.Write(sampleByArcLength);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::RevolutionSurface::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = ParentType::GetStreamingSize();
    size += CoreTools::GetStreamSize(xCenter);
    size += CoreTools::GetStreamSize(topology);
    size += CoreTools::GetStreamSize(numCurveSamples);
    size += CoreTools::GetStreamSize(numRadialSamples);
    size += (numRadialSamples + 1) * CoreTools::GetStreamSize(sin.at(0));
    size += (numRadialSamples + 1) * CoreTools::GetStreamSize(cos.at(0));
    size += CoreTools::GetStreamSize(sampleByArcLength);
    return size;
}

int Rendering::RevolutionSurface::GetCurveSamples() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return numCurveSamples;
}

int Rendering::RevolutionSurface::GetRadialSamples() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return numRadialSamples;
}

void Rendering::RevolutionSurface::SetCurve(const std::shared_ptr<Mathematics::Curve2<float>>& aCurve) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    curve = aCurve;
}

std::shared_ptr<Mathematics::Curve2<float>> Rendering::RevolutionSurface::GetCurve() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return curve;
}

Rendering::RevolutionSurface::TopologyType Rendering::RevolutionSurface::GetTopology() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return topology;
}

void Rendering::RevolutionSurface::SetSampleByArcLength(bool aSampleByArcLength) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    sampleByArcLength = aSampleByArcLength;
}

bool Rendering::RevolutionSurface::GetSampleByArcLength() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return sampleByArcLength;
}
