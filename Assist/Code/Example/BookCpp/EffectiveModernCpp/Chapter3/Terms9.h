///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/09/30 20:37)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER3_TERM9_H
#define EFFECTIVE_MODERN_CPP_CHAPTER3_TERM9_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <list>
#include <memory>
#include <string>
#include <unordered_map>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter3
        {
            namespace Terms9
            {
                namespace Example0
                {
                    typedef std::unique_ptr<std::unordered_map<std::string, std::string>> UPtrMapSS;
                }

                namespace Example1
                {
                    using UPtrMapSS = std::unique_ptr<std::unordered_map<std::string, std::string>>;
                }

                namespace Example0
                {
                    // FP的型别是一个指涉到函数的指针，该函数形参包括一个int和一个const std::string&，没有返回值
                    typedef void (*FP)(int, const std::string&);  // 使用typedef
                }

                namespace Example1
                {
                    // 和以上这句意义相同
                    using FP = void (*)(int, const std::string&);  // 使用别名声明
                }

                template <typename T>
                class MyAlloc : public std::allocator<T>
                {
                };

                class Widget
                {
                };

                namespace Example0
                {
                    // MyAllocList<T>是std::list<T, MyAlloc<T>>的同义词
                    template <typename T>
                    using MyAllocList = std::list<T, MyAlloc<T>>;
                }

                namespace Example1
                {
                    // MyAllocList<T>::Type是std::list<T, MyAlloc<T>>的同义词
                    template <typename T>
                    struct MyAllocList
                    {
                        typedef std::list<T, MyAlloc<T>> Type;
                    };

                    template <typename T>
                    class Widget
                    {
                    private:
                        // Widget<T>含有一个MyAllocList<T>型别的数据成员
                        typename MyAllocList<T>::Type list;
                    };
                }

                namespace Example2
                {
                    // 同前
                    template <typename T>
                    using MyAllocList = std::list<T, MyAlloc<T>>;

                    template <typename T>
                    class Widget
                    {
                    private:
                        // 不再有“typename”和“::Type”
                        MyAllocList<T> list;
                    };
                }

                namespace Example3
                {
                    template <typename T>
                    struct MyAllocList
                    {
                        typedef std::list<T, MyAlloc<T>> Type;
                    };

                    template <typename T>
                    class Widget
                    {
                    private:
                        typename MyAllocList<T>::Type list;
                    };

                    class Wine
                    {
                        // ...
                    };

                    // 在T取值为Wine型别时MyAllocList的特化
                    template <>
                    class MyAllocList<Wine>
                    {
                    private:
                        enum class WineType
                        {
                            White,
                            Red,
                            Rose
                        };

                        // 在这个类中，Type是个数据成员。
                        WineType Type;
                    };
                }

                template <typename T>
                class Example
                {
                public:
                    using Type0 = typename std::remove_const<T>::type;  // 由const T生成T
                    using Type1 = typename std::remove_reference<T>::type;  // 由T&或T&&生成T
                    using Type2 = typename std::add_lvalue_reference<T>::type;  // 由T生成T&

                    using Type3 = typename std::remove_const<T>::type;  // C++11 const T -> T
                    using Type4 = std::remove_const_t<T>;  // C++14中的等价物
                    using Type5 = typename std::remove_reference<T>::type;  // C++11 T&/T&& -> T
                    using Type6 = std::remove_reference_t<T>;  // C++ 14中的等价物
                    using Type7 = typename std::add_lvalue_reference<T>::type;  // C++11 T -> T&
                    using Type8 = std::add_lvalue_reference_t<T>;  // C++ 14中的等价物
                };

                template <class T>
                using RemoveConstT = typename std::remove_const<T>::type;

                template <class T>
                using RemoveReferenceT = typename std::remove_reference<T>::type;

                template <class T>
                using AddLValueReferenceT = typename std::add_lvalue_reference_t<T>::type;
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER3_TERM9_H
