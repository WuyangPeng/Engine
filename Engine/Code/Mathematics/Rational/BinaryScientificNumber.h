/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/07 09:47)

#ifndef MATHEMATICS_RATIONAL_BINARY_SCIENTIFIC_NUMBER_H
#define MATHEMATICS_RATIONAL_BINARY_SCIENTIFIC_NUMBER_H

#include "Mathematics/MathematicsDll.h"

#include "UIntegerFixedPrecision32.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/MemoryTools/TypeTraits.h"

//// BinaryScientificNumber（二进制科学数）类旨在为稳健算法提供精确的算法，
//// 通常是那些我们需要知道行列式的确切符号的算法。
//// 模板参数UInteger必须至少支持以下公共接口。
//// 写入/读取的fstream对象必须使用std::ios::binary创建。
//// 如果操作成功，则Write/Read的返回值为true。
////
////      class UInteger
////      {
////      public:
////          UInteger();
////          UInteger(const UInteger& number);
////          UInteger(uint32_t number);
////          UInteger(uint64_t number);
////          UInteger& operator=(const UInteger& number);
////          UInteger(UInteger&& number);
////          UInteger& operator=(UInteger&& number);
////          void SetNumBits(int numBits);
////          int GetNumBits() const;
////          bool operator==(const UInteger& number) const;
////          bool operator< (const UInteger& number) const;
////          void Add(const UInteger& n0, const UInteger& n1);
////          void Sub(const UInteger& n0, const UInteger& n1);
////          void Mul(const UInteger& n0, const UInteger& n1);
////          void ShiftLeft(const UInteger& number, int32_t shift);
////          int ShiftRightToOdd(const UInteger& number);
////          int RoundUp();
////          uint64_t GetPrefix(int numRequested) const;
////          bool Write(std::ofstream& output) const;
////          bool Read(std::ifstream& input);
////      };
//// 目前为UInteger提供了每个字32位的存储空间。
//// 请参见类UIntegerArbitraryPrecision32（任意精度）、
//// UIntegerFixedPrecision32（固定精度）和UIntegerArithmeticLogicUnit32（前两个类共享的算术逻辑单元）。
namespace Mathematics
{
    template <typename UInteger>
    class BinaryScientificNumber
    {
    public:
        using ClassType = BinaryScientificNumber<UInteger>;

    public:
        /// 生成零BSNumber。
        NODISCARD static BinaryScientificNumber CreateZero() noexcept(noexcept(UInteger::CreateZero()));

        explicit BinaryScientificNumber(float number);
        explicit BinaryScientificNumber(double number) requires(!std::is_same_v<UIntegerFixedPrecision32<1>, UInteger>);
        explicit BinaryScientificNumber(int32_t number);
        explicit BinaryScientificNumber(uint32_t number);
        explicit BinaryScientificNumber(int64_t number) requires(!std::is_same_v<UIntegerFixedPrecision32<1>, UInteger>);
        explicit BinaryScientificNumber(uint64_t number) requires(!std::is_same_v<UIntegerFixedPrecision32<1>, UInteger>);

        /// 数字的形式必须是"x"、"+x"或"-x"，
        /// 其中x是一个前导数字为非零的正整数。
        explicit BinaryScientificNumber(const std::string& number);

        CLASS_INVARIANT_DECLARE;

        /// 隐式转换。
        /// 这些始终使用默认的舍入模式，四舍五入到最接近的平局。
        NODISCARD explicit operator float() const;
        NODISCARD explicit operator double() const;

        /// 成员访问。
        void SetSign(int aSign) noexcept(!isBinaryScientificShowDouble);
        NODISCARD int GetSign() const noexcept;
        void Negate() noexcept(!isBinaryScientificShowDouble);

        void SetBiasedExponent(int aBiasedExponent) noexcept(!isBinaryScientificShowDouble);
        NODISCARD int GetBiasedExponent() const noexcept;
        void SetExponent(int exponent) noexcept(!isBinaryScientificShowDouble);
        NODISCARD int GetExponent() const noexcept;

        NODISCARD const UInteger& GetUInteger() const noexcept;
        NODISCARD UInteger& GetUInteger() noexcept;

        /// 一元运算。
        NODISCARD BinaryScientificNumber operator+() const noexcept;
        NODISCARD BinaryScientificNumber operator-() const noexcept(!isBinaryScientificShowDouble);

        BinaryScientificNumber& operator+=(const BinaryScientificNumber& rhs);
        BinaryScientificNumber& operator-=(const BinaryScientificNumber& rhs);
        BinaryScientificNumber& operator*=(const BinaryScientificNumber& rhs);

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
        explicit BinaryScientificNumber(CoreTools::DisableNotThrow disableNotThrow) noexcept(noexcept(UInteger::CreateZero()));

        /// 用于将字符串转换为BinaryScientificNumber的帮助程序。
        /// 该字符串对于不带前导 '+'号的非负整数必须有效。
        NODISCARD static BinaryScientificNumber ConvertToInteger(const std::string& number);

        /// 加两个正数。
        NODISCARD static BinaryScientificNumber AddIgnoreSign(const BinaryScientificNumber& lhs, const BinaryScientificNumber& rhs, int resultSign);

        /// 减去两个正数，其中 lhs > rhs。
        NODISCARD static BinaryScientificNumber SubIgnoreSign(const BinaryScientificNumber& lhs, const BinaryScientificNumber& rhs, int resultSign);

        /// 支持从浮点数到BinaryScientificNumber的转换。
        template <typename Ieee>
        void ConvertFrom(typename Ieee::FloatType number);

        /// 支持从BinaryScientificNumber到浮点数的转换。
        template <typename Ieee>
        NODISCARD typename Ieee::FloatType ConvertTo() const;

        template <typename Ieee>
        NODISCARD typename Ieee::UIntType GetTrailing(int normal, int sigma) const;

    private:
#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

        /// 首先列出此项，使其首先显示在调试器监视窗口中。
        double value{};

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

        /// 数字0表示为： sign = 0, biasedExponent = 0和uInteger = 0。
        /// 对于非零值，sign != 0 and uInteger > 0。
        int sign;
        int biasedExponent;
        UInteger uInteger;
    };

    /// operator==, operator<, operator+, operator-的帮助程序。
    template <typename UInteger>
    NODISCARD bool EqualIgnoreSign(const BinaryScientificNumber<UInteger>& lhs, const BinaryScientificNumber<UInteger>& rhs);

    template <typename UInteger>
    NODISCARD bool LessThanIgnoreSign(const BinaryScientificNumber<UInteger>& lhs, const BinaryScientificNumber<UInteger>& rhs);

    /// 比较
    template <typename UInteger>
    NODISCARD bool operator==(const BinaryScientificNumber<UInteger>& lhs, const BinaryScientificNumber<UInteger>& rhs);

    template <typename UInteger>
    NODISCARD bool operator!=(const BinaryScientificNumber<UInteger>& lhs, const BinaryScientificNumber<UInteger>& rhs);

    template <typename UInteger>
    NODISCARD bool operator<(const BinaryScientificNumber<UInteger>& lhs, const BinaryScientificNumber<UInteger>& rhs);

    template <typename UInteger>
    NODISCARD bool operator<=(const BinaryScientificNumber<UInteger>& lhs, const BinaryScientificNumber<UInteger>& rhs);

    template <typename UInteger>
    NODISCARD bool operator>(const BinaryScientificNumber<UInteger>& lhs, const BinaryScientificNumber<UInteger>& rhs);

    template <typename UInteger>
    NODISCARD bool operator>=(const BinaryScientificNumber<UInteger>& lhs, const BinaryScientificNumber<UInteger>& rhs);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> operator+(const BinaryScientificNumber<UInteger>& lhs, const BinaryScientificNumber<UInteger>& rhs);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> operator-(const BinaryScientificNumber<UInteger>& lhs, const BinaryScientificNumber<UInteger>& rhs);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> operator*(const BinaryScientificNumber<UInteger>& lhs, const BinaryScientificNumber<UInteger>& rhs);

    /// 显式转换为用户指定的精度。
    /// 舍入模式是中提供的标志之一。模式为
    //   FE_TONEAREST:  四舍五入到最接近的平局
    //   FE_DOWNWARD:   向负无穷大取整
    //   FE_TOWARDZERO: 向零取整
    //   FE_UPWARD:     向正无穷大取整
    template <typename UInteger>
    void Convert(const BinaryScientificNumber<UInteger>& input,
                 int precision,
                 int roundingMode,
                 BinaryScientificNumber<UInteger>& output);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> AtanDivPi(const BinaryScientificNumber<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Atan2DivPi(const BinaryScientificNumber<UInteger>& y, const BinaryScientificNumber<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Clamp(const BinaryScientificNumber<UInteger>& x, const BinaryScientificNumber<UInteger>& xMin, const BinaryScientificNumber<UInteger>& xMax);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> CosPi(const BinaryScientificNumber<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Exp10(const BinaryScientificNumber<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> InvSqrt(const BinaryScientificNumber<UInteger>& x);

    template <typename UInteger>
    NODISCARD int SignToInt(const BinaryScientificNumber<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Saturate(const BinaryScientificNumber<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Sign(const BinaryScientificNumber<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> SinPi(const BinaryScientificNumber<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Sqr(const BinaryScientificNumber<UInteger>& x);

    /// 计算 u * v + w.
    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Fma(const BinaryScientificNumber<UInteger>& u,
                                                   const BinaryScientificNumber<UInteger>& v,
                                                   const BinaryScientificNumber<UInteger>& w);

    /// 产品总和 (SOP) u * v + w * z.
    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> RobustSop(const BinaryScientificNumber<UInteger>& u,
                                                         const BinaryScientificNumber<UInteger>& v,
                                                         const BinaryScientificNumber<UInteger>& w,
                                                         const BinaryScientificNumber<UInteger>& z);

    /// 产品差 (DOP) u * v - w * z.
    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> RobustDop(const BinaryScientificNumber<UInteger>& u,
                                                         const BinaryScientificNumber<UInteger>& v,
                                                         const BinaryScientificNumber<UInteger>& w,
                                                         const BinaryScientificNumber<UInteger>& z);

    /// 允许在计算结果时使用指定精度的数学函数的实现。
    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Acos(const BinaryScientificNumber<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Acosh(const BinaryScientificNumber<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Asin(const BinaryScientificNumber<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Asinh(const BinaryScientificNumber<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Atan(const BinaryScientificNumber<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Atanh(const BinaryScientificNumber<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Atan2(const BinaryScientificNumber<UInteger>& y, const BinaryScientificNumber<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Ceil(const BinaryScientificNumber<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Cos(const BinaryScientificNumber<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Cosh(const BinaryScientificNumber<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Exp(const BinaryScientificNumber<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Exp2(const BinaryScientificNumber<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Fabs(const BinaryScientificNumber<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Floor(const BinaryScientificNumber<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Fmod(const BinaryScientificNumber<UInteger>& x, const BinaryScientificNumber<UInteger>& y);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Frexp(const BinaryScientificNumber<UInteger>& x, int32_t* exponent);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Ldexp(const BinaryScientificNumber<UInteger>& x, int32_t exponent);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Log(const BinaryScientificNumber<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Log2(const BinaryScientificNumber<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Log10(const BinaryScientificNumber<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Pow(const BinaryScientificNumber<UInteger>& x, const BinaryScientificNumber<UInteger>& y);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Remainder(const BinaryScientificNumber<UInteger>& x, const BinaryScientificNumber<UInteger>& y);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Sin(const BinaryScientificNumber<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Sinh(const BinaryScientificNumber<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Sqrt(const BinaryScientificNumber<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Tan(const BinaryScientificNumber<UInteger>& x);

    template <typename UInteger>
    NODISCARD BinaryScientificNumber<UInteger> Tanh(const BinaryScientificNumber<UInteger>& x);
}

namespace std
{
    /// 表示BinaryScientificNumber是有符号类型的类型特征。
    template <typename UInteger>
    struct is_signed<Mathematics::BinaryScientificNumber<UInteger>> : true_type
    {
    };
}

namespace CoreTools
{
    /// 请参阅TypeTraits.h中关于trait IsArbitraryPrecisionInternal的注释。
    template <typename UInteger>
    struct IsArbitraryPrecisionInternal<Mathematics::BinaryScientificNumber<UInteger>> : std::true_type
    {
    };
}

#endif  // MATHEMATICS_RATIONAL_BINARY_SCIENTIFIC_NUMBER_H
