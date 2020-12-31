//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 11:22)

#include "Network/NetworkExport.h"

#include "HandleSetImpl.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::make_shared;

CLASS_INVARIANT_STUB_DEFINE(Network, HandleSetImpl)

void Network::HandleSetImpl::SetBit([[maybe_unused]] ACEHandle handle)
{
    NETWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();
}

int64_t Network::HandleSetImpl::GetMaxSet() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    CoreTools::DisableNoexcept();

    return 0;
}

Network::SockFdSet* Network::HandleSetImpl::GetFdSet()
{
    NETWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("获取fdset失败！"s));
}

void Network::HandleSetImpl::Sync([[maybe_unused]] ACEHandle maxHandle)
{
    NETWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();
}

bool Network::HandleSetImpl::IsSet([[maybe_unused]] ACEHandle handle) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    CoreTools::DisableNoexcept();

    return false;
}

void Network::HandleSetImpl::ClearBit([[maybe_unused]] ACEHandle handle)
{
    NETWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();
}

Network::HandleSetImpl::ImplTypePtr Network::HandleSetImpl::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return make_shared<ClassType>(*this);
}

const Network::ACEHandleSet& Network::HandleSetImpl::GetACEHandleSet() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("获取ACEHandleSet失败！"s));
}

bool Network::HandleSetImpl::IsFdSetFull() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    CoreTools::DisableNoexcept();

    return true;
}

int Network::HandleSetImpl::IsFdSetCount() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    CoreTools::DisableNoexcept();

    return 0;
}

bool Network::HandleSetImpl::Select([[maybe_unused]] int width)
{
    NETWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    return false;
}

bool Network::HandleSetImpl::IsFdSetCountIsOne() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return IsFdSetCount() == 1;
}
