/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 15:43)

#ifndef CORE_TOOLS_MEMORY_TOOLS_ARRAY2_H
#define CORE_TOOLS_MEMORY_TOOLS_ARRAY2_H

#include "CoreTools/CoreToolsDll.h"

#include <vector>

/// Array2���ʾһ��2ά���飬
/// ����������޶ȵؼ����˵���new��delete��������
/// T����洢��һ�������������С�
namespace CoreTools
{
    template <typename T>
    class Array2 final
    {
    public:
        using ClassType = Array2<T>;

    public:
        /// ֧�ֶ�̬������С�����ƻ��ƶ���
        Array2() noexcept;

        /// ���������bound0�к�bound1�С�
        Array2(int bound0, int bound1);
        ~Array2() noexcept = default;
        Array2(const Array2& rhs);
        Array2& operator=(const Array2& rhs);
        Array2(Array2&& rhs) noexcept;
        Array2& operator=(Array2&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        /// �������顣ʾ���÷�Ϊ
        ///   Array2<T> myArray{ 3, 2 };
        ///   ����objectsΪ
        ///   00 01 02
        ///   10 11 12
        ///   ����indirectָ�� 00 10��
        ///   T* row1 = myArray[1];
        ///   T row1Column2 = myArray[1][2];
        NODISCARD int GetBound0() const noexcept;
        NODISCARD int GetBound1() const noexcept;

        NODISCARD const T* operator[](int row) const;
        NODISCARD T* operator[](int row);

        NODISCARD const T& operator()(int row, int column) const;
        NODISCARD T& operator()(int row, int column);

    private:
        void SetPointers();

        NODISCARD constexpr static int GetObjectSize(int bound0, int bound1) noexcept
        {
            return bound0 * bound1;
        }

    private:
        int bound0;
        int bound1;
        std::vector<T> objects;
        std::vector<T*> indirect;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_ARRAY2_H
