/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:25)

#include "Network/NetworkExport.h"

#include "NetworkPerformanceUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/PerformanceUnshared/NetworkPerformanceUnsharedMacroImpl.h"

Network::NetworkPerformanceUnsharedMacro::NetworkPerformanceUnsharedMacro(int count)
    : impl{ count }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, NetworkPerformanceUnsharedMacro)

int Network::NetworkPerformanceUnsharedMacro::GetCount() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

const void* Network::NetworkPerformanceUnsharedMacro::GetAddress() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}