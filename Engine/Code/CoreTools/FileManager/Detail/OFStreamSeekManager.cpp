///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/03/02 10:48)

#include "CoreTools/CoreToolsExport.h"

#include "OFStreamSeekManager.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using namespace std::literals;

CoreTools::OFStreamSeekManager::OFStreamSeekManager(MasterTypeReference master)
    : master{ master }, currentPosition{ master.tellp() }
{
    SeekBeginPosition();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

void CoreTools::OFStreamSeekManager::SeekBeginPosition()
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

CoreTools::OFStreamSeekManager::~OFStreamSeekManager() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    ResetPosition();
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::OFStreamSeekManager::IsValid() const noexcept
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

CoreTools::OFStreamSeekManager::MasterPosType CoreTools::OFStreamSeekManager::GetErrorPosition()
{
    static MasterPosType errorPosition{ -1 };

    return errorPosition;
}

void CoreTools::OFStreamSeekManager::ResetPosition() noexcept
{
    EXCEPTION_TRY
    {
        master.seekp(currentPosition, MasterType::beg);
    }
    EXCEPTION_ALL_CATCH(CoreTools)
}
