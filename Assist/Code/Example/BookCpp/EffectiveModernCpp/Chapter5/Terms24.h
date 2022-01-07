///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.5 (2021/11/04 21:05)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER5_TERM24_H
#define EFFECTIVE_MODERN_CPP_CHAPTER5_TERM24_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <vector>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter5
        {
            namespace Terms24
            {
                class Widget
                {
                };

                namespace Example0
                {
                    void F(Widget&& param);  // ��ֵ����

                    template <typename T>
                    void F(std::vector<T>&& param);  // ��ֵ����

                    template <typename T>
                    void F(T&& param);  // ����ֵ����
                }

                namespace Example1
                {
                    // ���漰�ͱ��Ƶ���param�Ǹ���ֵ����
                    void F(Widget&& param);

                    // param�Ǹ���������
                    template <typename T>
                    void F(T&& param);
                }

                namespace Example2
                {
                    // param�Ǹ���������
                    template <typename T>
                    void F(MAYBE_UNUSED T&& param) noexcept
                    {
                    }
                }

                namespace Example3
                {
                    template <typename T>
                    void F(MAYBE_UNUSED std::vector<T>&& param) noexcept  // param�Ǹ���ֵ����
                    {
                    }
                }

                namespace Example4
                {
                    // param�Ǹ���ֵ����
                    template <typename T>
                    void F(const T&& param);
                }

                template <class T, class Allocator = std::allocator<T>>  // ����C++��׼
                class Vector
                {
                public:
                    void PushBack(T&& x);

                    // ...

                    template <class... Args>
                    void EmplaceBack(Args&&... args);
                };

                template <>
                class Vector<Widget, std::allocator<Widget>>
                {
                public:
                    void PushBack(Widget&& x);  // ��ֵ����
                };

                // param�Ǹ���������
                template <typename MyTemplateType>
                void SomeFunc(MyTemplateType&& param);
            }
        }
    }
}
#endif  // EFFECTIVE_MODERN_CPP_CHAPTER5_TERM24_H
