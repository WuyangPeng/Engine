/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef OUTPUT_C_S_V_TESTING_OUTPUT_C_S_V_TESTING_CONTAINER_H
#define OUTPUT_C_S_V_TESTING_OUTPUT_C_S_V_TESTING_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "OutputCSVTestingFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <filesystem>
#include <memory>

namespace OutputCSVTesting
{
    class OutputCSVTestingContainer final
    {
    public:
        using ClassType = OutputCSVTestingContainer;

        using String = System::String;
        using ConstInput1ContainerSharedPtr = std::shared_ptr<const Input1Container>;
        using ConstInput2ContainerSharedPtr = std::shared_ptr<const Input2Container>;
        using ConstInput3ContainerSharedPtr = std::shared_ptr<const Input3Container>;

    public:
        explicit OutputCSVTestingContainer(const String& directory);

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

#endif  // OUTPUT_C_S_V_TESTING_OUTPUT_C_S_V_TESTING_CONTAINER_H