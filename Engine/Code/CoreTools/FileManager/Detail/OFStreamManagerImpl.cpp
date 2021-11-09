///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.3 (2021/09/03 14:17)

#include "CoreTools/CoreToolsExport.h"

#include "OFStreamManagerImpl.h"
#include "OFStreamSeekManager.h"
#include "System/FileManager/CFile.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::locale;
using namespace std::literals;

CoreTools::OFStreamManagerImpl::OFStreamManagerImpl(const String& fileName, bool addition)
    : oStream{}, fileName{ fileName }
{
    if (!fileName.empty())
    {
        OpenFile(addition);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("文件名为空！"s));
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::OFStreamManagerImpl::OpenFile(bool addition)
{
    OFileStream::openmode mode{ OFileStream::out };
    if (addition)
    {
        mode |= OFileStream::app;
    }

    oStream.open(fileName.c_str(), mode);

    if (!oStream)
    {
        THROW_EXCEPTION((Error::Format(SYSTEM_TEXT("打开文件%1%失败！"s)) % fileName).str());
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

CoreTools::OFStreamManagerImpl::PosType CoreTools::OFStreamManagerImpl::GetOFStreamSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const OFileStream::pos_type errorPosition{ -1 };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26492)
    auto thisImpl = const_cast<OFStreamManagerImpl*>(this);
#include STSTEM_WARNING_POP

    OFStreamSeekManager manager{ thisImpl->oStream };

    thisImpl->SeekEnd();

    const auto endPosition = thisImpl->oStream.tellp();

    if (endPosition != errorPosition)
        return endPosition;
    else
        return 0;
}

// private
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
    locale chs{ "chs" };

    oStream.imbue(chs);
#endif  // !defined(TCRE_USE_GCC)
}
