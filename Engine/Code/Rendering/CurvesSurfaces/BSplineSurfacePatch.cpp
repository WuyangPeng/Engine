///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:59)

#include "Rendering/RenderingExport.h"

#include "BSplineSurfacePatch.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/CurvesSurfacesVolumes/BSplineBasisDetail.h"
#include "Mathematics/CurvesSurfacesVolumes/BSplineRectangleDetail.h"
#include "Mathematics/CurvesSurfacesVolumes/ParametricSurfaceDetail.h"
#include "Mathematics/CurvesSurfacesVolumes/SurfaceDetail.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, BSplineSurfacePatch);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, BSplineSurfacePatch);
CORE_TOOLS_FACTORY_DEFINE(Rendering, BSplineSurfacePatch);

Rendering::BSplineSurfacePatch::BSplineSurfacePatch(int numUCtrlPoints, int numVCtrlPoints, const std::vector<std::vector<Mathematics::Vector3F>>& ctrlPoints, int uDegree, int vDegree, bool uLoop, bool vLoop, bool uOpen, bool vOpen)
    : ParentType{ 0.0f, 1.0f, 0.0f, 1.0f, true },
      constructor{ 1 },
      patch{ std::make_shared<Mathematics::BSplineRectangle<float>>(numUCtrlPoints, numVCtrlPoints, ctrlPoints, uDegree, vDegree, uLoop, vLoop, uOpen, vOpen) }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::BSplineSurfacePatch::BSplineSurfacePatch(int numUCtrlPoints, int numVCtrlPoints, const std::vector<std::vector<Mathematics::Vector3F>>& ctrlPoints, int uDegree, int vDegree, bool uLoop, bool vLoop, bool uOpen, float* vKnots)
    : ParentType{ 0.0f, 1.0f, 0.0f, 1.0f, true },
      constructor{ 2 },
      patch{ std::make_shared<Mathematics::BSplineRectangle<float>>(numUCtrlPoints, numVCtrlPoints, ctrlPoints, uDegree, vDegree, uLoop, vLoop, uOpen, vKnots) }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::BSplineSurfacePatch::BSplineSurfacePatch(int numUCtrlPoints, int numVCtrlPoints, const std::vector<std::vector<Mathematics::Vector3F>>& ctrlPoints, int uDegree, int vDegree, bool uLoop, bool vLoop, float* uKnots, bool vOpen)
    : ParentType{ 0.0f, 1.0f, 0.0f, 1.0f, true },
      constructor{ 3 },
      patch{ std::make_shared<Mathematics::BSplineRectangle<float>>(numUCtrlPoints, numVCtrlPoints, ctrlPoints, uDegree, vDegree, uLoop, vLoop, uKnots, vOpen) }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::BSplineSurfacePatch::BSplineSurfacePatch(int numUCtrlPoints, int numVCtrlPoints, const std::vector<std::vector<Mathematics::Vector3F>>& ctrlPoints, int uDegree, int vDegree, bool uLoop, bool vLoop, float* uKnots, float* vKnots)
    : ParentType{ 0.0f, 1.0f, 0.0f, 1.0f, true },
      constructor{ 4 },
      patch{ std::make_shared<Mathematics::BSplineRectangle<float>>(numUCtrlPoints, numVCtrlPoints, ctrlPoints, uDegree, vDegree, uLoop, vLoop, uKnots, vKnots) }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, BSplineSurfacePatch)

Mathematics::APointF Rendering::BSplineSurfacePatch::GetPosition(float u, float v) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto p = patch->P(u, v);

    return APoint{ p[0], p[1], p[2] };
}

Mathematics::AVectorF Rendering::BSplineSurfacePatch::GetDerivativesU(float u, float v) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto pu = patch->PU(u, v);

    return AVector{ pu[0], pu[1], pu[2] };
}

Mathematics::AVectorF Rendering::BSplineSurfacePatch::GetDerivativesV(float u, float v) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto pv = patch->PV(u, v);

    return AVector{ pv[0], pv[1], pv[2] };
}

Mathematics::AVectorF Rendering::BSplineSurfacePatch::GetDerivativesUU(float u, float v) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto puu = patch->PUU(u, v);

    return AVector{ puu[0], puu[1], puu[2] };
}

Mathematics::AVectorF Rendering::BSplineSurfacePatch::GetDerivativesUV(float u, float v) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto puv = patch->PUV(u, v);

    return AVector{ puv[0], puv[1], puv[2] };
}

Mathematics::AVectorF Rendering::BSplineSurfacePatch::GetDerivativesVV(float u, float v) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto pvv = patch->PVV(u, v);

    return AVector{ pvv[0], pvv[1], pvv[2] };
}

Rendering::BSplineSurfacePatch::BSplineSurfacePatch(LoadConstructor value)
    : SurfacePatch{ value }, constructor{ 0 }, patch{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

void Rendering::BSplineSurfacePatch::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    SurfacePatch::Load(source);

    source.Read(constructor);

    int32_t numCtrlPoints0{ 0 };
    int32_t numCtrlPoints1{ 0 };
    source.Read(numCtrlPoints0);
    source.Read(numCtrlPoints1);
    std::vector<std::vector<Mathematics::Vector3F>> ctrl(numCtrlPoints1, std::vector<Mathematics::Vector3F>(numCtrlPoints0));

    for (auto i0 = 0; i0 < numCtrlPoints0; ++i0)
    {
        for (auto i1 = 0; i1 < numCtrlPoints1; ++i1)
        {
            source.ReadAggregate(ctrl.at(i0).at(i1));
        }
    }

    int32_t degree0{ 0 };
    int32_t degree1{ 0 };
    source.Read(degree0);
    source.Read(degree1);

    auto loop0 = source.ReadBool();
    auto loop1 = source.ReadBool();

    auto open0 = false;
    auto open1 = false;
    std::vector<float> knot0{};
    std::vector<float> knot1{};
    auto numKnots0 = 0;
    auto numKnots1 = 0;

    switch (constructor)
    {
        case 1:
        {
            open0 = source.ReadBool();
            open1 = source.ReadBool();

            patch = std::make_shared<Mathematics::BSplineRectangle<float>>(numCtrlPoints0, numCtrlPoints1, ctrl, degree0, degree1, loop0, loop1, open0, open1);
        }
        break;
        case 2:
        {
            open0 = source.ReadBool();
            numKnots1 = numCtrlPoints1 - degree1 - 1;
            knot1 = source.ReadContainerUseNumber<std::vector<float>>(numKnots1);

            patch = std::make_shared<Mathematics::BSplineRectangle<float>>(numCtrlPoints0, numCtrlPoints1, ctrl, degree0, degree1, loop0, loop1, open0, knot1.data());
        }
        break;
        case 3:
        {
            numKnots0 = numCtrlPoints0 - degree0 - 1;
            knot0 = source.ReadContainerUseNumber<std::vector<float>>(numKnots0);

            open1 = source.ReadBool();

            patch = std::make_shared<Mathematics::BSplineRectangle<float>>(numCtrlPoints0, numCtrlPoints1, ctrl, degree0, degree1, loop0, loop1, knot0.data(), open1);
        }
        break;
        case 4:
        {
            numKnots0 = numCtrlPoints0 - degree0 - 1;
            knot0 = source.ReadContainerUseNumber<std::vector<float>>(numKnots0);
            numKnots1 = numCtrlPoints1 - degree1 - 1;
            knot1 = source.ReadContainerUseNumber<std::vector<float>>(numKnots1);

            patch = std::make_shared<Mathematics::BSplineRectangle<float>>(numCtrlPoints0, numCtrlPoints1, ctrl, degree0, degree1, loop0, loop1, knot0.data(), knot1.data());
        }
        break;
        default:
        {
            RENDERING_ASSERTION_0(false, "意外情况\n");
        }
        break;
    }

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::BSplineSurfacePatch::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    SurfacePatch::Link(source);
}

void Rendering::BSplineSurfacePatch::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    SurfacePatch::PostLink();
}

int64_t Rendering::BSplineSurfacePatch::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return SurfacePatch::Register(target);
}

void Rendering::BSplineSurfacePatch::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    SurfacePatch::Save(target);

    target.Write(constructor);

    const auto numCtrlPoints0 = patch->GetNumCtrlPoints(0);
    const auto numCtrlPoints1 = patch->GetNumCtrlPoints(1);
    target.Write(numCtrlPoints0);
    target.Write(numCtrlPoints1);

    for (auto i0 = 0; i0 < numCtrlPoints0; ++i0)
    {
        for (auto i1 = 0; i1 < numCtrlPoints1; ++i1)
        {
            target.WriteAggregate(patch->GetControlPoint(i0, i1));
        }
    }

    const auto degree0 = patch->GetDegree(0);
    const auto degree1 = patch->GetDegree(1);
    target.Write(degree0);
    target.Write(degree1);

    const auto loop0 = patch->IsLoop(0);
    const auto loop1 = patch->IsLoop(1);
    target.Write(loop0);
    target.Write(loop1);

    auto open0 = false;
    auto open1 = false;
    auto numKnots0 = 0;
    auto numKnots1 = 0;

    switch (constructor)
    {
        case 1:
        {
            open0 = patch->IsOpen(0);
            target.Write(open0);
            open1 = patch->IsOpen(1);
            target.Write(open1);
        }
        break;
        case 2:
        {
            open0 = patch->IsOpen(0);
            target.Write(open0);
            numKnots1 = numCtrlPoints1 - degree1 - 1;
            for (auto i1 = 0; i1 < numKnots1; ++i1)
            {
                target.Write(patch->GetKnot(1, i1));
            }
        }
        break;
        case 3:
        {
            numKnots0 = numCtrlPoints0 - degree0 - 1;
            for (auto i0 = 0; i0 < numKnots0; ++i0)
            {
                target.Write(patch->GetKnot(0, i0));
            }

            open1 = patch->IsOpen(1);
            target.Write(open1);
        }
        break;
        case 4:
        {
            numKnots0 = numCtrlPoints0 - degree0 - 1;
            for (auto i0 = 0; i0 < numKnots0; ++i0)
            {
                target.Write(patch->GetKnot(0, i0));
            }

            numKnots1 = numCtrlPoints1 - degree1 - 1;
            for (auto i1 = 0; i1 < numKnots1; ++i1)
            {
                target.Write(patch->GetKnot(1, i1));
            }
        }
        break;
        default:
        {
            RENDERING_ASSERTION_0(false, "意外情况\n");
        }
        break;
    }

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::BSplineSurfacePatch::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = SurfacePatch::GetStreamingSize();
    size += sizeof(constructor);

    const auto numCtrlPoints0 = patch->GetNumCtrlPoints(0);
    const auto numCtrlPoints1 = patch->GetNumCtrlPoints(1);
    const auto degree0 = patch->GetDegree(0);
    const auto degree1 = patch->GetDegree(1);
    constexpr auto loop0 = false;
    size += CoreTools::GetStreamSize(numCtrlPoints0);
    size += CoreTools::GetStreamSize(numCtrlPoints1);
    size += CoreTools::GetStreamSize(degree0);
    size += CoreTools::GetStreamSize(degree1);
    size += 2 * CoreTools::GetStreamSize(loop0);  // loop0, loop1

    switch (constructor)
    {
        case 1:
        {
            size += 2 * CoreTools::GetStreamSize(loop0);  // open0, open1
        }
        break;
        case 2:
        {
            size += CoreTools::GetStreamSize(loop0);  // open0

            size += (numCtrlPoints1 - degree1 - 1) * CoreTools::GetStreamSize(float{});  // knot1[]
        }
        break;
        case 3:
        {
            size += (numCtrlPoints0 - degree0 - 1) * CoreTools::GetStreamSize(float{});  // knot0[]

            size += CoreTools::GetStreamSize(loop0);  // open1
        }
        break;
        case 4:
        {
            size += (numCtrlPoints0 - degree0 - 1) * CoreTools::GetStreamSize(float{});  // knot0[]
            size += (numCtrlPoints1 - degree1 - 1) * CoreTools::GetStreamSize(float{});  // knot1[]
        }
        break;
        default:
        {
            RENDERING_ASSERTION_0(false, "意外情况\n");
        }
        break;
    }

    return size;
}

CoreTools::ObjectInterfaceSharedPtr Rendering::BSplineSurfacePatch::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
