///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/10 13:29)

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
    class Tuple : private boost::totally_ordered<Tuple<Dimension, Type>>
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

        explicit Tuple(ParamType param0) noexcept(std::is_arithmetic_v<Type>);
        Tuple(ParamType param0, ParamType param1) noexcept(std::is_arithmetic_v<Type>);
        Tuple(ParamType param0, ParamType param1, ParamType param2) noexcept(std::is_arithmetic_v<Type>);
        Tuple(ParamType param0, ParamType param1, ParamType param2, ParamType param3) noexcept(std::is_arithmetic_v<Type>);

        CLASS_INVARIANT_DECLARE;

        NODISCARD const Type& operator[](int index) const;
        NODISCARD Type& operator[](int index);

        NODISCARD ArrayTypeConstIter begin() const noexcept;
        NODISCARD ArrayTypeConstIter end() const noexcept;

        NODISCARD Type GetSum() const noexcept;

    private:
        ArrayType tuple;
    };

    // ��T������ԭ�����ݻ�������������ĳ�Ա������
    // bool operator== (const T&,const T&);
    // bool operator< (const T&,const T&);

    template <int32_t Dimension, typename Type>
    NODISCARD bool operator==(const Tuple<Dimension, Type>& lhs, const Tuple<Dimension, Type>& rhs);

    template <int32_t Dimension, typename Type>
    NODISCARD bool operator<(const Tuple<Dimension, Type>& lhs, const Tuple<Dimension, Type>& rhs);

    template <int32_t Dimension, typename Type>
    std::ostream& operator<<(std::ostream& os, const Tuple<Dimension, Type>& tuple);
}

#endif  // CORE_TOOLS_DATA_TYPE_TUPLE_H