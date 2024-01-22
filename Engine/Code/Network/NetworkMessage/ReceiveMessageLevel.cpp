/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 16:23)

#include "Network/NetworkExport.h"

#include "ReceiveMessageLevel.h"
#include "Detail/ReceiveMessageLevelImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Network, ReceiveMessageLevel)

Network::ReceiveMessageLevel Network::ReceiveMessageLevel::Create()
{
    return ReceiveMessageLevel{ CoreTools::DisableNotThrow::Disable };
}

Network::ReceiveMessageLevel::ReceiveMessageLevel(CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ReceiveMessageLevel)

int Network::ReceiveMessageLevel::GetTopLevelSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetTopLevelSize();
}

Network::ConstMessageInterfaceSharedPtr Network::ReceiveMessageLevel::operator[](int index) const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return (*impl)[index];
}

Network::ReceiveMessageLevel::MessageContainerConstIter Network::ReceiveMessageLevel::begin() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->begin();
}

Network::ReceiveMessageLevel::MessageContainerConstIter Network::ReceiveMessageLevel::end() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->end();
}

void Network::ReceiveMessageLevel::Insert(const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->Insert(message);
}
