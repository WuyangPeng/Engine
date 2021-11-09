///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/10/04 16:10)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms12.h"
#include "System/Helper/PragmaWarning.h"

#include <iostream>

using std::cout;

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example0::Base::DoWork() noexcept
{
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26433)

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example0::Derived::DoWork() noexcept
{
}

#include STSTEM_WARNING_POP

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example0::Widget::DoWork() &
{
    cout << "左值版本被调用。\n";
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example0::Widget::DoWork() &&
{
    cout << "右值版本被调用。\n";
}

BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example0::Widget BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example0::MakeWidget() noexcept
{
    return Widget{};
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example1::Base::MF1() const
{
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example1::Base::MF2(MAYBE_UNUSED int x)
{
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example1::Base::MF3() &
{
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example1::Base::MF4() const
{
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example1::Derived::MF1()
{
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example1::Derived::MF2(MAYBE_UNUSED unsigned int x)
{
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example1::Derived::MF3() &&
{
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example1::Derived::MF4() const
{
}

#include STSTEM_WARNING_POP

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example2::Base::MF1() const
{
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example2::Base::MF2(MAYBE_UNUSED int x)
{
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example2::Base::MF3() &
{
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example2::Base::MF4() const
{
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example3::Base::MF1() const
{
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example3::Base::MF2(MAYBE_UNUSED int x)
{
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example3::Base::MF3() &
{
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example3::Base::MF4() const
{
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26435)

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example3::Derived::MF1() const
{
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example3::Derived::MF2(MAYBE_UNUSED int x)
{
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example3::Derived::MF3() &
{
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example3::Derived::MF4() const
{
}

#include STSTEM_WARNING_POP

#include STSTEM_WARNING_POP

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Warning::override()
{
}

#include STSTEM_WARNING_POP

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example0::DoSomething(MAYBE_UNUSED Widget&& w) noexcept
{
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example0::DoSomething(MAYBE_UNUSED Widget& w) noexcept
{
}

BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example1::Widget::DataType& BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example1::Widget::Data() noexcept
{
    return values;
}

BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example1::Widget BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example1::MakeWidget() noexcept
{
    return Widget{};
}

BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example2::Widget::DataType& BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example2::Widget::Data() & noexcept
{
    return values;
}

BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example2::Widget::DataType BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example2::Widget::Data() && noexcept
{
    return std::move(values);
}

BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example2::Widget BookExperience::EffectiveModernCpp::Chapter3::Terms12::Example2::MakeWidget() noexcept
{
    return Widget{};
}
