///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/02 21:07)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms16.h"
#include "Terms16Example.h"
#include "CoreTools/Threading/ThreadGuardDetail.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <thread>
#include <vector>

BookExperience::EffectiveModernCpp::Chapter3::Terms16::Terms16Example::Terms16Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter3::Terms16, Terms16Example)

void BookExperience::EffectiveModernCpp::Chapter3::Terms16::Terms16Example::PolynomialExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Example1::Polynomial p;

    // ...

    CoreTools::ThreadGuard thread0{ &ClassType::Thread0, this, p };
    CoreTools::ThreadGuard thread1{ &ClassType::Thread1, this, p };
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms16::Terms16Example::Thread0(const Example1::Polynomial& p) const
{
    // �߳�1
    auto rootsOfP = p.Roots();
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms16::Terms16Example::Thread1(const Example1::Polynomial& p) const
{
    // �߳�2
    auto valsGivingZero = p.Roots();
}
