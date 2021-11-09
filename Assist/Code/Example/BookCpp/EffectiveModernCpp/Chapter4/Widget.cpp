///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.5 (2021/10/24 20:35)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include "Gadget.h"
#include "Widget.h"  // λ��ʵ���ļ���Widget.cpp����

#include <string>
#include <vector>

BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example0::Widget::Widget() noexcept
{
}

// Widget::Impl��ʵ��
// ������ǰ��Widget�е����ݳ�Ա
struct BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example1::Widget::Impl
{
    std::string name;
    std::vector<double> data;
    Gadget g1, g2, g3;
};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26455)

// Ϊ��Widget����������ݳ�Ա�����ڴ�
BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example1::Widget::Widget()
    : pImpl(new Impl)
{
}

#include STSTEM_WARNING_POP

// Ϊ��Widget�����������ݳ�Ա
BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example1::Widget::~Widget() noexcept
{
    delete pImpl;
}

// ͬǰ
struct BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example2::Widget::Impl
{
    std::string name;
    std::vector<double> data;
    Gadget g1, g2, g3;
};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)

BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example2::Widget::Widget()
    : pImpl(std::make_unique<Impl>())  // ʹ��std::make_unique����std::unique_ptr
{
}

#include STSTEM_WARNING_POP

// ͬǰ��Widget::Impl
struct BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example3::Widget::Impl
{
    std::string name;
    std::vector<double> data;
    Gadget g1, g2, g3;
};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)

BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example3::Widget::Widget()
    : pImpl(std::make_unique<Impl>())  // ͬǰ
{
}

#include STSTEM_WARNING_POP

// ~Widget�Ķ���
BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example3::Widget::~Widget() noexcept
{
}

struct BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example4::Widget::Impl
{
    std::string name;
    std::vector<double> data;
    Gadget g1, g2, g3;
};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)

BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example4::Widget::Widget()
    : pImpl(std::make_unique<Impl>())
{
}

#include STSTEM_WARNING_POP

BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example4::Widget::~Widget() noexcept = default;  // Ч��ͬ��

struct BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example5::Widget::Impl
{
    std::string name;
    std::vector<double> data;
    Gadget g1, g2, g3;
};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)

BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example5::Widget::Widget()
    : pImpl(std::make_unique<Impl>())
{
}

#include STSTEM_WARNING_POP

BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example5::Widget::~Widget() noexcept = default;

struct BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example6::Widget::Impl
{
    std::string name;
    std::vector<double> data;
    Gadget g1, g2, g3;
};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)

BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example6::Widget::Widget()
    : pImpl(std::make_unique<Impl>())
{
}

#include STSTEM_WARNING_POP

BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example6::Widget::~Widget() noexcept = default;

BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example6::Widget::Widget(Widget&& rhs) noexcept = default;  // ��������ö���
BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example6::Widget& BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example6::Widget::operator=(Widget&& rhs) noexcept = default;

struct BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example7::Widget::Impl
{
    std::string name;
    std::vector<double> data;
    Gadget g1, g2, g3;
};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)

BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example7::Widget::Widget()
    : pImpl(std::make_unique<Impl>())
{
}

#include STSTEM_WARNING_POP

BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example7::Widget::~Widget() noexcept = default;  // ����������ͬǰ

BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example7::Widget::Widget(Widget&& rhs) noexcept = default;
BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example7::Widget& BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example7::Widget::operator=(Widget&& rhs) noexcept = default;

BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example7::Widget::Widget(const Widget& rhs)  // ���ƹ��캯��
    : pImpl(std::make_unique<Impl>(*rhs.pImpl))
{
}

// ���Ƹ�ֵ�����
BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example7::Widget& BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example7::Widget::operator=(const Widget& rhs)
{
    *pImpl = *rhs.pImpl;

    return *this;
}

struct BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example8::Widget::Impl
{
    std::string name;
    std::vector<double> data;
    Gadget g1, g2, g3;
};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)

BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example8::Widget::Widget()
    : pImpl(std::make_shared<Impl>())
{
}

#include STSTEM_WARNING_POP