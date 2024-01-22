/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 19:55)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_DIRECTORY_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_DIRECTORY_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE GenerateDirectory
    {
    public:
        using ClassType = GenerateDirectory;

        using String = System::String;
        using StringView = System::StringView;

    public:
        GenerateDirectory(String input, String output) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetInputDirectory() const;
        NODISCARD String GetOutputDirectory() const;

        NODISCARD GenerateDirectory GetGenerateDirectory(const StringView& pathRoute) const;
        NODISCARD GenerateDirectory GetGenerateDirectory(const StringView& inputPathRoute, const StringView& outputPathRoute) const;
        NODISCARD GenerateDirectory GetGenerateDirectory(const StringView& inputPathRoute, const String& outputPathRoute) const;

        void CreateFileDirectory() const noexcept;
        void AddOutputPathRoute(const StringView& outputPathRoute);

    private:
        String input;
        String output;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_DIRECTORY_H
