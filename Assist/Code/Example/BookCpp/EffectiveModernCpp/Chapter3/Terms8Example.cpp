///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/02 21:07)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms8.h"
#include "Terms8Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <mutex>
#include <vector>

BookExperience::EffectiveModernCpp::Chapter3::Terms8::Terms8Example::Terms8Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter3::Terms8, Terms8Example)

void BookExperience::EffectiveModernCpp::Chapter3::Terms8::Terms8Example::OverloadExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    F(0);  // 调用的是F(int)，而不是F(void*)

    F(NULL);  // 可能通不过编译，但一般会调用F(int)。从来不会调用F(void*)

    F(nullptr);  // 调用的是F(void*)这个重载版本
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms8::Terms8Example::FindRecordExample() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26462)

    {
        auto result = FindRecord(/* 实参 */);
        if (result == 0)
        {
            // ...
        }
    }

    {
        auto result = FindRecord(/* 实参 */);
        if (result == nullptr)
        {
            // ...
        }
    }

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms8::Terms8Example::MutexExample0() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::mutex f1m, f2m, f3m;

    // C++11中的typedef
    using MuxGuard = std::lock_guard<std::mutex>;

    {
        // 为F1锁定互斥量，
        MuxGuard g(f1m);

        // 向F1传入0作为空指针，解锁互斥量
        const auto result = F1(0);
    }

    {
        // 为F2锁定互斥量，
        MuxGuard g(f2m);

        // 向F2传入NULL作为空指针，解锁互斥量
        const auto result = F2(NULL);
    }

    {
        // 为F3锁定互斥量，
        MuxGuard g(f1m);

        // 向F3传入nullptr作为空指针，解锁互斥量
        const auto result = F3(nullptr);
    }
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms8::Terms8Example::MutexExample1() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::mutex f1m, f2m, f3m;

    // auto result1 = Example1::LockAndCall(F1, f1m, 0);  // 错误！

    // auto result2 = Example1::LockAndCall(F2, f2m, NULL);  // 错误！

    MAYBE_UNUSED const auto result3 = Example1::LockAndCall(F3, f3m, nullptr);  // 没问题
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms8::Terms8Example::MutexExample2() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::mutex f1m, f2m, f3m;

    MAYBE_UNUSED const auto result1 = Example2::LockAndCall(F1, f1m, nullptr);

    MAYBE_UNUSED const auto result2 = Example2::LockAndCall(F2, f2m, nullptr);

    MAYBE_UNUSED const auto result3 = Example2::LockAndCall(F3, f3m, nullptr);
}
