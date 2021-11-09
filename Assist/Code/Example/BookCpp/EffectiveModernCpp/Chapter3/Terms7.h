///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/09/30 20:37)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER3_TERM7_H
#define EFFECTIVE_MODERN_CPP_CHAPTER3_TERM7_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <iostream>
#include <string>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter3
        {
            namespace Terms7
            {
                class Widget
                {
                    //...

                private:
                    int x{ 0 };  // ���У�x��Ĭ��ֵΪ0
                    int y = 0;  // Ҳ����
                    // int z(0);  // �����У�
                };

                namespace Example0
                {
                    class Widget
                    {
                    public:
                        Widget() noexcept = default;
                        Widget(MAYBE_UNUSED int x) noexcept;
                    };
                }

                namespace Example1
                {
                    class Widget
                    {
                    public:
                        Widget(MAYBE_UNUSED int i, MAYBE_UNUSED bool b) noexcept;  // ���캯�����β���û���κ�һ���߱�std::initialize_list�ͱ�
                        Widget(MAYBE_UNUSED int i, MAYBE_UNUSED double d) noexcept;
                    };
                }

                namespace Example2
                {
                    class Widget
                    {
                    public:
                        Widget(MAYBE_UNUSED int i, MAYBE_UNUSED bool b);  // ͬǰ
                        Widget(MAYBE_UNUSED int i, MAYBE_UNUSED double d);  // ͬǰ
                        Widget(MAYBE_UNUSED std::initializer_list<long double> i1);  // ���ӵİ汾
                    };
                }

                namespace Example3
                {
                    class Widget
                    {
                    public:
                        Widget(MAYBE_UNUSED int i, MAYBE_UNUSED bool b);  // ͬǰ
                        Widget(MAYBE_UNUSED int i, MAYBE_UNUSED double d);  // ͬǰ
                        Widget(MAYBE_UNUSED std::initializer_list<long double> i1);  // ͬǰ

                        operator float() const noexcept;  // ǿ��ת����float�ͱ�
                    };
                }

                namespace Example4
                {
                    class Widget
                    {
                    public:
                        Widget(MAYBE_UNUSED int i, MAYBE_UNUSED bool b) noexcept;  // ͬǰ
                        Widget(MAYBE_UNUSED int i, MAYBE_UNUSED double d) noexcept;  // ͬǰ
                        Widget(MAYBE_UNUSED std::initializer_list<bool> i1) noexcept;  // ����Ԫ���ͱ�������bool��

                        // ...
                        // ��û����ʽǿ���ͱ�ת������
                    };
                }

                namespace Example5
                {
                    class Widget
                    {
                    public:
                        Widget(MAYBE_UNUSED int i, MAYBE_UNUSED bool b) noexcept;  // ͬǰ
                        Widget(MAYBE_UNUSED int i, MAYBE_UNUSED double d) noexcept;  // ͬǰ
                        // std::initializer_listģ���Ԫ���ͱ�������std::string��
                        Widget(MAYBE_UNUSED std::initializer_list<std::string> i1) noexcept;

                        // ...
                        // ��û����ʽǿ���ͱ�ת������
                    };
                }

                namespace Example6
                {
                    class Widget
                    {
                    public:
                        Widget() noexcept = default;  // Ĭ�Ϲ��캯��
                        Widget(std::initializer_list<int> i1);  // ����std::initializer_list�ͱ��βεĹ��캯��

                        // ...
                        // ��û����ʽǿ���ͱ�ת������
                    };
                }

                template <typename T,  // ����������ͱ�
                          typename... Ts>  // һϵ�ж�����ͱ�
                void DoSomeWork(Ts&&... params)
                {
                    // ����params�����ֲ�����T
                    // ...

                    T localObject0(std::forward<Ts>(params)...);  // ����С����
                    T localObject1{ std::forward<Ts>(params)... };  // ���ô�����

                    std::cout << "localObject0��СΪ��" << localObject0.size() << '\n';
                    std::cout << "localObject1��СΪ��" << localObject1.size() << '\n';
                }
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER3_TERM7_H
