/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "Input2.h"
#include "Input2ContainerDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

OutputCSVTesting::Input2Container::Input2Container(const CSVContent& csvContent)
    : input2{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void OutputCSVTesting::Input2Container::Parsing(const CSVContent& csvContent)
{
    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("input2表开始载入……"));

    Load(csvContent);
    Unique();

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("input2表结束载入……"));
}

void OutputCSVTesting::Input2Container::Load(const CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    const auto csvHead = csvContent.GetCSVHead();

    for (auto index = 0; index < size; ++index)
    {
        CoreTools::CSVRow csvRow{ csvHead, csvContent.GetContent(index) };

        input2.emplace_back(std::make_shared<Input2>(csvRow));
    }

    std::ranges::sort(input2, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });
}

void OutputCSVTesting::Input2Container::Unique()
{
    const auto iter = std::ranges::unique(input2, [](const auto& lhs, const auto& rhs) noexcept {
        if((*lhs).GetKey() == (*rhs).GetKey())
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, User, SYSTEM_TEXT("input2表存在重复主键，key = "), (*lhs).GetKey(), SYSTEM_TEXT("。\n"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

            return true;
        }
        else
        {
            return false;
        }
    });

    if (iter.begin() != iter.end())
    {
        input2.erase(iter.begin(), iter.end());
    }

    input2.shrink_to_fit();
}

CLASS_INVARIANT_STUB_DEFINE(OutputCSVTesting, Input2Container)

OutputCSVTesting::Input2Container::ConstInput2SharedPtr OutputCSVTesting::Input2Container::GetFirstInput2() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return input2.at(0);
}

OutputCSVTesting::Input2Container::ConstInput2SharedPtr OutputCSVTesting::Input2Container::GetInput2(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    if (const auto iter = std::ranges::lower_bound(input2, std::make_shared<Input2Base>(key), function);
        iter != input2.cend() && (*iter)->GetKey() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("input2表未找到key = "s) + System::ToString(key) + SYSTEM_TEXT("的配置信息。"s))
    }
}

OutputCSVTesting::Input2Container::Container OutputCSVTesting::Input2Container::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return input2;
}

int OutputCSVTesting::Input2Container::GetContainerSize() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(input2.size());
}

