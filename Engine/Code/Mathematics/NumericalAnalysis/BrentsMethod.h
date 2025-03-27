/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 13:46)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_H

#include "Mathematics/MathematicsDll.h"

#include "BrentsMethodRoot.h"
#include "Mathematics/Base/MathDetail.h"

namespace Mathematics
{
    template <typename Real, typename UserDataType>
    class BrentsMethod final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = BrentsMethod<Real, UserDataType>;

        using MathType = Math<Real>;
        using BrentsMethodRoot = BrentsMethodRoot<Real>;

        // һ������F(x)������һ������Ĳ�����
        // ���㴫���û���������ݸ���Ҫ�����ĺ�����
        using Function = Real (*)(Real, const UserDataType*);

    public:
        // ����Brent�ķ������ڼ���һ�������ĸ��ļ��[x0,x1]����f(x0) * f(x1) < 0�ķ�����
        // ʹ������β�ֵ���Բ���һ�����Ƹ���
        // �����Ҫ�Ļ����ں����ʵʩ�������ڲ壨�������
        // ���⣬������ǰ�����У����������ڲ�Ĺ����ǲ��㹻����ʱ���÷��������˵����ַ���

        //  function:
        //  ���������������ġ�����ָ�����ǿա�

        //  maxIterations:
        //  ���ڶ�λһ��������������������Ӧ�������ġ�
        //  negativeFTolerance, positiveFTolerance:
        //  ������x������ʱ�ĺ���ֵf(x)����
        //  negativeFTolerance <= f(x) <= positiveFTolerance��
        //  ֵ�������㣺negativeFTolerance <= 0, positiveFTolerance >= 0��
        //  stepXTolerance:
        //  Brent�ķ�����Ҫ����Ĳ���֮ǰ���ڲ�xֵ������Ϊ��һ�����Ƹ���
        //  ��Щ���Խ��бȽϵ����������Ĳ��죬
        //  ��Ҫ�������û�ָ����x����ϴ�����ȷ�����ȣ���
        //  �˲�����ƫ�
        //  convXTolerance:
        //  ������������ʱ����ֹ��ǰ�ӵ���[xsub0,xsub1]���㹻С�ģ�
        //  Ҳ����˵��|xsub1 - xsub0| <= tolerance���˲�����ƫ�
        //  userData:
        //  �˲��������㴫������Ҫ�����ĺ���ר�ŵ����ݡ�
        //  ͨ������£���function����һ����ľ�̬�������Ի��C���ĺ���ָ�룩
        //  �͡�userData����'this'���������ݵ�һ���Ӽ��ġ�this��ָ�룩��

        BrentsMethod(Function function,
                     int maxIterations,
                     Real negativeFTolerance,
                     Real positiveFTolerance,
                     Real stepXTolerance,
                     Real convXTolerance,
                     const UserDataType* userData) noexcept;

        CLASS_INVARIANT_DECLARE;

        void SetFunction(Function newFunction);
        NODISCARD Function GetFunction() const noexcept;
        void SetMaxIterations(int newMaxIterations) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        NODISCARD int GetMaxIterations() const noexcept;
        void SetNegativeFTolerance(Real newNegativeFTolerance) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        NODISCARD Real GetNegativeFTolerance() const noexcept;
        void SetPositiveFTolerance(Real newPositiveFTolerance) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        NODISCARD Real GetPositiveFTolerance() const noexcept;
        void SetStepXTolerance(Real newStepXTolerance) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        NODISCARD Real GetStepXTolerance() const noexcept;
        void SetConvXTolerance(Real newConvXTolerance) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        NODISCARD Real GetConvXTolerance() const noexcept;
        void SetUserData(const UserDataType* newUserData) noexcept;
        NODISCARD const UserDataType* GetUserData() const noexcept;

        NODISCARD Real GetFunctionValue(Real value) const;

        // �����صĸ��н�ʱ��x�Ǹ���y�Ǹ��ĺ���ֵ��
        NODISCARD BrentsMethodRoot GetRoot(Real begin, Real end);

    private:
        Function function;
        int maxIterations;
        Real negativeFTolerance;
        Real positiveFTolerance;
        Real stepXTolerance;
        Real convXTolerance;
        const UserDataType* userData;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_H
