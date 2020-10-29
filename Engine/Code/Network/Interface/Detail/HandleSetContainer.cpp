//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 11:20)

#include "Network/NetworkExport.h"

#include "HandleSetContainer.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

#include <gsl/gsl_util>
#include <functional>

using std::bind;
using std::placeholders::_1;

Network::HandleSetContainer::HandleSetContainer(const ConfigurationStrategy& configurationStrategy, ACEHandle acceptorHandle)
    : m_ConfigurationStrategy{ configurationStrategy }, m_AcceptorHandle{ acceptorHandle },
      m_HandleSetGroup{ HandleSet(configurationStrategy) }, m_CurrentIndex{ 0 }
{
    Init();

    NETWORK_SELF_CLASS_IS_VALID_1;
}

void Network::HandleSetContainer::Init()
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    m_HandleSetGroup[m_CurrentIndex].SetBit(m_AcceptorHandle);
#include STSTEM_WARNING_POP
}

#ifdef OPEN_CLASS_INVARIANT
bool Network::HandleSetContainer::IsValid() const noexcept
{
    if (0 <= m_CurrentIndex && m_CurrentIndex < gsl::narrow_cast<int>(m_HandleSetGroup.size()))
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

const Network::HandleSet Network::HandleSetContainer::GetCurrentHandleSet() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    return m_HandleSetGroup[m_CurrentIndex];
#include STSTEM_WARNING_POP
}

void Network::HandleSetContainer::SetBit(ACEHandle sockStreamHandle)
{
    NETWORK_CLASS_IS_VALID_1;

    auto setIndex = m_CurrentIndex;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    if (m_HandleSetGroup[setIndex].IsFdSetFull())
    {
        Expansion();
        setIndex = boost::numeric_cast<int>(m_HandleSetGroup.size() - 1);
    }

    m_HandleSetGroup[setIndex].SetBit(sockStreamHandle);
#include STSTEM_WARNING_POP
}

void Network::HandleSetContainer::ClearBit(ACEHandle sockStreamHandle)
{
    NETWORK_CLASS_IS_VALID_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    m_HandleSetGroup[m_CurrentIndex].ClearBit(sockStreamHandle);
#include STSTEM_WARNING_POP
}

void Network::HandleSetContainer::ToNextIndex()
{
    NETWORK_CLASS_IS_VALID_1;

    if (1 < m_HandleSetGroup.size())
    {
        ++m_CurrentIndex;

        if (boost::numeric_cast<int>(m_HandleSetGroup.size()) <= m_CurrentIndex)
        {
            m_CurrentIndex = 0;

            m_HandleSetGroup.erase(remove_if(m_HandleSetGroup.begin() + 1, m_HandleSetGroup.end(), bind(&HandleSet::IsFdSetCountIsOne, _1)), m_HandleSetGroup.end());
        }
    }
}

// private
void Network::HandleSetContainer::Expansion()
{
    auto endIndex = m_HandleSetGroup.size() - 1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    if (m_HandleSetGroup[endIndex].IsFdSetFull())
    {
        m_HandleSetGroup.emplace_back(m_ConfigurationStrategy);
        endIndex = m_HandleSetGroup.size() - 1;
        m_HandleSetGroup[endIndex].SetBit(m_AcceptorHandle);
    }
#include STSTEM_WARNING_POP
}
