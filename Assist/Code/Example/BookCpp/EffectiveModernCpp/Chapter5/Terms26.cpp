///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.6 (2021/11/15 20:28)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms26.h"

std::multiset<std::string> BookExperience::EffectiveModernCpp::Chapter5::Terms26::names;

void BookExperience::EffectiveModernCpp::Chapter5::Terms26::Example0::LogAndAdd(const std::string& name)
{
    const auto now = std::chrono::system_clock::now();  // ȡ�õ�ǰʱ��

    Log(now, "logAndAdd");  // �Ʊ���־��Ŀ

    names.emplace(name);  // ��������ӵ�ȫ�����ݽṹ��
}

std::string BookExperience::EffectiveModernCpp::Chapter5::Terms26::Example0::NameFromIdx(MAYBE_UNUSED int idx)
{
    return "";
}

std::string BookExperience::EffectiveModernCpp::Chapter5::Terms26::Example2::NameFromIdx(MAYBE_UNUSED int idx)
{
    return "";
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms26::Example2::LogAndAdd(int idx)
{
    const auto now = std::chrono::system_clock::now();

    Log(now, "logAndAdd");

    names.emplace(NameFromIdx(idx));
}

BookExperience::EffectiveModernCpp::Chapter5::Terms26::Example0::Person::Person(int idx)
    : name(NameFromIdx(idx))
{
}

std::string BookExperience::EffectiveModernCpp::Chapter5::Terms26::Example1::NameFromIdx(MAYBE_UNUSED int idx)
{
    return "";
}
