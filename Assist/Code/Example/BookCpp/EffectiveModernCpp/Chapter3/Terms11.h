///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/04 15:03)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER3_TERM11_H
#define EFFECTIVE_MODERN_CPP_CHAPTER3_TERM11_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <iostream>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter3
        {
            namespace Terms11
            {
                namespace Example0
                {
                    template <class charT, class traits = std::char_traits<charT>>
                    class BasicIos : public std::ios_base
                    {
                    public:
                        // ...

                    private:
                        BasicIos(const BasicIos&);  // δ����
                        BasicIos& operator=(const BasicIos&);  // δ����
                    };
                }

                namespace Example1
                {
                    template <class charT, class traits = std::char_traits<charT>>
                    class BasicIos : public std::ios_base
                    {
                    public:
                        // ...

                        BasicIos(const BasicIos&) = delete;
                        BasicIos& operator=(const BasicIos&) = delete;

                        // ...
                    };
                }

                namespace Example0
                {
                    bool IsLucky(MAYBE_UNUSED int number) noexcept;
                }

                namespace Example1
                {
                    bool IsLucky(MAYBE_UNUSED int number) noexcept;  // ԭʼ�汾

                    bool IsLucky(char) = delete;  // �ܾ�char�ͱ�

                    bool IsLucky(bool) = delete;  // �ܾ�bool�ͱ�

                    bool IsLucky(double) = delete;  // �ܾ�double��float�ͱ�
                }

                template <typename T>
                void ProcessPointer(MAYBE_UNUSED T* ptr)
                {
                }

                template <>
                void ProcessPointer<void>(void* ptr) = delete;

                template <>
                void ProcessPointer<char>(char* ptr) = delete;

                template <>
                void ProcessPointer<const void>(const void* ptr) = delete;

                template <>
                void ProcessPointer<const char>(const char* ptr) = delete;

                namespace Example0
                {
                    class Widget
                    {
                    public:
                        // ...
                        template <typename T>
                        void ProcessPointer(MAYBE_UNUSED T* ptr) noexcept
                        {
                        }

                    private:
                        template <>
                        void ProcessPointer<void>(void* ptr);  // ����
                    };
                }

                namespace Example1
                {
                    class Widget
                    {
                    public:
                        // ...
                        template <typename T>
                        void ProcessPointer(MAYBE_UNUSED T* ptr)
                        {
                        }
                    };

                    // ��Ȼ�߱�public���ʲ㼶������ɾ���ˡ�
                    template <>
                    void Widget::ProcessPointer<void>(void* ptr) = delete;
                }
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER3_TERM11_H
