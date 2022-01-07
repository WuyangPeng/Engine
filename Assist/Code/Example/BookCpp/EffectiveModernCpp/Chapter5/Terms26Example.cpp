///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.6 (2021/11/15 20:29)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms26.h"
#include "Terms26Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

BookExperience::EffectiveModernCpp::Chapter5::Terms26::Terms26Example::Terms26Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter5::Terms26, Terms26Example)

void BookExperience::EffectiveModernCpp::Chapter5::Terms26::Terms26Example::Log0Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::string petName("Darla");

    Example0::LogAndAdd(petName);  // ������ֵstd::string

    Example0::LogAndAdd(std::string("Persephone"));  // ������ֵstd::string

    Example0::LogAndAdd("Patty Dog");  // �����ַ���������
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms26::Terms26Example::Log1Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::string petName("Darla");  // һ���ǰ

    Example1::LogAndAdd(petName);  // һ���ǰ������ֵ������multiset

    Example1::LogAndAdd(std::string("Persephone"));  // ����ֵʵʩ�ƶ����Ǹ���

    Example1::LogAndAdd("Patty Dog");  // ��multiset��ֱ�ӹ���һ��std::string���󣬶��Ǹ���һ��std::string �ͱ����ʱ����
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms26::Terms26Example::Log2Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::string petName("Darla");  // һ���ǰ

    Example2::LogAndAdd(petName);  // һ���ǰ��������������䶼�������β��ͱ�ΪT&&�����ذ汾
    Example2::LogAndAdd(std::string("Persephone"));
    Example2::LogAndAdd("Patty Dog");

    Example2::LogAndAdd(22);  // ����������β��ͱ�Ϊint�����ذ汾

    MAYBE_UNUSED constexpr short nameIdx = 0;
    // ��ֵ��nameIdx

    //  Example2::LogAndAdd(nameIdx);  // ����
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms26::Terms26Example::Person0Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Example0::Person p("Nancy");

    // auto clonePfP(p);  // ��p���������µ�Person�ͱ����
    // ���������޷�ͨ������
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms26::Terms26Example::Person1Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const Example1::Person p("Nancy");  // �����ɳ���

    auto clonePfP(p);  // ��ص��õ��Ǹ��ƹ��캯��
}
