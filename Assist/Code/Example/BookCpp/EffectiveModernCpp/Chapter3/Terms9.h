///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/09/30 20:37)

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
                    // FP���ͱ���һ��ָ�浽������ָ�룬�ú����βΰ���һ��int��һ��const std::string&��û�з���ֵ
                    typedef void (*FP)(int, const std::string&);  // ʹ��typedef
                }

                namespace Example1
                {
                    // ���������������ͬ
                    using FP = void (*)(int, const std::string&);  // ʹ�ñ�������
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
                    // MyAllocList<T>��std::list<T, MyAlloc<T>>��ͬ���
                    template <typename T>
                    using MyAllocList = std::list<T, MyAlloc<T>>;
                }

                namespace Example1
                {
                    // MyAllocList<T>::Type��std::list<T, MyAlloc<T>>��ͬ���
                    template <typename T>
                    struct MyAllocList
                    {
                        typedef std::list<T, MyAlloc<T>> Type;
                    };

                    template <typename T>
                    class Widget
                    {
                    private:
                        // Widget<T>����һ��MyAllocList<T>�ͱ�����ݳ�Ա
                        typename MyAllocList<T>::Type list;
                    };
                }

                namespace Example2
                {
                    // ͬǰ
                    template <typename T>
                    using MyAllocList = std::list<T, MyAlloc<T>>;

                    template <typename T>
                    class Widget
                    {
                    private:
                        // �����С�typename���͡�::Type��
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

                    // ��TȡֵΪWine�ͱ�ʱMyAllocList���ػ�
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

                        // ��������У�Type�Ǹ����ݳ�Ա��
                        WineType Type;
                    };
                }

                template <typename T>
                class Example
                {
                public:
                    using Type0 = typename std::remove_const<T>::type;  // ��const T����T
                    using Type1 = typename std::remove_reference<T>::type;  // ��T&��T&&����T
                    using Type2 = typename std::add_lvalue_reference<T>::type;  // ��T����T&

                    using Type3 = typename std::remove_const<T>::type;  // C++11 const T -> T
                    using Type4 = std::remove_const_t<T>;  // C++14�еĵȼ���
                    using Type5 = typename std::remove_reference<T>::type;  // C++11 T&/T&& -> T
                    using Type6 = std::remove_reference_t<T>;  // C++ 14�еĵȼ���
                    using Type7 = typename std::add_lvalue_reference<T>::type;  // C++11 T -> T&
                    using Type8 = std::add_lvalue_reference_t<T>;  // C++ 14�еĵȼ���
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
