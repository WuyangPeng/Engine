///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
///	ÁªÏµ×÷Õß£º94458936@qq.com
///
///	±ê×¼£ºstd:c++20
///	°æ±¾£º0.9.1.2 (2023/07/24 16:11)

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
#include "Mathematics/Algebra/TransformDetail.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Rendering/RendererEngine/BaseRenderer.h"
#include "Rendering/Resources/Flags/DataFormatType.h"

Rendering::PointControllerImpl::PointControllerImpl(const BaseRendererSharedPtr& baseRenderer) noexcept
    : systemLinearSpeed{ 0.0f },
      systemAngularSpeed{ 0.0f },
      systemLinearAxis{ Mathematics::AVectorF::GetUnitZ() },
      systemAngularAxis{ Mathematics::AVectorF::GetUnitZ() },
      numPoints{},
      pointLinearSpeeds{},
      pointAngularSpeeds{},
      pointLinearAxes{},
      pointAngularAxes{},
      baseRenderer{ baseRenderer }
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
      pointAngularAxes{},
      baseRenderer{}
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

    auto size = CoreTools::GetStreamSize(systemLinearSpeed);

    size += CoreTools::GetStreamSize(systemAngularSpeed);
    size += Mathematics::GetStreamSize(systemLinearAxis);
    size += Mathematics::GetStreamSize(systemAngularAxis);
    size += CoreTools::GetStreamSize(numPoints);
    size += numPoints * CoreTools::GetStreamSize(pointLinearSpeeds.at(0));
    size += numPoints * CoreTools::GetStreamSize(pointAngularSpeeds.at(0));
    size += numPoints * Mathematics::GetStreamSize(pointLinearAxes.at(0));
    size += numPoints * Mathematics::GetStreamSize(pointAngularAxes.at(0));

    return size;
}

void Rendering::PointControllerImpl::SetControllerObject(Visual& visual)
{
    RENDERING_CLASS_IS_VALID_1;

    pointLinearSpeeds.clear();
    pointAngularSpeeds.clear();
    pointLinearAxes.clear();
    pointAngularAxes.clear();

    const auto indexBuffer = visual.GetIndexBuffer();

    if (const auto primitiveType = indexBuffer->GetPrimitiveType();
        primitiveType != IndexFormatType::PolyPoint)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Geometric primitive must be points."))
    }

    const auto vertexBuffer = visual.GetVertexBuffer();
    const auto vertexFormat = vertexBuffer->GetFormat();
    auto index = vertexFormat.GetIndex(VertexFormatFlags::Semantic::Position, 0);
    if (index < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Vertex format does not have VertexFormatFlags::Semantic::Position."))
    }

    if (const auto type = vertexFormat.GetAttributeType(index);
        type != DataFormatType::R32G32B32A32Float && type != DataFormatType::R32G32B32Float)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Invalid position type."))
    }

    if (const auto offset = vertexFormat.GetOffset(index);
        offset != 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Position offset must be 0."))
    }

    index = vertexFormat.GetIndex(VertexFormatFlags::Semantic::Normal, 0);
    if (index >= 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Invalid normal type."))
    }

    const auto count = vertexBuffer->GetNumElements();
    pointLinearSpeeds.resize(count);
    pointAngularSpeeds.resize(count);
    pointLinearAxes.resize(count);
    pointAngularAxes.resize(count);
    for (auto i = 0; i < count; ++i)
    {
        pointLinearSpeeds.at(i) = 0.0f;
        pointAngularSpeeds.at(i) = 0.0f;
        pointLinearAxes.at(i) = Mathematics::AVector<float>::GetUnitY();
        pointAngularAxes.at(i) = Mathematics::AVector<float>::GetUnitY();
    }
}

void Rendering::PointControllerImpl::UpdateSystemMotion(Visual& visual, float ctrlTime)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto distance = ctrlTime * systemLinearSpeed;
    const auto currentTrn = visual.GetLocalTransform().GetTranslate();
    const auto deltaTrn = distance * systemLinearAxis;
    visual.SetLocalTransformTranslate(currentTrn + deltaTrn);

    const auto angle = ctrlTime * systemAngularSpeed;
    const auto currentRot = visual.GetLocalTransform().GetRotate();
    const Mathematics::Matrix deltaRot{ systemAngularAxis, angle };
    visual.SetLocalTransformRotate(deltaRot * currentRot);
}

void Rendering::PointControllerImpl::UpdatePointMotion(Visual& visual, float ctrlTime)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto vertexBuffer = visual.GetVertexBuffer();
    const auto vertexFormat = vertexBuffer->GetFormat();
    const auto numVertices = vertexBuffer->GetNumElements();
    auto vertices = vertexBuffer->GetData();
    const auto vertexSize = vertexFormat.GetStride();

    for (auto i = 0; i < numVertices; ++i)
    {
        Mathematics::AVector<float> position{};
        position.SetX(vertices.Increase<float>());
        position.SetY(vertices.Increase<float>());
        position.SetZ(vertices.Increase<float>());

        const auto distance = ctrlTime * pointLinearSpeeds.at(i);
        const auto deltaTrn = distance * pointLinearAxes.at(i);
        position += deltaTrn;

        if (vertexSize > CoreTools::GetStreamSize<float>() * 3)
        {
            vertices += (vertexSize - CoreTools::GetStreamSize<float>() * 3);
        }
    }

    if (const auto index = vertexFormat.GetIndex(VertexFormatFlags::Semantic::Normal, 0);
        index >= 0)
    {
        const auto offset = vertexFormat.GetOffset(index);
        vertices = vertexBuffer->GetData(offset);
        for (auto i = 0; i < numVertices; ++i)
        {
            Mathematics::AVector<float> normal{};
            normal.SetX(vertices.Increase<float>());
            normal.SetY(vertices.Increase<float>());
            normal.SetZ(vertices.Increase<float>());
            normal.Normalize();

            const auto angle = ctrlTime * pointAngularSpeeds.at(i);
            const Mathematics::Matrix deltaRot{ pointAngularAxes.at(i), angle };
            normal = deltaRot * normal;
            if (vertexSize > CoreTools::GetStreamSize<float>() * 3)
            {
                vertices += (vertexSize - CoreTools::GetStreamSize<float>() * 3);
            }
        }
    }

    visual.UpdateModelBound();
    visual.UpdateModelNormals();
    MAYBE_UNUSED const auto result = baseRenderer.lock()->Update(vertexBuffer);
}
