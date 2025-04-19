/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/18 16:06)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_MINIMIZE_N_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_MINIMIZE_N_H

#include "Mathematics/MathematicsDll.h"

#include "Minimize1.h"
#include "Mathematics/Algebra/VariableLengthVector.h"

#include <functional>

/// 提供给GetMinimum(*)的笛卡尔乘积域具有存储在t0[0..d-1] 中的最小值和存储在t1[0..d-1]中的最大值，其中d是“维度”。
/// 沿着通过最小位置的当前估计的线来搜索域。
/// 使用Minimize1<T>对象搜索每条这样的线的最小值。
/// 这就是所谓的“鲍威尔方向集方法”。
/// Minimize1<T>使用参数'maxLevel'和'maxBracket'，因此请阅读该类的文档（在其头文件中）以了解这些参数的含义。
/// 输入'maxIterations'是方向集方法的迭代次数。
namespace Mathematics::Algebra
{
    template <typename T>
    class MinimizeN
    {
    public:
        using ClassType = MinimizeN<T>;

        using MathType = Math<T>;
        using Container = std::vector<T>;
        using FunctionType = std::function<T(const Container&)>;

    public:
        MinimizeN(int dimensions,
                  FunctionType f,
                  int maxLevel,
                  int maxBracket,
                  int maxIterations,
                  T epsilon = MathType::GetValue(1e-06));

        CLASS_INVARIANT_DECLARE;

        /// 成员访问
        void SetEpsilon(T aEpsilon) noexcept;
        NODISCARD T GetEpsilon() const noexcept;

        /// 在笛卡尔乘积域上找到最小值存储在t0[0..d-1]中，
        /// 最大值存储在t1[0..d-1]中的最小值，其中d是“维度”。
        /// 初始猜测在tInitial[0..d-1]中指定。
        /// 最小值的位置是tMin[0..d-1]，最小值的值是'fMin'。
        void GetMinimum(const Container& t0, const Container& t1, const Container& tInitial, Container& aTMin, T& aFMin);

    private:
        using VariableLengthVectorType = VariableLengthVector<T>;
        using Minimize1Type = Minimize1<T>;
        using VariableLengthVectorContainer = std::vector<VariableLengthVectorType>;

    private:
        /// 最小位置的当前估计为mTCurr[0..d-1]。
        /// 要搜索的当前行的方向是 mDCurr[0..d-1]。
        /// 这条线必须相对于笛卡尔乘积域进行剪裁，这是在该函数中实现的过程。
        /// 如果该行是mTCurr+s*mDCurr，则剪辑结果是s-区间[ell0,ell1]。
        void ComputeDomain(const Container& t0, const Container& t1, T& ell0, T& ell1);

    private:
        int dimensions;
        FunctionType function;
        int maxIterations;
        T epsilon;
        VariableLengthVectorContainer directions;
        int dConjIndex;
        int dCurrIndex;
        VariableLengthVectorType tCurr;
        VariableLengthVectorType tSave;
        T fCurr;
        Minimize1Type minimizer;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_MINIMIZE_N_H
