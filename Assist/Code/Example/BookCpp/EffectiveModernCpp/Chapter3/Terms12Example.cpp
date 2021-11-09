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
#include "Terms12Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <vector>

BookExperience::EffectiveModernCpp::Chapter3::Terms12::Terms12Example::Terms12Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter3::Terms12, Terms12Example)

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Terms12Example::DoWorkExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    std::unique_ptr<Example0::Base> upb = std::make_unique<Example0::Derived>();  // 创建基类指针，指涉到派生类对象。

#include STSTEM_WARNING_POP

    // 通过基类指针调用DoWork；结果是派生类函数被调用
    upb->DoWork();
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Terms12Example::Widget0Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_9;

    Example0::Widget w;  // 普通对象（左值）

    // ...

    w.DoWork();  // 以左值调用Widget::DoWork（即Widget::DoWork&）
    Example0::MakeWidget().DoWork();  // 以右值调用Widget::DoWork（即Widget::DoWork&&）
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Terms12Example::Widget1Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_9;

    Example1::Widget w;

    // ...

    auto vals1 = w.Data();  // 把w.values复制到vals1

    auto vals2 = Example1::MakeWidget().Data();  // 把Widget中的values复制到vals2
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Terms12Example::Widget2Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_9;

    Example2::Widget w;

    // 把Widget::Data的左值重载版本，
    // vals1采用复制构造完成初始化。
    auto vals1 = w.Data();  

    // 把Widget::Data的右值重载版本，
    // vals2采用移动构造完成初始化。
    auto vals2 = Example2::MakeWidget().Data();  
}
