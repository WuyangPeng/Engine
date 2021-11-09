///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/02 21:08)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER1_TERM1_DERIVE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER1_TERM1_DERIVE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter1
        {
            namespace Terms1
            {
                // template <typename T>
                // void F(ParamType param);

                // F(expr); ��ĳ���ʽ����F
                // ��expr���Ƶ�T��ParamType���ͱ�

                template <typename T>
                void F(MAYBE_UNUSED const T& param) noexcept  // ParamType��const T&
                {
                }

                template <typename T>
                void F0(MAYBE_UNUSED T& param) noexcept  // param�Ǹ�����
                {
                }

                template <typename T>
                void F1(MAYBE_UNUSED const T& param) noexcept  // param������const������
                {
                }

                template <typename T>
                void F2(MAYBE_UNUSED T* param) noexcept  // param�����Ǹ�ָ����
                {
                }

                template <typename T>
                void F3(MAYBE_UNUSED T&& param) noexcept  // param�����Ǹ�����������
                {
                }

                template <typename T>
                void F4(MAYBE_UNUSED T param) noexcept  // param�����ǰ�ֵ����
                {
                }

                template <typename T>
                void F5(MAYBE_UNUSED T param) noexcept  // param�԰�ֵ����
                {
                }

                template <typename T>
                void F6(MAYBE_UNUSED T param) noexcept  // ���а�ֵ�βε�ģ��
                {
                }

                void MyFunc(MAYBE_UNUSED int param[]) noexcept;
                void MyFunc(MAYBE_UNUSED int* param) noexcept;

                template <typename T>
                void F7(MAYBE_UNUSED T& param) noexcept  // �����÷�ʽ�����βε�ģ��
                {
                }

                /// �Ա����ڳ�����ʽ��������ߴ�
                /// ���������β�δ�����֣���Ϊ����ֻ�����京�е�Ԫ�ظ�����
                template <typename T, std::size_t N>
                constexpr std::size_t ArraySize(T (&)[N]) noexcept
                {
                    return N;
                }

                void SomeFunc(int, double) noexcept;  // SomeFunc�Ǹ����������ͱ�Ϊvoid(int, double)

                template <typename T>
                void F8(MAYBE_UNUSED T param) noexcept  // param��ֵ����
                {
                }

                template <typename T>
                void F9(MAYBE_UNUSED T& param) noexcept  // param�����ô���
                {
                }
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER1_TERM1_DERIVE_H
