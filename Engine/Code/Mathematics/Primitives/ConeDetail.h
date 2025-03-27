///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/29 09:54)

#ifndef MATHEMATICS_PRIMITIVES_CONE_DETAIL_H
#define MATHEMATICS_PRIMITIVES_CONE_DETAIL_H

#include "Cone.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/Matrix/MatrixDetail.h"
#include "Mathematics/Algebra/Vector/Vector3Detail.h"
#include "Mathematics/Meshes/UniqueVerticesSimplices.h"

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::Cone<N, Real>::Cone() noexcept requires(N == 3)
    : ray{ Vector{}, Vector{ Real{}, Real{}, MathType::GetValue(1) } },
      angle{ MathType::GetQuarterPI() },
      cosAngle{ MathType::Cos(angle) },
      sinAngle{ MathType::Sin(angle) },
      tanAngle{ MathType::Tan(angle) },
      cosAngleSqr{ cosAngle * cosAngle },
      sinAngleSqr{ sinAngle * sinAngle },
      invSinAngle{ MathType::GetValue(1) / sinAngle },
      minHeight{},
      maxHeight{ MathType::GetValue(-1) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::Cone<N, Real>::Cone(const RayType& ray, Real angle) noexcept
    : ray{ ray },
      angle{ angle },
      cosAngle{ MathType::Cos(angle) },
      sinAngle{ MathType::Sin(angle) },
      tanAngle{ MathType::Tan(angle) },
      cosAngleSqr{ cosAngle * cosAngle },
      sinAngleSqr{ sinAngle * sinAngle },
      invSinAngle{ MathType::GetValue(1) / sinAngle },
      minHeight{},
      maxHeight{ MathType::GetValue(-1) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::Cone<N, Real>::Cone(const RayType& ray, Real angle, Real minHeight) noexcept
    : ray{ ray },
      angle{ angle },
      cosAngle{ MathType::Cos(angle) },
      sinAngle{ MathType::Sin(angle) },
      tanAngle{ MathType::Tan(angle) },
      cosAngleSqr{ cosAngle * cosAngle },
      sinAngleSqr{ sinAngle * sinAngle },
      invSinAngle{ MathType::GetValue(1) / sinAngle },
      minHeight{ minHeight },
      maxHeight{ MathType::GetValue(-1) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::Cone<N, Real>::Cone(const RayType& ray, Real angle, Real minHeight, Real maxHeight) noexcept
    : ray{ ray },
      angle{ angle },
      cosAngle{ MathType::Cos(angle) },
      sinAngle{ MathType::Sin(angle) },
      tanAngle{ MathType::Tan(angle) },
      cosAngleSqr{ cosAngle * cosAngle },
      sinAngleSqr{ sinAngle * sinAngle },
      invSinAngle{ MathType::GetValue(1) / sinAngle },
      minHeight{ minHeight },
      maxHeight{ maxHeight }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Cone<N, Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::Cone<N, Real>::RayType Mathematics::Cone<N, Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ray;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::Cone<N, Real>::SetRay(const RayType& aRay) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    ray = aRay;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Real Mathematics::Cone<N, Real>::GetAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return angle;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::Cone<N, Real>::SetAngle(Real aAngle)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (aAngle <= Real{} || MathType::GetHalfPI() <= aAngle)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效角度"))
    }

    angle = aAngle;

    cosAngle = MathType::Cos(angle);
    sinAngle = MathType::Sin(angle);
    tanAngle = MathType::Tan(angle);
    cosAngleSqr = cosAngle * cosAngle;
    sinAngleSqr = sinAngle * sinAngle;
    invSinAngle = MathType::GetValue(1) / sinAngle;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Real Mathematics::Cone<N, Real>::GetCosAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return cosAngle;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Real Mathematics::Cone<N, Real>::GetSinAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return sinAngle;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Real Mathematics::Cone<N, Real>::GetTanAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return tanAngle;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Real Mathematics::Cone<N, Real>::GetCosAngleSqr() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return cosAngleSqr;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Real Mathematics::Cone<N, Real>::GetSinAngleSqr() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return sinAngleSqr;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Real Mathematics::Cone<N, Real>::GetInvSinAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return invSinAngle;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::Cone<N, Real>::MakeInfiniteCone() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    minHeight = Real{};
    maxHeight = MathType::GetValue(-1);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::Cone<N, Real>::MakeInfiniteTruncatedCone(Real aMinHeight)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (aMinHeight < Real{})
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效最小高度"))
    }

    minHeight = aMinHeight;
    maxHeight = MathType::GetValue(-1);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::Cone<N, Real>::MakeFiniteCone(Real aMaxHeight)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (aMaxHeight <= Real{})
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效最大高度"))
    }

    minHeight = Real{};
    maxHeight = aMaxHeight;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::Cone<N, Real>::MakeConeFrustum(Real aMinHeight, Real aMaxHeight)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (aMinHeight < Real{} || aMaxHeight <= aMinHeight)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效最小或最大高度"))
    }

    minHeight = aMinHeight;
    maxHeight = aMaxHeight;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Real Mathematics::Cone<N, Real>::GetMinHeight() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minHeight;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Real Mathematics::Cone<N, Real>::GetMaxHeight() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return maxHeight;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Cone<N, Real>::HeightInRange(Real h) const noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minHeight <= h && (!MathType::Approximate(maxHeight, MathType::GetValue(-1)) ? h <= maxHeight : true);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Cone<N, Real>::HeightLessThanMin(Real h) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return h < minHeight;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Cone<N, Real>::HeightGreaterThanMax(Real h) const noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (!MathType::Approximate(maxHeight, MathType::GetValue(-1)) ? maxHeight < h : false);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Cone<N, Real>::IsFinite() const noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return !MathType::Approximate(maxHeight, MathType::GetValue(-1));
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Cone<N, Real>::IsInfinite() const noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return MathType::Approximate(maxHeight, MathType::GetValue(-1));
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::Cone<N, Real>::CreateMesh(int numMinVertices, bool inscribed, Vector3Container& vertices, IndicesContainer& indices) requires(N == 3)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (!IsFinite())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无限圆锥无法生成网格"))
    }

    const auto hMin = GetMinHeight();
    const auto hMax = GetMaxHeight();
    const auto rMin = hMin * tanAngle;
    const auto rMax = hMax * tanAngle;
    const auto tNumExtra = MathType::GetRational(1, 2) * rMax / rMin - MathType::GetValue(1);
    auto numExtra = 0;
    if (Real{} < tNumExtra)
    {
        numExtra = boost::numeric_cast<int>(MathType::Ceil(tNumExtra));
    }
    const auto numMaxVertices = 2 * numMinVertices * (1 + numExtra);
    vertices.clear();
    indices.clear();

    Vector2Container polygonMin{};
    Vector2Container polygonMax{};
    if (inscribed)
    {
        GenerateInscribed(numMinVertices, rMin, polygonMin);
        GenerateInscribed(numMaxVertices, rMax, polygonMax);
    }
    else
    {
        GenerateCircumscribed(numMinVertices, rMin, polygonMin);
        GenerateCircumscribed(numMaxVertices, rMax, polygonMax);
    }

    if (Real{} < hMin)
    {
        CreateConeFrustumMesh(numMinVertices, numMaxVertices, numExtra, hMin, hMax, polygonMin, polygonMax, vertices, indices);
    }
    else
    {
        // TODO:
        // CreateFiniteTruncatedConeMesh(numMaxVertices, numExtra, hMax, polygonMax, vertices, indices);
    }

    /// 变换到圆锥体的坐标系。
    Vector3Container basis(3);
    basis.at(0) = ray.GetDirection();
    ComputeOrthogonalComplement(1, basis);
    Algebra::Matrix<3, 3, Real> rotate{};
    rotate.SetColumn(0, basis.at(1));
    rotate.SetColumn(1, basis.at(2));
    rotate.SetColumn(2, basis.at(0));
    for (auto i = 0u; i < vertices.size(); ++i)
    {
        vertices.at(i) = rotate * vertices.at(i) + ray.GetOrigin();
    }
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::Cone<N, Real>::GenerateInscribed(int numVertices, Real radius, Vector2Container& polygon) requires(N == 3)
{
    const auto theta = MathType::GetTwoPI() / boost::numeric_cast<Real>(numVertices);
    polygon.clear();
    for (auto i = 0; i < numVertices; ++i)
    {
        const auto angleTheta = boost::numeric_cast<Real>(i) * theta;
        polygon.emplace_back(radius * MathType::Cos(angleTheta), radius * MathType::Sin(angleTheta));
    }
    polygon.emplace_back(polygon.at(0));
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::Cone<N, Real>::GenerateCircumscribed(int numVertices, Real radius, Vector2Container& polygon) requires(N == 3)
{
    const auto theta = MathType::GetTwoPI() / boost::numeric_cast<Real>(numVertices);
    Vector2Container inscribed{};
    for (auto i = 0; i < numVertices; ++i)
    {
        const auto angleTheta = boost::numeric_cast<Real>(i) * theta;
        inscribed.emplace_back(radius * MathType::Cos(angleTheta), radius * MathType::Sin(angleTheta));
    }
    inscribed.emplace_back(inscribed.at(0));

    const auto divisor = MathType::GetValue(1) + MathType::Cos(theta);
    polygon.clear();
    for (auto i = 0, ip1 = 1; i < numVertices; ++i, ++ip1)
    {
        polygon.emplace_back((inscribed.at(i) + inscribed.at(ip1)) / divisor);
    }
    polygon.emplace_back(polygon.at(0));
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::Cone<N, Real>::CreateConeFrustumMesh(int numMinVertices,
                                                       int numMaxVertices,
                                                       int numExtra,
                                                       Real hMin,
                                                       Real hMax,
                                                       const Vector2Container& polygonMin,
                                                       const Vector2Container& polygonMax,
                                                       Vector3Container& vertices,
                                                       IndicesContainer& indices) requires(N == 3)
{
    Vector3Container vertexPool{};

    for (auto i0 = 0, i1 = 1; i0 < numMinVertices; i0 = i1++)
    {
        const auto j0 = 2 * (numExtra + 1) * i0;
        auto v0 = HomogeneousLift(polygonMin.at(i0), hMin);
        for (auto k0 = 0, k1 = 1; k0 <= numExtra; k0 = k1++)
        {
            const auto v1 = HomogeneousLift(polygonMax.at(System::GetPlus(j0, k1)), hMax);
            const auto v2 = HomogeneousLift(polygonMax.at(System::GetPlus(j0, k0)), hMax);
            vertexPool.emplace_back(v0);
            vertexPool.emplace_back(v1);
            vertexPool.emplace_back(v2);
        }

        const auto j1 = 2 * (numExtra + 1) * i1;
        v0 = HomogeneousLift(polygonMin.at(i1), hMin);
        for (auto k0 = 0, k1 = 1; k0 <= numExtra; k0 = k1++)
        {
            const auto v1 = HomogeneousLift(polygonMax.at(System::GetMinus(j1, k0)), hMax);
            const auto v2 = HomogeneousLift(polygonMax.at(System::GetMinus(j1, k1)), hMax);
            vertexPool.emplace_back(v0);
            vertexPool.emplace_back(v1);
            vertexPool.emplace_back(v2);
        }

        const auto jMid = j0 + (numExtra + 1);
        v0 = HomogeneousLift(polygonMax.at(jMid), hMax);
        const auto v1 = HomogeneousLift(polygonMin.at(i0), hMin);
        const auto v2 = HomogeneousLift(polygonMin.at(i1), hMin);
        vertexPool.emplace_back(v0);
        vertexPool.emplace_back(v1);
        vertexPool.emplace_back(v2);
    }

    Vector3 v0{ Real{}, Real{}, hMin };
    for (auto i0 = 0, i1 = 1; i0 < numMinVertices; i0 = i1++)
    {
        const auto v1 = HomogeneousLift(polygonMin.at(i1), hMin);
        const auto v2 = HomogeneousLift(polygonMin.at(i0), hMin);
        vertexPool.emplace_back(v0);
        vertexPool.emplace_back(v1);
        vertexPool.emplace_back(v2);
    }

    v0 = { Real{}, Real{}, hMax };
    for (auto i0 = 0, i1 = 1; i0 < numMaxVertices; i0 = i1++)
    {
        const auto v1 = HomogeneousLift(polygonMax.at(i0), hMax);
        const auto v2 = HomogeneousLift(polygonMax.at(i1), hMax);
        vertexPool.emplace_back(v0);
        vertexPool.emplace_back(v1);
        vertexPool.emplace_back(v2);
    }

    UniqueVerticesSimplices<Vector3, int, 3>::GenerateIndexedSimplices(vertexPool, vertices, indices);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator==(const Cone<N, Real>& lhs, const Cone<N, Real>& rhs)
{
    return lhs.GetRay() == rhs.GetRay() && lhs.GetAngle() == rhs.GetAngle() && lhs.GetMinHeight() == rhs.GetMinHeight() && lhs.GetMaxHeight() == rhs.GetMaxHeight();
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator!=(const Cone<N, Real>& lhs, const Cone<N, Real>& rhs)
{
    return !(lhs == rhs);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator<(const Cone<N, Real>& lhs, const Cone<N, Real>& rhs)
{
    if (lhs.GetRay() < rhs.GetRay())
    {
        return true;
    }

    if (rhs.GetRay() < lhs.GetRay())
    {
        return false;
    }

    if (lhs.GetAngle() < rhs.GetAngle())
    {
        return true;
    }

    if (rhs.GetAngle() < lhs.GetAngle())
    {
        return false;
    }

    if (lhs.GetMinHeight() < rhs.GetMinHeight())
    {
        return true;
    }

    if (rhs.GetMinHeight() < lhs.GetMinHeight())
    {
        return false;
    }

    return lhs.GetMaxHeight() < rhs.GetMaxHeight();
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator<=(const Cone<N, Real>& lhs, const Cone<N, Real>& rhs)
{
    return !(rhs < lhs);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator>(const Cone<N, Real>& lhs, const Cone<N, Real>& rhs)
{
    return rhs < lhs;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator>=(const Cone<N, Real>& lhs, const Cone<N, Real>& rhs)
{
    return !(lhs < rhs);
}

#endif  // MATHEMATICS_PRIMITIVES_CONE_DETAIL_H
