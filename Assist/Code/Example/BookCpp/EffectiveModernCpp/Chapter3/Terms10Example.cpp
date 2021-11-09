///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/02 21:07)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms10.h"
#include "Terms10Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <vector>
#include <string>

BookExperience::EffectiveModernCpp::Chapter3::Terms10::Terms10Example::Terms10Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter3::Terms10, Terms10Example)

void BookExperience::EffectiveModernCpp::Chapter3::Terms10::Terms10Example::EnumExample() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    // black��white��red�����������Color��ͬ
    enum Color
    {
        black,
        white,
        red
    };

    // auto white = false;  // ����white���ڷ�Χ�ڱ���������
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms10::Terms10Example::EnumClassExample() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    // black��white��red�����������޶���Color��
    enum class Color
    {
        black,
        white,
        red
    };

    MAYBE_UNUSED constexpr auto white = false;  // û���⣬��Χ�ڲ���������white��

    // Color c0 = white;  // ���󣬷�Χ�ڲ�����Ϊ��white����ö����

    MAYBE_UNUSED const Color c1 = Color::white;  // û����

    MAYBE_UNUSED const auto c2 = Color::white;  // ͬ��û����
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms10::Terms10Example::EnumConversionExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    // �޶���Χ��ö���ͱ�
    enum Color
    {
        black,
        white,
        red
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26812)

    Color c = red;

#include STSTEM_WARNING_POP
    // ...

    // ��Color�ͱ��double�ͱ�ֵ�Ƚϣ�����
    if (c < 14.5)
    {
        // ����һ��Color�ͱ��������������
        auto factors = PrimeFactors(c);

        // ...
    }
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms10::Terms10Example::EnumClassConversionExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    // �����������ö���ͱ�
    enum class Color
    {
        black,
        white,
        red
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    // ͬǰ��������Ҫ���Ϸ�Χ�޶��δ�
    Color c = Color::red;

#include STSTEM_WARNING_POP

    // ...

    // ���󣡲��ܽ�Color�ͱ��double�ͱ�ֵ�Ƚ�
    // if (c < 14.5)
    {
        // ���󣡲��ܽ�Color�ͱ���Ҫ��std::size_t�ͱ��βεĺ���
        // auto factors = PrimeFactors(c);

        // ...
    }

    // ����Ȼ�Ĵ��룬���Ϸ�
    if (static_cast<double>(c) < 14.5)
    {
        // �Ϸ��Կ��ɣ������ܹ�ͨ������
        auto factors = PrimeFactors(static_cast<std::size_t>(c));

        // ...
    }
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms10::Terms10Example::Tuple0Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    using UserInfo = std::tuple<std::string,  // ����
                                std::string,  // �����ʼ�
                                std::size_t>;  // ����ֵ

    UserInfo uInfo;  // std::tuple�ͱ����

    // ...

    auto val = std::get<1>(uInfo);
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms10::Terms10Example::Tuple1Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    using UserInfo = std::tuple<std::string, std::string, std::size_t>;

    enum UserInfoFields
    {
        uiName,
        uiEmail,
        uiReputation
    };

    UserInfo uInfo;  // ͬǰ

    // ...

    auto val = std::get<uiEmail>(uInfo);  // ����ȡ�õ����ʼ���Ӧ������
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms10::Terms10Example::Tuple2Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    using UserInfo = std::tuple<std::string, std::string, std::size_t>;

    enum class UserInfoFields
    {
        uiName,
        uiEmail,
        uiReputation
    };

    UserInfo uInfo;  // ͬǰ

    // ...

    auto val = std::get<static_cast<std::size_t>(UserInfoFields::uiEmail)>(uInfo);
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms10::Terms10Example::Tuple3Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    using UserInfo = std::tuple<std::string, std::string, std::size_t>;

    enum class UserInfoFields
    {
        uiName,
        uiEmail,
        uiReputation
    };

    UserInfo uInfo;

    auto val = std::get<Example2::ToUType(UserInfoFields::uiEmail)>(uInfo);
}
