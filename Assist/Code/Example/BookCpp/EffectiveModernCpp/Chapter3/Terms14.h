///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/05 11:36)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER3_TERM14_H
#define EFFECTIVE_MODERN_CPP_CHAPTER3_TERM14_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <string>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter3
        {
            namespace Terms14
            {
                namespace Example0
                {
                    int F(MAYBE_UNUSED int x) throw();  // F���ᷢ���쳣��C++98���
                }

                namespace Example1
                {
                    int F(MAYBE_UNUSED int x) noexcept;  // F���ᷢ���쳣��C++11���
                }

                // RetType Function(params) noexcept;  // ���Ż�
                // RetType Function(params) throw();  // �Ż�����
                // RetType Function(params);  // �Ż�����

                class Widget
                {
                };

                template <class T, size_t N>
                void Swap(T (&a)[N], T (&b)[N]) noexcept(noexcept(swap(*a, *b)))
                {
                    std::swap(*a, *b);
                }

                template <class T1, class T2>
                struct Pair
                {
                    // ...
                    void Swap(Pair& p) noexcept(noexcept(swap(first, p.first)) && noexcept(swap(second, p.second)))
                    {
                        std::swap(first, p.first);
                        std::swap(second, p.second);
                    }

                    T1 first;
                    T2 second;
                };

                void F(MAYBE_UNUSED const std::string& s) noexcept;  // ǰ��������s.length() <= 32

                void Setup();
                void Cleanup();

                void DoWork() noexcept;
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER3_TERM14_H
