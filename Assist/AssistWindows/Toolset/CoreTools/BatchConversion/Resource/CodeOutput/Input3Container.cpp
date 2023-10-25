/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "Input3.h"
#include "Input3ContainerDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

CsvOutput::Input3Container::Input3Container(const CSVContent& csvContent)
    : input3{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void CsvOutput::Input3Container::Parsing(const CSVContent& csvContent)
{
    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("input3��ʼ���롭��"));

    Load(csvContent);
    Unique();

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("input3��������롭��"));
}

void CsvOutput::Input3Container::Load(const CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    const auto csvHead = csvContent.GetCSVHead();

    for (auto i = 0; i < size; ++i)
    {
        CoreTools::CSVRow csvRow{ csvHead, csvContent.GetContent(i) };

        input3.emplace_back(std::make_shared<Input3>(csvRow));
    }

    std::ranges::sort(input3, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });
}

void CsvOutput::Input3Container::Unique()
{
    const auto iter = std::ranges::unique(input3, [](const auto& lhs, const auto& rhs) noexcept {
        if((*lhs).GetKey() == (*rhs).GetKey())
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, User, SYSTEM_TEXT("input3������ظ�������key = "), (*lhs).GetKey(), SYSTEM_TEXT("��\n"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

            return true;
        }
        else
        {
            return false;
        }
    });

    if (iter.begin() != iter.end())
    {
        input3.erase(iter.begin(), iter.end());
    }

    input3.shrink_to_fit();
}

CLASS_INVARIANT_STUB_DEFINE(CsvOutput, Input3Container)

CsvOutput::Input3Container::ConstInput3BaseSharedPtr CsvOutput::Input3Container::GetFirstInput3() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return input3.at(0);
}

CsvOutput::Input3Container::ConstInput3BaseSharedPtr CsvOutput::Input3Container::GetInput3(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    const auto iter = std::ranges::lower_bound(input3, std::make_shared<Input3Base>(key), function);

    if (iter != input3.cend() && (*iter)->GetKey() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("input3��δ�ҵ�key = "s) + System::ToString(key) + SYSTEM_TEXT("��������Ϣ��"s))
    }
}

CsvOutput::Input3Container::Container CsvOutput::Input3Container::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return input3;
}

int CsvOutput::Input3Container::GetContainerSize() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(input3.size());
}

