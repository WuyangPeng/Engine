/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/07 17:27)

#ifndef MATHEMATICS_RATIONAL_BINARY_SCIENTIFIC_RATIONAL_H
#define MATHEMATICS_RATIONAL_BINARY_SCIENTIFIC_RATIONAL_H

#include "Mathematics/MathematicsDll.h"

#include "BinaryScientificNumber.h"

/// 请参阅BinaryScientificNumber.h中关于UInteger要求的注释。
/// BinaryScientificRational的分母被选择为正，这允许比较的一些简化。
/// 另请参阅有关公开MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE条件定义的注释。
namespace Mathematics
{
    template <typename UInteger>
    class BinaryScientificRational
    {
    public:
        using ClassType = BinaryScientificRational<UInteger>;

        using BinaryScientificNumberType = BinaryScientificNumber<UInteger>;

    public:
        /// 函数生成零BinaryScientificRational。
        /// 只取分子的构造函数将分母设置为1。
        NODISCARD static BinaryScientificRational CreateZero();

        explicit BinaryScientificRational(float numerator);
        explicit BinaryScientificRational(double numerator) requires(!std::is_same_v<UIntegerFixedPrecision32<1>, UInteger>);
        explicit BinaryScientificRational(int32_t numerator);
        explicit BinaryScientificRational(uint32_t numerator);
        explicit BinaryScientificRational(int64_t numerator) requires(!std::is_same_v<UIntegerFixedPrecision32<1>, UInteger>);
        explicit BinaryScientificRational(uint64_t numerator) requires(!std::is_same_v<UIntegerFixedPrecision32<1>, UInteger>);
        explicit BinaryScientificRational(const BinaryScientificNumberType& numerator);

        BinaryScientificRational(float numerator, float denominator);
        BinaryScientificRational(double numerator, double denominator) requires(!std::is_same_v<UIntegerFixedPrecision32<1>, UInteger>);
        BinaryScientificRational(int32_t numerator, int32_t denominator);
        BinaryScientificRational(uint32_t numerator, uint32_t denominator);
        BinaryScientificRational(int64_t numerator, int64_t denominator) requires(!std::is_same_v<UIntegerFixedPrecision32<1>, UInteger>);
        BinaryScientificRational(uint64_t numerator, uint64_t denominator) requires(!std::is_same_v<UIntegerFixedPrecision32<1>, UInteger>);
        BinaryScientificRational(const BinaryScientificNumberType& numerator, const BinaryScientificNumberType& denominator);

        CLASS_INVARIANT_DECLARE;

        /// 隐式转换。这些始终使用默认的舍入模式，
        /// 四舍五入到最接近的平局。
        NODISCARD explicit operator float() const;
        NODISCARD explicit operator double() const;

        /// 成员访问。
        void SetSign(int sign) noexcept(!isBinaryScientificShowDouble);
        NODISCARD int GetSign() const noexcept;

        void Negate() noexcept(!isBinaryScientificShowDouble);

        NODISCARD const BinaryScientificNumberType& GetNumerator() const noexcept;
        NODISCARD BinaryScientificNumberType& GetNumerator() noexcept;

        NODISCARD const BinaryScientificNumberType& GetDenominator() const noexcept;
        NODISCARD BinaryScientificNumberType& GetDenominator() noexcept;

        /// 一元运算。
        NODISCARD BinaryScientificRational operator+() const noexcept;
        NODISCARD BinaryScientificRational operator-() const;

        BinaryScientificRational& operator+=(const BinaryScientificRational& rhs);
        BinaryScientificRational& operator-=(const BinaryScientificRational& rhs);
        BinaryScientificRational& operator*=(const BinaryScientificRational& rhs);
        BinaryScientificRational& operator/=(const BinaryScientificRational& rhs);

        /// 磁盘输入/输出。
        /// 应该使用std::ios::binary创建fstream对象。
        /// 如果操作成功，则返回值为“true”。
        bool Write(std::ostream& output) const;
        bool Read(std::istream& input);

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

        NODISCARD double GetValue() const noexcept;
        void SetValue(double aValue) noexcept;
        void SetValue();

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

    private:
        explicit BinaryScientificRational(CoreTools::DisableNotThrow disableNotThrow);

        /// 用于将字符串转换为BinaryScientificRational的帮助程序，
        /// 其中字符串是字符串“x.y”的小数部分“y”。
        NODISCARD static BinaryScientificRational ConvertToFraction(const std::string& number);

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    private:
        /// 首先列出此项，使其首先显示在调试器监视窗口中。
        double value{};

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

        BinaryScientificNumberType numerator;
        BinaryScientificNumberType denominator;
    };

    /// 显式转换为用户指定的精度。
    /// 舍入模式是<cfenv>中提供的标志之一。模式为
    ///   FE_TONEAREST:  四舍五入到最接近的平局
    ///   FE_DOWNWARD:   向负无穷大取整
    ///   FE_TOWARDZERO: 向零取整
    ///   FE_UPWARD:     向正无穷大取整
    template <typename UInteger>
    void Convert(const BinaryScientificRational<UInteger>& input,
                 int precision,
                 int roundingMode,
                 BinaryScientificNumber<UInteger>& output);

    /// 此转换用于避免在APConversion类中以及通过名为Rational的模板参数传递BinaryScientificRational<UInteger>的其他地方公开BinaryScientificNumber。
    template <typename UInteger>
    void Convert(const BinaryScientificRational<UInteger>& input,
                 int precision,
                 int roundingMode,
                 BinaryScientificRational<UInteger>& output);

    /// 使用指定的舍入模式转换为'float'或'double'。
    template <typename UInteger, typename FloatingPointType>
    void Convert(const BinaryScientificRational<UInteger>& input, int roundingMode, FloatingPointType& output);

    /// 算术。
    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> operator+(const BinaryScientificRational<UInteger>& lhs, const BinaryScientificRational<UInteger>& rhs);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> operator-(const BinaryScientificRational<UInteger>& lhs, const BinaryScientificRational<UInteger>& rhs);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> operator*(const BinaryScientificRational<UInteger>& lhs, const BinaryScientificRational<UInteger>& rhs);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> operator/(const BinaryScientificRational<UInteger>& lhs, const BinaryScientificRational<UInteger>& rhs);

    /// 比较。
    template <typename UInteger>
    NODISCARD bool operator==(const BinaryScientificRational<UInteger>& lhs, const BinaryScientificRational<UInteger>& rhs);

    template <typename UInteger>
    NODISCARD bool operator!=(const BinaryScientificRational<UInteger>& lhs, const BinaryScientificRational<UInteger>& rhs);

    template <typename UInteger>
    NODISCARD bool operator<(const BinaryScientificRational<UInteger>& lhs, const BinaryScientificRational<UInteger>& rhs);

    template <typename UInteger>
    NODISCARD bool operator<=(const BinaryScientificRational<UInteger>& lhs, const BinaryScientificRational<UInteger>& rhs);

    template <typename UInteger>
    NODISCARD bool operator>(const BinaryScientificRational<UInteger>& lhs, const BinaryScientificRational<UInteger>& rhs);

    template <typename UInteger>
    NODISCARD bool operator>=(const BinaryScientificRational<UInteger>& lhs, const BinaryScientificRational<UInteger>& rhs);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> AtanDivPi(const BinaryScientificRational<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Atan2DivPi(const BinaryScientificRational<UInteger>& y, const BinaryScientificRational<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Clamp(const BinaryScientificRational<UInteger>& x, const BinaryScientificRational<UInteger>& xMin, const BinaryScientificRational<UInteger>& xMax);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> CosPi(const BinaryScientificRational<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Exp10(const BinaryScientificRational<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> InvSqrt(const BinaryScientificRational<UInteger>& x);

    template <typename UInteger>
    NODISCARD int SignToInt(const BinaryScientificRational<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Saturate(const BinaryScientificRational<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Sign(const BinaryScientificRational<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> SinPi(const BinaryScientificRational<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Sqr(const BinaryScientificRational<UInteger>& x);

    /// 计算 u * v + w.
    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Fma(const BinaryScientificRational<UInteger>& u,
                                                     const BinaryScientificRational<UInteger>& v,
                                                     const BinaryScientificRational<UInteger>& w);

    /// 产品总和 (SOP) u * v + w * z.
    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> RobustSop(const BinaryScientificRational<UInteger>& u,
                                                           const BinaryScientificRational<UInteger>& v,
                                                           const BinaryScientificRational<UInteger>& w,
                                                           const BinaryScientificRational<UInteger>& z);

    /// 产品差 (DOP) u * v - w * z.
    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> RobustDop(const BinaryScientificRational<UInteger>& u,
                                                           const BinaryScientificRational<UInteger>& v,
                                                           const BinaryScientificRational<UInteger>& w,
                                                           const BinaryScientificRational<UInteger>& z);

    /// 允许在计算结果时使用指定精度的数学函数的实现。
    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Acos(const BinaryScientificRational<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Acosh(const BinaryScientificRational<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Asin(const BinaryScientificRational<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Asinh(const BinaryScientificRational<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Atan(const BinaryScientificRational<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Atanh(const BinaryScientificRational<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Atan2(const BinaryScientificRational<UInteger>& y, const BinaryScientificRational<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Ceil(const BinaryScientificRational<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Cos(const BinaryScientificRational<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Cosh(const BinaryScientificRational<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Exp(const BinaryScientificRational<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Exp2(const BinaryScientificRational<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Fabs(const BinaryScientificRational<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Floor(const BinaryScientificRational<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Fmod(const BinaryScientificRational<UInteger>& x, const BinaryScientificRational<UInteger>& y);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Frexp(const BinaryScientificRational<UInteger>& x, int32_t* exponent);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Ldexp(const BinaryScientificRational<UInteger>& x, int32_t exponent) noexcept(!isBinaryScientificShowDouble);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Log(const BinaryScientificRational<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Log2(const BinaryScientificRational<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Log10(const BinaryScientificRational<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Pow(const BinaryScientificRational<UInteger>& x, const BinaryScientificRational<UInteger>& y);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Remainder(const BinaryScientificRational<UInteger>& x, const BinaryScientificRational<UInteger>& y);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Sin(const BinaryScientificRational<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Sinh(const BinaryScientificRational<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Sqrt(const BinaryScientificRational<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Tan(const BinaryScientificRational<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificRational<UInteger> Tanh(const BinaryScientificRational<UInteger>& x);
}

namespace std
{
    /// 表示BinaryScientificRational是有符号类型的类型特征。
    template <typename UInteger>
    struct is_signed<Mathematics::BinaryScientificRational<UInteger>> : true_type
    {
    };
}

namespace CoreTools
{
    /// 请参阅TypeTraits.h中关于trait IsArbitraryPrecisionInternal、HasDivisionOperatorInternal的注释。
    template <typename UInteger>
    struct IsArbitraryPrecisionInternal<Mathematics::BinaryScientificRational<UInteger>> : std::true_type
    {
    };

    template <typename UInteger>
    struct HasDivisionOperatorInternal<Mathematics::BinaryScientificRational<UInteger>> : std::true_type
    {
    };
}

#endif  // MATHEMATICS_RATIONAL_BINARY_SCIENTIFIC_RATIONAL_H
