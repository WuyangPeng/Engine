///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/20 12:27)

#ifndef MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM_H
#define MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/VariableMatrix.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class IntpBSplineUniform
    {
    public:
        using ClassType = IntpBSplineUniform<Real>;

    public:
        IntpBSplineUniform(int dims, int degree, const std::vector<int>& dim, const std::vector<Real>& data);
        virtual ~IntpBSplineUniform() noexcept = default;
        IntpBSplineUniform(const IntpBSplineUniform& rhs) = default;
        IntpBSplineUniform& operator=(const IntpBSplineUniform& rhs) = default;
        IntpBSplineUniform(IntpBSplineUniform&& rhs) = default;
        IntpBSplineUniform& operator=(IntpBSplineUniform&& rhs) = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD int GetDimension() const noexcept;
        NODISCARD int GetDegree() const noexcept;
        NODISCARD Real GetDomainMin(int i) const;
        NODISCARD Real GetDomainMax(int i) const;
        NODISCARD int GetGridMin(int i) const;
        NODISCARD int GetGridMax(int i) const;

        NODISCARD virtual Real operator()(const std::vector<Real>& x) = 0;
        NODISCARD virtual Real operator()(const std::vector<int>& dx, const std::vector<Real>& x) = 0;

    protected:
        NODISCARD virtual void EvaluateUnknownData() = 0;
        NODISCARD virtual void ComputeIntermediate() = 0;
        void SetPolynomial(int order, Real diff, VariableLengthVector<Real>& polynomial);

        NODISCARD static int Choose(int n, int k) noexcept;
        NODISCARD static VariableMatrix<Real> BlendMatrix(int degree);

        void SetBase(int index, int value);
        NODISCARD bool IsBaseChange(int index) const;
        void SwitchToNewLocalGrid(int index);
        NODISCARD bool HasEvaluateCallback() const noexcept;
        NODISCARD int GetBase(int index) const;
        NODISCARD VariableLengthVector<Real>& GetPolynomial(int index);
        NODISCARD Real GetInter(int index) const;
        NODISCARD Real GetData(int index) const;
        void SetData(int index);
        void SetInter(int index, Real value);
        NODISCARD Real GetMatrix(int row, int column) const;
        NODISCARD int GetDim(int index) const;
        NODISCARD int GetDP1() const noexcept;
        NODISCARD int GetDP1ToN() const noexcept;
        void SetCache(int index, Real value);
        NODISCARD Real GetCache(int index) const;
        NODISCARD int GetSkip(int index) const;
        NODISCARD Real GetProduct(int index) const;

    private:
        using EvaluateCallback = Real (*)(int);

    private:
        int dims;
        int degree;
        int dp1;
        int dp1ToN;
        int dp1To2N;
        std::vector<int> dim;
        std::vector<Real> data;
        std::vector<Real> domMin;
        std::vector<Real> domMax;
        std::vector<int> gridMin;
        std::vector<int> gridMax;
        std::vector<int> base;
        std::vector<int> oldBase;
        VariableMatrix<Real> matrix;
        std::vector<Real> cache;
        std::vector<Real> inter;
        VariableMatrix<Real> poly;
        VariableMatrix<Real> coeff;
        std::vector<Real> product;
        std::vector<int> skip;

        EvaluateCallback evaluateCallback;
    };
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM_H
