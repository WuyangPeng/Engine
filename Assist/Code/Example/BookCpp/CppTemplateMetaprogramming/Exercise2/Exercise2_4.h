///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/04/14 23:15)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE2_4_H
#define CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE2_4_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        // 我的解决方案
        template <class T>
        struct TypeDescriptor10
        {
        };

        template <>
        struct TypeDescriptor10<int>
        {
            std::ostream& Print(std::ostream& os) const
            {
                return os << "int";
            }
        };

        template <>
        struct TypeDescriptor10<long>
        {
            std::ostream& Print(std::ostream& os) const
            {
                return os << "long";
            }
        };

        template <>
        struct TypeDescriptor10<char>
        {
            std::ostream& Print(std::ostream& os) const
            {
                return os << "char";
            }
        };

        template <>
        struct TypeDescriptor10<short>
        {
            std::ostream& Print(std::ostream& os) const
            {
                return os << "short";
            }
        };

        template <class T>
        struct TypeDescriptor10<T*>
        {
            std::ostream& Print(std::ostream& os) const
            {
                return os << TypeDescriptor10<T>{} << " *";
            }
        };

        template <class T>
        struct TypeDescriptor10<T&>
        {
            std::ostream& Print(std::ostream& os) const
            {
                return os << TypeDescriptor10<T>{} << " &";
            }
        };

        template <class T>
        struct TypeDescriptor10<const T>
        {
            std::ostream& Print(std::ostream& os) const
            {
                return os << "const " << TypeDescriptor10<T>{};
            }
        };

        template <class T>
        struct TypeDescriptor10<volatile T>
        {
            std::ostream& Print(std::ostream& os) const
            {
                return os << "volatile " << TypeDescriptor10<T>{};
            }
        };

        template <typename T>
        struct TypeDescriptor10<const volatile T>
        {
            std::ostream& Print(std::ostream& os) const
            {
                return os << "const volatile " << TypeDescriptor10<T>{};
            }
        };

        template <typename Array>
        void PutExtents(std::ostream& os)
        {
            os << "[" << std::extent<Array>::value << "]";
            using Slice = typename std::remove_extent<Array>::type;
            if (std::is_array<Slice>::value)
            {
                PutExtents<Slice>(os);
            }
        }

        template <typename T, std::size_t N>
        struct TypeDescriptor10<T[N]>
        {
            std::ostream& Print(std::ostream& os) const
            {
                using NoExtents = typename std::remove_all_extents<T[N]>::type;
                os << TypeDescriptor10<NoExtents>{};
                PutExtents<T[N]>(os);
                return os;
            }
        };

        template <typename T>
        std::ostream& operator<<(std::ostream& os, const TypeDescriptor10<T>& typeDescriptor10)
        {
            return typeDescriptor10.Print(os);
        }

        // Ariel Badichi的解决方案
        template <typename T>
        struct TypeDescriptor11;

        template <typename T>
        struct TypeDescriptor11<T*>
        {
            std::ostream& Print(std::ostream& out) const
            {
                return out << TypeDescriptor11<T>() << " *";
            }
        };

        template <typename T>
        struct TypeDescriptor11<T&>
        {
            std::ostream& Print(std::ostream& out) const
            {
                return out << TypeDescriptor11<T>() << " &";
            }
        };

        template <typename T, std::size_t N>
        struct TypeDescriptor11<T[N]>
        {
            std::ostream& Print(std::ostream& out) const
            {
                return out << TypeDescriptor11<T>() << " [" << N << "]";
            }
        };

        template <typename T>
        struct TypeDescriptor11<const T>
        {
            std::ostream& Print(std::ostream& out) const
            {
                return out << TypeDescriptor11<T>() << " const";
            }
        };

        template <typename T>
        struct TypeDescriptor11<volatile T>
        {
            std::ostream& Print(std::ostream& out) const
            {
                return out << TypeDescriptor11<T>() << " volatile";
            }
        };

        // by Irfan Zaidi
        // 上面的解决方案可以正常工作，但是如果您在同一组合类型中具有volatile和const，则无法在VC ++ 8.0上进行编译。
        // 您需要在模板的部分特化中将const volatile添加在一起以解决此问题。
        template <typename T>
        struct TypeDescriptor11<const volatile T>
        {
            std::ostream& Print(std::ostream& out) const
            {
                out << "const volatile " << TypeDescriptor11<T>();
                return out;
            }
        };

        // 同样也可以处理* const
        template <typename T>
        struct TypeDescriptor11<T* const>
        {
            std::ostream& Print(std::ostream& out) const
            {
                out << TypeDescriptor11<T>() << "* const";
                return out;
            }
        };

        template <>
        struct TypeDescriptor11<int>
        {
            std::ostream& Print(std::ostream& out) const
            {
                return out << "int";
            }
        };

        template <>
        struct TypeDescriptor11<char>
        {
            std::ostream& Print(std::ostream& out) const
            {
                return out << "char";
            }
        };

        template <>
        struct TypeDescriptor11<long>
        {
            std::ostream& Print(std::ostream& out) const
            {
                return out << "long";
            }
        };

        template <>
        struct TypeDescriptor11<short>
        {
            std::ostream& Print(std::ostream& out) const
            {
                return out << "short";
            }
        };

        template <typename T>
        std::ostream& operator<<(std::ostream& out, const TypeDescriptor11<T>& desc)
        {
            return desc.Print(out);
        }
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE2_4_H
