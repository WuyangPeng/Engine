//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/14 13:02)

#include "CoreTools/CoreToolsExport.h"

#include "IFStreamSeekManager.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::IFStreamSeekManager::IFStreamSeekManager(MasterTypeReference master)
    : m_Master{ master }, m_CurrentPosition{ m_Master.tellg() }
{
    SeekBeginPosition();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::IFStreamSeekManager::SeekBeginPosition()
{
    if (m_Master && m_CurrentPosition != GetErrorPosition())
    {
        m_Master.seekg(0, MasterType::beg);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("设置文件当前位置失败!"s));
    }
}

CoreTools::IFStreamSeekManager::~IFStreamSeekManager() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    EXCEPTION_TRY
    {
        m_Master.seekg(m_CurrentPosition, MasterType::beg);
    }
    EXCEPTION_ALL_CATCH(CoreTools)
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::IFStreamSeekManager::IsValid() const noexcept
{
    try
    {
        if (m_Master && m_CurrentPosition != GetErrorPosition())
            return true;
        else
            return false;
    }
    catch (...)
    {
        return false;
    }
}
#endif  // OPEN_CLASS_INVARIANT

CoreTools::IFStreamSeekManager::MasterPosType CoreTools::IFStreamSeekManager::GetErrorPosition()
{
    static MasterPosType errorPosition{ -1 };

    return errorPosition;
}
