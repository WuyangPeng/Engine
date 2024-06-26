/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:00)

#include "Network/NetworkExport.h"

#include "NetworkCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/CopyUnshared/NetworkCopyUnsharedMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Network, NetworkCopyUnsharedMacro)

Network::NetworkCopyUnsharedMacro::NetworkCopyUnsharedMacro(int count)
    : impl{ count }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, NetworkCopyUnsharedMacro)

int Network::NetworkCopyUnsharedMacro::GetCount() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Network::NetworkCopyUnsharedMacro::SetCount(int count) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

const void* Network::NetworkCopyUnsharedMacro::GetAddress() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}