/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "SystemConstant.h"
#include "SystemConstantContainer.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

CSVConfigure::SystemConstantContainer::SystemConstantContainer(const CSVContent& csvContent)
    : systemConstant{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void CSVConfigure::SystemConstantContainer::Parsing(const CSVContent& csvContent)
{
    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("systemConstant��ʼ���롭��"));

    Load(csvContent);
    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("systemConstant��������롭��"));
}

void CSVConfigure::SystemConstantContainer::Load(const CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    const auto csvHead = csvContent.GetCSVHead();

    if (size == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("systemConstant��Ϊ�ա�"s))
    }

    if (1 < size)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, User, SYSTEM_TEXT("systemConstant����Ψһ��"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }

    CoreTools::CSVRow csvRow{ csvContent.GetCSVHead(), csvContent.GetContent(0) };

    systemConstant = std::make_shared<SystemConstant>(csvRow);

}

CLASS_INVARIANT_STUB_DEFINE(CSVConfigure, SystemConstantContainer)

CSVConfigure::SystemConstantContainer::ConstSystemConstantSharedPtr CSVConfigure::SystemConstantContainer::GetSystemConstant() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return systemConstant;
}

