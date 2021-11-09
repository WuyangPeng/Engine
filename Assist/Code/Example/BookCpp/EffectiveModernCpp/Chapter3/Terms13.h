///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/04 21:36)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER3_TERM13_H
#define EFFECTIVE_MODERN_CPP_CHAPTER3_TERM13_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter3
        {
            namespace Terms13
            {
                template <typename C, typename V>
                void FindAndInsert(C& container,  // �������в���targetVal
                                   const V& targetVal,  // ��һ�γ��ֵ�λ��
                                   const V& insertVal)  // Ȼ���ڱ˴�����insertVal
                {
                    using std::cbegin;
                    using std::end;

                    auto it = std::find(cbegin(container),  // �ǳ�Ա�����汾��cbegin
                                        cend(container),  // �ǳ�Ա�����汾��cend
                                        targetVal);

                    container.insert(it, insertVal);
                }

                template <class C>
                auto cbegin(const C& container) -> decltype(std::begin(container))
                {
                    return std::begin(container);
                }
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER3_TERM13_H
