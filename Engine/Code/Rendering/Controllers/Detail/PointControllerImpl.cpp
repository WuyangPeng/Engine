///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
///	ÁªÏµ×÷Õß£º94458936@qq.com
///
///	±ê×¼£ºstd:c++20
///	ÒýÇæ°æ±¾£º0.8.0.6 (2022/04/06 16:24)

#include "Rendering/RenderingExport.h"

#include "PointControllerImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "Mathematics/Algebra/AlgebraAggregate.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Rendering/DataTypes/SpecializedIO.h"

using std::vector;

Rendering::PointControllerImpl::PointControllerImpl(int numPoints)
    : systemLinearSpeed{ 0.0f },
      systemAngularSpeed{ 0.0f },
      systemLinearAxis{ Mathematics::AVectorF::GetUnitZ() },
      systemAngularAxis{ Mathematics::AVectorF::GetUnitZ() },
      numPoints{ numPoints },
      pointLinearSpeeds(numPoints),
      pointAngularSpeeds(numPoints),
      pointLinearAxes(numPoints),
      pointAngularAxes(numPoints)
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::PointControllerImpl::PointControllerImpl() noexcept
    : systemLinearSpeed{ 0.0f },
      systemAngularSpeed{ 0.0f },
      systemLinearAxis{ Mathematics::AVectorF::GetUnitZ() },
      systemAngularAxis{ Mathematics::AVectorF::GetUnitZ() },
      numPoints{ 0 },
      pointLinearSpeeds{},
      pointAngularSpeeds{},
      pointLinearAxes{},
      pointAngularAxes{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::PointControllerImpl::IsValid() const noexcept
{
    if (0 <= numPoints)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int Rendering::PointControllerImpl::GetNumPoints() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numPoints;
}

float Rendering::PointControllerImpl::GetPointLinearSpeed(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= index && index < numPoints, "Ë÷Òý´íÎó£¡");

    return pointLinearSpeeds.at(index);
}

float Rendering::PointControllerImpl::GetPointAngularSpeed(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= index && index < numPoints, "Ë÷Òý´íÎó£¡");

    return pointAngularSpeeds.at(index);
}

Rendering::PointControllerImpl::AVector Rendering::PointControllerImpl::GetPointLinearAxis(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= index && index < numPoints, "Ë÷Òý´íÎó£¡");

    return pointLinearAxes.at(index);
}

Rendering::PointControllerImpl::AVector Rendering::PointControllerImpl::GetPointAngularAxis(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= index && index < numPoints, "Ë÷Òý´íÎó£¡");

    return pointAngularAxes.at(index);
}

void Rendering::PointControllerImpl::SetPointLinearSpeed(int index, float pointLinearSpeed)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= index && index < numPoints, "Ë÷Òý´íÎó£¡");

    pointLinearSpeeds.at(index) = pointLinearSpeed;
}

void Rendering::PointControllerImpl::SetPointAngularSpeed(int index, float pointAngularSpeed)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= index && index < numPoints, "Ë÷Òý´íÎó£¡");

    pointAngularSpeeds.at(index) = pointAngularSpeed;
}

void Rendering::PointControllerImpl::SetPointLinearAxis(int index, const AVector& pointLinearAxis)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= index && index < numPoints, "Ë÷Òý´íÎó£¡");

    pointLinearAxes.at(index) = pointLinearAxis;
}

void Rendering::PointControllerImpl::SetPointAngularAxis(int index, const AVector& pointAngularAxis)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= index && index < numPoints, "Ë÷Òý´íÎó£¡");

    pointAngularAxes.at(index) = pointAngularAxis;
}

float Rendering::PointControllerImpl::GetSystemLinearSpeed() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return systemLinearSpeed;
}

void Rendering::PointControllerImpl::SetSystemLinearSpeed(float aSystemLinearSpeed) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    systemLinearSpeed = aSystemLinearSpeed;
}

float Rendering::PointControllerImpl::GetSystemAngularSpeed() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return systemAngularSpeed;
}

void Rendering::PointControllerImpl::SetSystemAngularSpeed(float aSystemAngularSpeed) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    systemAngularSpeed = aSystemAngularSpeed;
}

Rendering::PointControllerImpl::AVector Rendering::PointControllerImpl::GetSystemLinearAxis() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return systemLinearAxis;
}

void Rendering::PointControllerImpl::SetSystemLinearAxis(const AVector& aSystemLinearAxis) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    systemLinearAxis = aSystemLinearAxis;
}

Rendering::PointControllerImpl::AVector Rendering::PointControllerImpl::GetSystemAngularAxis() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return systemAngularAxis;
}

void Rendering::PointControllerImpl::SetSystemAngularAxis(const AVector& aSystemAngularAxis) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    systemAngularAxis = aSystemAngularAxis;
}

void Rendering::PointControllerImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.Read(systemLinearSpeed);
    source.Read(systemAngularSpeed);
    source.ReadAggregate(systemLinearAxis);
    source.ReadAggregate(systemAngularAxis);
    source.Read(numPoints);

    pointLinearSpeeds.resize(numPoints);
    pointAngularSpeeds.resize(numPoints);
    pointLinearAxes.resize(numPoints);
    pointAngularAxes.resize(numPoints);

    source.ReadContainer(pointLinearSpeeds);
    source.ReadContainer(pointAngularSpeeds);
    source.ReadAggregateContainer(numPoints, pointLinearAxes);
    source.ReadAggregateContainer(numPoints, pointAngularAxes);
}

void Rendering::PointControllerImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.Write(systemLinearSpeed);
    target.Write(systemAngularSpeed);
    target.WriteAggregate(systemLinearAxis);
    target.WriteAggregate(systemAngularAxis);
    target.Write(numPoints);
    target.WriteContainerWithoutNumber(pointLinearSpeeds);
    target.WriteContainerWithoutNumber(pointAngularSpeeds);
    target.WriteAggregateContainerWithoutNumber(pointLinearAxes);
    target.WriteAggregateContainerWithoutNumber(pointAngularAxes);
}

int Rendering::PointControllerImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = CORE_TOOLS_STREAM_SIZE(systemLinearSpeed);

    size += CORE_TOOLS_STREAM_SIZE(systemAngularSpeed);
    size += MATHEMATICS_STREAM_SIZE(systemLinearAxis);
    size += MATHEMATICS_STREAM_SIZE(systemAngularAxis);
    size += CORE_TOOLS_STREAM_SIZE(numPoints);
    size += numPoints * CORE_TOOLS_STREAM_SIZE(pointLinearSpeeds.at(0));
    size += numPoints * CORE_TOOLS_STREAM_SIZE(pointAngularSpeeds.at(0));
    size += numPoints * MATHEMATICS_STREAM_SIZE(pointLinearAxes.at(0));
    size += numPoints * MATHEMATICS_STREAM_SIZE(pointAngularAxes.at(0));

    return size;
}
