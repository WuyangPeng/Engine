///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/18 21:45)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER2_TERM5_H
#define EFFECTIVE_MODERN_CPP_CHAPTER2_TERM5_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter2
        {
            namespace Terms5
            {
                // �������룬do what I mean �㷨Ӧ�÷�Χ�Ǵ�b��e������Ԫ��
                template <typename It>
                void Dwim(It b, It e)
                {
                    while (b != e)
                    {
                        typename std::iterator_traits<It>::value_type currValue = *b;
                        // ...
                    }
                }

                // ����ͬǰ
                template <typename It>
                void Dwim1(It b, It e)
                {
                    while (b != e)
                    {
                        auto currValue = *b;
                        // ...
                    }
                }

                class Widget
                {
                };

                bool operator<(MAYBE_UNUSED const Widget& lhs, MAYBE_UNUSED const Widget& rhs) noexcept;
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER2_TERM5_H
