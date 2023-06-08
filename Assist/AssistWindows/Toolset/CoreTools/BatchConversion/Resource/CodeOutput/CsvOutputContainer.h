/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef CSV_OUTPUT_CSV_OUTPUT_CONTAINER_H
#define CSV_OUTPUT_CSV_OUTPUT_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "CsvOutputFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>

namespace CsvOutput
{
    class CsvOutputContainer final
    {
    public:
        using ClassType = CsvOutputContainer;

    public:
        explicit CsvOutputContainer(const System::String& directory);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::shared_ptr<const Input1Container> GetInput1Container() const noexcept;
        NODISCARD std::shared_ptr<const Input2Container> GetInput2Container() const noexcept;
        NODISCARD std::shared_ptr<const Input3Container> GetInput3Container() const noexcept;

    private:
        void Parsing(const System::String& directory);
        void Verify() const;

    private:
        std::shared_ptr<const Input1Container> input1Container;
        std::shared_ptr<const Input2Container> input2Container;
        std::shared_ptr<const Input3Container> input3Container;
    };
}

#endif  // CSV_OUTPUT_CONTAINER_H
