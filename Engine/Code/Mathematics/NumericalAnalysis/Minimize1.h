///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/15 11:43)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_H

#include "Mathematics/MathematicsDll.h"

#include "Minimize1DataDetail.h"

namespace Mathematics
{
    template <typename Real, typename UserDataType>
    class Minimize1 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Minimize1<Real, UserDataType>;

        // 最小化的函数类型：result = f(t,userData)。
        // userData是通过构造函数或SetUserData(*)设置的指针。
        // 这使您可以通过一个类的静态函数封装调用一个非静态成员函数，
        // 在这种情况下，用户数据是一个指向类对象。
        // 当然，当你需要它来确保“function”拥有所有计算其所需的信息，
        // 用户数据可以是复杂的。
        using Function = Real (*)(Real, const UserDataType*);
        using Minimize1Data = Minimize1Data<Real>;
        using Math = Math<Real>;

    public:
        // 区间[t0,t1]提供给GetMinimum(Real,Real,Real)
        // 是通过检查子区间进行处理。
        // 在每个子区间[a,b]，值f0 = f(a)，f1 = f((a+b)/2)，
        // 和f2 = f(b)的检查。
        // 如果{f0,f1,f2}是单调的，然后按[a,b]被细分和处理。
        // 递归的最大深度是通过'maxLevel'限定。
        // 如果{f0,f1,f2}不是单调的，则产生下述两种情况。
        // 首先，如果f1 = min{f0,f1,f2}，则{f0,f1,f2}被表示为
        // “括号的最小值”和
        // GetBracketedMinimum(*)被调用以定位函数最小值。
        // 该方法使用二分的一种形式被称为“抛物线插值”
        // 二等分步进的最大数目是“maxBracket'。
        // 其次，如果为f1 = max{f0,f1,f2}，
        // 则{f0,f1,f2}为括号最大值。
        // 最小搜索继续递归如之前在[a,(a+b)/2] 和 [(a+b)/2,b]上。
        Minimize1(Function function, int maxLevel, int maxBracket, const UserDataType* userData) noexcept;

        CLASS_INVARIANT_DECLARE;

        void SetUserData(const UserDataType* newUserData) noexcept;
        NODISCARD const UserDataType* GetUserData() const noexcept;

        // 搜索'function'的最小的区间[t0,t1]使用
        // “tInitial”为初始猜测在'function'值。
        // 最小的位置为'tMin'和最小的值是'fMin'。
        // 返回的第一部分为tMin和第二部分为fMin
        NODISCARD Minimize1Data GetMinimum(Real begin, Real end, Real initial) const;

    private:
        // 这是调用的开始搜索相关的[t0,tInitial]和[tInitial,t1]。
        void CompareMinimum(Real begin, Real beginFunction, Real end, Real endFunction, int level, Minimize1Data& minimize1Data) const;

    private:
        // 这是调用递归搜索在[a,(a+b)/2] 和 [(a+b)/2,b]。
        void CompareMinimum(Real begin, Real beginFunction, Real middle, Real middleFunction, Real end, Real endFunction, int level, Minimize1Data& minimize1Data) const;

        // 这是调用当{f0,f1,f2}括号是最小值时。
        void CompareBracketedMinimum(Real begin,
                                     Real beginFunction,
                                     Real middle,
                                     Real middleFunction,
                                     Real end,
                                     Real endFunction,
                                     int level,
                                     Minimize1Data& minimize1Data) const;

    private:
        Function function;
        int maxLevel;
        int maxBracket;
        const UserDataType* userData;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_H
