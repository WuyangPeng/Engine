/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.5 (2024/01/22 14:00)

#ifndef CORE_TOOLS_MEMORY_TOOLS_ARRAY4_H
#define CORE_TOOLS_MEMORY_TOOLS_ARRAY4_H

#include "CoreTools/CoreToolsDll.h"

#include <vector>

/// Array4���ʾһ��4ά���飬
/// ����������޶ȵؼ����˵���new��delete��������
/// T����洢��һ�������������С�
namespace CoreTools
{
    template <typename T>
    class Array4 final
    {
    public:
        using ClassType = Array4<T>;

    public:
        /// ֧�ֶ�̬������С�����ƻ��ƶ���
        Array4() noexcept;

        /// ���������bound0�С�bound1�С�bound2��Ƭ��bound3�����塣
        Array4(int bound0, int bound1, int bound2, int bound3);
        ~Array4() noexcept = default;
        Array4(const Array4& rhs);
        Array4& operator=(const Array4& rhs);
        Array4(Array4&& rhs) noexcept;
        Array4& operator=(Array4&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        /// �������С�ʾ���÷�Ϊ
        //   Array4<T> myArray{ 5, 4, 3, 2 };
        //   T*** cuboid1 = myArray[1];
        //   T** cuboid1Slice2 = myArray[1][2];
        //   T* cuboid1Slice2Row3 = myArray[1][2][3];
        //   T cuboid1Slice2Row3Col4 = myArray[1][2][3][4];
        NODISCARD int GetBound0() const noexcept;
        NODISCARD int GetBound1() const noexcept;
        NODISCARD int GetBound2() const noexcept;
        NODISCARD int GetBound3() const noexcept;

        NODISCARD T** const* operator[](int cuboid) const;
        NODISCARD T*** operator[](int cuboid);

        NODISCARD T* const* operator()(int cuboid, int slice) const;
        NODISCARD T** operator()(int cuboid, int slice);

        NODISCARD const T* operator()(int cuboid, int slice, int row) const;
        NODISCARD T* operator()(int cuboid, int slice, int row);

        NODISCARD const T& operator()(int cuboid, int slice, int row, int column) const;
        NODISCARD T& operator()(int cuboid, int slice, int row, int column);

    private:
        void SetPointers();

        NODISCARD constexpr static int GetObjectSize(int bound0, int bound1) noexcept
        {
            return bound0 * bound1;
        }

        NODISCARD constexpr static int GetObjectSize(int bound0, int bound1, int bound2) noexcept
        {
            return bound0 * bound1 * bound2;
        }

        NODISCARD constexpr static int GetObjectSize(int bound0, int bound1, int bound2, int bound3) noexcept
        {
            return bound0 * bound1 * bound2 * bound3;
        }

    private:
        int bound0;
        int bound1;
        int bound2;
        int bound3;
        std::vector<T> objects;
        std::vector<T*> indirect1;
        std::vector<T**> indirect2;
        std::vector<T***> indirect3;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_ARRAY4_H
