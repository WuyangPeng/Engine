///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/04 22:18)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER1_TERM2_DERIVE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER1_TERM2_DERIVE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter1
        {
            namespace Terms2
            {
                // template <typename T>
                // void F(ParamType param);

                // F(expr); ��ĳ���ʽ����F

                template <typename T>
                void FuncForX0(MAYBE_UNUSED T param) noexcept  // Ϊ�Ƶ�x���ͱ�����ɵĸ�����ģ��
                {
                }

                template <typename T>
                void FuncForX1(MAYBE_UNUSED const T param) noexcept  // Ϊ�Ƶ�cx���ͱ�����ɵĸ�����ģ��
                {
                }

                template <typename T>
                void FuncForX2(MAYBE_UNUSED const T& param) noexcept  // Ϊ�Ƶ�rx���ͱ�����ɵĸ�����ģ��
                {
                }

                void SomeFunc(int, double) noexcept;  // SomeFunc�Ǹ��������ͱ���void(int, double)

                template <typename T>
                void F(MAYBE_UNUSED T param) noexcept  // �����βε�ģ����x�������ȼ۵�����ʽ
                {
                }

                template <typename T>
                void F0(MAYBE_UNUSED std::initializer_list<T> initList) noexcept
                {
                }

                /* auto CreateInitList()
                {
                    return { 1, 2, 3 };  // �����޷�Ϊ{ 1, 2, 3 }����ͱ��Ƶ�
                }*/
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER1_TERM2_DERIVE_H
