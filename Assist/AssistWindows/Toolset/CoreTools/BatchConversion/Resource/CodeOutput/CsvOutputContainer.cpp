/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "CsvOutputContainer.h"

#include "Input1Container.h"
#include "Input2Container.h"
#include "Input3Container.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"

#include <filesystem>

using namespace std::literals;

CsvOutput::CsvOutputContainer::CsvOutputContainer(const System::String& directory)
    : input1Container{},
      input2Container{},
      input3Container{}
{
    Parsing(directory);
    Verify();

    USER_SELF_CLASS_IS_VALID_1;
}

void CsvOutput::CsvOutputContainer::Parsing(const System::String& directory)
{
    const std::filesystem::path path{ directory };

    for (const auto& inputPath : std::filesystem::directory_iterator(path))
    {
        auto fileName = inputPath.path().native();

        if (fileName.find(SYSTEM_TEXT(".csv"s)) != (fileName.size() - 4))
        {
            continue;
        }

        CoreTools::CSVContent csvContent{ fileName };

        const auto csvClassName = csvContent.GetCSVClassName();

        if (csvClassName == SYSTEM_TEXT("Input1"s))
        {
            input1Container = std::make_shared<Input1Container>(csvContent);
        }
        else if (csvClassName == SYSTEM_TEXT("Input2"s))
        {
            input2Container = std::make_shared<Input2Container>(csvContent);
        }
        else if (csvClassName == SYSTEM_TEXT("Input3"s))
        {
            input3Container = std::make_shared<Input3Container>(csvContent);
        }
    }
}

void CsvOutput::CsvOutputContainer::Verify() const
{
    if (!input1Container)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("input1表不存在。"s))
    }

    if (!input2Container)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("input2表不存在。"s))
    }

    if (!input3Container)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("input3表不存在。"s))
    }

}

#ifdef OPEN_CLASS_INVARIANT

bool CsvOutput::CsvOutputContainer::IsValid() const noexcept
{
    if (input1Container &&
        input2Container &&
        input3Container)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

std::shared_ptr<const CsvOutput::Input1Container> CsvOutput::CsvOutputContainer::GetInput1Container() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return input1Container;
}

std::shared_ptr<const CsvOutput::Input2Container> CsvOutput::CsvOutputContainer::GetInput2Container() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return input2Container;
}

std::shared_ptr<const CsvOutput::Input3Container> CsvOutput::CsvOutputContainer::GetInput3Container() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return input3Container;
}

