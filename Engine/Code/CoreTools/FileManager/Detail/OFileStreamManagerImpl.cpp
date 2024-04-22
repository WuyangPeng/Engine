/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/01 10:41)

#include "CoreTools/CoreToolsExport.h"

#include "OFileStreamManagerImpl.h"
#include "OFileStreamSeekManager.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::OFileStreamManagerImpl::OFileStreamManagerImpl(const String& fileName, bool addition)
    : oStream{ fileName, GetOpenMode(fileName, addition) }, fileName{ fileName }
{
    ASSERT_FAIL_THROW_EXCEPTION(oStream, (Error::Format(SYSTEM_TEXT("打开文件%1%失败！"s)) % fileName).str())

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

std::ios_base::openmode CoreTools::OFileStreamManagerImpl::GetOpenMode(const String& fileName, bool addition)
{
    if (fileName.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("文件名为空！"s))
    }

    if (addition)
    {
        return OFileStream::out | OFileStream::app;
    }
    else
    {
        return OFileStream::out;
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::OFileStreamManagerImpl::IsValid() const noexcept
{
    try
    {
        return !fileName.empty() && oStream;
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

CoreTools::OFileStreamManagerImpl::PosType CoreTools::OFileStreamManagerImpl::GetStreamSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const PosType errorPosition{ -1 };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26492)

    const auto thisImpl = const_cast<OFileStreamManagerImpl*>(this);

#include SYSTEM_WARNING_POP

    OFileStreamSeekManager manager{ thisImpl->oStream };

    thisImpl->SeekEnd();

    if (const auto endPosition = thisImpl->oStream.tellp(); endPosition != errorPosition)
        return PosType{ endPosition };
    else
        return PosType{ 0 };
}

void CoreTools::OFileStreamManagerImpl::SeekEnd()
{
    oStream.seekp(0, OFileStream::end);
}

CoreTools::OFileStreamManagerImpl& CoreTools::OFileStreamManagerImpl::operator<<(const String& message)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    oStream << message;

    return *this;
}

void CoreTools::OFileStreamManagerImpl::SetSimplifiedChinese()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

#if !defined(TCRE_USE_GCC)

    static const std::locale chs{ "chs" };

    oStream.imbue(chs);

#endif  // !defined(TCRE_USE_GCC)
}
