///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 15:24)

#include "Network/NetworkExport.h"

#include "HandleSetContainer.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

#include <gsl/util>

Network::HandleSetContainer::HandleSetContainer(const ConfigurationStrategy& configurationStrategy, ACEHandleType acceptorHandle)
    : configurationStrategy{ configurationStrategy },
      acceptorHandle{ acceptorHandle },
      handleSetGroup{ HandleSet(configurationStrategy) },
      currentIndex{ 0 }
{
    Init();

    NETWORK_SELF_CLASS_IS_VALID_1;
}

void Network::HandleSetContainer::Init()
{
    handleSetGroup.at(currentIndex).SetBit(acceptorHandle);
}

#ifdef OPEN_CLASS_INVARIANT

bool Network::HandleSetContainer::IsValid() const noexcept
{
    if (0 <= currentIndex && currentIndex < gsl::narrow_cast<int>(handleSetGroup.size()))
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

Network::HandleSet Network::HandleSetContainer::GetCurrentHandleSet() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return handleSetGroup.at(currentIndex);
}

void Network::HandleSetContainer::SetBit(ACEHandleType sockStreamHandle)
{
    NETWORK_CLASS_IS_VALID_1;

    auto setIndex = currentIndex;

    if (handleSetGroup.at(setIndex).IsFdSetFull())
    {
        Expansion();
        setIndex = boost::numeric_cast<int>(handleSetGroup.size() - 1);
    }

    handleSetGroup.at(setIndex).SetBit(sockStreamHandle);
}

void Network::HandleSetContainer::ClearBit(ACEHandleType sockStreamHandle)
{
    NETWORK_CLASS_IS_VALID_1;

    handleSetGroup.at(currentIndex).ClearBit(sockStreamHandle);
}

void Network::HandleSetContainer::ToNextIndex()
{
    NETWORK_CLASS_IS_VALID_1;

    if (1 < handleSetGroup.size())
    {
        ++currentIndex;

        if (boost::numeric_cast<int>(handleSetGroup.size()) <= currentIndex)
        {
            currentIndex = 0;

            handleSetGroup.erase(remove_if(handleSetGroup.begin() + 1,
                                           handleSetGroup.end(),
                                           [](const auto& value) {
                                               return value.IsFdSetCountIsOne();
                                           }),

                                 handleSetGroup.end());
        }
    }
}

void Network::HandleSetContainer::Expansion()
{
    if (auto endIndex = handleSetGroup.size() - 1;
        handleSetGroup.at(endIndex).IsFdSetFull())
    {
        handleSetGroup.emplace_back(configurationStrategy);

        endIndex = handleSetGroup.size() - 1;
        handleSetGroup.at(endIndex).SetBit(acceptorHandle);
    }
}
