///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.5 (2021/10/22 20:49)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms21.h"
#include "Terms21Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <vector>

BookExperience::EffectiveModernCpp::Chapter4::Terms21::Terms21Example::Terms21Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter4::Terms21, Terms21Example)

void BookExperience::EffectiveModernCpp::Chapter4::Terms21::Terms21Example::MakeExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26414)

    auto upw1(std::make_unique<Widget>());  // 使用make系列函数

    std::unique_ptr<Widget> upw2(new Widget);  // 不使用make系列函数

    auto spw1(std::make_shared<Widget>());  // 使用make系列函数

    std::shared_ptr<Widget> spw2(new Widget);  // 不使用make系列函数

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms21::Terms21Example::ProcessWidget0Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)

    // 潜在的内存泄漏
    ProcessWidget(std::shared_ptr<Widget>(new Widget), ComputePriority());

#include STSTEM_WARNING_POP

    // 不会发生潜在的内存泄漏风险
    ProcessWidget(std::make_shared<Widget>(), ComputePriority());

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26414)

    std::shared_ptr<Widget> spw1(new Widget);

#include STSTEM_WARNING_POP

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    auto spw2 = std::make_shared<Widget>();

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms21::Terms21Example::DeleterExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const auto widgetDeleter = [](Widget* pw) noexcept {
    // ...

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26401)
#include SYSTEM_WARNING_DISABLE(26409)
        delete pw;

#include STSTEM_WARNING_POP
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)

    std::unique_ptr<Widget, decltype(widgetDeleter)> upw(new Widget, widgetDeleter);

    std::shared_ptr<Widget> spw(new Widget, widgetDeleter);

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms21::Terms21Example::Vector0Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    auto upv = std::make_unique<std::vector<int>>(10, 20);

    auto spv = std::make_shared<std::vector<int>>(10, 20);

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms21::Terms21Example::Vector1Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    // 创建std::initializer_list型别对象
    auto initList = { 10, 20 };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    // 利用std::initializer_list型别的构造函数创建std::vector
    auto spv = std::make_shared<std::vector<int>>(initList);

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms21::Terms21Example::ReallyBigType0Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    // 通过std::make_shared创建颇大的对象
    auto pBigObj = std::make_shared<ReallyBigType>();

#include STSTEM_WARNING_POP

    // ...
    // 创建指涉到大对象的多个std::shared_ptr和std::weak_ptr
    // 并使用这些智能指针对象来操作该对象。

    // ...
    // 最后一个指涉到该对象的std::shared_ptr在此析构，
    // 但指涉到该对象的若干std::weak_ptr仍然存在

    // ...
    // 在此阶段，前述大对象所占用的内存仍处于分配未回收状态

    // ...
    // 最后一个指涉到对象的std::weak_ptr在此被析构
    // 控制块和对象所占用的同一内存块在此得到释放。
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms21::Terms21Example::ReallyBigType1Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26414)

    // 通过new表达式创建颇大的对象
    std::shared_ptr<ReallyBigType> pBigObj(new ReallyBigType);

#include STSTEM_WARNING_POP

    // ...

    // 同前，创建指涉到大对象的
    // 多个std::shared_ptr和std::weak_ptr，
    // 并使用这些智能指针来操作该对象。

    // ...

    // 最后一个指涉到该对象的std::shared_ptr在此被析构，
    // 但指涉到该对象的若干std::weak_ptr仍然存在
    // 前述大对象所占用的内存在些被回收。

    // ...

    // 在此阶段，仅控制块所占用的内存仍处于分配未回收状态

    // ...
    // 最后一个指涉到对象的std::weak_ptr在此被析构
    // 控制块所占用的内存块在此得到释放。
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms21::Terms21Example::ProcessWidget1Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)

    // 同前，潜在的资源泄漏！
    ProcessWidget(std::shared_ptr<Widget>(new Widget, CusDel), ComputePriority());  // 实参是个右值

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms21::Terms21Example::ProcessWidget2Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)

    std::shared_ptr<Widget> spw(new Widget, CusDel);

#include STSTEM_WARNING_POP

    // 正确，但并非最优化
    ProcessWidget(spw, ComputePriority());  // 实参是个左值
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms21::Terms21Example::ProcessWidget3Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)

    std::shared_ptr<Widget> spw(new Widget, CusDel);

#include STSTEM_WARNING_POP

    ProcessWidget(std::move(spw), ComputePriority());  // 既有效率，又异常安全
}
