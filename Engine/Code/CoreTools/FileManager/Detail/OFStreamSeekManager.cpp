//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/14 13:16)

#include "CoreTools/CoreToolsExport.h"

#include "OFStreamSeekManager.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using namespace std::literals;

CoreTools::OFStreamSeekManager::OFStreamSeekManager(MasterTypeReference master)
    : m_Master{ master }, m_CurrentPosition{ m_Master.tellp() }
{
    SeekBeginPosition();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::OFStreamSeekManager::SeekBeginPosition()
{
    if (m_Master && m_CurrentPosition != GetErrorPosition())
    {
        m_Master.seekp(0, MasterType::beg);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("获取文件当前位置失败!"s));
    }
}

CoreTools::OFStreamSeekManager::~OFStreamSeekManager() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    EXCEPTION_TRY
    {
        m_Master.seekp(m_CurrentPosition, MasterType::beg);
    }
    EXCEPTION_ALL_CATCH(CoreTools)
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::OFStreamSeekManager::IsValid() const noexcept
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

CoreTools::OFStreamSeekManager::MasterPosType CoreTools::OFStreamSeekManager::GetErrorPosition()
{
    static MasterPosType errorPosition{ -1 };

    return errorPosition;
}