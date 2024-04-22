/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/01 10:40)

#include "CoreTools/CoreToolsExport.h"

#include "IFileStreamSeekManager.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::IFileStreamSeekManager::IFileStreamSeekManager(MasterTypeReference master)
    : master{ master }, currentPosition{ master.tellg() }
{
    SeekBeginPosition();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

void CoreTools::IFileStreamSeekManager::SeekBeginPosition()
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

CoreTools::IFileStreamSeekManager::~IFileStreamSeekManager() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    ResetPosition();
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::IFileStreamSeekManager::IsValid() const noexcept
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

CoreTools::IFileStreamSeekManager::MasterPosType CoreTools::IFileStreamSeekManager::GetErrorPosition()
{
    static MasterPosType errorPosition{ -1 };

    return errorPosition;
}

void CoreTools::IFileStreamSeekManager::ResetPosition() noexcept
{
    EXCEPTION_TRY
    {
        master.seekg(currentPosition, MasterType::beg);
    }
    EXCEPTION_ALL_CATCH(CoreTools)
}
