///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/22 13:47)

#ifndef NETWORK_ACE_WRAPPERS_STRING_CONVERSION_H
#define NETWORK_ACE_WRAPPERS_STRING_CONVERSION_H

#include "Network/NetworkDll.h"

#include "System/Helper/PragmaWarning/ACE.h"
#include "Network/Interface/Detail/BaseMainManagerImpl.h"

#ifdef NETWORK_USE_ACE

namespace Network
{
    class NETWORK_HIDDEN_DECLARE StringConversion final
    {
    public:
        using ClassType = StringConversion;

    public:
        StringConversion() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD static std::string ACEStringConversionMultiByte(const ACEString& character);
    };
}

#endif  // NETWORK_USE_ACE

#endif  // NETWORK_ACE_WRAPPERS_STRING_CONVERSION_H
