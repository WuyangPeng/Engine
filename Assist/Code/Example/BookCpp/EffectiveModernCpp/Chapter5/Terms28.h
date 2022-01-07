///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.6 (2021/11/17 21:03)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER5_TERM28_H
#define EFFECTIVE_MODERN_CPP_CHAPTER5_TERM28_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <memory>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter5
        {
            namespace Terms28
            {
                namespace Example0
                {
                    template <typename T>
                    void Func(MAYBE_UNUSED T&& param) noexcept
                    {
                    }

                    class Widget
                    {
                    };

                    constexpr Widget WidgetFactory() noexcept
                    {
                        return Widget();
                    }
                }

                template <typename T>
                void SomeFunc(MAYBE_UNUSED T&& param)
                {
                }

                template <typename T>
                void F(T&& fParam)
                {
                    // ...
                    // ���һЩ����

                    // ��fParamlת����SomeFunc
                    SomeFunc(std::forward<T>(fParam));
                }

                namespace Example0
                {
                    template <typename T>  // �����ֿռ�std��
                    T&& Forward(typename std::remove_reference<T>::type& param)
                    {
                        return static_cast<T&&>(param);
                    }

                    /*
                    Widget& && Forward(typename std::remove_reference<Widget&>::type& param)
                    {
                        return static_cast<Widget& &&>(param);
                    }
                    */

                    /*
                    Widget& && Forward(Widget& param)
                    {
                        return static_cast<Widget& &&>(param);
                    }
                    */

                    /*
                    Widget& Forward(Widget& param) // ��λ�����ֿռ�std��
                    {
                        return static_cast<Widget&>(param);
                    }
                    */

                    /*
                    Widget&& Forward(typename std::remove_reference<Widget>::type& param)
                    {
                        return static_cast<Widget&&>(param);
                    }
                    */

                    /*
                    Widget&& Forward(Widget& param)
                    {
                        return static_cast<Widget&&>(param);
                    }
                    */
                }

                namespace Example1
                {
                    template <typename T>  // C++14,�������ֿռ�std��
                    T&& Forward(std::remove_reference_t<T>& param)
                    {
                        return static_cast<T&&>(param);
                    }
                }

                namespace Example1
                {
                    template <typename T>
                    class Widget
                    {
                    public:
                        typedef T&& RvalueRefToT;

                        // ...
                    };
                }
            }
        }
    }
}
#endif  // EFFECTIVE_MODERN_CPP_CHAPTER5_TERM28_H
