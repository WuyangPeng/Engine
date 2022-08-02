///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/27 13:21)

#include "MailServerCoreExport.h"

#include "DllLib.h"
#include "MailServerCore.h"

#ifdef BUILDING_MAIL_SERVER_CORE_STATIC
 
namespace MailServerCore
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // BUILDING_MAIL_SERVER_CORE_STATIC