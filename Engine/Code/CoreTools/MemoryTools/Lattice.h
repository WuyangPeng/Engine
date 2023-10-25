///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/21 09:31)

#ifndef CORE_TOOLS_MEMORY_TOOLS_LATTICE_H
#define CORE_TOOLS_MEMORY_TOOLS_LATTICE_H

#include "CoreTools/CoreToolsDll.h"

#include "TypeTraits.h"
#include "System/Helper/PragmaWarning.h"

#include <gsl/util>
#include <array>
#include <vector>

namespace CoreTools
{
    /// ����ʱ��֪��С�ĸ��ӿ�ܵ�ʵ�֡�
    /// ����û�����ݳ�Ա��
    /// ���ĳ�Ա����ʹ��ģ��Ԫ��̽�����ӳ�䵽�������ʹӶ�����ӳ��������
    /// Sizes��������n > =1��Ԫ�أ���ʾ�߽�(b[0],...,b[n-1])��
    template <bool OrderLToR, int... Sizes>
    class Lattice
    {
    public:
        using ClassType = Lattice<OrderLToR, Sizes...>;

        static_assert(sizeof...(Sizes) >= 1);

    public:
        Lattice() noexcept = default;
        virtual ~Lattice() noexcept = default;
        Lattice(const Lattice& rhs) = default;
        Lattice& operator=(const Lattice& rhs) = default;
        Lattice(Lattice&& rhs) noexcept = default;
        Lattice& operator=(Lattice&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        /// ά������Sizes�������еĲ������������ǹ��ڸ��ӿ��ע���е�'n'��
        NODISCARD static constexpr int GetDimensions() noexcept
        {
            return sizeof...(Sizes);
        }

        /// ��ȡά��d��Ԫ���������ǹ��ڸ��ӿ��ע���е�'b[d]'��
        NODISCARD int GetSize(int dimension) const;

        /// ��ȡԪ�ص����������ǹ��ڸ��ӿ��ע���е�'�˻�{d=0}^{n-1} b[d]' ��
        NODISCARD constexpr int GetSize() const noexcept
        {
            return MetaProduct<Sizes...>::value;
        }

        /// �����������ת����

        /// ��nά����ת��Ϊһά����������������
        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<Condition> = 0>
        requires(sizeof...(IndexTypes) == sizeof...(Sizes))
        NODISCARD int GetIndex(IndexTypes... tuple) const noexcept;

        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<Condition> = 0>
        NODISCARD int GetIndex(const std::array<int, sizeof...(Sizes)>& coordinate) const;

        /// ��һά����ת��Ϊnά����������������
        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<Condition> = 0>
        NODISCARD std::array<int, sizeof...(Sizes)> GetCoordinate(int index) const;

        /// ���ҵ��������ת����

        /// ��nά����ת��Ϊһά���������ҵ�������
        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<!Condition> = 0>
        requires(sizeof...(IndexTypes) == sizeof...(Sizes))
        NODISCARD int GetIndex(IndexTypes... tuple) const noexcept;

        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<!Condition> = 0>
        NODISCARD int GetIndex(const std::array<int, sizeof...(Sizes)>& coordinate) const;

        /// ��һά����ת��Ϊnά���������ҵ�������
        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<!Condition> = 0>
        NODISCARD std::array<int, sizeof...(Sizes)> GetCoordinate(int index) const;

    private:
        // Ԫ���֧�ִ�Sizes��������ѡ�������
        template <int I, int F, int... R>
        struct MetaArgument
        {
            static const auto value = MetaArgument<I - 1, R...>::value;
        };

        template <int F, int... R>
        struct MetaArgument<0, F, R...>
        {
            static const auto value = F;
        };

        // Ԫ���֧�ֽ�Sizes����pack������������顣
        template <int I, int F, int... R>
        constexpr void MetaAssignSize(int* sizes) const noexcept
        {
            if (sizes != nullptr)
            {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                sizes[I] = F;

#include SYSTEM_WARNING_POP

                MetaAssignSize<I + 1, R...>(sizes);
            }
        }

        template <int NumElements>
        constexpr void MetaAssignSize(int*) const noexcept
        {
        }

        // Ԫ���֧�ּ���Sizes�����������ĳ˻���
        template <int...>
        struct MetaProduct : std::integral_constant<int, 1>
        {
        };

        template <int F, int... R>
        struct MetaProduct<F, R...> : std::integral_constant<int, F * MetaProduct<R...>::value>
        {
        };

        // ��ʹ�ô��������������(IndexTypes...)��Ԫ���֧�֡�
        template <typename First, typename... Successors>
        NODISCARD constexpr int MetaGetIndexLToR(First first, Successors... successors) const noexcept requires(std::is_integral_v<First> && !std::is_same_v<First, bool>)
        {
            constexpr auto size = MetaArgument<sizeof...(Sizes) - 1 - sizeof...(Successors), Sizes...>::value;

            return gsl::narrow_cast<int>(first) + size * MetaGetIndexLToR(successors...);
        }

        template <typename Last>
        NODISCARD constexpr int MetaGetIndexLToR(Last last) const noexcept requires(std::is_integral_v<Last> && !std::is_same_v<Last, bool>)
        {
            return gsl::narrow_cast<int>(last);
        }

        // Ԫ���֧��ʹ�ô��������������(const std::array<*,*)>&) ��
        template <int NumDimensions = sizeof...(Sizes), TraitSelector<(NumDimensions > 1)> = 0>
        NODISCARD int GetIndexLToR(const std::array<int, sizeof...(Sizes)>& coordinate) const;

        template <int NumDimensions = sizeof...(Sizes), TraitSelector<NumDimensions == 1> = 0>
        NODISCARD int GetIndexLToR(const std::array<int, 1>& coordinate) const noexcept;

        // ��ʹ�ô��ҵ������������(IndexTypes...)��Ԫ���֧�֡�
        template <typename Term, typename First, typename... Successors>
        NODISCARD constexpr int MetaGetIndexRToL(Term t, First first, Successors... successors) const noexcept requires(std::is_integral_v<First> && !std::is_same_v<First, bool>)
        {
            constexpr auto size = MetaArgument<sizeof...(Sizes) - sizeof...(Successors), Sizes...>::value;

            return MetaGetIndexRToL(size * gsl::narrow_cast<int>(first + t), successors...);
        }

        template <typename Term, typename First>
        NODISCARD constexpr int MetaGetIndexRToL(Term t, First first) const noexcept requires(std::is_integral_v<First> && !std::is_same_v<First, bool>)
        {
            return gsl::narrow_cast<int>(first + t);
        }

        // Ԫ���֧��ʹ�ô��ҵ������������(const std::array<*,*)>&) ��
        template <int NumDimensions = sizeof...(Sizes), TraitSelector<(NumDimensions > 1)> = 0>
        NODISCARD int GetIndexRToL(const std::array<int, sizeof...(Sizes)>& coordinate) const;

        template <int NumDimensions = sizeof...(Sizes), TraitSelector<NumDimensions == 1> = 0>
        NODISCARD int GetIndexRToL(const std::array<int, 1>& coordinate) const noexcept;

    public:
        static int constexpr numDimensions = sizeof...(Sizes);
        static int constexpr numElements = MetaProduct<Sizes...>::value;
    };

    /// ��������ʱ��֪�����С�ĸ��ӿ�ܵ�ʵ�֡�
    /// ������size�洢(b[0],...,b[n-1])����numElements�洢�߽�ĳ˻���
    template <bool OrderLToR>
    class Lattice<OrderLToR> : private boost::totally_ordered<Lattice<OrderLToR>>
    {
    public:
        using ClassType = Lattice<OrderLToR>;

        using SizeType = std::vector<int>;

    public:
        Lattice() noexcept;
        virtual ~Lattice() noexcept = default;
        Lattice(const Lattice& rhs) = default;
        Lattice& operator=(const Lattice& rhs) = default;
        Lattice(Lattice&& rhs) noexcept = default;
        Lattice& operator=(Lattice&& rhs) noexcept = default;

        // ���ӿ�ܾ���ָ���Ĵ�С��
        explicit Lattice(const SizeType& sizes);
        explicit Lattice(const std::initializer_list<int>& sizes);

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // ֧����Ĭ�Ϲ��캯��������ʼ���ӿ�ܵ��ӳٹ��졣
        // ���Ժ��ִ�й����У����Ը�����Ҫ���ø��ӿ�ܴ�С��
        virtual void Reset(const SizeType& aSizes);
        virtual void Reset(const std::initializer_list<int>& aSizes);

        /// ά������size��Ԫ���������ǹ��ڸ��ӿ��ע���е�'n'��
        NODISCARD int GetDimensions() const;

        // ��ȡά��d��Ԫ���������ǹ��ڸ��ӿ��ע���е�'b[d]'��
        NODISCARD int GetSize(int dimension) const;

        // ��ȡԪ�ص����������ǹ��ڸ��ӿ��ע���е�'�˻�{d=0}^{n-1} b[d]'��
        NODISCARD int GetSize() const noexcept;

        /// ��nά����ת��Ϊһά����������������
        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<Condition> = 0>
        NODISCARD int GetIndex(IndexTypes... tuple) const;

        template <bool Condition = OrderLToR, TraitSelector<Condition> = 0>
        NODISCARD int GetIndex(const SizeType& coordinate) const;

        /// ��nά����ת��Ϊһά���������ҵ�������
        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<!Condition> = 0>
        NODISCARD int GetIndex(IndexTypes... tuple) const;

        template <bool Condition = OrderLToR, TraitSelector<!Condition> = 0>
        NODISCARD int GetIndex(const SizeType& coordinate) const;

        /// ��һά����ת��Ϊnά����������������
        template <bool Condition = OrderLToR, TraitSelector<Condition> = 0>
        NODISCARD SizeType GetCoordinate(int index) const;

        /// ��һά����ת��Ϊnά���������ҵ�������
        template <bool Condition = OrderLToR, TraitSelector<!Condition> = 0>
        NODISCARD SizeType GetCoordinate(int index) const;

        // ֧�ֶ�Lattice�����������ͱȽϡ�
        NODISCARD bool operator==(const Lattice& rhs) const noexcept;

        NODISCARD bool operator<(const Lattice& rhs) const noexcept;

    private:
        template <typename Container>
        void InternalReset(const Container& container);

        // ��ʹ�ô��������������(IndexTypes...) ��Ԫ���֧�֡�
        template <typename First, typename... Successors>
        requires(std::is_integral_v<First> && !std::is_same_v<First, bool>)
        NODISCARD int MetaGetIndexLToR(First first, Successors... successors) const;

        template <typename Last>
        requires(std::is_integral_v<Last> && !std::is_same_v<Last, bool>)
        NODISCARD int MetaGetIndexLToR(Last last) const noexcept;

        // ��ʹ�ô��ҵ������������(IndexTypes...) ��Ԫ���֧�֡�
        template <typename Term, typename First, typename... Successors>
        requires(std::is_integral_v<First> && !std::is_same_v<First, bool>)
        NODISCARD int MetaGetIndexRToL(Term t, First first, Successors... successors) const;

        template <typename Term, typename First>
        requires(std::is_integral_v<First> && !std::is_same_v<First, bool>)
        NODISCARD int MetaGetIndexRToL(Term t, First first) const noexcept;

        template <typename First>
        requires(std::is_integral_v<First> && !std::is_same_v<First, bool>)
        NODISCARD int MetaGetIndexRToL(First first) const;

    protected:
        int numElements;
        SizeType sizes;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_LATTICE_H
