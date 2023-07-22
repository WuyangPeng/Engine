/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "Input1.h"
#include "Input1ContainerDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

OutputCSVTesting::Input1Container::Input1Container(const CSVContent& csvContent)
    : input1{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void OutputCSVTesting::Input1Container::Parsing(const CSVContent& csvContent)
{
    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("input1����ʼ���롭��"));

    Load(csvContent);
    Unique();

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("input1���������롭��"));
}

void OutputCSVTesting::Input1Container::Load(const CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    const auto csvHead = csvContent.GetCSVHead();

    for (auto i = 0; i < size; ++i)
    {
        CoreTools::CSVRow csvRow{ csvHead, csvContent.GetContent(i) };

        input1.emplace_back(std::make_shared<Input1>(csvRow));
    }

    std::ranges::sort(input1, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });
}

void OutputCSVTesting::Input1Container::Unique()
{
    const auto iter = std::ranges::unique(input1, [](const auto& lhs, const auto& rhs) noexcept {
        if((*lhs).GetKey() == (*rhs).GetKey())
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, User, SYSTEM_TEXT("input1�������ظ�������key = "), (*lhs).GetKey(), SYSTEM_TEXT("��\n"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

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
        THROW_EXCEPTION(SYSTEM_TEXT("input1��δ�ҵ�key = "s) + System::ToString(key) + SYSTEM_TEXT("��������Ϣ��"s))
    }
}

OutputCSVTesting::Input1Container::Container OutputCSVTesting::Input1Container::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return input1;
}
