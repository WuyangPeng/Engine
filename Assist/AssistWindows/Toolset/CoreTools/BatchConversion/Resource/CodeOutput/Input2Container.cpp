/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "Input2.h"
#include "Input2ContainerDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

CsvOutput::Input2Container::Input2Container(const CoreTools::CSVContent& csvContent)
    : input2{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void CsvOutput::Input2Container::Parsing(const CoreTools::CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    for (auto i = 0; i < size; ++i)
    {
        CoreTools::CSVRow csvRow{ csvContent.GetCSVHead(), csvContent.GetContent(i) };

        input2.emplace_back(std::make_shared<Input2>(csvRow));
    }

    std::ranges::sort(input2, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });

    const auto iter = std::ranges::unique(input2, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() == (*rhs).GetKey();
    });

    if (iter.begin() != iter.end())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, User,  SYSTEM_TEXT("input2�������ظ�������"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

        input2.erase(iter.begin(), iter.end());
    }
}

CLASS_INVARIANT_STUB_DEFINE(CsvOutput, Input2Container)

CsvOutput::Input2Container::ConstInput2BaseSharedPtr CsvOutput::Input2Container::GetFirstInput2() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return input2.at(0);
}

CsvOutput::Input2Container::ConstInput2BaseSharedPtr CsvOutput::Input2Container::GetInput2(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    const auto iter = std::ranges::lower_bound(input2, std::make_shared<Input2Base>(key), function);

    if (iter != input2.cend() && (*iter)->GetKey() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("input2��δ�ҵ�key = "s) + System::ToString(key) + SYSTEM_TEXT("��������Ϣ��"s))
    }
}

CsvOutput::Input2Container::Container CsvOutput::Input2Container::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return input2;
}
