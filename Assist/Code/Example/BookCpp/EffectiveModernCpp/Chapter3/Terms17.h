///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/09/30 20:37)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER3_TERM17_H
#define EFFECTIVE_MODERN_CPP_CHAPTER3_TERM17_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <map>
#include <string>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter3
        {
            namespace Terms17
            {
                namespace Example0
                {
                    class Widget
                    {
                    public:
                        // ...
                        Widget(Widget&& rhs);  // �ƶ����캯��

                        Widget& operator=(Widget&& rhs);  // �ƶ���ֵ�����

                        // ...

                        ~Widget() noexcept = default;
                        Widget(const Widget& rhs) = default;
                        Widget& operator=(const Widget& rhs) = default;
                    };
                }

                namespace Example1
                {
                    class Widget
                    {
                    public:
                        ~Widget() noexcept;  // �û��������������

                        // ...

                        Widget(const Widget& rhs) = default;  // Ĭ�ϵĸ��ƹ��캯������Ϊ����ȷ��
                        Widget& operator=(const Widget& rhs) = default;  // Ĭ�ϵĸ��Ƹ�ֵ���������Ϊ����ȷ��

                        // ...
                        Widget(Widget&& rhs) noexcept = default;
                        Widget& operator=(Widget&& rhs) noexcept = default;
                    };
                }

                class Base
                {
                public:
                    ~Base() noexcept = default;  // ʹ����������Ϊ���
                    Base(Base&& rhs) noexcept = default;  // �ṩ�ƶ�������֧��
                    Base& operator=(Base&& rhs) noexcept = default;

                    Base(const Base& rhs) = default;  //  �ṩ���Ʋ�����֧��
                    Base& operator=(const Base& rhs) = default;

                    // ...
                };

                namespace Example0
                {
                    class StringTable
                    {
                    public:
                        StringTable() noexcept;
                        // ...
                        // ʵ�ֲ��롢�����������Ȳ����ĺ���
                        // ��û�к�����ʵ�ָ��ơ��ƶ�������

                    private:
                        std::map<int, std::string> values;
                    };
                }

                void MakeLogEntry(MAYBE_UNUSED std::string_view log) noexcept;

                namespace Example1
                {
                    class StringTable
                    {
                    public:
                        StringTable() noexcept;
                        ~StringTable() noexcept;

                        // ...
                        // ������������

                    private:
                        std::map<int, std::string> values;  // ���ݳ�ԱҲ����
                    };
                }

                namespace Example2
                {
                    class Widget
                    {
                    public:
                        // ...
                        template <typename T>
                        Widget(const T& rhs);  // �������ͱ���Widget

                        template <typename T>
                        Widget& operator=(const T& rhs);  // �������ͱ��Widget��ֵ

                        // ...
                    };
                }
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER3_TERM17_H
