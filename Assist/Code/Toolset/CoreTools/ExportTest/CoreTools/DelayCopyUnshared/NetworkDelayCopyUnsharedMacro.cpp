///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/18 22:12)

#include "Network/NetworkExport.h"

#include "NetworkDelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/DelayCopyUnshared/NetworkDelayCopyUnsharedMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Network, NetworkDelayCopyUnsharedMacro)

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
