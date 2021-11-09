///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/02 21:07)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms6.h"
#include "Terms6Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

BookExperience::EffectiveModernCpp::Chapter2::Terms6::Terms6Example::Terms6Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter2::Terms6, Terms6Example)

void BookExperience::EffectiveModernCpp::Chapter2::Terms6::Terms6Example::VectorExample() const
{
    Widget w;
    //...

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    // 显式声明highPriority的型别
    bool highPriority = Features(w)[5];  // w具有高优先级吗？

#include STSTEM_WARNING_POP
    //...

    ProcessWidget(w, highPriority);  // 按照w的优先级来处理之
}

void BookExperience::EffectiveModernCpp::Chapter2::Terms6::Terms6Example::AutoErrorExample() const
{
    Widget w;
    //...

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    // highPriority的型别由推导而得
    MAYBE_UNUSED const auto highPriority = Features(w)[5];  // w具有高优先级吗？
    //...

#include STSTEM_WARNING_POP

    // ProcessWidget(w, highPriority);  // 未定义行为！
    // highPriority含有空悬指针
}

void BookExperience::EffectiveModernCpp::Chapter2::Terms6::Terms6Example::MatrixExample() const noexcept
{
    Matrix m1;
    Matrix m2;
    Matrix m3;
    Matrix m4;

    Matrix sum = m1 + m2 + m3 + m4;
}

void BookExperience::EffectiveModernCpp::Chapter2::Terms6::Terms6Example::StaticCastExample() const
{
    Widget w;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    MAYBE_UNUSED auto highPriority = static_cast<bool>(Features(w)[5]);

#include STSTEM_WARNING_POP

    Matrix m1;
    Matrix m2;
    Matrix m3;
    Matrix m4;

    const Matrix sum = static_cast<Matrix>(m1 + m2 + m3 + m4);
}

void BookExperience::EffectiveModernCpp::Chapter2::Terms6::Terms6Example::CalcEpsilonExample() const noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(4244)
    MAYBE_UNUSED const float ep = CalcEpsilon();  // 进行从double到float的隐式型别转换
#include STSTEM_WARNING_POP

    MAYBE_UNUSED const auto ep0 = static_cast<float>(CalcEpsilon());
}

void BookExperience::EffectiveModernCpp::Chapter2::Terms6::Terms6Example::IndexExample() const noexcept
{
    std::vector<int> c;
    constexpr double d = 0.5;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(4244)
    MAYBE_UNUSED const int index = d * c.size();
#include STSTEM_WARNING_POP

    MAYBE_UNUSED const auto index0 = static_cast<int>(d * c.size());
}
