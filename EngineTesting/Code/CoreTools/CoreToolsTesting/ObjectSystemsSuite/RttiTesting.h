/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/22 16:53)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_RTTI_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_RTTI_TESTING_H

#include "RttiTestingBase.h"
#include "CoreTools/Helper/RttiMacro.h"

namespace CoreTools
{
    class RttiTesting : public RttiTestingBase
    {
    public:
        using ClassType = RttiTesting;
        using ParentType = RttiTestingBase;

    public:
        explicit RttiTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void RttiTest() override;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_RTTI_TESTING_H