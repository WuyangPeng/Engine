///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 17:06)

#ifndef MATHEMATICS_OBJECTS_3D_BOX3_DETAIL_H
#define MATHEMATICS_OBJECTS_3D_BOX3_DETAIL_H

#include "Box3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3Tools.h"

template <typename Real>
Mathematics::Box3<Real>::Box3() noexcept
    : center{}, epsilon{}, axis{}, extent{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Box3<Real>::Box3(const Vector3& center,
                              const Vector3& axis0,
                              const Vector3& axis1,
                              const Vector3& axis2,
                              const Real extent0,
                              const Real extent1,
                              const Real extent2,
                              const Real epsilon) noexcept
    : center{ center }, axis{ axis0, axis1, axis2 }, extent{ extent0, extent1, extent2 }, epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Box3<Real>::IsValid() const noexcept
{
    try
    {
    #include SYSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26446)

        if (axis[0].IsNormalize(epsilon) &&
            axis[1].IsNormalize(epsilon) &&
            axis[2].IsNormalize(epsilon) &&
            -epsilon <= extent[0] &&
            -epsilon <= extent[1] &&
            -epsilon <= extent[2] &&
            Math::GetValue(0) <= epsilon)

    #include SYSTEM_WARNING_POP
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

template <typename Real>
typename Mathematics::Box3<Real>::VerticesType Mathematics::Box3<Real>::ComputeVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto extAxis0 = GetAxis0() * GetExtent0();
    const auto extAxis1 = GetAxis1() * GetExtent1();
    const auto extAxis2 = GetAxis2() * GetExtent2();

    VerticesType vertex{ center - extAxis0 - extAxis1 - extAxis2,
                         center + extAxis0 - extAxis1 - extAxis2,
                         center + extAxis0 + extAxis1 - extAxis2,
                         center - extAxis0 + extAxis1 - extAxis2,
                         center - extAxis0 - extAxis1 + extAxis2,
                         center + extAxis0 - extAxis1 + extAxis2,
                         center + extAxis0 + extAxis1 + extAxis2,
                         center - extAxis0 + extAxis1 + extAxis2 };

    MATHEMATICS_ASSERTION_1(vertex.size() == 8, "返回的顶点数目不正确！");

    return vertex;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Box3<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return center;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Box3<Real>::GetAxis0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return axis[0];

#include SYSTEM_WARNING_POP
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Box3<Real>::GetAxis1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return axis[1];

#include SYSTEM_WARNING_POP
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Box3<Real>::GetAxis2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return axis[2];

#include SYSTEM_WARNING_POP
}

template <typename Real>
typename Mathematics::Box3<Real>::Vector3 Mathematics::Box3<Real>::GetAxis(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return axis.at(index);
}

template <typename Real>
Real Mathematics::Box3<Real>::GetExtent(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return extent.at(index);
}

template <typename Real>
Real Mathematics::Box3<Real>::GetExtent0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return extent[0];

#include SYSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::Box3<Real>::GetExtent1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return extent[1];

#include SYSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::Box3<Real>::GetExtent2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return extent[2];

#include SYSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::Box3<Real>::GetEpsilon() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return epsilon;
}

template <typename Real>
Mathematics::Box3<Real> Mathematics::Box3<Real>::GetMove(Real t, const Vector3& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Box3{ GetCenter() * t + velocity,
                 GetAxis0(),
                 GetAxis1(),
                 GetAxis2(),
                 GetExtent0(),
                 GetExtent1(),
                 GetExtent2(),
                 GetEpsilon() };
}

template <typename Real>
void Mathematics::Box3<Real>::Set(const Vector3& newCenter,
                                  const Vector3& axis0,
                                  const Vector3& axis1,
                                  const Vector3& axis2,
                                  const Real extent0,
                                  const Real extent1,
                                  const Real extent2) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    center = newCenter;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    axis[0] = axis0;
    axis[1] = axis1;
    axis[2] = axis2;
    extent[0] = extent0;
    extent[1] = extent1;
    extent[2] = extent2;

#include SYSTEM_WARNING_POP
}

template <typename Real>
bool Mathematics::Approximate(const Box3<Real>& lhs, const Box3<Real>& rhs, Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    return Vector3Tools<Real>::Approximate(lhs.GetCenter(), rhs.GetCenter(), epsilon) &&
           Vector3Tools<Real>::Approximate(lhs.GetAxis0(), rhs.GetAxis0(), epsilon) &&
           Vector3Tools<Real>::Approximate(lhs.GetAxis1(), rhs.GetAxis1(), epsilon) &&
           Vector3Tools<Real>::Approximate(lhs.GetAxis2(), rhs.GetAxis2(), epsilon) &&
           Math<Real>::Approximate(lhs.GetExtent0(), rhs.GetExtent0(), epsilon) &&
           Math<Real>::Approximate(lhs.GetExtent1(), rhs.GetExtent1(), epsilon) &&
           Math<Real>::Approximate(lhs.GetExtent2(), rhs.GetExtent2(), epsilon);
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& outFile, const Box3<Real>& box)
{
    outFile << "center=" << box.GetCenter()
            << ",axis0=" << box.GetAxis0()
            << ",axis1=" << box.GetAxis1()
            << ",axis2=" << box.GetAxis2()
            << "extent0=" << box.GetExtent0()
            << "extent1=" << box.GetExtent1()
            << "extent2=" << box.GetExtent2();

    return outFile;
}

#endif  // MATHEMATICS_OBJECTS_3D_BOX3_DETAIL_H
