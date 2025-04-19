///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:56)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_QUADRIC_SURFACE_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_QUADRIC_SURFACE_H

#include "Mathematics/MathematicsDll.h"

#include "ImplicitSurface.h"
#include "Mathematics/Rational/RationalVector3.h"

namespace Mathematics
{
    template <typename Real>
    class QuadricSurface : public ImplicitSurface<Real>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = QuadricSurface<Real>;
        using ParentType = ImplicitSurface<Real>;

    public:
        QuadricSurface() noexcept;
        explicit QuadricSurface(const std::array<Real, 10>& coeff);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD const Real* GetCoefficients() const noexcept;
        NODISCARD const Matrix3<Real>& GetA() const noexcept;
        NODISCARD const Vector3<Real>& GetB() const noexcept;
        NODISCARD Real GetC() const noexcept;

        NODISCARD Real F(const Vector3<Real>& pos) const override;

        NODISCARD Real FX(const Vector3<Real>& pos) const override;
        NODISCARD Real FY(const Vector3<Real>& pos) const override;
        NODISCARD Real FZ(const Vector3<Real>& pos) const override;

        NODISCARD Real FXX(const Vector3<Real>& pos) const override;
        NODISCARD Real FXY(const Vector3<Real>& pos) const override;
        NODISCARD Real FXZ(const Vector3<Real>& pos) const override;
        NODISCARD Real FYY(const Vector3<Real>& pos) const override;
        NODISCARD Real FYZ(const Vector3<Real>& pos) const override;
        NODISCARD Real FZZ(const Vector3<Real>& pos) const override;

        enum class Type
        {
            None,
            Point,
            Line,
            Plane,
            TowPlane,
            ParabolicCylinder,
            EllipticCylinder,
            HyperbolicCylinder,
            EllipticParaboloid,
            HyperbolicParaboloid,
            EllipticCone,
            HyperboloidOneSheet,
            HyperboloidTwoSheets,
            Ellipsoid
        };

        NODISCARD Type GetType() const;

    private:
        using QRational = SignRational<4 * sizeof(Real)>;
        using QSVector = RationalVector3<4 * sizeof(Real)>;

        class RReps
        {
        public:
            RReps(const std::array<Real, 10>& coeff);

            QRational a00;
            QRational a01;
            QRational a02;
            QRational a11;
            QRational a12;
            QRational a22;
            QRational b0;
            QRational b1;
            QRational b2;
            QRational c;

            QRational sub00;
            QRational sub01;
            QRational sub02;
            QRational sub11;
            QRational sub12;
            QRational sub22;

            QRational c0;
            QRational c1;
            QRational c2;

            QRational c3;
            QRational c4;
            QRational c5;
        };

        static void GetRootSigns(RReps& reps, int& positiveRoots, int& negativeRoots, int& zeroRoots);
        NODISCARD static int GetSignChanges(int quantity, const std::array<QRational, 4>& value);
        NODISCARD static Type ClassifyZeroRoots0(const RReps& reps, int positiveRoots);
        NODISCARD static Type ClassifyZeroRoots1(const RReps& reps, int positiveRoots);
        NODISCARD static Type ClassifyZeroRoots1(const RReps& reps, int positiveRoots, const QSVector& P0, const QSVector& P1, const QSVector& P2);
        NODISCARD static Type ClassifyZeroRoots2(const RReps& reps, int positiveRoots);
        NODISCARD static Type ClassifyZeroRoots2(const RReps& reps, int positiveRoots, const QSVector& P0, const QSVector& P1, const QSVector& P2);
        NODISCARD static Type ClassifyZeroRoots3(const RReps& reps);

    private:
        std::array<Real, 10> coeff;
        Matrix3<Real> a;
        Vector3<Real> b;
        Real c;
    };
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_QUADRIC_SURFACE_H
