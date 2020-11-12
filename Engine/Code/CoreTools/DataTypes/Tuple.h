///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/03 10:20)

#ifndef CORE_TOOLS_DATA_TYPE_TUPLE_H
#define CORE_TOOLS_DATA_TYPE_TUPLE_H

// ��T������ԭ�����ݻ�������������ĳ�Ա������
// T::T();
// T::T(const T&);
// T& T::operator= (const T&);

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include "CoreTools/TemplateTools/ParamType.h"

#include <array>
#include <iosfwd>

namespace CoreTools
{
    template <int Dimension, typename Type>
    class Tuple final : private boost::totally_ordered<Tuple<Dimension, Type>>
    {
    public:
        using TupleType = Type;
        static constexpr auto TupleDimension = Dimension;

        using ClassType = Tuple<Dimension, Type>;
        using ParamType = typename ParamType<Type>::type;
        using ArrayType = std::array<Type, Dimension>;
        using ArrayTypeConstIter = typename ArrayType::const_iterator;

    public:
        Tuple() noexcept;

        explicit Tuple(ParamType param0) noexcept;
        Tuple(ParamType param0, ParamType param1) noexcept;
        Tuple(ParamType param0, ParamType param1, ParamType param2) noexcept;
        Tuple(ParamType param0, ParamType param1, ParamType param2, ParamType param3) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Type& operator[](int index) const;
        [[nodiscard]] Type& operator[](int index);

        [[nodiscard]] ArrayTypeConstIter begin() const noexcept;
        [[nodiscard]] ArrayTypeConstIter end() const noexcept;

        [[nodiscard]] Type GetSum() const noexcept;

    private:
        ArrayType m_Tuple;
    };    

    // ��T������ԭ�����ݻ�������������ĳ�Ա������
    // bool operator== (const T&,const T&);
    // bool operator< (const T&,const T&);

    template <int32_t Dimension, typename Type>
    bool operator==(const Tuple<Dimension, Type>& lhs, const Tuple<Dimension, Type>& rhs);

    template <int32_t Dimension, typename Type>
    bool operator<(const Tuple<Dimension, Type>& lhs, const Tuple<Dimension, Type>& rhs);

    template <int32_t Dimension, typename Type>
    std::ostream& operator<<(std::ostream& os, const Tuple<Dimension, Type>& tuple);
}

#endif  // CORE_TOOLS_DATA_TYPE_TUPLE_H