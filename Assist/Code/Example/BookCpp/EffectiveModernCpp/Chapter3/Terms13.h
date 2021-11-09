///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/10/04 21:36)

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
                void FindAndInsert(C& container,  // 在容器中查找targetVal
                                   const V& targetVal,  // 第一次出现的位置
                                   const V& insertVal)  // 然后在彼处插入insertVal
                {
                    using std::cbegin;
                    using std::end;

                    auto it = std::find(cbegin(container),  // 非成员函数版本的cbegin
                                        cend(container),  // 非成员函数版本的cend
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
