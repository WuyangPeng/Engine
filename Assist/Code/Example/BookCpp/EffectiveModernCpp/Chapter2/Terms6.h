///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/18 21:45)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER2_TERM6_H
#define EFFECTIVE_MODERN_CPP_CHAPTER2_TERM6_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <vector>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter2
        {
            namespace Terms6
            {
                class Widget
                {
                };

                std::vector<bool> Features(MAYBE_UNUSED const Widget& w);

                void ProcessWidget(MAYBE_UNUSED const Widget& w, MAYBE_UNUSED bool highPriority) noexcept;

                class Matrix
                {
                };

                Matrix operator+(const Matrix& lhs, MAYBE_UNUSED const Matrix& rhs) noexcept;

                namespace Std  // ժ��C++��׼
                {
                    template <typename T, class Allocator>
                    class Vector;

                    template <class Allocator>
                    class Vector<bool, Allocator>
                    {
                    public:
                        using size_type = size_t;
                        // ...
                        class Reference
                        {
                            //...
                        };

                        Reference operator[](size_type n);
                        // ...
                    };
                }

                double CalcEpsilon() noexcept;  // ����������
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER2_TERM6_H
