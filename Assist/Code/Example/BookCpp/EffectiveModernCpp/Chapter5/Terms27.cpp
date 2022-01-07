///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.6 (2021/11/16 20:44)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms27.h"

std::multiset<std::string> BookExperience::EffectiveModernCpp::Chapter5::Terms27::names;

BookExperience::EffectiveModernCpp::Chapter5::Terms27::Example0::Person::Person(std::string n) noexcept
    : name(std::move(n))
{
}

BookExperience::EffectiveModernCpp::Chapter5::Terms27::Example0::Person::Person(int idx)
    : name(NameFromIdx(idx))
{
}

std::string BookExperience::EffectiveModernCpp::Chapter5::Terms27::Example0::NameFromIdx(MAYBE_UNUSED int idx)
{
    return "";
}

std::string BookExperience::EffectiveModernCpp::Chapter5::Terms27::Example1::NameFromIdx(MAYBE_UNUSED int idx)
{
    return "";
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms27::Example1::LogAndAddImpl(int idx, std::true_type)
{
    LogAndAdd(NameFromIdx(idx));
}

std::string BookExperience::EffectiveModernCpp::Chapter5::Terms27::Example2::NameFromIdx(MAYBE_UNUSED int idx)
{
    return "";
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms27::Example2::LogAndAddImpl(int idx, std::true_type)
{
    LogAndAdd(NameFromIdx(idx));
}

std::string BookExperience::EffectiveModernCpp::Chapter5::Terms27::Example4::NameFromIdx(MAYBE_UNUSED int idx)
{
    return "";
}

BookExperience::EffectiveModernCpp::Chapter5::Terms27::Example4::Person::Person(int idx)
    : name(NameFromIdx(idx))
{
}

std::string BookExperience::EffectiveModernCpp::Chapter5::Terms27::Example5::NameFromIdx(MAYBE_UNUSED int idx)
{
    return "";
}

BookExperience::EffectiveModernCpp::Chapter5::Terms27::Example5::Person::Person(int idx)
    : name(NameFromIdx(idx))
{
}
