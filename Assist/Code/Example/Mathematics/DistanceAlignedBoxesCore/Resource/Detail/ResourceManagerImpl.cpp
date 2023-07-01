///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/26 18:13)

#include "Example/Mathematics/DistanceAlignedBoxesCore/DistanceAlignedBoxesCoreExport.h"

#include "ResourceManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Rendering/State/Flags/RasterizerStateCull.h"
#include "Rendering/State/Flags/RasterizerStateFill.h"
#include "Rendering/State/RasterizerState.h"

DistanceAlignedBoxes::ResourceManagerImpl::ResourceManagerImpl(const EnvironmentDirectory& environmentDirectory)
    : noCullState{ RasterizerState::Create("noCullState", Rendering::RasterizerStateCull::None) },
      noCullWireState{ RasterizerState::Create("noCullWireState", Rendering::RasterizerStateFill::Wireframe, Rendering::RasterizerStateCull::None) }
{
    System::UnusedFunction(environmentDirectory);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool DistanceAlignedBoxes::ResourceManagerImpl::IsValid() const noexcept
{
    if (noCullState != nullptr && noCullWireState != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

DistanceAlignedBoxes::ResourceManagerImpl::RasterizerStateSharedPtr DistanceAlignedBoxes::ResourceManagerImpl::GetNoCullStater() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    return noCullState;
}
