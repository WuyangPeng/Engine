///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.6 (2021/11/14 20:42)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER5_TERM25_H
#define EFFECTIVE_MODERN_CPP_CHAPTER5_TERM25_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <chrono>
#include <memory>
#include <string>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter5
        {
            namespace Terms25
            {
                namespace Example0
                {
                    class Widget
                    {
                        // rhsȷ�����ɵػ�󶨵����Ժ����ƶ�Ŀ�ĵĶ���
                        Widget(Widget&& rhs);
                    };
                }

                class SomeDataStructure
                {
                };

                namespace Example1
                {
                    class Widget
                    {
                    public:
                        // rhs�Ǹ���ֵ����
                        Widget(Widget&& rhs) noexcept;

                        ~Widget() noexcept = default;
                        Widget(const Widget& rhs) = default;
                        Widget& operator=(const Widget& rhs) = default;
                        Widget& operator=(Widget&& rhs) noexcept = default;

                    private:
                        std::string name;
                        std::shared_ptr<SomeDataStructure> p;
                    };
                }

                namespace Example2
                {
                    class Widget
                    {
                    public:
                        template <typename T>
                        void SetName(T&& newName)
                        {
                            name = std::forward<T>(newName);  // newName�Ǹ���������
                        }

                    private:
                        std::string name;
                    };
                }

                namespace Example3
                {
                    class Widget
                    {
                    public:
                        template <typename T>
                        void SetName(T&& newName) noexcept
                        {
                            name = std::move(newName);  // �������ã����Ա��룬�������͸����
                        }

                    private:
                        std::string name;
                        std::shared_ptr<SomeDataStructure> p;
                    };

                    std::string GetWidgetName();  // ��������
                }

                namespace Example4
                {
                    class Widget
                    {
                    public:
                        void SetName(const std::string& newName);
                        void SetName(std::string&& newName) noexcept;

                    private:
                        std::string name;
                    };
                }

                template <class T, class... Args>
                std::shared_ptr<T> MakeShared(Args&&... args);  // ѡ��C++11��׼

                template <class T, class... Args>
                std::unique_ptr<T> MakeUnique(Args&&... args);  // ѡ��C++14��׼

                namespace Example5
                {
                    class Sign
                    {
                    public:
                        void SetText(MAYBE_UNUSED const std::string& text) noexcept;

                        void Add(MAYBE_UNUSED const std::chrono::time_point<std::chrono::system_clock>& now, MAYBE_UNUSED const std::string& text) noexcept;
                    };

                    class Widget
                    {
                    public:
                        template <typename T>
                        void SetSignText(T& text)  // text�Ǹ���������
                        {
                            sign.SetText(text);  // ʹ��text�������Ķ���ֵ

                            auto now = std::chrono::system_clock::now();  // ȡ�õ�ǰʱ��

                            signHistory.Add(now, std::forward<T>(text));  // �������ؽ�textǿ��ת������ֵ�ͱ�
                        }

                    private:
                        Sign sign;
                        Sign signHistory;
                    };
                }

                namespace Example0
                {
                    class Matrix
                    {
                    public:
                        Matrix& operator+=(MAYBE_UNUSED const Matrix& rhs) noexcept;
                    };

                    Matrix operator+(Matrix&& lhs, const Matrix& rhs) noexcept;  // ��ֵ����
                }

                namespace Example1
                {
                    class Matrix
                    {
                    public:
                        Matrix& operator+=(MAYBE_UNUSED const Matrix& rhs) noexcept;
                    };

                    Matrix operator+(Matrix&& lhs, const Matrix& rhs) noexcept;  // ͬ��
                }

                class Fraction
                {
                };

                template <typename T>
                Fraction ReduceAndCopy(T&& frac)  // ��ֵ���أ����������β�
                {
                    frac.Reduce();

                    // ������ֵ�������뷵��ֵ
                    // ������ֵ���Ǹ����뷵��ֵ
                    return std::forward<T>(frac);
                }

                namespace Example6
                {
                    class Widget
                    {
                    };

                    Widget MakeWidget() noexcept;  // MakeWidget�ġ����ơ��汾
                }

                namespace Example7
                {
                    class Widget
                    {
                    };

                    Widget MakeWidget() noexcept;  // MakeWidget���ƶ��汾
                }

                namespace Example8
                {
                    class Widget
                    {
                    };

                    Widget MakeWidget(Widget w) noexcept;  // ��ֵ���ݵ��βΣ��뺯������ֵ�ͱ���ͬ
                }
            }
        }
    }
}
#endif  // EFFECTIVE_MODERN_CPP_CHAPTER5_TERM24_H
