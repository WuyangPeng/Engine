// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 11:03)

#include "Network/NetworkExport.h" 

#include "HandleSetContainer.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 

#include "System/Helper/PragmaWarning/NumericCast.h"
#include <functional>
#include <gsl/gsl_util>

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26486)

using std::placeholders::_1;
using std::bind;

Network::HandleSetContainer
	::HandleSetContainer(const ConfigurationStrategy& configurationStrategy, ACEHandle acceptorHandle)
	: m_ConfigurationStrategy{ configurationStrategy }, m_AcceptorHandle{ acceptorHandle },
	  m_HandleSetGroup{ HandleSet(configurationStrategy) }, m_CurrentIndex{ 0 }
{
	Init();

	NETWORK_SELF_CLASS_IS_VALID_1;
}

void Network::HandleSetContainer
	::Init()
{
	m_HandleSetGroup[m_CurrentIndex].SetBit(m_AcceptorHandle);
}

#ifdef OPEN_CLASS_INVARIANT
bool Network::HandleSetContainer
	::IsValid() const noexcept
{
	if (0 <= m_CurrentIndex && m_CurrentIndex < gsl::narrow_cast<int>(m_HandleSetGroup.size()))
		return true;
	else
		return false;
}

#endif // OPEN_CLASS_INVARIANT	

const  Network::HandleSet Network::HandleSetContainer
	::GetCurrentHandleSet() const noexcept
{
	NETWORK_CLASS_IS_VALID_CONST_1;

	return m_HandleSetGroup[m_CurrentIndex];
}

void Network::HandleSetContainer
	::SetBit(ACEHandle sockStreamHandle)
{
	NETWORK_CLASS_IS_VALID_1;

	auto setIndex = m_CurrentIndex;

	if (m_HandleSetGroup[setIndex].IsFdSetFull())
	{
		Expansion();
		setIndex = boost::numeric_cast<int>(m_HandleSetGroup.size() - 1);
	}

	m_HandleSetGroup[setIndex].SetBit(sockStreamHandle);
}

void Network::HandleSetContainer
	::ClearBit(ACEHandle sockStreamHandle)
{
	NETWORK_CLASS_IS_VALID_1;

	m_HandleSetGroup[m_CurrentIndex].ClearBit(sockStreamHandle);
}

void Network::HandleSetContainer
	::ToNextIndex()
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
void Network::HandleSetContainer
	::Expansion()
{
	auto endIndex = m_HandleSetGroup.size() - 1;
	if (m_HandleSetGroup[endIndex].IsFdSetFull())
	{
		m_HandleSetGroup.emplace_back(m_ConfigurationStrategy);
		endIndex = m_HandleSetGroup.size() - 1;
		m_HandleSetGroup[endIndex].SetBit(m_AcceptorHandle);
	}
}

#include STSTEM_WARNING_POP