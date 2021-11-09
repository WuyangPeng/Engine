///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.5 (2021/10/24 20:35)

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

                    // 位于头文件“widget.h”内
                    class Widget
                    {
                    public:
                        Widget() noexcept;

                        // ...

                    private:
                        std::string name;
                        std::vector<double> data;
                        Gadget g1, g2, g3;  // Gadget是某种用户自定义型别
                    };
                }

                namespace Example1
                {
                    // 仍位于头文件“widget.h”内
                    class Widget
                    {
                    public:
                        Widget();
                        ~Widget() noexcept;  // 析构函数变得必要，见下

                        // ...

                        Widget(const Widget& rhs) = delete;
                        Widget& operator=(const Widget& rhs) = delete;
                        Widget(Widget&& rhs) noexcept = delete;
                        Widget& operator=(Widget&& rhs) noexcept = delete;

                    private:
                        struct Impl;  // 声明实现结构体
                        Impl* pImpl;  // 以及指涉到它的指针
                    };
                }

                namespace Example2
                {
                    // 位于头文件“widget.h”内
                    class Widget
                    {
                    public:
                        Widget();

                        // ...

                    private:
                        struct Impl;
                        std::unique_ptr<Impl> pImpl;  // 使用智能指针而非裸指针
                    };
                }

                namespace Example3
                {
                    // 同前，位于头文件“widget.h”内
                    class Widget
                    {
                    public:
                        Widget();
                        ~Widget() noexcept;  // 仅声明

                        // ...
                        Widget(const Widget& rhs) = delete;
                        Widget& operator=(const Widget& rhs) = delete;
                        Widget(Widget&& rhs) noexcept = delete;
                        Widget& operator=(Widget&& rhs) noexcept = delete;

                    private:
                        struct Impl;
                        std::unique_ptr<Impl> pImpl;  // 使用智能指针而非裸指针
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

                        Widget(Widget&& rhs) noexcept = default;  // 想法正确，代码错误
                        Widget& operator=(Widget&& rhs) noexcept = default;

                        // ...
                        Widget(const Widget& rhs) = delete;
                        Widget& operator=(const Widget& rhs) = delete;

                    private:
                        struct Impl;  // 同前
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

                        Widget(Widget&& rhs) noexcept;  // 仅声明
                        Widget& operator=(Widget&& rhs) noexcept;

                        // ...
                        Widget(const Widget& rhs) = delete;
                        Widget& operator=(const Widget& rhs) = delete;

                    private:
                        struct Impl;  // 同前
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
                        // 其他函数，同前

                        // ...
                        Widget(const Widget& rhs);  // 仅声明
                        Widget& operator=(const Widget& rhs);

                    private:
                        struct Impl;  // 同前
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
                        // 不再有析构函数或移动操作的声明

                    private:
                        struct Impl;
                        std::shared_ptr<Impl> pImpl;  // 使用std::shared_ptr而非std::unique_ptr
                    };
                }
            }
        }
    }
}
#endif  // EFFECTIVE_MODERN_CPP_CHAPTER4_TERM22_H
