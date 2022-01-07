///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.7 (2021/11/29 21:29)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER6_TERM31_H
#define EFFECTIVE_MODERN_CPP_CHAPTER6_TERM31_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <algorithm>
#include <functional>
#include <vector>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter6
        {
            namespace Terms31
            {
                void AddDivisorFilter();

                int ComputeSomeValue1() noexcept;
                int ComputeSomeValue2() noexcept;

                constexpr int ComputeDivisor(int calc1, int calc2) noexcept
                {
                    return calc1 + calc2;
                }

                namespace Example0
                {
                    template <typename C>
                    void WorkWithContainer(const C& container)
                    {
                        const auto calc1 = ComputeSomeValue1();  // ͬ��
                        const auto calc2 = ComputeSomeValue2();  // ͬ��

                        auto divisor = ComputeDivisor(calc1, calc2);  // ͬ��

                        using ContElemT = typename C::value_type;  // Ϊʵ�ַ����㷨��ȡ�������е�Ԫ���ͱ�

                        using std::begin;
                        using std::end;

                        // ������������е�Ԫ��ֵ����divisor�ı���
                        if (std::all_of(begin(container), end(container),
                                        [&](const ContElemT& value) {
                                            return value % divisor;
                                        }))
                        {
                            // ��ȫ�ǣ�ִ������
                            // ...
                        }
                        else
                        {
                            // ��������һ�����ǣ�ִ������
                            // ...
                        }
                    }
                }

                namespace Example1
                {
                    template <typename C>
                    void WorkWithContainer(const C& container)
                    {
                        const auto calc1 = ComputeSomeValue1();  // ͬ��
                        const auto calc2 = ComputeSomeValue2();  // ͬ��

                        auto divisor = ComputeDivisor(calc1, calc2);  // ͬ��

                        using std::begin;
                        using std::end;

                        // ������������е�Ԫ��ֵ����divisor�ı���
                        if (std::all_of(begin(container), end(container),
                                        [&](const auto& value) {  // C++14
                                            return value % divisor;
                                        }))
                        {
                            // ��ȫ�ǣ�ִ������
                            // ...
                        }
                        else
                        {
                            // ��������һ�����ǣ�ִ������
                            // ...
                        }
                    }
                }

                namespace Example0
                {
                    using FilterContainer = std::vector<std::function<bool(int)>>;

                    extern FilterContainer filters;

                    class Widget
                    {
                    public:
                        // ...
                        // ���캯����
                        void AddFilter() const;  // ��filters���һ����Ŀ

                    private:
                        int divisor;  // ����Widget��filterԪ��
                    };
                }

                namespace Example1
                {
                    using FilterContainer = std::vector<std::function<bool(int)>>;

                    extern FilterContainer filters;

                    class Widget
                    {
                    public:
                        // ...
                        // ���캯����
                        void AddFilter() const;  // ��filters���һ����Ŀ

                    private:
                        int divisor;  // ����Widget��filterԪ��
                    };

                    void DoSomeWork();
                }

                namespace Example2
                {
                    using FilterContainer = std::vector<std::function<bool(int)>>;

                    extern FilterContainer filters;

                    class Widget
                    {
                    public:
                        // ...
                        // ���캯����
                        void AddFilter() const;  // ��filters���һ����Ŀ

                    private:
                        int divisor;  // ����Widget��filterԪ��
                    };
                }

                namespace Example3
                {
                    using FilterContainer = std::vector<std::function<bool(int)>>;

                    extern FilterContainer filters;

                    class Widget
                    {
                    public:
                        // ...
                        // ���캯����
                        void AddFilter() const;  // ��filters���һ����Ŀ

                    private:
                        int divisor;  // ����Widget��filterԪ��
                    };
                }

                namespace Example4
                {
                    using FilterContainer = std::vector<std::function<bool(int)>>;

                    extern FilterContainer filters;

                    class Widget
                    {
                    public:
                        // ...
                        // ���캯����
                        void AddFilter() const;  // ��filters���һ����Ŀ

                    private:
                        int divisor;  // ����Widget��filterԪ��
                    };
                }

                namespace Example1
                {
                    void AddDivisorFilter();
                }
            }
        }
    }
}
#endif  // EFFECTIVE_MODERN_CPP_CHAPTER6_TERM31_H
