///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/10/04 16:10)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER3_TERM12_H
#define EFFECTIVE_MODERN_CPP_CHAPTER3_TERM12_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <vector>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter3
        {
            namespace Terms12
            {
                namespace Example0
                {
                    class Base
                    {
                    public:
                        virtual void DoWork() noexcept;  // 基类中的虚函数

                        // ...

                        Base() noexcept = default;
                        virtual ~Base() noexcept = default;
                        Base(const Base&) noexcept = default;
                        Base& operator=(const Base&) noexcept = default;
                        Base(Base&&) noexcept = default;
                        Base& operator=(Base&&) noexcept = default;
                    };

                    class Derived : public Base
                    {
                    public:
                        virtual void DoWork() noexcept;  // 改写了Base::DoWork（“virtual”在这里可写可不写）

                        // ...
                    };

                    class Widget
                    {
                    public:
                        // ...
                        void DoWork() &;  // 这个版本的DoWork仅在*this是左值时调用

                        void DoWork() &&;  // 这个版本的DoWork仅在*this是右值时调用
                    };

                    Widget MakeWidget() noexcept;  // 工厂函数（返回右值）
                }

                namespace Example1
                {
                    class Base
                    {
                    public:
                        virtual void MF1() const;
                        virtual void MF2(MAYBE_UNUSED int x);
                        virtual void MF3() &;
                        void MF4() const;

                        Base() noexcept = default;
                        virtual ~Base() noexcept = default;
                        Base(const Base&) noexcept = default;
                        Base& operator=(const Base&) noexcept = default;
                        Base(Base&&) noexcept = default;
                        Base& operator=(Base&&) noexcept = default;
                    };

                    class Derived : public Base
                    {
                    public:
                        virtual void MF1();
                        virtual void MF2(MAYBE_UNUSED unsigned int x);
                        virtual void MF3() &&;
                        void MF4() const;
                    };
                }

                namespace Example2
                {
                    class Base
                    {
                    public:
                        virtual void MF1() const;
                        virtual void MF2(MAYBE_UNUSED int x);
                        virtual void MF3() &;
                        void MF4() const;

                        Base() noexcept = default;
                        virtual ~Base() noexcept = default;
                        Base(const Base&) noexcept = default;
                        Base& operator=(const Base&) noexcept = default;
                        Base(Base&&) noexcept = default;
                        Base& operator=(Base&&) noexcept = default;
                    };

                    // 无法通过编译
                    /*
                    class Derived : public Base
                    {
                    public:
                        virtual void MF1() override;
                        virtual void MF2(MAYBE_UNUSED unsigned int x) override;
                        virtual void MF3() && override;
                        void MF4() const override;
                    };
                    */
                }

                namespace Example3
                {
                    class Base
                    {
                    public:
                        virtual void MF1() const;
                        virtual void MF2(MAYBE_UNUSED int x);
                        virtual void MF3() &;
                        virtual void MF4() const;

                        Base() noexcept = default;
                        virtual ~Base() noexcept = default;
                        Base(const Base&) noexcept = default;
                        Base& operator=(const Base&) noexcept = default;
                        Base(Base&&) noexcept = default;
                        Base& operator=(Base&&) noexcept = default;
                    };

                    class Derived : public Base
                    {
                    public:
                        virtual void MF1() const override;
                        virtual void MF2(MAYBE_UNUSED int x) override;
                        virtual void MF3() & override;
                        void MF4() const override;  // 加个“virtual”没问题，但也没必要
                    };
                }

                // C++98中可能遗留代码
                class Warning
                {
                public:
                    // ...

                    void override();  // C++98和C++11都合法（意义也相同）
                };

                namespace Example0
                {
                    void DoSomething(MAYBE_UNUSED Widget& w) noexcept;  // 仅接受左值的Widgets型别
                    void DoSomething(MAYBE_UNUSED Widget&& w) noexcept;  // 仅接受右值的Widgets型别
                }

                namespace Example1
                {
                    class Widget
                    {
                    public:
                        using DataType = std::vector<double>;

                        // ...

                        DataType& Data() noexcept;

                    private:
                        DataType values;
                    };

                    Widget MakeWidget() noexcept;
                }

                namespace Example2
                {
                    class Widget
                    {
                    public:
                        using DataType = std::vector<double>;

                        // ...

                        // 对于左值的Widget型别，返回左值
                        DataType& Data() & noexcept;

                        // 对于右值的Widget型别，返回右值
                        DataType Data() && noexcept;

                    private:
                        DataType values;
                    };

                    Widget MakeWidget() noexcept;
                }
            }
        }
    }
}
#endif  // EFFECTIVE_MODERN_CPP_CHAPTER3_TERM12_H
