/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 16:37)

#include "Example/Mathematics/DistanceAlignedBoxesCore/DistanceAlignedBoxesCoreExport.h"

#include "ResourceManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Rendering/State/BlendState.h"
#include "Rendering/State/Flags/RasterizerStateCull.h"
#include "Rendering/State/Flags/RasterizerStateFill.h"
#include "Rendering/State/RasterizerState.h"

DistanceAlignedBoxes::ResourceManagerImpl::ResourceManagerImpl(const EnvironmentDirectory& environmentDirectory)
    : noCullState{ RasterizerState::Create("noCullState", Rendering::RasterizerStateCull::None) },
      noCullWireState{ RasterizerState::Create("noCullWireState", Rendering::RasterizerStateFill::Wireframe, Rendering::RasterizerStateCull::None) },
      blendState{ BlendState::Create("blendState") },
      box0Mesh{},
      box1Mesh{},
      redEffect{},
      blueEffect{},
      sgment{},
      point0{},
      point1{},
      box0{},
      box1{}
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
