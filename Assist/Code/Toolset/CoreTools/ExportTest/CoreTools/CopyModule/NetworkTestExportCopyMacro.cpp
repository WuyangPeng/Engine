///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 18:52)

#include "Network/NetworkExport.h"

#include "NetworkTestExportCopyMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/CopyModule/NetworkTestExportCopyMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Network, NetworkTestExportCopyMacro)

Network::NetworkTestExportCopyMacro::NetworkTestExportCopyMacro(int count)
    : impl{ count }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, NetworkTestExportCopyMacro)

int Network::NetworkTestExportCopyMacro::GetCount() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Network::NetworkTestExportCopyMacro::SetCount(int count) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    impl->SetCount(count);
}
