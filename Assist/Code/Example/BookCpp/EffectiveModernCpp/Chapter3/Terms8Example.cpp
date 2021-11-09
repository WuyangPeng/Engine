///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/02 21:07)

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

    F(0);  // ���õ���F(int)��������F(void*)

    F(NULL);  // ����ͨ�������룬��һ������F(int)�������������F(void*)

    F(nullptr);  // ���õ���F(void*)������ذ汾
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms8::Terms8Example::FindRecordExample() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26462)

    {
        auto result = FindRecord(/* ʵ�� */);
        if (result == 0)
        {
            // ...
        }
    }

    {
        auto result = FindRecord(/* ʵ�� */);
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

    // C++11�е�typedef
    using MuxGuard = std::lock_guard<std::mutex>;

    {
        // ΪF1������������
        MuxGuard g(f1m);

        // ��F1����0��Ϊ��ָ�룬����������
        const auto result = F1(0);
    }

    {
        // ΪF2������������
        MuxGuard g(f2m);

        // ��F2����NULL��Ϊ��ָ�룬����������
        const auto result = F2(NULL);
    }

    {
        // ΪF3������������
        MuxGuard g(f1m);

        // ��F3����nullptr��Ϊ��ָ�룬����������
        const auto result = F3(nullptr);
    }
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms8::Terms8Example::MutexExample1() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::mutex f1m, f2m, f3m;

    // auto result1 = Example1::LockAndCall(F1, f1m, 0);  // ����

    // auto result2 = Example1::LockAndCall(F2, f2m, NULL);  // ����

    MAYBE_UNUSED const auto result3 = Example1::LockAndCall(F3, f3m, nullptr);  // û����
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms8::Terms8Example::MutexExample2() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::mutex f1m, f2m, f3m;

    MAYBE_UNUSED const auto result1 = Example2::LockAndCall(F1, f1m, nullptr);

    MAYBE_UNUSED const auto result2 = Example2::LockAndCall(F2, f2m, nullptr);

    MAYBE_UNUSED const auto result3 = Example2::LockAndCall(F3, f3m, nullptr);
}
