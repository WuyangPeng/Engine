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
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

CsvOutput::Input1Container::Input1Container(const CSVContent& csvContent)
    : input1{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void CsvOutput::Input1Container::Parsing(const CSVContent& csvContent)
{
    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("input1表开始载入……"));

    Load(csvContent);
    Unique();

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("input1表结束载入……"));
}

void CsvOutput::Input1Container::Load(const CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    const auto csvHead = csvContent.GetCSVHead();

    for (auto index = 0; index < size; ++index)
    {
        CoreTools::CSVRow csvRow{ csvHead, csvContent.GetContent(index) };

        input1.emplace_back(std::make_shared<Input1>(csvRow));
    }

    std::ranges::sort(input1, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });
}

void CsvOutput::Input1Container::Unique()
{
    const auto iter = std::ranges::unique(input1, [](const auto& lhs, const auto& rhs) noexcept {
        if((*lhs).GetKey() == (*rhs).GetKey())
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, User, SYSTEM_TEXT("input1表存在重复主键，key = "), (*lhs).GetKey(), SYSTEM_TEXT("。\n"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

            return true;
        }
        else
        {
            return false;
        }
    });

    if (iter.begin() != iter.end())
    {
        input1.erase(iter.begin(), iter.end());
    }

    input1.shrink_to_fit();
}

CLASS_INVARIANT_STUB_DEFINE(CsvOutput, Input1Container)

CsvOutput::Input1Container::ConstInput1SharedPtr CsvOutput::Input1Container::GetFirstInput1() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return input1.at(0);
}

CsvOutput::Input1Container::ConstInput1SharedPtr CsvOutput::Input1Container::GetInput1(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    if (const auto iter = std::ranges::lower_bound(input1, std::make_shared<Input1Base>(key), function);
        iter != input1.cend() && (*iter)->GetKey() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("input1表未找到key = "s) + System::ToString(key) + SYSTEM_TEXT("的配置信息。"s))
    }
}

CsvOutput::Input1Container::Container CsvOutput::Input1Container::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return input1;
}

int CsvOutput::Input1Container::GetContainerSize() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(input1.size());
}

