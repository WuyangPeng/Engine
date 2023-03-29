///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/16 19:36)

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