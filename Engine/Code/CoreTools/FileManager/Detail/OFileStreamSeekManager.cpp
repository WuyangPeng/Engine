/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/01 10:41)

#include "CoreTools/CoreToolsExport.h"

#include "OFileStreamSeekManager.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::OFileStreamSeekManager::OFileStreamSeekManager(MasterTypeReference master)
    : master{ master }, currentPosition{ master.tellp() }
{
    SeekBeginPosition();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

void CoreTools::OFileStreamSeekManager::SeekBeginPosition()
{
    if (master && currentPosition != GetErrorPosition())
    {
        master.seekp(0, MasterType::beg);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("获取文件当前位置失败!"s));
    }
}

CoreTools::OFileStreamSeekManager::~OFileStreamSeekManager() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    ResetPosition();
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::OFileStreamSeekManager::IsValid() const noexcept
{
    try
    {
        return master && currentPosition != GetErrorPosition();
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

CoreTools::OFileStreamSeekManager::MasterPosType CoreTools::OFileStreamSeekManager::GetErrorPosition()
{
    static MasterPosType errorPosition{ -1 };

    return errorPosition;
}

void CoreTools::OFileStreamSeekManager::ResetPosition() noexcept
{
    EXCEPTION_TRY
    {
        master.seekp(currentPosition, MasterType::beg);
    }
    EXCEPTION_ALL_CATCH(CoreTools)
}
