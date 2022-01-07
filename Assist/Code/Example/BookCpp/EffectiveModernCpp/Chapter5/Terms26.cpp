///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.6 (2021/11/15 20:28)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms26.h"

std::multiset<std::string> BookExperience::EffectiveModernCpp::Chapter5::Terms26::names;

void BookExperience::EffectiveModernCpp::Chapter5::Terms26::Example0::LogAndAdd(const std::string& name)
{
    const auto now = std::chrono::system_clock::now();  // 取得当前时间

    Log(now, "logAndAdd");  // 制备日志条目

    names.emplace(name);  // 将名字添加到全局数据结构中
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
