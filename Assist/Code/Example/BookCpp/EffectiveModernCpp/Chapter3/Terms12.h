///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/04 16:10)

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
                        virtual void DoWork() noexcept;  // �����е��麯��

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
                        virtual void DoWork() noexcept;  // ��д��Base::DoWork����virtual���������д�ɲ�д��

                        // ...
                    };

                    class Widget
                    {
                    public:
                        // ...
                        void DoWork() &;  // ����汾��DoWork����*this����ֵʱ����

                        void DoWork() &&;  // ����汾��DoWork����*this����ֵʱ����
                    };

                    Widget MakeWidget() noexcept;  // ����������������ֵ��
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

                    // �޷�ͨ������
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
                        void MF4() const override;  // �Ӹ���virtual��û���⣬��Ҳû��Ҫ
                    };
                }

                // C++98�п�����������
                class Warning
                {
                public:
                    // ...

                    void override();  // C++98��C++11���Ϸ�������Ҳ��ͬ��
                };

                namespace Example0
                {
                    void DoSomething(MAYBE_UNUSED Widget& w) noexcept;  // ��������ֵ��Widgets�ͱ�
                    void DoSomething(MAYBE_UNUSED Widget&& w) noexcept;  // ��������ֵ��Widgets�ͱ�
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

                        // ������ֵ��Widget�ͱ𣬷�����ֵ
                        DataType& Data() & noexcept;

                        // ������ֵ��Widget�ͱ𣬷�����ֵ
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
