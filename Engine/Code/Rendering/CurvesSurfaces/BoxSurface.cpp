///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:59)

#include "Rendering/RenderingExport.h"

#include "BoxSurface.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Base/SpanIteratorDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Base/Float.h"
#include "Mathematics/CurvesSurfacesVolumes/BSplineBasisDetail.h"
#include "Mathematics/CurvesSurfacesVolumes/BSplineVolumeDetail.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"
#include "Rendering/SceneGraph/Flags/VisualFlags.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, BoxSurface);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, BoxSurface);
CORE_TOOLS_FACTORY_DEFINE(Rendering, BoxSurface);

Rendering::BoxSurface::BoxSurface(const Mathematics::BSplineVolume<float>& volume, int numUSamples, int numVSamples, int numWSamples, const std::array<VertexFormatSharedPtr, 6>& vformat)
    : ParentType{ "BoxSurface", NodeCreate::Init },
      volume{ std::make_shared<Mathematics::BSplineVolume<float>>(volume) },
      numUSamples{ numUSamples },
      numVSamples{ numVSamples },
      numWSamples{ numWSamples },
      doSort{ false }
{
    vformat;

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, BoxSurface)

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26418)

void Rendering::BoxSurface::UpdateFace(int numRows, int numCols, MAYBE_UNUSED const VertexFormatSharedPtr& vformat, MAYBE_UNUSED const VertexBufferSharedPtr& vbuffer, MAYBE_UNUSED bool ccw, float faceValue, const std::array<int, 3>& permute)
{
    RENDERING_CLASS_IS_VALID_9;

    std::array<float, 3> param{};
    param.at(permute.at(2)) = faceValue;

    const auto rowFactor = 1.0f / boost::numeric_cast<float>(numRows - 1);
    const auto colFactor = 1.0f / boost::numeric_cast<float>(numCols - 1);
    for (auto row = 0, i = 0; row < numRows; ++row)
    {
        param.at(permute.at(1)) = row * rowFactor;
        for (auto col = 0; col < numCols; ++col, ++i)
        {
            param.at(permute.at(0)) = col * colFactor;
        }
    }
}

#include SYSTEM_WARNING_POP

void Rendering::BoxSurface::UpdateSurface() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

Rendering::BoxSurface::BoxSurface(LoadConstructor value)
    : ParentType{ value },
      volume{},
      numUSamples{ 0 },
      numVSamples{ 0 },
      numWSamples{ 0 },
      doSort{ false }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

void Rendering::BoxSurface::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    int32_t numUCtrlPoints{ 0 };
    int32_t numVCtrlPoints{ 0 };
    int32_t numWCtrlPoints{ 0 };
    int32_t uDegree{ 0 };
    int32_t vDegree{ 0 };
    int32_t wDegree{ 0 };
    source.Read(numUCtrlPoints);
    source.Read(numVCtrlPoints);
    source.Read(numWCtrlPoints);
    source.Read(uDegree);
    source.Read(vDegree);
    source.Read(wDegree);
    volume = std::make_shared<Mathematics::BSplineVolume<float>>(numUCtrlPoints, numVCtrlPoints, numWCtrlPoints, uDegree, vDegree, wDegree);
    for (auto u = 0; u < numUCtrlPoints; ++u)
    {
        for (auto v = 0; v < numVCtrlPoints; ++v)
        {
            for (auto w = 0; w < numWCtrlPoints; ++w)
            {
                Mathematics::Vector3F ctrl{};
                source.ReadAggregate(ctrl);
                volume->SetControlPoint(u, v, w, ctrl);
            }
        }
    }

    source.Read(numUSamples);
    source.Read(numVSamples);
    source.Read(numWSamples);
    doSort = source.ReadBool();

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::BoxSurface::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::Link(source);
}

void Rendering::BoxSurface::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::PostLink();
}

int64_t Rendering::BoxSurface::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::Register(target);
}

void Rendering::BoxSurface::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    const auto numUCtrlPoints = volume->GetNumCtrlPoints(0);
    const auto numVCtrlPoints = volume->GetNumCtrlPoints(1);
    const auto numWCtrlPoints = volume->GetNumCtrlPoints(2);
    const auto uDegree = volume->GetDegree(0);
    const auto vDegree = volume->GetDegree(1);
    const auto wDegree = volume->GetDegree(2);
    target.Write(numUCtrlPoints);
    target.Write(numVCtrlPoints);
    target.Write(numWCtrlPoints);
    target.Write(uDegree);
    target.Write(vDegree);
    target.Write(wDegree);
    for (auto u = 0; u < numUCtrlPoints; ++u)
    {
        for (auto v = 0; v < numVCtrlPoints; ++v)
        {
            for (auto w = 0; w < numWCtrlPoints; ++w)
            {
                const auto ctrl = volume->GetControlPoint(u, v, w);
                target.WriteAggregate(ctrl);
            }
        }
    }

    target.Write(numUSamples);
    target.Write(numVSamples);
    target.Write(numWSamples);
    target.Write(doSort);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::BoxSurface::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = Node::GetStreamingSize();

    const auto numUCtrlPoints = volume->GetNumCtrlPoints(0);
    const auto numVCtrlPoints = volume->GetNumCtrlPoints(1);
    const auto numWCtrlPoints = volume->GetNumCtrlPoints(2);
    size += CoreTools::GetStreamSize(numUCtrlPoints);
    size += CoreTools::GetStreamSize(numVCtrlPoints);
    size += CoreTools::GetStreamSize(numWCtrlPoints);
    size += CoreTools::GetStreamSize(int{});  // uDegree
    size += CoreTools::GetStreamSize(int{});  // vDegree
    size += CoreTools::GetStreamSize(int{});  // wDegree
    size += numUCtrlPoints * numVCtrlPoints * numWCtrlPoints * CoreTools::GetStreamSize(Mathematics::Vector3F{});

    size += CoreTools::GetStreamSize(numUSamples);
    size += CoreTools::GetStreamSize(numVSamples);
    size += CoreTools::GetStreamSize(numWSamples);
    size += CoreTools::GetStreamSize(doSort);

    return size;
}

const Mathematics::BSplineVolume<float>& Rendering::BoxSurface::GetVolume() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return *volume;
}

int Rendering::BoxSurface::GetNumUSamples() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return numUSamples;
}

int Rendering::BoxSurface::GetNumVSamples() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return numVSamples;
}

int Rendering::BoxSurface::GetNumWSamples() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return numWSamples;
}

CoreTools::ObjectInterfaceSharedPtr Rendering::BoxSurface::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
