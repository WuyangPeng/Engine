///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/22 13:50)

#include "CoreTools/CoreToolsExport.h"

#include "OFStreamManagerImpl.h"
#include "OFStreamSeekManager.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using namespace std::literals;

CoreTools::OFStreamManagerImpl::OFStreamManagerImpl(const String& fileName, bool addition)
    : oStream{ fileName, GetOpenMode(fileName, addition) }, fileName{ fileName }
{
    if (!oStream)
    {
        THROW_EXCEPTION((Error::Format(SYSTEM_TEXT("打开文件%1%失败！"s)) % fileName).str())
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

int CoreTools::OFStreamManagerImpl::GetOpenMode(const String& fileName, bool addition)
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

bool CoreTools::OFStreamManagerImpl::IsValid() const noexcept
{
    try
    {
        if (!fileName.empty() && oStream)
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

CoreTools::OFStreamManagerImpl::PosType CoreTools::OFStreamManagerImpl::GetStreamSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const OFileStream::pos_type errorPosition{ -1 };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26492)

    const auto thisImpl = const_cast<OFStreamManagerImpl*>(this);

#include SYSTEM_WARNING_POP

    OFStreamSeekManager manager{ thisImpl->oStream };

    thisImpl->SeekEnd();

    if (const auto endPosition = thisImpl->oStream.tellp(); endPosition != errorPosition)
        return endPosition;
    else
        return 0;
}

void CoreTools::OFStreamManagerImpl::SeekEnd()
{
    oStream.seekp(0, OFileStream::end);
}

CoreTools::OFStreamManagerImpl& CoreTools::OFStreamManagerImpl::operator<<(const String& message)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    oStream << message;

    return *this;
}

void CoreTools::OFStreamManagerImpl::SetSimplifiedChinese()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

#if !defined(TCRE_USE_GCC)

    static const std::locale chs{ "chs" };

    oStream.imbue(chs);

#endif  // !defined(TCRE_USE_GCC)
}
