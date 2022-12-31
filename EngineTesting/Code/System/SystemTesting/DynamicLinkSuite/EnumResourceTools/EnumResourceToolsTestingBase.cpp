///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/09 11:26)

/// ԭʼ�ļ���SystemTesting�£�SystemWindowsTesting�µ�Ϊ�Զ������ļ��������޸ġ�
#include "EnumResourceToolsTestingBase.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::EnumResourceToolsTestingBase::EnumResourceToolsTestingBase(const OStreamShared& stream)
    : ParentType{ stream }, enumResourceDataContainer{}
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, EnumResourceToolsTestingBase)

void System::EnumResourceToolsTestingBase::AddEnumResourceData(const DynamicLinkCharType* type, const DynamicLinkCharType* name, WindowsWord language)
{
    SYSTEM_CLASS_IS_VALID_1;

    enumResourceDataContainer.emplace_back(type, name, language);
}

System::EnumResourceToolsTestingBase::EnumResourceDataContainerConstIter System::EnumResourceToolsTestingBase::begin() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return enumResourceDataContainer.cbegin();
}

System::EnumResourceToolsTestingBase::EnumResourceDataContainerConstIter System::EnumResourceToolsTestingBase::end() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return enumResourceDataContainer.cend();
}

size_t System::EnumResourceToolsTestingBase::GetEnumResourceDataSize() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return enumResourceDataContainer.size();
}

System::EnumResourceToolsTestingBase* System::EnumResourceToolsTestingBase::GetBase(WindowsLongPtrSizeType lParam) noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    return reinterpret_cast<ClassType*>(lParam);

#include STSTEM_WARNING_POP
}

void System::EnumResourceToolsTestingBase::ClearEnumResourceData() noexcept
{
    SYSTEM_CLASS_IS_VALID_1;

    enumResourceDataContainer.clear();
}
