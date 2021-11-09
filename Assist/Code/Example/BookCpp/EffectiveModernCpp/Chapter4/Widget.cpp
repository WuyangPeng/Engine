///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.5 (2021/10/24 20:35)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include "Gadget.h"
#include "Widget.h"  // 位于实现文件“Widget.cpp”内

#include <string>
#include <vector>

BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example0::Widget::Widget() noexcept
{
}

// Widget::Impl的实现
// 包括此前在Widget中的数据成员
struct BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example1::Widget::Impl
{
    std::string name;
    std::vector<double> data;
    Gadget g1, g2, g3;
};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26455)

// 为本Widget对象分配数据成员所需内存
BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example1::Widget::Widget()
    : pImpl(new Impl)
{
}

#include STSTEM_WARNING_POP

// 为本Widget对象析构数据成员
BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example1::Widget::~Widget() noexcept
{
    delete pImpl;
}

// 同前
struct BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example2::Widget::Impl
{
    std::string name;
    std::vector<double> data;
    Gadget g1, g2, g3;
};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)

BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example2::Widget::Widget()
    : pImpl(std::make_unique<Impl>())  // 使用std::make_unique创建std::unique_ptr
{
}

#include STSTEM_WARNING_POP

// 同前，Widget::Impl
struct BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example3::Widget::Impl
{
    std::string name;
    std::vector<double> data;
    Gadget g1, g2, g3;
};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)

BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example3::Widget::Widget()
    : pImpl(std::make_unique<Impl>())  // 同前
{
}

#include STSTEM_WARNING_POP

// ~Widget的定义
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

BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example4::Widget::~Widget() noexcept = default;  // 效果同上

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

BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example6::Widget::Widget(Widget&& rhs) noexcept = default;  // 在这里放置定义
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

BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example7::Widget::~Widget() noexcept = default;  // 其他函数，同前

BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example7::Widget::Widget(Widget&& rhs) noexcept = default;
BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example7::Widget& BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example7::Widget::operator=(Widget&& rhs) noexcept = default;

BookExperience::EffectiveModernCpp::Chapter4::Terms22::Example7::Widget::Widget(const Widget& rhs)  // 复制构造函数
    : pImpl(std::make_unique<Impl>(*rhs.pImpl))
{
}

// 复制赋值运算符
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