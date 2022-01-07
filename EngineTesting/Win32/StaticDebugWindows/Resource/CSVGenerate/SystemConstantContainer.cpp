/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++17
/// 自动生成

#include "SystemConstant.h"
#include "SystemConstantContainer.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

using std::make_shared;

CSVConfigure::SystemConstantContainer::SystemConstantContainer(const CoreTools::CSVContent& csvContent)
    : systemConstant{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void CSVConfigure::SystemConstantContainer::Parsing(const CoreTools::CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    if (size == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("systemConstant表为空。"s));
    }

    if (1 < size)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, User)
            << SYSTEM_TEXT("systemConstant表不是唯一的")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }

    CoreTools::CSVRow csvRow{ csvContent.GetCSVHead(), csvContent.GetContent(0) };

    systemConstant = make_shared<SystemConstant>(csvRow);
}

CLASS_INVARIANT_STUB_DEFINE(CSVConfigure, SystemConstantContainer)

CSVConfigure::SystemConstantContainer::ConstSystemConstantSharedPtr CSVConfigure::SystemConstantContainer::GetSystemConstant() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return systemConstant;
}

