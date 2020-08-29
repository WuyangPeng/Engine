// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/22 16:35)

#include "Rendering/RenderingExport.h"

#include "PickRecordImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26456)
Rendering::PickRecordImpl ::PickRecordImpl() noexcept
    : m_Intersected{}, m_Parameter{ 0.0f }, m_Triangle{ -1 }
{
    m_Bary[0] = 1.0f;
    m_Bary[1] = 0.0f;
    m_Bary[2] = 0.0f;

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::PickRecordImpl ::PickRecordImpl(const PickRecordImpl& rhs)
    : m_Intersected{ (rhs.m_Intersected == nullptr) ? ConstSpatialSmartPointer() : boost::polymorphic_pointer_cast<Spatial>(rhs.m_Intersected->Clone()) },
      m_Parameter{ rhs.m_Parameter }, m_Triangle{ rhs.m_Triangle }
{
    m_Bary[0] = rhs.m_Bary[0];
    m_Bary[1] = rhs.m_Bary[1];
    m_Bary[2] = rhs.m_Bary[2];

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::PickRecordImpl& Rendering::PickRecordImpl ::operator=(const PickRecordImpl& rhs)
{
    RENDERING_CLASS_IS_VALID_1;

    if (!rhs.m_Intersected)
    {
        m_Intersected.reset();
    }
    else
    {
        m_Intersected = boost::polymorphic_pointer_cast<Spatial>(rhs.m_Intersected->Clone());
    }

    m_Parameter = rhs.m_Parameter;
    m_Triangle = rhs.m_Triangle;

    m_Bary[0] = rhs.m_Bary[0];
    m_Bary[1] = rhs.m_Bary[1];
    m_Bary[2] = rhs.m_Bary[2];

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::PickRecordImpl ::IsValid() const noexcept
{
    try
    {
        if (-1 <= m_Triangle && 0.0f <= m_Bary[0] && m_Bary[0] <= 1.0f &&
            0.0f <= m_Bary[1] && m_Bary[1] <= 1.0f && 0.0f <= m_Bary[2] && m_Bary[2] <= 1.0f &&
            Mathematics::Mathf::Approximate(1.0f, m_Bary[0] + m_Bary[1] + m_Bary[2]))
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

float Rendering::PickRecordImpl ::GetParameter() const noexcept

{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Parameter;
}

void Rendering::PickRecordImpl ::SetParameter(float parameter) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    m_Parameter = parameter;
}

int Rendering::PickRecordImpl ::GetTriangle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Triangle;
}

void Rendering::PickRecordImpl ::SetTriangle(int triangle) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    m_Triangle = triangle;
}

float Rendering::PickRecordImpl ::GetBary(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_1(0 <= index && index < sm_BarySize, "索引越界");
    CoreTools::DoNothing();
    if (0 <= index && index < sm_BarySize)
    {
        return m_Bary[index];
    }
    else
    {
        return 0.0f;
    }
}

void Rendering::PickRecordImpl ::SetBary(float firstBary, float secondBary)
{
    RENDERING_CLASS_IS_VALID_1;
    CoreTools::DoNothing();
    RENDERING_ASSERTION_1(0.0f <= firstBary && firstBary <= 1.0f, "firstBary的取值在0.0和1.0之间");
    RENDERING_ASSERTION_1(0.0f <= secondBary && secondBary <= 1.0f, "secondBary的取值在0.0和1.0之间");

    m_Bary[0] = firstBary;
    m_Bary[1] = secondBary;
    m_Bary[2] = 1.0f - firstBary - secondBary;
}

Rendering::ConstSpatialSmartPointer Rendering::PickRecordImpl ::GetIntersected() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Intersected;
}

void Rendering::PickRecordImpl ::SetIntersected(const ConstSpatialSmartPointer& intersected) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    m_Intersected = intersected;
}

bool Rendering ::operator==(const PickRecordImpl& lhs, const PickRecordImpl& rhs) noexcept
{
    const auto lhsParameter = lhs.GetParameter();
    const auto rhsParameter = rhs.GetParameter();

    return memcmp(&lhsParameter, &rhsParameter, sizeof(float)) == 0;
}

bool Rendering ::operator<(const PickRecordImpl& lhs, const PickRecordImpl& rhs) noexcept
{
    return lhs.GetParameter() < rhs.GetParameter();
}

#include STSTEM_WARNING_POP