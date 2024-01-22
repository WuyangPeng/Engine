/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 23:28)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DATA_H
#define MATHEMATICS_RATIONAL_INTEGER_DATA_H

#include "Mathematics/MathematicsDll.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"

#include <array>
#include <iosfwd>
#include <vector>

namespace Mathematics
{
    // N������ҪԪ������32λ�ֽڵ���Ŀ��
    template <int N>
    class IntegerData final : private boost::totally_ordered<IntegerData<N>>
    {
    public:
        using ClassType = IntegerData<N>;

        using DataType = std::vector<uint16_t>;

        static constexpr auto intSize = 2 * N;

    public:
        enum class Special
        {
            One = 1,
        };

        explicit IntegerData(Special special) noexcept;

        IntegerData() noexcept;
        explicit IntegerData(const DataType& data);

        template <typename T>
        explicit IntegerData(T value);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsZero() const noexcept;
        NODISCARD void SetZero();
        NODISCARD NumericalValueSymbol GetSign() const noexcept;

        void SwapBigEndian() noexcept;

        void SetBit(int index, bool on);
        NODISCARD bool GetBit(int index) const;

        NODISCARD uint16_t& operator[](int index);
        NODISCARD const uint16_t& operator[](int index) const;

        // ֧�ֱȽϡ��Ƚϵķ���ֵ��
        //   -1 �� lhs < rhs,
        //    0 �� lhs == rhs,
        //   +1 �� lhs > rhs.
        // ����ȽϽ�����==��<ʹ�ã�ʹ���޷������Ƚϡ�
        NODISCARD static NumericalValueSymbol UnsignedDataCompare(const IntegerData& lhs, const IntegerData& rhs);

    private:
        template <typename T>
        void Init(T value);

        void Init(const DataType& data);

    private:
        static constexpr auto intBytes = intSize * sizeof(uint16_t);
        static constexpr auto intLast = intSize - 1;
        static constexpr auto blockSize = 16;

        using ArrayType = std::array<uint16_t, intSize>;

    private:
        // ���λ����������0��
        ArrayType buffer;
    };

    // �Ƚ�
    template <int N>
    NODISCARD bool operator==(const IntegerData<N>& lhs, const IntegerData<N>& rhs);

    template <int N>
    NODISCARD bool operator<(const IntegerData<N>& lhs, const IntegerData<N>& rhs);

    template <int N>
    std::ostream& operator<<(std::ostream& os, const IntegerData<N>& integerData);
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_DATA_H
