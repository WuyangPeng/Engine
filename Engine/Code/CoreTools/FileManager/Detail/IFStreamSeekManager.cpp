///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 15:38)

#include "CoreTools/CoreToolsExport.h"

#include "IFStreamSeekManager.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::IFStreamSeekManager::IFStreamSeekManager(MasterTypeReference master)
    : master{ master }, currentPosition{ master.tellg() }
{
    SeekBeginPosition();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

void CoreTools::IFStreamSeekManager::SeekBeginPosition()
{
    if (master && currentPosition != GetErrorPosition())
    {
        master.seekg(0, MasterType::beg);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("设置文件当前位置失败!"s))
    }
}

CoreTools::IFStreamSeekManager::~IFStreamSeekManager() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    ResetPosition();
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::IFStreamSeekManager::IsValid() const noexcept
{
    try
    {
        if (master && currentPosition != GetErrorPosition())
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

void CoreTools::IFStreamSeekManager::ResetPosition() noexcept
{
    EXCEPTION_TRY
    {
        master.seekg(currentPosition, MasterType::beg);
    }
    EXCEPTION_ALL_CATCH(CoreTools)
}
