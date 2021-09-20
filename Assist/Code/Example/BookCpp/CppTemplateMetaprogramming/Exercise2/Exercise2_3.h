///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/04/14 23:15)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE2_3_H
#define CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE2_3_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "System/Helper/PragmaWarning/TypeTraits.h"

#include <boost/type_traits/extent.hpp>
#include <boost/type_traits/rank.hpp>
#include <boost/type_traits/remove_all_extents.hpp>
#include <cstddef>
#include <iostream>

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        template <class>
        int TypeDescriptor() noexcept
        {
            return 0;
        }

        CPP_TEMPLATE_METAPROGRAMMING_DEFAULT_DECLARE void F();

        // Ariel Badichi�Ľ������

        // by HSH
        // �����и�С����
        // std::cout << type_descriptor<int[2][3]>() << std::endl;
        // prints int[3][2]...
        // ����Ϊ����ͨ���������硰 bound_descriptor��֮��ķ����������
        // ���ǣ��ⲻ��һ���ܺõĽ��������
        template <typename T>
        struct Bounds
        {
            static constexpr std::size_t value = 0;
        };

        template <typename T, std::size_t N>
        struct Bounds<T[N]>
        {
            static constexpr std::size_t value = N;
        };

        template <typename T>
        struct TypeDescriptor1
        {
            std::ostream& Print(std::ostream& out) const
            {
                if (boost::is_volatile<T>::value)
                {
                    typedef typename boost::remove_volatile<T>::type NewType;
                    out << TypeDescriptor1<NewType>() << " volatile";
                }
                else if (boost::is_const<T>::value)
                {
                    typedef typename boost::remove_const<T>::type NewType;
                    out << TypeDescriptor1<NewType>() << " const";
                }
                else if (boost::is_pointer<T>::value)
                {
                    typedef typename boost::remove_pointer<T>::type NewType;
                    out << TypeDescriptor1<NewType>() << " *";
                }
                else if (boost::is_reference<T>::value)
                {
                    typedef typename boost::remove_reference<T>::type NewType;
                    out << TypeDescriptor1<NewType>() << " &";
                }
                else if (boost::is_array<T>::value)
                {
                    typedef typename boost::remove_bounds<T>::type NewType;
                    out << TypeDescriptor1<NewType>() << " [" << Bounds<T>::value << "]";
                }
                else if (boost::is_same<long, T>::value)
                {
                    out << "long";
                }
                else if (boost::is_same<int, T>::value)
                {
                    out << "int";
                }
                else if (boost::is_same<short, T>::value)
                {
                    out << "short";
                }
                else if (boost::is_same<char, T>::value)
                {
                    out << "char";
                }
                else
                {
                    out << "unknown";
                }
                return out;
            }
        };

        template <typename T>
        std::ostream& operator<<(std::ostream& out, const TypeDescriptor1<T>& desc)
        {
            return desc.Print(out);
        }

        // Nicolas Haller <nicolas@boiteameuh.org>�Ľ������
        // ����Ariel Badichi���������������ϰ���������������չ����
        // �ҿ϶����кܶ�Ľ�����أ�����ⲻ����ȫ����Ļ�������������ʱ�޸��ҵĽ��������

        // ���ʵ������ģ������������
        template <class T>
        struct TypeDescriptor2
        {
        };

        // �����������͵��ػ�ģ��
        template <>
        struct TypeDescriptor2<int>
        {
            static std::ostream& Print(std::ostream& ost)
            {
                return ost << "int";
            }
        };

        template <>
        struct TypeDescriptor2<long>
        {
            static std::ostream& Print(std::ostream& ost)
            {
                return ost << "long";
            }
        };

        template <>
        struct TypeDescriptor2<char>
        {
            static std::ostream& Print(std::ostream& ost)
            {
                return ost << "char";
            }
        };

        // �й��޶���Ϊָ��/���õ��ػ�ģ��
        template <class T>
        struct TypeDescriptor2<T*>
        {
            static std::ostream& Print(std::ostream& ost)
            {
                return TypeDescriptor2<T>::Print(ost) << " *";
            }
        };

        template <class T>
        struct TypeDescriptor2<T&>
        {
            static std::ostream& Print(std::ostream& ost)
            {
                return TypeDescriptor2<T>::Print(ost) << " &";
            }
        };

        template <class T>
        struct TypeDescriptor2<const T>
        {
            static std::ostream& Print(std::ostream& ost)
            {
                ost << " const ";
                return TypeDescriptor2<T>::Print(ost);
            }
        };

        // ������Ҫ�κ��ػ���ģ�庯��
        template <class T>
        std::ostream& operator<<(std::ostream& ost, MAYBE_UNUSED const TypeDescriptor2<T>& tdesc)
        {
            return TypeDescriptor2<T>::Print(ost);
        }

        // Mitch Besser�Ľ������
        template <typename T>
        struct TypeDescriptor3
        {
            std::ostream& Print(std::ostream& out) const
            {
                if (boost::is_volatile<T>::value)
                {
                    typedef typename boost::remove_volatile<T>::type NewType;
                    out << TypeDescriptor3<NewType>() << " volatile";
                }
                else if (boost::is_const<T>::value)
                {
                    typedef typename boost::remove_const<T>::type NewType;
                    out << TypeDescriptor3<NewType>() << " const";
                }
                else if (boost::is_pointer<T>::value)
                {
                    typedef typename boost::remove_pointer<T>::type NewType;
                    out << TypeDescriptor3<NewType>() << " *";
                }
                else if (boost::is_reference<T>::value)
                {
                    typedef typename boost::remove_reference<T>::type NewType;
                    out << TypeDescriptor3<NewType>() << " &";
                }
                else if (boost::is_array<T>::value)
                {
                    // Ϊ�˻��ʹ������Ķ��ά�ȣ��Ҹ����˴��룺
                    // typedef typename boost::remove_bounds<T>::type NewType;
                    // out << TypeDescriptor3<NewType>() << " [" << Bounds<T>::value << "]";
                    // �������������������ٹ̶��������ȣ���ƥ�������Ariel Badichi�Ĵ��룩��
                    // const unsigned rank = boost::rank<T>::value;
                    // typedef typename boost::remove_extent<T, rank - 1>::type slice;
                    // out << TypeDescriptor3<slice>() << "[" << boost::extent<T, rank - 1>::value << "]";
                    // ���ҵ��ǣ����Ҳ���ʹboost::remove_extent<>����ɾ�������Ч�ȼ��ķ�������Ϊ��û��ģ���������ִ�д˲�����
                    // ex:  boost::remove_extent<T /*, rank - 1 */> // so sad
                    // ���boost����Ļ���������е�ͨ���������޷���������
                    // ��ˣ���Ϊ����������ҹ�����һ��˽�еĵݹ������������
                    typedef typename boost::remove_all_extents<T>::type no_extents;
                    out << TypeDescriptor3<no_extents>();
                    PutExtents<T>(out);
                }
                else if (boost::is_same<long, T>::value)
                {
                    out << "long";
                }
                else if (boost::is_same<int, T>::value)
                {
                    out << "int";
                }
                else if (boost::is_same<short, T>::value)
                {
                    out << "short";
                }
                else if (boost::is_same<char, T>::value)
                {
                    out << "char";
                }
                else
                {
                    out << "unknown";
                }
                return out;
            }

        private:
            template <typename Array>
            void PutExtents(std::ostream& out) const
            {
                out << "[" << boost::extent<Array>::value << "]";
                typedef typename boost::remove_extent<Array>::type slice;
                if (boost::is_array<slice>::value)
                {
                    PutExtents<slice>(out);
                }
            }
        };

        template <typename T>
        std::ostream& operator<<(std::ostream& out, const TypeDescriptor3<T>& desc)
        {
            return desc.Print(out);
        }

        // �ҵĽ������
        template <typename T>
        struct TypeDescriptor4
        {
            std::ostream& Print(std::ostream& os) const
            {
                if constexpr (std::is_volatile<T>::value)
                {
                    using NewType = typename std::remove_volatile<T>::type;
                    os << TypeDescriptor4<NewType>() << " volatile";
                }
                else if constexpr (std::is_const<T>::value)
                {
                    using NewType = typename std::remove_const<T>::type;
                    os << TypeDescriptor4<NewType>() << " const";
                }
                else if constexpr (std::is_pointer<T>::value)
                {
                    using NewType = typename std::remove_pointer<T>::type;
                    os << TypeDescriptor4<NewType>() << " *";
                }
                else if constexpr (std::is_reference<T>::value)
                {
                    using NewType = typename std::remove_reference<T>::type;
                    os << TypeDescriptor4<NewType>() << " &";
                }
                else if constexpr (std::is_array<T>::value)
                {
                    using NoExtents = typename std::remove_all_extents<T>::type;
                    os << TypeDescriptor4<NoExtents>();
                    PutExtents<T>(os);
                }
                else if constexpr (std::is_same<long, T>::value)
                {
                    os << "long";
                }
                else if constexpr (std::is_same<int, T>::value)
                {
                    os << "int";
                }
                else if constexpr (std::is_same<short, T>::value)
                {
                    os << "short";
                }
                else if constexpr (std::is_same<char, T>::value)
                {
                    os << "char";
                }
                else
                {
                    os << "unknown";
                }
                return os;
            }

        private:
            template <typename Array>
            void PutExtents(std::ostream& out) const
            {
                out << "[" << std::extent<Array>::value << "]";
                using Slice = typename std::remove_extent<Array>::type;
                if (std::is_array<Slice>::value)
                {
                    PutExtents<Slice>(out);
                }
            }
        };

        template <typename T>
        std::ostream& operator<<(std::ostream& os, const TypeDescriptor4<T>& typeDescriptor)
        {
            return typeDescriptor.Print(os);
        }
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE2_3_H
