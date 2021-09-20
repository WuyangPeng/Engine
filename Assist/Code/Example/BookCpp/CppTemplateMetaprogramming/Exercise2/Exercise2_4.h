///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/04/14 23:15)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE2_4_H
#define CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE2_4_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        // �ҵĽ������
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

        // Ariel Badichi�Ľ������
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
        // ����Ľ�������������������������������ͬһ��������о���volatile��const�����޷���VC ++ 8.0�Ͻ��б��롣
        // ����Ҫ��ģ��Ĳ����ػ��н�const volatile�����һ���Խ�������⡣
        template <typename T>
        struct TypeDescriptor11<const volatile T>
        {
            std::ostream& Print(std::ostream& out) const
            {
                out << "const volatile " << TypeDescriptor11<T>();
                return out;
            }
        };

        // ͬ��Ҳ���Դ���* const
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
