///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/18 19:04)

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

        static constexpr auto sm_IntSize = 2 * N;

    public:
        IntegerData() noexcept;
        explicit IntegerData(const DataType& data);

        template <typename T>
        explicit IntegerData(T value);

        template <int Other>
        IntegerData(const IntegerData<Other>& rhs);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] bool IsZero() const noexcept;
        [[nodiscard]] void SetZero();
        [[nodiscard]] NumericalValueSymbol GetSign() const noexcept;

        void SwapBigEndian();

        void SetBit(int index, bool on);
        [[nodiscard]] bool GetBit(int index) const;

        [[nodiscard]] uint16_t& operator[](int index);
        [[nodiscard]] const uint16_t& operator[](int index) const;

        // ֧�ֱȽϡ��Ƚϵķ���ֵ��
        //   -1 �� lhs < rhs,
        //    0 �� lhs == rhs,
        //   +1 �� lhs > rhs.
        // ����ȽϽ�����==��<ʹ�ã�ʹ���޷������Ƚϡ�
        [[nodiscard]] static NumericalValueSymbol UnsignedDataCompare(const IntegerData& lhs, const IntegerData& rhs);

    private:
        template <typename T>
        void Init(T value);

        void Init(const DataType& data);

    private:
        static constexpr auto sm_IntBytes = sm_IntSize * sizeof(uint16_t);
        static constexpr auto sm_IntLast = sm_IntSize - 1;
        static constexpr auto sm_BlockSize = 16;

        using ArrayType = std::array<uint16_t, sm_IntSize>;

    private:
        // ���λ����������0��
        ArrayType m_Buffer;
    };

    // �Ƚ�
    template <int N>
    [[nodiscard]] bool operator==(const IntegerData<N>& lhs, const IntegerData<N>& rhs);

    template <int N>
    [[nodiscard]] bool operator<(const IntegerData<N>& lhs, const IntegerData<N>& rhs);

    template <int N>
    std::ostream& operator<<(std::ostream& os, const IntegerData<N>& integerData);
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_DATA_H
