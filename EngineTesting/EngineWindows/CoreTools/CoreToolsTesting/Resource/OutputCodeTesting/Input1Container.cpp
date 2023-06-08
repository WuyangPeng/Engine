/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "Input1.h"
#include "Input1ContainerDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

OutputCSVTesting::Input1Container::Input1Container(const CoreTools::CSVContent& csvContent)
    : input1{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void OutputCSVTesting::Input1Container::Parsing(const CoreTools::CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    for (auto i = 0; i < size; ++i)
    {
        CoreTools::CSVRow csvRow{ csvContent.GetCSVHead(), csvContent.GetContent(i) };

        input1.emplace_back(std::make_shared<Input1>(csvRow));
    }

    std::ranges::sort(input1, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });

    const auto iter = std::ranges::unique(input1, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() == (*rhs).GetKey();
    });

    if (iter.begin() != iter.end())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, User,  SYSTEM_TEXT("input1表存在重复主键。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

        input1.erase(iter.begin(), iter.end());
    }
}

CLASS_INVARIANT_STUB_DEFINE(OutputCSVTesting, Input1Container)

OutputCSVTesting::Input1Container::ConstInput1BaseSharedPtr OutputCSVTesting::Input1Container::GetFirstInput1() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return input1.at(0);
}

OutputCSVTesting::Input1Container::ConstInput1BaseSharedPtr OutputCSVTesting::Input1Container::GetInput1(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    const auto iter = std::ranges::lower_bound(input1, std::make_shared<Input1Base>(key), function);

    if (iter != input1.cend() && (*iter)->GetKey() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("input1表未找到key = "s) + System::ToString(key) + SYSTEM_TEXT("的配置信息。"s))
    }
}

OutputCSVTesting::Input1Container::Container OutputCSVTesting::Input1Container::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return input1;
}

