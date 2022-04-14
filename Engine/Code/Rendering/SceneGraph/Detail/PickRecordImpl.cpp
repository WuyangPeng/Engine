///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/01 16:31)

#include "Rendering/RenderingExport.h"

#include "PickRecordImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::PickRecordImpl::PickRecordImpl() noexcept
    : intersected{}, parameter{ 0.0f }, triangle{ -1 }, bary{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::PickRecordImpl::PickRecordImpl(const PickRecordImpl& rhs)
    : intersected{ (rhs.intersected == nullptr) ? ConstSpatialSharedPtr() : boost::polymorphic_pointer_cast<Spatial>(rhs.intersected->Clone()) },
      parameter{ rhs.parameter },
      triangle{ rhs.triangle },
      bary{ rhs.bary }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::PickRecordImpl& Rendering::PickRecordImpl::operator=(const PickRecordImpl& rhs)
{
    RENDERING_CLASS_IS_VALID_1;

    if (!rhs.intersected)
    {
        intersected.reset();
    }
    else
    {
        intersected = boost::polymorphic_pointer_cast<Spatial>(rhs.intersected->Clone());
    }

    parameter = rhs.parameter;
    triangle = rhs.triangle;

    bary.at(0) = rhs.bary.at(0);
    bary.at(1) = rhs.bary.at(1);
    bary.at(2) = rhs.bary.at(2);

    return *this;
}

Rendering::PickRecordImpl& Rendering::PickRecordImpl::operator=(PickRecordImpl&& rhs) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    intersected = std::move(rhs.intersected);

    parameter = std::move(rhs.parameter);
    triangle = std::move(rhs.triangle);

    bary = std::move(rhs.bary);

    return *this;
}

Rendering::PickRecordImpl::PickRecordImpl(PickRecordImpl&& rhs) noexcept
    : intersected{ std::move(rhs.intersected) }, parameter{ std::move(rhs.parameter) }, triangle{ std::move(rhs.triangle) }, bary{ std::move(rhs.bary) }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::PickRecordImpl::IsValid() const noexcept
{
    try
    {
        if (-1 <= triangle &&
            0.0f <= bary.at(0) &&
            bary.at(0) <= 1.0f &&
            0.0f <= bary.at(1) &&
            bary.at(1) <= 1.0f &&
            0.0f <= bary.at(2) &&
            bary.at(2) <= 1.0f &&
            Mathematics::MathF::Approximate(1.0f, bary.at(0) + bary.at(1) + bary.at(2)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

float Rendering::PickRecordImpl::GetParameter() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return parameter;
}

void Rendering::PickRecordImpl::SetParameter(float aParameter) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    parameter = aParameter;
}

int Rendering::PickRecordImpl::GetTriangle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return triangle;
}

void Rendering::PickRecordImpl::SetTriangle(int aTriangle) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    triangle = aTriangle;
}

float Rendering::PickRecordImpl::GetBary(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_1(0 <= index && index < barySize, "索引越界");

    return bary.at(index);
}

void Rendering::PickRecordImpl::SetBary(float firstBary, float secondBary)
{
    RENDERING_CLASS_IS_VALID_1;

    RENDERING_ASSERTION_0(0.0f <= firstBary && firstBary <= 1.0f, "firstBary的取值在0.0和1.0之间");
    RENDERING_ASSERTION_0(0.0f <= secondBary && secondBary <= 1.0f, "secondBary的取值在0.0和1.0之间");

    bary.at(0) = firstBary;
    bary.at(1) = secondBary;
    bary.at(2) = 1.0f - firstBary - secondBary;
}

Rendering::ConstSpatialSharedPtr Rendering::PickRecordImpl::GetIntersected() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return intersected;
}

void Rendering::PickRecordImpl::SetIntersected(const ConstSpatialSharedPtr& aIntersected) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    intersected = aIntersected;
}

bool Rendering::operator==(const PickRecordImpl& lhs, const PickRecordImpl& rhs) noexcept
{
    const auto lhsParameter = lhs.GetParameter();
    const auto rhsParameter = rhs.GetParameter();

    return memcmp(&lhsParameter, &rhsParameter, sizeof(float)) == 0;
}

bool Rendering::operator<(const PickRecordImpl& lhs, const PickRecordImpl& rhs) noexcept
{
    return lhs.GetParameter() < rhs.GetParameter();
}
