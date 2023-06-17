///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:52)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_QUADRIC_SURFACE_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_QUADRIC_SURFACE_DETAIL_H

#include "QuadricSurface.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Rational/RationalVector3Detail.h"
#include "Mathematics/Rational/SignRationalDetail.h"

template <typename Real>
Mathematics::QuadricSurface<Real>::QuadricSurface() noexcept
    : ParentType{}, coeff{}, a{}, b{}, c{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::QuadricSurface<Real>::QuadricSurface(const std::array<Real, 10>& coeff)
    : ParentType{}, coeff{ coeff }, a{}, b{ coeff.at(1), coeff.at(2), coeff.at(3) }, c{ coeff.at(0) }
{
    a[0][0] = coeff.at(4);
    a[0][1] = Math<Real>::GetRational(1, 2) * coeff.at(5);
    a[0][2] = Math<Real>::GetRational(1, 2) * coeff.at(6);
    a[1][0] = a[0][1];
    a[1][1] = coeff.at(7);
    a[1][2] = Math<Real>::GetRational(1, 2) * coeff.at(8);
    a[2][0] = a[0][2];
    a[2][1] = a[1][2];
    a[2][2] = coeff.at(9);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::QuadricSurface<Real>::IsValid() const noexcept
{
    return ParentType::IsValid();
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Real* Mathematics::QuadricSurface<Real>::GetCoefficients() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return coeff.data();
}

template <typename Real>
const Mathematics::Matrix3<Real>& Mathematics::QuadricSurface<Real>::GetA() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return a;
}

template <typename Real>
const Mathematics::Vector3<Real>& Mathematics::QuadricSurface<Real>::GetB() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return b;
}

template <typename Real>
Real Mathematics::QuadricSurface<Real>::GetC() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return c;
}

template <typename Real>
Real Mathematics::QuadricSurface<Real>::F(const Vector3<Real>& pos) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto f = Vector3Tools<Real>::DotProduct(pos, (a * pos + b)) + c;

    return f;
}

template <typename Real>
Real Mathematics::QuadricSurface<Real>::FX(const Vector3<Real>& pos) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto sum = a[0][0] * pos[0] + a[0][1] * pos[1] + a[0][2] * pos[2];
    auto fx = (Math<Real>::GetValue(2)) * sum + b[0];

    return fx;
}

template <typename Real>
Real Mathematics::QuadricSurface<Real>::FY(const Vector3<Real>& pos) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto sum = a[1][0] * pos[0] + a[1][1] * pos[1] + a[1][2] * pos[2];
    auto fy = (Math<Real>::GetValue(2)) * sum + b[1];

    return fy;
}

template <typename Real>
Real Mathematics::QuadricSurface<Real>::FZ(const Vector3<Real>& pos) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto sum = a[2][0] * pos[0] + a[2][1] * pos[1] + a[2][2] * pos[2];
    auto fz = (Math<Real>::GetValue(2)) * sum + b[2];

    return fz;
}

template <typename Real>
Real Mathematics::QuadricSurface<Real>::FXX(const Vector3<Real>&) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto fxx = (Math<Real>::GetValue(2)) * a[0][0];

    return fxx;
}

template <typename Real>
Real Mathematics::QuadricSurface<Real>::FXY(const Vector3<Real>&) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto fxy = (Math<Real>::GetValue(2)) * a[0][1];

    return fxy;
}

template <typename Real>
Real Mathematics::QuadricSurface<Real>::FXZ(const Vector3<Real>&) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto fxz = (Math<Real>::GetValue(2)) * a[0][2];

    return fxz;
}

template <typename Real>
Real Mathematics::QuadricSurface<Real>::FYY(const Vector3<Real>&) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto fyy = (Math<Real>::GetValue(2)) * a[1][1];

    return fyy;
}

template <typename Real>
Real Mathematics::QuadricSurface<Real>::FYZ(const Vector3<Real>&) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto fyz = (Math<Real>::GetValue(2)) * a[1][2];

    return fyz;
}

template <typename Real>
Real Mathematics::QuadricSurface<Real>::FZZ(const Vector3<Real>&) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto fzz = (Math<Real>::GetValue(2)) * a[2][2];

    return fzz;
}

template <typename Real>
typename Mathematics::QuadricSurface<Real>::Type Mathematics::QuadricSurface<Real>::GetType() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    RReps reps{ coeff };

    auto positiveRoots = 0;
    auto negativeRoots = 0;
    auto zeroRoots = 0;

    GetRootSigns(reps, positiveRoots, negativeRoots, zeroRoots);

    auto type = Type::None;
    switch (zeroRoots)
    {
        case 0:
            type = ClassifyZeroRoots0(reps, positiveRoots);
            break;
        case 1:
            type = ClassifyZeroRoots1(reps, positiveRoots);
            break;
        case 2:
            type = ClassifyZeroRoots2(reps, positiveRoots);
            break;
        case 3:
            type = ClassifyZeroRoots3(reps);
            break;
        default:
            break;
    }
    return type;
}

template <typename Real>
void Mathematics::QuadricSurface<Real>::GetRootSigns(RReps& reps, int& positiveRoots, int& negativeRoots, int& zeroRoots)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto signChangeMI = 0;
    auto signChange0 = 0;
    auto signChangePI = 0;
    auto distinctNonzeroRoots = 0;
    std::array<QRational, 4> value{};
    if (reps.c0 != QRational{ 0 })
    {
        reps.c3 = QRational{ 2, 9 } * reps.c2 * reps.c2 - QRational{ 2, 3 } * reps.c1;
        reps.c4 = reps.c0 - QRational{ 1, 9 } * reps.c1 * reps.c2;

        if (reps.c3 != QRational{ 0 })
        {
            reps.c5 = -(reps.c1 + ((QRational{ 2 } * reps.c2 * reps.c3 + QRational{ 3 } * reps.c4) * reps.c4) / (reps.c3 * reps.c3));

            value.at(0) = QRational{ 1 };
            value.at(1) = -reps.c3;
            value.at(2) = reps.c5;
            signChangeMI = 1 + GetSignChanges(3, value);

            value.at(0) = -reps.c0;
            value.at(1) = reps.c1;
            value.at(2) = reps.c4;
            value.at(3) = reps.c5;
            signChange0 = GetSignChanges(4, value);

            value.at(0) = QRational{ 1 };
            value.at(1) = reps.c3;
            value.at(2) = reps.c5;
            signChangePI = GetSignChanges(3, value);
        }
        else
        {
            value.at(0) = -reps.c0;
            value.at(1) = reps.c1;
            value.at(2) = reps.c4;
            signChange0 = GetSignChanges(3, value);

            value.at(0) = QRational{ 1 };
            value.at(1) = reps.c4;
            signChangePI = GetSignChanges(2, value);
            signChangeMI = 1 + signChangePI;
        }

        positiveRoots = signChange0 - signChangePI;
        MATHEMATICS_ASSERTION_0(positiveRoots >= 0, "意外情况\n");
        negativeRoots = signChangeMI - signChange0;
        MATHEMATICS_ASSERTION_0(negativeRoots >= 0, "意外情况\n");
        zeroRoots = 0;

        distinctNonzeroRoots = positiveRoots + negativeRoots;
        if (distinctNonzeroRoots == 2)
        {
            if (positiveRoots == 2)
            {
                positiveRoots = 3;
            }
            else if (negativeRoots == 2)
            {
                negativeRoots = 3;
            }
            else
            {
                auto x = QRational{ 1, 3 } * reps.c2;
                auto poly = x * (x * (x - reps.c2) + reps.c1) - reps.c0;
                if (poly > QRational{ 0 })
                {
                    positiveRoots = 2;
                }
                else
                {
                    negativeRoots = 2;
                }
            }
        }
        else if (distinctNonzeroRoots == 1)
        {
            if (positiveRoots == 1)
            {
                positiveRoots = 3;
            }
            else
            {
                negativeRoots = 3;
            }
        }

        return;
    }

    if (reps.c1 != QRational{ 0 })
    {
        reps.c3 = QRational{ 1, 4 } * reps.c2 * reps.c2 - reps.c1;

        value.at(0) = QRational{ -1 };
        value.at(1) = reps.c3;
        signChangeMI = 1 + GetSignChanges(2, value);

        value.at(0) = reps.c1;
        value.at(1) = -reps.c2;
        value.at(2) = reps.c3;
        signChange0 = GetSignChanges(3, value);

        value.at(0) = QRational{ 1 };
        value.at(1) = reps.c3;
        signChangePI = GetSignChanges(2, value);

        positiveRoots = signChange0 - signChangePI;
        MATHEMATICS_ASSERTION_0(positiveRoots >= 0, "意外情况\n");
        negativeRoots = signChangeMI - signChange0;
        MATHEMATICS_ASSERTION_0(negativeRoots >= 0, "意外情况\n");
        zeroRoots = 1;

        distinctNonzeroRoots = positiveRoots + negativeRoots;
        if (distinctNonzeroRoots == 1)
        {
            positiveRoots = 2;
        }

        return;
    }

    if (reps.c2 != QRational{ 0 })
    {
        zeroRoots = 2;
        if (reps.c2 > QRational{ 0 })
        {
            positiveRoots = 1;
            negativeRoots = 0;
        }
        else
        {
            positiveRoots = 0;
            negativeRoots = 1;
        }
        return;
    }

    positiveRoots = 0;
    negativeRoots = 0;
    zeroRoots = 3;
}

template <typename Real>
int Mathematics::QuadricSurface<Real>::GetSignChanges(int quantity, const std::array<QRational, 4>& value)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto signChanges = 0;
    const QRational zero{ 0 };

    auto prev = value.at(0);
    for (auto i = 1; i < quantity; ++i)
    {
        const auto& next = value.at(i);
        if (next != zero)
        {
            if (prev * next < zero)
            {
                ++signChanges;
            }

            prev = next;
        }
    }

    return signChanges;
}

template <typename Real>
typename Mathematics::QuadricSurface<Real>::Type Mathematics::QuadricSurface<Real>::ClassifyZeroRoots0(const RReps& reps, int positiveRoots)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto fourDet = QRational{ 4 } * reps.c0;

    const auto qForm = reps.b0 * (reps.sub00 * reps.b0 - reps.sub01 * reps.b1 + reps.sub02 * reps.b2) - reps.b1 * (reps.sub01 * reps.b0 - reps.sub11 * reps.b1 + reps.sub12 * reps.b2) + reps.b2 * (reps.sub02 * reps.b0 - reps.sub12 * reps.b1 + reps.sub22 * reps.b2);

    const auto r = QRational{ 1, 4 } * qForm / fourDet - reps.c;
    if (r > QRational{ 0 })
    {
        if (positiveRoots == 3)
        {
            return Type::Ellipsoid;
        }
        else if (positiveRoots == 2)
        {
            return Type::HyperboloidOneSheet;
        }
        else if (positiveRoots == 1)
        {
            return Type::HyperboloidTwoSheets;
        }
        else
        {
            return Type::None;
        }
    }
    else if (r < QRational{ 0 })
    {
        if (positiveRoots == 3)
        {
            return Type::None;
        }
        else if (positiveRoots == 2)
        {
            return Type::HyperboloidTwoSheets;
        }
        else if (positiveRoots == 1)
        {
            return Type::HyperboloidOneSheet;
        }
        else
        {
            return Type::Ellipsoid;
        }
    }

    if (positiveRoots == 3 || positiveRoots == 0)
    {
        return Type::Point;
    }

    return Type::EllipticCone;
}

template <typename Real>
typename Mathematics::QuadricSurface<Real>::Type Mathematics::QuadricSurface<Real>::ClassifyZeroRoots1(const RReps& reps, int positiveRoots)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    QSVector p0{};
    QSVector p1{};
    QSVector p2{};

    if (reps.sub00 != QRational{ 0 } || reps.sub01 != QRational{ 0 } || reps.sub02 != QRational{ 0 })
    {
        p0 = QSVector{ reps.sub00, -reps.sub01, reps.sub02 };
        p1 = QSVector{ reps.a01, reps.a11, reps.a12 };
        p2 = Cross(p0, p1);

        return ClassifyZeroRoots1(reps, positiveRoots, p0, p1, p2);
    }

    if (reps.sub01 != QRational{ 0 } || reps.sub11 != QRational{ 0 } || reps.sub12 != QRational{ 0 })
    {
        p0 = QSVector{ -reps.sub01, reps.sub11, -reps.sub12 };
        p1 = QSVector{ reps.a02, reps.a12, reps.a22 };
        p2 = Cross(p0, p1);

        return ClassifyZeroRoots1(reps, positiveRoots, p0, p1, p2);
    }

    p0 = QSVector{ reps.sub02, -reps.sub12, reps.sub22 };
    p1 = QSVector{ reps.a00, reps.a01, reps.a02 };
    p2 = Cross(p0, p1);

    return ClassifyZeroRoots1(reps, positiveRoots, p0, p1, p2);
}

template <typename Real>
typename Mathematics::QuadricSurface<Real>::Type Mathematics::QuadricSurface<Real>::ClassifyZeroRoots1(const RReps& reps, int positiveRoots, const QSVector& P0, const QSVector& P1, const QSVector& P2)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto e0 = P0.GetX() * reps.b0 + P0.GetY() * reps.b1 + P0.GetZ() * reps.b2;

    if (e0 != QRational{ 0 })
    {
        if (positiveRoots == 1)
        {
            return Type::HyperbolicParaboloid;
        }
        else
        {
            return Type::EllipticParaboloid;
        }
    }

    const auto f11 = P1.GetX() * (reps.a00 * P1.GetX() + reps.a01 * P1.GetY() + reps.a02 * P1.GetZ()) +
                     P1.GetY() * (reps.a01 * P1.GetX() + reps.a11 * P1.GetY() + reps.a12 * P1.GetZ()) +
                     P1.GetZ() * (reps.a02 * P1.GetX() + reps.a12 * P1.GetY() + reps.a22 * P1.GetZ());

    const auto f12 = P2.GetX() * (reps.a00 * P1.GetX() + reps.a01 * P1.GetY() + reps.a02 * P1.GetZ()) +
                     P2.GetY() * (reps.a01 * P1.GetX() + reps.a11 * P1.GetY() + reps.a12 * P1.GetZ()) +
                     P2.GetZ() * (reps.a02 * P1.GetX() + reps.a12 * P1.GetY() + reps.a22 * P1.GetZ());

    const auto f22 = P2.GetX() * (reps.a00 * P2.GetX() + reps.a01 * P2.GetY() + reps.a02 * P2.GetZ()) +
                     P2.GetY() * (reps.a01 * P2.GetX() + reps.a11 * P2.GetY() + reps.a12 * P2.GetZ()) +
                     P2.GetZ() * (reps.a02 * P2.GetX() + reps.a12 * P2.GetY() + reps.a22 * P2.GetZ());

    const auto g1 = P1.GetX() * reps.b0 + P1.GetY() * reps.b1 + P1.GetZ() * reps.b2;
    const auto g2 = P2.GetX() * reps.b0 + P2.GetY() * reps.b1 + P2.GetZ() * reps.b2;

    const auto fourDet = QRational{ 4 } * (f11 * f22 - f12 * f12);
    const auto r = (g1 * (f22 * g1 - f12 * g2) + g2 * (f11 * g2 - f12 * g1)) / fourDet - reps.c;

    if (r > QRational{ 0 })
    {
        if (positiveRoots == 2)
        {
            return Type::EllipticCylinder;
        }
        else if (positiveRoots == 1)
        {
            return Type::HyperbolicCylinder;
        }
        else
        {
            return Type::None;
        }
    }
    else if (r < QRational{ 0 })
    {
        if (positiveRoots == 2)
        {
            return Type::None;
        }
        else if (positiveRoots == 1)
        {
            return Type::HyperbolicCylinder;
        }
        else
        {
            return Type::EllipticCylinder;
        }
    }

    return (positiveRoots == 1 ? Type::TowPlane : Type::Line);
}

template <typename Real>
typename Mathematics::QuadricSurface<Real>::Type Mathematics::QuadricSurface<Real>::ClassifyZeroRoots2(const RReps& reps, int positiveRoots)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    QSVector p0{};
    QSVector p1{};
    QSVector p2{};

    if (reps.a00 != QRational{ 0 } || reps.a01 != QRational{ 0 } || reps.a02 != QRational{ 0 })
    {
        p2 = QSVector{ reps.a00, reps.a01, reps.a02 };
    }
    else if (reps.a01 != QRational{ 0 } || reps.a11 != QRational{ 0 } || reps.a12 != QRational{ 0 })
    {
        p2 = QSVector{ reps.a01, reps.a11, reps.a12 };
    }
    else
    {
        p2 = QSVector{ reps.a02, reps.a12, reps.a22 };
    }

    if (p2.GetX() != QRational{ 0 })
    {
        p1.SetX(p2.GetY());
        p1.SetY(-p2.GetX());
        p1.SetZ(QRational{ 0 });
    }
    else
    {
        p1.SetX(QRational{ 0 });
        p1.SetY(p2.GetZ());
        p1.SetZ(-p2.GetY());
    }
    p0 = Cross(p1, p2);

    return ClassifyZeroRoots2(reps, positiveRoots, p0, p1, p2);
}

template <typename Real>
typename Mathematics::QuadricSurface<Real>::Type Mathematics::QuadricSurface<Real>::ClassifyZeroRoots2(const RReps& reps, int positiveRoots, const QSVector& P0, const QSVector& P1, const QSVector& P2)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto e0 = P0.GetX() * reps.b0 + P0.GetY() * reps.b1 + P0.GetZ() * reps.b1;
    if (e0 != QRational{ 0 })
    {
        return Type::ParabolicCylinder;
    }

    const auto e1 = P1.GetX() * reps.b0 + P1.GetY() * reps.b1 + P1.GetZ() * reps.b1;
    if (e1 != QRational{ 0 })
    {
        return Type::ParabolicCylinder;
    }

    const auto f1 = reps.c2 * (Dot(P2, P2));
    const auto e2 = P2.GetX() * reps.b0 + P2.GetY() * reps.b1 + P2.GetZ() * reps.b1;
    const auto r = e2 * e2 / (QRational{ 4 } * f1) - reps.c;
    if (r > QRational{ 0 })
    {
        if (positiveRoots == 1)
        {
            return Type::TowPlane;
        }
        else
        {
            return Type::None;
        }
    }
    else if (r < QRational{ 0 })
    {
        if (positiveRoots == 1)
        {
            return Type::None;
        }
        else
        {
            return Type::TowPlane;
        }
    }

    return Type::Plane;
}

template <typename Real>
typename Mathematics::QuadricSurface<Real>::Type Mathematics::QuadricSurface<Real>::ClassifyZeroRoots3(const RReps& reps)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (reps.b0 != QRational{ 0 } || reps.b1 != QRational{ 0 } || reps.b2 != QRational{ 0 })
    {
        return Type::Plane;
    }

    return Type::None;
}

template <typename Real>
Mathematics::QuadricSurface<Real>::RReps::RReps(const std::array<Real, 10>& coeff)
{
    const QRational oneHalf{ 1, 2 };

    c = QRational{ coeff.at(0) };
    b0 = QRational{ coeff.at(1) };
    b1 = QRational{ coeff.at(2) };
    b2 = QRational{ coeff.at(3) };
    a00 = QRational{ coeff.at(4) };
    a01 = oneHalf * QRational{ coeff.at(5) };
    a02 = oneHalf * QRational{ coeff.at(6) };
    a11 = QRational{ coeff.at(7) };
    a12 = oneHalf * QRational{ coeff.at(8) };
    a22 = QRational{ coeff.at(9) };

    sub00 = a11 * a22 - a12 * a12;
    sub01 = a01 * a22 - a12 * a02;
    sub02 = a01 * a12 - a02 * a11;
    sub11 = a00 * a22 - a02 * a02;
    sub12 = a00 * a12 - a02 * a01;
    sub22 = a00 * a11 - a01 * a01;
    c0 = a00 * sub00 - a01 * sub01 + a02 * sub02;
    c1 = sub00 + sub11 + sub22;
    c2 = a00 + a11 + a22;
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_QUADRIC_SURFACE_DETAIL_H