///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/25 09:50)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_ENGINE_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_ENGINE_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"

ASSIST_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(GenerateTestingEngineImpl);

namespace AssistTools
{
    class ASSIST_TOOLS_DEFAULT_DECLARE GenerateTestingEngine
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(GenerateTestingEngine);

        using String = System::String;

    public:
        GenerateTestingEngine(const String& input, const String& output);

        CLASS_INVARIANT_DECLARE;

        void Generate() const;

    private:
        PackageType impl;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_ENGINE_H
