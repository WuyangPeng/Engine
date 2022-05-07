///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/06 14:07)

#ifndef FRAMEWORK_MACINTOSH_MACINTOSH_CALL_BACK_INTERFACE_H
#define FRAMEWORK_MACINTOSH_MACINTOSH_CALL_BACK_INTERFACE_H

#include "Framework/FrameworkDll.h"

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE MacintoshCallBackInterface
    {
    public:
        using ClassType = MacintoshCallBackInterface;

    public:
        MacintoshCallBackInterface() noexcept = default;
        virtual ~MacintoshCallBackInterface() noexcept = default;
        MacintoshCallBackInterface(const MacintoshCallBackInterface& rhs) noexcept = default;
        MacintoshCallBackInterface& operator=(const MacintoshCallBackInterface& rhs) noexcept = default;
        MacintoshCallBackInterface(MacintoshCallBackInterface&& rhs) noexcept = default;
        MacintoshCallBackInterface& operator=(MacintoshCallBackInterface&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;
    };
}

#endif  // FRAMEWORK_MACINTOSH_MACINTOSH_CALL_BACK_INTERFACE_H
