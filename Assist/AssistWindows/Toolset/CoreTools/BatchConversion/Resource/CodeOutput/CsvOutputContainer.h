/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef CSV_OUTPUT_CSV_OUTPUT_CONTAINER_H
#define CSV_OUTPUT_CSV_OUTPUT_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "CsvOutputFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <filesystem>
#include <memory>

namespace CsvOutput
{
    class CsvOutputContainer final
    {
    public:
        using ClassType = CsvOutputContainer;

        using String = System::String;
        using ConstInput1ContainerSharedPtr = std::shared_ptr<const Input1Container>;
        using ConstInput2ContainerSharedPtr = std::shared_ptr<const Input2Container>;
        using ConstInput3ContainerSharedPtr = std::shared_ptr<const Input3Container>;

    public:
        explicit CsvOutputContainer(const String& directory);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstInput1ContainerSharedPtr GetInput1Container() const noexcept;
        NODISCARD ConstInput2ContainerSharedPtr GetInput2Container() const noexcept;
        NODISCARD ConstInput3ContainerSharedPtr GetInput3Container() const noexcept;

    private:
        void Parsing(const String& directory);
        void Parsing(const std::filesystem::directory_entry& inputPath);
        void Verify() const;

    private:
        ConstInput1ContainerSharedPtr input1Container;
        ConstInput2ContainerSharedPtr input2Container;
        ConstInput3ContainerSharedPtr input3Container;
    };
}

#endif  // CSV_OUTPUT_CSV_OUTPUT_CONTAINER_H