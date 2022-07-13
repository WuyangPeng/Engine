///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 13:41)

#include "Network/NetworkExport.h"

#include "NetworkDelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/DelayCopyUnshared/NetworkDelayCopyUnsharedMacroImpl.h"

Network::NetworkDelayCopyUnsharedMacro::NetworkDelayCopyUnsharedMacro(int count)
    : impl{ count }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, NetworkDelayCopyUnsharedMacro)

int Network::NetworkDelayCopyUnsharedMacro::GetCount() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Network::NetworkDelayCopyUnsharedMacro::SetCount(int count)
{
    NETWORK_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

COPY_UNSHARED_CLONE_SELF_DEFINE(Network, NetworkDelayCopyUnsharedMacro)