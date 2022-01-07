///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.5 (2021/11/04 21:05)

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
                    void F(Widget&& param);  // 右值引用

                    template <typename T>
                    void F(std::vector<T>&& param);  // 右值引用

                    template <typename T>
                    void F(T&& param);  // 非右值引用
                }

                namespace Example1
                {
                    // 不涉及型别推导，param是个右值引用
                    void F(Widget&& param);

                    // param是个万能引用
                    template <typename T>
                    void F(T&& param);
                }

                namespace Example2
                {
                    // param是个万能引用
                    template <typename T>
                    void F(MAYBE_UNUSED T&& param) noexcept
                    {
                    }
                }

                namespace Example3
                {
                    template <typename T>
                    void F(MAYBE_UNUSED std::vector<T>&& param) noexcept  // param是个右值引用
                    {
                    }
                }

                namespace Example4
                {
                    // param是个右值引用
                    template <typename T>
                    void F(const T&& param);
                }

                template <class T, class Allocator = std::allocator<T>>  // 来自C++标准
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
                    void PushBack(Widget&& x);  // 右值引用
                };

                // param是个万能引用
                template <typename MyTemplateType>
                void SomeFunc(MyTemplateType&& param);
            }
        }
    }
}
#endif  // EFFECTIVE_MODERN_CPP_CHAPTER5_TERM24_H
