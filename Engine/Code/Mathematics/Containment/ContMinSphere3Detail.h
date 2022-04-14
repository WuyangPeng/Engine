///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/11 14:58)

#ifndef MATHEMATICS_CONTAINMENT_CONT_MIN_SPHERE3_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_MIN_SPHERE3_DETAIL_H

#include "ContMinSphere3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::ContMinSphere3<Real>::ContMinSphere3(const std::vector<Vector3<Real>>& points, Sphere3<Real>& minimal, Real epsilon)
    : epsilon{ epsilon }, update{ nullptr, &ContMinSphere3<Real>::UpdateSupport1, &ContMinSphere3<Real>::UpdateSupport2, &ContMinSphere3<Real>::UpdateSupport3, &ContMinSphere3<Real>::UpdateSupport4 }
{
    Support support{};
    Real distDiff{};

    const auto numPoints = boost::numeric_cast<int>(points.size());

    if (numPoints >= 1)
    {
        std::vector<Vector3<Real>> permuted(numPoints);

        for (auto i = 0; i < numPoints; ++i)
        {
            permuted.at(i) = points.at(i);
        }

        for (auto i = numPoints - 1; i > 0; --i)
        {
            const auto j = rand() % (i + 1);
            if (j != i)
            {
                Vector3<Real> save = permuted.at(i);
                permuted.at(i) = permuted.at(j);
                permuted.at(j) = save;
            }
        }

        minimal = ExactSphere1(permuted.at(0));
        support.quantity = 1;
        support.index.at(0) = 0;

        for (auto i = 1 % numPoints, n = 0; i != n; i = (i + 1) % numPoints)
        {
            if (!support.Contains(i, permuted, epsilon))
            {
                if (!Contains(permuted.at(i), minimal, distDiff))
                {
                    auto updateFunction = update.at(support.quantity);
                    if (updateFunction != nullptr)
                    {
                        Sphere3<Real> sphere{};
                        sphere = (this->*updateFunction)(i, permuted, support);
                        if (sphere.GetRadius() > minimal.GetRadius())
                        {
                            minimal = sphere;
                            n = i;
                        }
                    }
                }
            }
        }
    }
    else
    {
        MATHEMATICS_ASSERTION_0(false, "输入必须包含点。\n");
    }

    minimal.SetSphere(minimal.GetCenter(), Math<Real>::Sqrt(minimal.GetRadius()));

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::ContMinSphere3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::ContMinSphere3<Real>::Contains(const Vector3<Real>& point, const Sphere3<Real>& sphere, Real& distDiff)
{
    auto diff = point - sphere.GetCenter();
    auto test = Vector3Tools<Real>::GetLengthSquared(diff);

    distDiff = test - sphere.GetRadius();

    return distDiff <= Math<Real>::GetValue(0);
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::ContMinSphere3<Real>::ExactSphere1(const Vector3<Real>& p) noexcept
{
    Sphere3<Real> minimal{ p, Math<Real>::GetValue(0) };

    return minimal;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::ContMinSphere3<Real>::ExactSphere2(const Vector3<Real>& p0, const Vector3<Real>& p1)
{
    auto diff = p1 - p0;
    Sphere3<Real> minimal{ Math<Real>::GetRational(1, 2) * (p0 + p1), Math<Real>::GetRational(1, 4) * Vector3Tools<Real>::GetLengthSquared(diff) };

    return minimal;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::ContMinSphere3<Real>::ExactSphere3(const Vector3<Real>& p0, const Vector3<Real>& p1, const Vector3<Real>& p2)
{
    auto a = p0 - p2;
    auto b = p1 - p2;
    auto ada = Vector3Tools<Real>::DotProduct(a, a);
    auto adb = Vector3Tools<Real>::DotProduct(a, b);
    auto bdb = Vector3Tools<Real>::DotProduct(b, b);
    auto det = ada * bdb - adb * adb;

    Vector3<Real> center{};
    Real radius{};
    if (Math<Real>::FAbs(det) > Math<Real>::GetValue(0))
    {
        Real m00{};
        Real m01{};
        Real m10{};
        Real m11{};
        Real d0{};
        Real d1{};
        if (ada >= bdb)
        {
            m00 = Math<Real>::GetValue(1);
            m01 = adb / ada;
            m10 = m01;
            m11 = bdb / ada;
            d0 = Math<Real>::GetRational(1, 2);
            d1 = Math<Real>::GetRational(1, 2) * m11;
        }
        else
        {
            m00 = ada / bdb;
            m01 = adb / bdb;
            m10 = m01;
            m11 = Math<Real>::GetValue(1);
            d0 = Math<Real>::GetRational(1, 2) * m00;
            d1 = Math<Real>::GetRational(1, 2);
        }
        auto invDet = (Math<Real>::GetValue(1)) / (m00 * m11 - m01 * m10);
        auto u0 = invDet * (m11 * d0 - m01 * d1);
        auto u1 = invDet * (m00 * d1 - m10 * d0);
        auto u2 = Math<Real>::GetValue(1) - u0 - u1;
        center = u0 * p0 + u1 * p1 + u2 * p2;
        auto tmp = u0 * a + u1 * b;
        radius = Vector3Tools<Real>::GetLengthSquared(tmp);
    }
    else
    {
        center = Vector3<Real>::GetZero();
        radius = Math<Real>::maxReal;
    }

    Sphere3<Real> minimal{ center, radius };

    return minimal;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::ContMinSphere3<Real>::ExactSphere4(const Vector3<Real>& p0, const Vector3<Real>& p1, const Vector3<Real>& p2, const Vector3<Real>& p3)
{
    auto a = p0 - p3;
    auto b = p1 - p3;
    auto c = p2 - p3;
    const Matrix3<Real> m{ a, b, c, MatrixMajorFlags::Row };
    Vector3<Real> d{ Vector3Tools<Real>::DotProduct(a, a),
                     Vector3Tools<Real>::DotProduct(b, b),
                     Vector3Tools<Real>::DotProduct(c, c) };
    d *= Math<Real>::GetRational(1, 2);

    const auto invM = m.Inverse(epsilon);

    Vector3<Real> center{};
    Real radius{};
    if (!Approximate(invM, Matrix3<Real>::GetZero()))
    {
        const auto v = d * invM;
        auto u = invM * v;
        auto u3 = Math<Real>::GetValue(1) - u[0] - u[1] - u[2];
        center = u[0] * p0 + u[1] * p1 + u[2] * p2 + u3 * p3;
        auto tmp = u[0] * a + u[1] * b + u[2] * c;
        radius = Vector3Tools<Real>::GetLengthSquared(tmp);
    }
    else
    {
        center = Vector3<Real>::GetZero();
        radius = Math<Real>::maxReal;
    }

    Sphere3<Real> minimal{ center, radius };
    return minimal;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::ContMinSphere3<Real>::UpdateSupport1(int i, const std::vector<Vector3<Real>>& permuted, Support& support)
{
    const auto& P0 = permuted.at(support.index.at(0));
    const auto& P1 = permuted.at(i);

    auto minimal = ExactSphere2(P0, P1);
    support.quantity = 2;
    support.index.at(1) = i;

    return minimal;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::ContMinSphere3<Real>::UpdateSupport2(int i, const std::vector<Vector3<Real>>& permuted, Support& support)
{
    const std::array<Vector3<Real>, 2> point{ permuted.at(support.index.at(0)), permuted.at(support.index.at(1)) };
    const auto& p2 = permuted.at(i);

    constexpr auto numType2 = 2;

    const std::array<std::array<int, 2>, numType2> type2{ std::array<int, 2>{ 0, 1 }, std::array<int, 2>{ 1, 0 } };

    constexpr auto numType3 = 1;

    std::array<Sphere3<Real>, numType2 + numType3> sphere{};
    auto indexSphere = 0;
    auto minRSqr = Math<Real>::maxReal;
    auto indexMinRSqr = -1;
    Real distDiff{};
    auto minDistDiff = Math<Real>::maxReal;
    auto indexMinDistDiff = -1;

    for (auto j = 0; j < numType2; ++j, ++indexSphere)
    {
        sphere.at(indexSphere) = ExactSphere2(point.at(type2.at(j).at(0)), p2);
        if (sphere.at(indexSphere).GetRadius() < minRSqr)
        {
            if (Contains(point.at(type2.at(j).at(1)), sphere.at(indexSphere), distDiff))
            {
                minRSqr = sphere.at(indexSphere).GetRadius();
                indexMinRSqr = indexSphere;
            }
            else if (distDiff < minDistDiff)
            {
                minDistDiff = distDiff;
                indexMinDistDiff = indexSphere;
            }
        }
    }

    sphere.at(indexSphere) = ExactSphere3(point.at(0), point.at(1), p2);
    if (sphere.at(indexSphere).GetRadius() < minRSqr)
    {
        minRSqr = sphere.at(indexSphere).GetRadius();
        indexMinRSqr = indexSphere;
    }

    if (indexMinRSqr == -1)
    {
        indexMinRSqr = indexMinDistDiff;
    }

    auto minimal = sphere.at(indexMinRSqr);
    switch (indexMinRSqr)
    {
        case 0:
            support.index.at(1) = i;
            break;
        case 1:
            support.index.at(0) = i;
            break;
        case 2:
            support.quantity = 3;
            support.index.at(2) = i;
            break;
        default:
            break;
    }

    return minimal;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::ContMinSphere3<Real>::UpdateSupport3(int i, const std::vector<Vector3<Real>>& permuted, Support& support)
{
    const std::array<Vector3<Real>, 3> point{ permuted.at(support.index.at(0)), permuted.at(support.index.at(1)), permuted.at(support.index.at(2)) };
    const auto& p3 = permuted.at(i);

    constexpr auto numType2 = 3;
    const std::array<std::array<int, 3>, numType2> type2{ std::array<int, 3>{ 0, 1, 2 }, std::array<int, 3>{ 1, 0, 2 }, std::array<int, 3>{ 2, 0, 1 } };

    constexpr auto numType3 = 3;
    const std::array<std::array<int, 3>, numType3> type3{ std::array<int, 3>{ 0, 1, 2 }, std::array<int, 3>{ 0, 2, 1 }, std::array<int, 3>{ 1, 2, 0 } };

    constexpr auto numType4 = 1;

    std::array<Sphere3<Real>, numType2 + numType3 + numType4> sphere{};
    auto indexSphere = 0;
    auto minRSqr = Math<Real>::maxReal;
    auto indexMinRSqr = -1;
    Real distDiff{};
    auto minDistDiff = Math<Real>::maxReal;
    auto indexMinDistDiff = -1;

    for (auto j = 0; j < numType2; ++j, ++indexSphere)
    {
        sphere.at(indexSphere) = ExactSphere2(point.at(type2.at(j).at(0)), p3);
        if (sphere.at(indexSphere).GetRadius() < minRSqr)
        {
            if (Contains(point.at(type2.at(j).at(1)), sphere.at(indexSphere), distDiff) && Contains(point.at(type2.at(j).at(2)), sphere.at(indexSphere), distDiff))
            {
                minRSqr = sphere.at(indexSphere).GetRadius();
                indexMinRSqr = indexSphere;
            }
            else if (distDiff < minDistDiff)
            {
                minDistDiff = distDiff;
                indexMinDistDiff = indexSphere;
            }
        }
    }

    for (auto j = 0; j < numType3; ++j, ++indexSphere)
    {
        sphere.at(indexSphere) = ExactSphere3(point.at(type3.at(j).at(0)), point.at(type3.at(j).at(1)), p3);
        if (sphere.at(indexSphere).GetRadius() < minRSqr)
        {
            if (Contains(point.at(type3.at(j).at(2)), sphere.at(indexSphere), distDiff))
            {
                minRSqr = sphere.at(indexSphere).GetRadius();
                indexMinRSqr = indexSphere;
            }
            else if (distDiff < minDistDiff)
            {
                minDistDiff = distDiff;
                indexMinDistDiff = indexSphere;
            }
        }
    }

    sphere.at(indexSphere) = ExactSphere4(point.at(0), point.at(1), point.at(2), p3);
    if (sphere.at(indexSphere).GetRadius() < minRSqr)
    {
        minRSqr = sphere.at(indexSphere).GetRadius();
        indexMinRSqr = indexSphere;
    }

    if (indexMinRSqr == -1)
    {
        indexMinRSqr = indexMinDistDiff;
    }

    auto minimal = sphere.at(indexMinRSqr);
    switch (indexMinRSqr)
    {
        case 0:
            support.quantity = 2;
            support.index.at(1) = i;
            break;
        case 1:
            support.quantity = 2;
            support.index.at(0) = i;
            break;
        case 2:
            support.quantity = 2;
            support.index.at(0) = support.index.at(2);
            support.index.at(1) = i;
            break;
        case 3:
            support.index.at(2) = i;
            break;
        case 4:
            support.index.at(1) = i;
            break;
        case 5:
            support.index.at(0) = i;
            break;
        case 6:
            support.quantity = 4;
            support.index.at(3) = i;
            break;
        default:
            break;
    }

    return minimal;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::ContMinSphere3<Real>::UpdateSupport4(int i, const std::vector<Vector3<Real>>& permuted, Support& support)
{
    const std::array<Vector3<Real>, 4> point{ permuted.at(support.index.at(0)),
                                              permuted.at(support.index.at(1)),
                                              permuted.at(support.index.at(2)),
                                              permuted.at(support.index.at(3)) };
    const Vector3<Real>& p4 = permuted.at(i);

    constexpr auto numType2 = 4;
    const std::array<std::array<int, 4>, numType2> type2{ std::array<int, 4>{ 0, 1, 2, 3 },
                                                          std::array<int, 4>{ 1, 0, 2, 3 },
                                                          std::array<int, 4>{ 2, 0, 1, 3 },
                                                          std::array<int, 4>{ 3, 0, 1, 2 } };

    constexpr auto numType3 = 6;
    const std::array<std::array<int, 4>, numType3> type3{ std::array<int, 4>{ 0, 1, 2, 3 },
                                                          std::array<int, 4>{ 0, 2, 1, 3 },
                                                          std::array<int, 4>{ 0, 3, 1, 2 },
                                                          std::array<int, 4>{ 1, 2, 0, 3 },
                                                          std::array<int, 4>{ 1, 3, 0, 2 },
                                                          std::array<int, 4>{ 2, 3, 0, 1 } };

    constexpr auto numType4 = 4;
    const std::array<std::array<int, 4>, numType4> type4{ std::array<int, 4>{ 0, 1, 2, 3 },
                                                          std::array<int, 4>{ 0, 1, 3, 2 },
                                                          std::array<int, 4>{ 0, 2, 3, 1 },
                                                          std::array<int, 4>{ 1, 2, 3, 0 } };

    std::array<Sphere3<Real>, numType2 + numType3 + numType4> sphere{};
    auto indexSphere = 0;
    auto minRSqr = Math<Real>::maxReal;
    auto indexMinRSqr = -1;
    Real distDiff{};
    auto minDistDiff = Math<Real>::maxReal;
    auto indexMinDistDiff = -1;

    for (auto j = 0; j < numType2; ++j, ++indexSphere)
    {
        sphere.at(indexSphere) = ExactSphere2(point.at(type2.at(j).at(0)), p4);
        if (sphere.at(indexSphere).GetRadius() < minRSqr)
        {
            if (Contains(point.at(type2.at(j).at(1)), sphere.at(indexSphere), distDiff) && Contains(point.at(type2.at(j).at(2)), sphere.at(indexSphere), distDiff) && Contains(point.at(type2.at(j).at(3)), sphere.at(indexSphere), distDiff))
            {
                minRSqr = sphere.at(indexSphere).GetRadius();
                indexMinRSqr = indexSphere;
            }
            else if (distDiff < minDistDiff)
            {
                minDistDiff = distDiff;
                indexMinDistDiff = indexSphere;
            }
        }
    }

    for (auto j = 0; j < numType3; ++j, ++indexSphere)
    {
        sphere.at(indexSphere) = ExactSphere3(point.at(type3.at(j).at(0)), point.at(type3.at(j).at(1)), p4);
        if (sphere.at(indexSphere).GetRadius() < minRSqr)
        {
            if (Contains(point.at(type3.at(j).at(2)), sphere.at(indexSphere), distDiff) && Contains(point.at(type3.at(j).at(3)), sphere.at(indexSphere), distDiff))
            {
                minRSqr = sphere.at(indexSphere).GetRadius();
                indexMinRSqr = indexSphere;
            }
            else if (distDiff < minDistDiff)
            {
                minDistDiff = distDiff;
                indexMinDistDiff = indexSphere;
            }
        }
    }

    for (auto j = 0; j < numType4; ++j, ++indexSphere)
    {
        sphere.at(indexSphere) = ExactSphere4(point.at(type4.at(j).at(0)), point.at(type4.at(j).at(1)), point.at(type4.at(j).at(2)), p4);
        if (sphere.at(indexSphere).GetRadius() < minRSqr)
        {
            if (Contains(point.at(type4.at(j).at(3)), sphere.at(indexSphere), distDiff))
            {
                minRSqr = sphere.at(indexSphere).GetRadius();
                indexMinRSqr = indexSphere;
            }
            else if (distDiff < minDistDiff)
            {
                minDistDiff = distDiff;
                indexMinDistDiff = indexSphere;
            }
        }
    }

    if (indexMinRSqr == -1)
    {
        indexMinRSqr = indexMinDistDiff;
    }

    auto minimal = sphere.at(indexMinRSqr);
    switch (indexMinRSqr)
    {
        case 0:
            support.quantity = 2;
            support.index.at(1) = i;
            break;
        case 1:
            support.quantity = 2;
            support.index.at(0) = i;
            break;
        case 2:
            support.quantity = 2;
            support.index.at(0) = support.index.at(2);
            support.index.at(1) = i;
            break;
        case 3:
            support.quantity = 2;
            support.index.at(0) = support.index.at(3);
            support.index.at(1) = i;
            break;
        case 4:
            support.quantity = 3;
            support.index.at(2) = i;
            break;
        case 5:
            support.quantity = 3;
            support.index.at(1) = i;
            break;
        case 6:
            support.quantity = 3;
            support.index.at(1) = support.index.at(3);
            support.index.at(2) = i;
            break;
        case 7:
            support.quantity = 3;
            support.index.at(0) = i;
            break;
        case 8:
            support.quantity = 3;
            support.index.at(0) = support.index.at(3);
            support.index.at(2) = i;
            break;
        case 9:
            support.quantity = 3;
            support.index.at(0) = support.index.at(3);
            support.index.at(1) = i;
            break;
        case 10:
            support.index.at(3) = i;
            break;
        case 11:
            support.index.at(2) = i;
            break;
        case 12:
            support.index.at(1) = i;
            break;
        case 13:
            support.index.at(0) = i;
            break;
        default:
            break;
    }

    return minimal;
}

template <typename Real>
bool Mathematics::ContMinSphere3<Real>::Support ::Contains(int pointIndex, const std::vector<Vector3<Real>>& points, Real epsilon)
{
    for (auto i = 0; i < quantity; ++i)
    {
        auto diff = points.at(pointIndex) - points.at(index.at(i));
        if (Vector3Tools<Real>::GetLengthSquared(diff) < epsilon)
        {
            return true;
        }
    }
    return false;
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_MIN_SPHERE3_DETAIL_H