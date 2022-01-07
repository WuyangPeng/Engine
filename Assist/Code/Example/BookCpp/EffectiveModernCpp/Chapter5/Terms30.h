///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.6 (2021/11/20 21:47)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER5_TERM30_H
#define EFFECTIVE_MODERN_CPP_CHAPTER5_TERM30_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <memory>
#include <vector>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter5
        {
            namespace Terms30
            {
                namespace Example0
                {
                    void F(MAYBE_UNUSED int v) noexcept;

                    template <typename T>
                    void Fwd(T&& param)  // ��������ʵ��
                    {
                        F(std::forward<T>(param));  // ת����ʵ�ε�F
                    }
                }

                namespace Example1
                {
                    void F(MAYBE_UNUSED int v) noexcept;

                    template <typename... Ts>
                    void Fwd(Ts&&... param)  // ��������ʵ��
                    {
                        F(std::forward<Ts>(param)...);  // ת����ʵ�ε�F
                    }
                }

                // F(expression);  // ��������ִ����ĳ������
                // Fwd(expression);  // �������ִ���˲�ͬ�Ĳ��������Fwd����ת��expression��Fʧ�ܡ�

                namespace Example2
                {
                    void F(MAYBE_UNUSED const std::vector<int>& v) noexcept;

                    template <typename... Ts>
                    void Fwd(Ts&&... param)
                    {
                        F(std::forward<Ts>(param)...);
                    }
                }

                namespace Example3
                {
                    class Widget
                    {
                    public:
                        static const std::size_t MinVals = 28;  // ������MinVals������
                    };

                    // ...

                    // δ����MinVals������

                    void F(MAYBE_UNUSED std::size_t val) noexcept;

                    template <typename... Ts>
                    void Fwd(Ts&&... param) noexcept
                    {
                        F(std::forward<Ts>(param)...);
                    }
                }

                namespace Example4
                {
                    void F(MAYBE_UNUSED int (*pf)(int)) noexcept;  // PF�ǡ�processing function���ļ��
                }

                namespace Example5
                {
                    void F(MAYBE_UNUSED int pf(int)) noexcept;  // ���������溬����ͬ��F

                    template <typename... Ts>
                    void Fwd(Ts&&... param) noexcept
                    {
                        F(std::forward<Ts>(param)...);
                    }

                    int ProcessVal(MAYBE_UNUSED int value) noexcept;
                    int ProcessVal(MAYBE_UNUSED int value, MAYBE_UNUSED int priority) noexcept;

                    template <typename T>
                    T WorkOnVal(T param) noexcept
                    {
                        return param;
                    }
                }

                namespace Example6
                {
                    struct IPv4Header
                    {
                        std::uint32_t version : 4,
                            IHL : 4,
                            DSCP : 6,
                            ECN : 2,
                            totalLength : 16;
                    };

                    void F(MAYBE_UNUSED std::size_t sz) noexcept;  // �����õĺ���

                    template <typename... Ts>
                    void Fwd(Ts&&... param) noexcept
                    {
                        F(std::forward<Ts>(param)...);
                    }
                }
            }
        }
    }
}
#endif  // EFFECTIVE_MODERN_CPP_CHAPTER5_TERM30_H
