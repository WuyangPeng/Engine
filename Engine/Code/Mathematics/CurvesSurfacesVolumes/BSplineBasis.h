///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:54)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_BASIS_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_BASIS_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h"

namespace Mathematics
{
    template <typename Real>
    class BSplineBasis
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = BSplineBasis<Real>;
        using Math = Math<Real>;

    public:
        BSplineBasis() noexcept;

        BSplineBasis(int numCtrlPoints, int degree, bool open);
        void Create(int numCtrlPoints, int degree, bool open);

        BSplineBasis(int numCtrlPoints, int degree, const std::vector<Real>& interiorKnot);
        void Create(int numCtrlPoints, int degree, const std::vector<Real>& interiorKnot);

        virtual ~BSplineBasis() noexcept = default;

        BSplineBasis(const BSplineBasis& rhs) = default;
        BSplineBasis& operator=(const BSplineBasis& rhs) = default;
        BSplineBasis(BSplineBasis&& rhs) noexcept = default;
        BSplineBasis& operator=(BSplineBasis&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD int GetNumCtrlPoints() const noexcept;
        NODISCARD int GetDegree() const noexcept;
        NODISCARD bool IsOpen() const noexcept;
        NODISCARD bool IsUniform() const noexcept;

        void SetKnot(int j, Real knot);
        NODISCARD Real GetKnot(int j) const;

        NODISCARD Real GetD0(int i) const;
        NODISCARD Real GetD1(int i) const;
        NODISCARD Real GetD2(int i) const;
        NODISCARD Real GetD3(int i) const;

        void Compute(Real t, int order, int& minIndex, int& maxIndex) const;

    protected:
        NODISCARD int Initialize(int numCtrlPoints, int newDegree, bool newOpen);
        NODISCARD std::vector<std::vector<Real>> Allocate() const;

        NODISCARD int GetKey(Real& t) const;

    private:
        int ctrlPointsCount;
        int degree;
        std::vector<Real> knot;
        bool open;
        bool uniform;

        mutable std::vector<std::vector<Real>> bD0;
        mutable std::vector<std::vector<Real>> bD1;
        mutable std::vector<std::vector<Real>> bD2;
        mutable std::vector<std::vector<Real>> bD3;
    };

    using BSplineBasisF = BSplineBasis<float>;
    using BSplineBasisD = BSplineBasis<double>;
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_BASIS_H
