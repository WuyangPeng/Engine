///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/04/14 23:15)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE2_5_H
#define CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE2_5_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "System/Helper/PragmaWarning/TypeTraits.h"

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        // Ariel Badichi的解决方案
        template <typename T>
        struct ReturnType1
        {
            typedef void Type;
        };

        template <typename R>
        struct ReturnType1<R()>
        {
            typedef R Type;
        };

        template <typename T>
        struct TypeDescriptor20
        {
            std::ostream& Print(std::ostream& out) const
            {
                if (boost::is_volatile<T>::value)
                {
                    typedef typename boost::remove_volatile<T>::type NewType;
                    out << "a volatile " << TypeDescriptor20<NewType>();
                }
                else if (boost::is_const<T>::value)
                {
                    typedef typename boost::remove_const<T>::type NewType;
                    out << "a const " << TypeDescriptor20<NewType>();
                }
                else if (boost::is_pointer<T>::value)
                {
                    typedef typename boost::remove_pointer<T>::type NewType;
                    out << "pointer to " << TypeDescriptor20<NewType>();
                }
                else if (boost::is_reference<T>::value)
                {
                    typedef typename boost::remove_reference<T>::type NewType;
                    out << "reference to " << TypeDescriptor20<NewType>();
                }
                else if (boost::is_array<T>::value)
                {
                    typedef typename boost::remove_bounds<T>::type NewType;
                    out << "array of " << TypeDescriptor20<NewType>();
                }
                else if (boost::is_function<T>::value)
                {
                    typedef typename ReturnType1<T>::Type NewType;
                    out << "function returning " << TypeDescriptor20<NewType>();
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
                else if (boost::is_same<void, T>::value)
                {
                    out << "void";
                }
                else
                {
                    out << "unknown";
                }
                return out;
            }
        };

        template <typename T>
        std::ostream& operator<<(std::ostream& out, const TypeDescriptor20<T>& desc)
        {
            return desc.Print(out);
        }

        // 我的解决方案
        template <typename T>
        struct ReturnType2
        {
            using Type = void;
        };

        template <typename R>
        struct ReturnType2<R()>
        {
            using Type = R;
        };

        template <typename T>
        struct TypeDescriptor21
        {
            std::ostream& Print(std::ostream& os) const
            {
                if constexpr (std::is_volatile<T>::value)
                {
                    using NewType = typename std::remove_volatile<T>::type;
                    os << "a volatile " << TypeDescriptor21<NewType>();
                }
                else if constexpr (std::is_const<T>::value)
                {
                    using NewType = typename std::remove_const<T>::type;
                    os << "a const " << TypeDescriptor21<NewType>();
                }
                else if constexpr (std::is_pointer<T>::value)
                {
                    using NewType = typename std::remove_pointer<T>::type;
                    os << "pointer to " << TypeDescriptor21<NewType>();
                }
                else if constexpr (std::is_reference<T>::value)
                {
                    using NewType = typename std::remove_reference<T>::type;
                    os << "reference to " << TypeDescriptor21<NewType>();
                }
                else if constexpr (std::is_array<T>::value)
                {
                    using NewType = typename boost::remove_bounds<T>::type;
                    os << "array of " << TypeDescriptor21<NewType>();
                }
                else if constexpr (std::is_function<T>::value)
                {
                    using NewType = typename ReturnType2<T>::Type;
                    os << "function returning " << TypeDescriptor21<NewType>();
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
        };

        template <typename T>
        std::ostream& operator<<(std::ostream& out, const TypeDescriptor21<T>& desc)
        {
            return desc.Print(out);
        }
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE2_5_H
