///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.5 (2021/10/24 20:35)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER4_TERM22_H
#define EFFECTIVE_MODERN_CPP_CHAPTER4_TERM22_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <string>
#include <vector>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter4
        {
            namespace Terms22
            {
                namespace Example0
                {
                    class Gadget
                    {
                    };

                    // λ��ͷ�ļ���widget.h����
                    class Widget
                    {
                    public:
                        Widget() noexcept;

                        // ...

                    private:
                        std::string name;
                        std::vector<double> data;
                        Gadget g1, g2, g3;  // Gadget��ĳ���û��Զ����ͱ�
                    };
                }

                namespace Example1
                {
                    // ��λ��ͷ�ļ���widget.h����
                    class Widget
                    {
                    public:
                        Widget();
                        ~Widget() noexcept;  // ����������ñ�Ҫ������

                        // ...

                        Widget(const Widget& rhs) = delete;
                        Widget& operator=(const Widget& rhs) = delete;
                        Widget(Widget&& rhs) noexcept = delete;
                        Widget& operator=(Widget&& rhs) noexcept = delete;

                    private:
                        struct Impl;  // ����ʵ�ֽṹ��
                        Impl* pImpl;  // �Լ�ָ�浽����ָ��
                    };
                }

                namespace Example2
                {
                    // λ��ͷ�ļ���widget.h����
                    class Widget
                    {
                    public:
                        Widget();

                        // ...

                    private:
                        struct Impl;
                        std::unique_ptr<Impl> pImpl;  // ʹ������ָ�������ָ��
                    };
                }

                namespace Example3
                {
                    // ͬǰ��λ��ͷ�ļ���widget.h����
                    class Widget
                    {
                    public:
                        Widget();
                        ~Widget() noexcept;  // ������

                        // ...
                        Widget(const Widget& rhs) = delete;
                        Widget& operator=(const Widget& rhs) = delete;
                        Widget(Widget&& rhs) noexcept = delete;
                        Widget& operator=(Widget&& rhs) noexcept = delete;

                    private:
                        struct Impl;
                        std::unique_ptr<Impl> pImpl;  // ʹ������ָ�������ָ��
                    };
                }

                namespace Example4
                {
                    class Widget
                    {
                    public:
                        Widget();
                        ~Widget() noexcept;

                        // ...
                        Widget(const Widget& rhs) = delete;
                        Widget& operator=(const Widget& rhs) = delete;
                        Widget(Widget&& rhs) noexcept = delete;
                        Widget& operator=(Widget&& rhs) noexcept = delete;

                    private:
                        struct Impl;
                        std::unique_ptr<Impl> pImpl;
                    };
                }

                namespace Example5
                {
                    class Widget
                    {
                    public:
                        Widget();
                        ~Widget() noexcept;

                        Widget(Widget&& rhs) noexcept = default;  // �뷨��ȷ���������
                        Widget& operator=(Widget&& rhs) noexcept = default;

                        // ...
                        Widget(const Widget& rhs) = delete;
                        Widget& operator=(const Widget& rhs) = delete;

                    private:
                        struct Impl;  // ͬǰ
                        std::unique_ptr<Impl> pImpl;
                    };
                }

                namespace Example6
                {
                    class Widget
                    {
                    public:
                        Widget();
                        ~Widget() noexcept;

                        Widget(Widget&& rhs) noexcept;  // ������
                        Widget& operator=(Widget&& rhs) noexcept;

                        // ...
                        Widget(const Widget& rhs) = delete;
                        Widget& operator=(const Widget& rhs) = delete;

                    private:
                        struct Impl;  // ͬǰ
                        std::unique_ptr<Impl> pImpl;
                    };
                }

                namespace Example7
                {
                    class Widget
                    {
                    public:
                        Widget();
                        ~Widget() noexcept;

                        Widget(Widget&& rhs) noexcept;
                        Widget& operator=(Widget&& rhs) noexcept;
                        // ����������ͬǰ

                        // ...
                        Widget(const Widget& rhs);  // ������
                        Widget& operator=(const Widget& rhs);

                    private:
                        struct Impl;  // ͬǰ
                        std::unique_ptr<Impl> pImpl;
                    };
                }

                namespace Example8
                {
                    class Widget
                    {
                    public:
                        Widget();
                        // ...
                        // �����������������ƶ�����������

                    private:
                        struct Impl;
                        std::shared_ptr<Impl> pImpl;  // ʹ��std::shared_ptr����std::unique_ptr
                    };
                }
            }
        }
    }
}
#endif  // EFFECTIVE_MODERN_CPP_CHAPTER4_TERM22_H
