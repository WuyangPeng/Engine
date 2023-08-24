///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/08 19:51)

#ifndef FRAMEWORK_MACINTOSH_MACINTOSH_PROCESS_H
#define FRAMEWORK_MACINTOSH_MACINTOSH_PROCESS_H

#include "Rendering/RenderingDll.h"

#include "MacintoshCallBackInterface.h"

#include <memory>
#include <type_traits>

namespace Framework
{
    template <typename MacintoshCallBack>
    class MacintoshProcess
    {
    public:
        static_assert(std::is_base_of_v<MacintoshCallBackInterface, MacintoshCallBack>);

    public:
        using CallBackType = MacintoshCallBack;
        using ClassType = MacintoshProcess<CallBackType>;

        using MacintoshCallBackInterfaceSharedPtr = std::shared_ptr<MacintoshCallBackInterface>;

    public:
        MacintoshProcess() = default;
        virtual ~MacintoshProcess() noexcept = default;
        MacintoshProcess(const MacintoshProcess& rhs) noexcept = default;
        MacintoshProcess& operator=(const MacintoshProcess& rhs) noexcept = default;
        MacintoshProcess(MacintoshProcess&& rhs) noexcept = default;
        MacintoshProcess& operator=(MacintoshProcess&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;
    };

    using MacintoshProcessInterface = MacintoshProcess<MacintoshCallBackInterface>;
}

#endif  // FRAMEWORK_MACINTOSH_MACINTOSH_PROCESS_H
