//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 14:46)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestData.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::UnitTestData::UnitTestData() noexcept
    : m_Pass{ 0 }, m_Fail{ 0 }, m_Error{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::UnitTestData::IsValid() const noexcept
{
    if (0 <= m_Fail && 0 <= m_Pass && 0 <= m_Error)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

int CoreTools::UnitTestData::GetPassedNumber() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Pass;
}

int CoreTools::UnitTestData::GetFailedNumber() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Fail;
}

int CoreTools::UnitTestData::GetErrorNumber() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Error;
}

bool CoreTools::UnitTestData::IsEmpty() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return (m_Pass == 0) && (m_Fail == 0) && (m_Error == 0);
}

void CoreTools::UnitTestData::AddPassedNumber() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    ++m_Pass;
}

void CoreTools::UnitTestData::AddFailedNumber() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (m_Fail == 0)
    {
        System::SystemPause();
    }

    ++m_Fail;
}

void CoreTools::UnitTestData::AddErrorNumber() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (m_Error == 0)
    {
        System::SystemPause();
    }

    ++m_Error;
}

void CoreTools::UnitTestData::ClearData() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_Pass = 0;
    m_Fail = 0;
    m_Error = 0;
}
