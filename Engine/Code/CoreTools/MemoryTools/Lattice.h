///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:31)

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
    /// 编译时已知大小的格子框架的实现。
    /// 该类没有数据成员。
    /// 它的成员函数使用模板元编程将索引映射到多索引和从多索引映射索引。
    /// Sizes参数包有n > =1个元素，表示边界(b[0],...,b[n-1])。
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

        /// 维度数是Sizes参数包中的参数数量。这是关于格子框架注释中的'n'。
        NODISCARD static constexpr int GetDimensions() noexcept
        {
            return sizeof...(Sizes);
        }

        /// 获取维度d的元素数。这是关于格子框架注释中的'b[d]'。
        NODISCARD int GetSize(int dimension) const;

        /// 获取元素的数量。这是关于格子框架注释中的'乘积{d=0}^{n-1} b[d]' 。
        NODISCARD constexpr int GetSize() const noexcept
        {
            return MetaProduct<Sizes...>::value;
        }

        /// 从左到右排序的转换。

        /// 从n维索引转换为一维索引，从左到右排序。
        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<Condition> = 0>
        requires(sizeof...(IndexTypes) == sizeof...(Sizes))
        NODISCARD int GetIndex(IndexTypes... tuple) const noexcept;

        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<Condition> = 0>
        NODISCARD int GetIndex(const std::array<int, sizeof...(Sizes)>& coordinate) const;

        /// 将一维索引转换为n维索引，从左到右排序。
        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<Condition> = 0>
        NODISCARD std::array<int, sizeof...(Sizes)> GetCoordinate(int index) const;

        /// 从右到左排序的转换。

        /// 从n维索引转换为一维索引，从右到左排序。
        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<!Condition> = 0>
        requires(sizeof...(IndexTypes) == sizeof...(Sizes))
        NODISCARD int GetIndex(IndexTypes... tuple) const noexcept;

        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<!Condition> = 0>
        NODISCARD int GetIndex(const std::array<int, sizeof...(Sizes)>& coordinate) const;

        /// 将一维索引转换为n维索引，从右到左排序。
        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<!Condition> = 0>
        NODISCARD std::array<int, sizeof...(Sizes)> GetCoordinate(int index) const;

    private:
        // 元编程支持从Sizes参数包中选择参数。
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

        // 元编程支持将Sizes参数pack参数分配给数组。
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

        // 元编程支持计算Sizes参数包参数的乘积。
        template <int...>
        struct MetaProduct : std::integral_constant<int, 1>
        {
        };

        template <int F, int... R>
        struct MetaProduct<F, R...> : std::integral_constant<int, F * MetaProduct<R...>::value>
        {
        };

        // 对使用从左到右排序的索引(IndexTypes...)的元编程支持。
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

        // 元编程支持使用从左到右排序的索引(const std::array<*,*)>&) 。
        template <int NumDimensions = sizeof...(Sizes), TraitSelector<(NumDimensions > 1)> = 0>
        NODISCARD int GetIndexLToR(const std::array<int, sizeof...(Sizes)>& coordinate) const;

        template <int NumDimensions = sizeof...(Sizes), TraitSelector<NumDimensions == 1> = 0>
        NODISCARD int GetIndexLToR(const std::array<int, 1>& coordinate) const noexcept;

        // 对使用从右到左排序的索引(IndexTypes...)的元编程支持。
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

        // 元编程支持使用从右到左排序的索引(const std::array<*,*)>&) 。
        template <int NumDimensions = sizeof...(Sizes), TraitSelector<(NumDimensions > 1)> = 0>
        NODISCARD int GetIndexRToL(const std::array<int, sizeof...(Sizes)>& coordinate) const;

        template <int NumDimensions = sizeof...(Sizes), TraitSelector<NumDimensions == 1> = 0>
        NODISCARD int GetIndexRToL(const std::array<int, 1>& coordinate) const noexcept;

    public:
        static int constexpr numDimensions = sizeof...(Sizes);
        static int constexpr numElements = MetaProduct<Sizes...>::value;
    };

    /// 仅在运行时才知道其大小的格子框架的实现。
    /// 该类以size存储(b[0],...,b[n-1])，以numElements存储边界的乘积。
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

        // 格子框架具有指定的大小。
        explicit Lattice(const SizeType& sizes);
        explicit Lattice(const std::initializer_list<int>& sizes);

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // 支持由默认构造函数创建初始格子框架的延迟构造。
        // 在以后的执行过程中，可以根据需要设置格子框架大小。
        virtual void Reset(const SizeType& aSizes);
        virtual void Reset(const std::initializer_list<int>& aSizes);

        /// 维度数是size的元素数。这是关于格子框架注释中的'n'。
        NODISCARD int GetDimensions() const;

        // 获取维度d的元素数。这是关于格子框架注释中的'b[d]'。
        NODISCARD int GetSize(int dimension) const;

        // 获取元素的数量。这是关于格子框架注释中的'乘积{d=0}^{n-1} b[d]'。
        NODISCARD int GetSize() const noexcept;

        /// 从n维索引转换为一维索引，从左到右排序。
        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<Condition> = 0>
        NODISCARD int GetIndex(IndexTypes... tuple) const;

        template <bool Condition = OrderLToR, TraitSelector<Condition> = 0>
        NODISCARD int GetIndex(const SizeType& coordinate) const;

        /// 从n维索引转换为一维索引，从右到左排序。
        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<!Condition> = 0>
        NODISCARD int GetIndex(IndexTypes... tuple) const;

        template <bool Condition = OrderLToR, TraitSelector<!Condition> = 0>
        NODISCARD int GetIndex(const SizeType& coordinate) const;

        /// 将一维索引转换为n维索引，从左到右排序。
        template <bool Condition = OrderLToR, TraitSelector<Condition> = 0>
        NODISCARD SizeType GetCoordinate(int index) const;

        /// 将一维索引转换为n维索引，从右到左排序。
        template <bool Condition = OrderLToR, TraitSelector<!Condition> = 0>
        NODISCARD SizeType GetCoordinate(int index) const;

        // 支持对Lattice对象进行排序和比较。
        NODISCARD bool operator==(const Lattice& rhs) const noexcept;

        NODISCARD bool operator<(const Lattice& rhs) const noexcept;

    private:
        template <typename Container>
        void InternalReset(const Container& container);

        // 对使用从左到右排序的索引(IndexTypes...) 的元编程支持。
        template <typename First, typename... Successors>
        requires(std::is_integral_v<First> && !std::is_same_v<First, bool>)
        NODISCARD int MetaGetIndexLToR(First first, Successors... successors) const;

        template <typename Last>
        requires(std::is_integral_v<Last> && !std::is_same_v<Last, bool>)
        NODISCARD int MetaGetIndexLToR(Last last) const noexcept;

        // 对使用从右到左排序的索引(IndexTypes...) 的元编程支持。
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
