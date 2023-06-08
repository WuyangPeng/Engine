///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 16:42)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_GET_MINIMUM_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_GET_MINIMUM_H

#include "Mathematics/MathematicsDll.h"

#include "Minimize1.h"
#include "MinimizeNData.h"

namespace Mathematics
{
    template <typename Real, typename UserDataType>
    class MinimizeNGetMinimum final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = MinimizeNGetMinimum<Real, UserDataType>;
        using Math = Math<Real>;
        using Minimize1 = Minimize1<Real, ClassType>;
        using MinimizeNData = MinimizeNData<Real>;
        using Container = std::vector<Real>;
        using IndexContainer = std::vector<int>;
        using Function = Real (*)(const Container&, const UserDataType*);

    public:
        MinimizeNGetMinimum(int dimensions,
                            const Container& initial,
                            Function function,
                            const UserDataType* userData,
                            const Container& begin,
                            const Container& end);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetDimensions() const noexcept;
        NODISCARD Real CalculateLineArg(int index, Real value) const;
        NODISCARD Real GetFunctionResult(const Container& lineArg) const;

        void FindEachDirection(int index, int maxLevel, int maxBracket);
        NODISCARD Real EstimateUnitLengthConjugateDirection();
        void MinimizeConjugateDirection(Real length, int maxLevel, int maxBracket);

        NODISCARD const MinimizeNData& GetMinimizeNData() const noexcept;

    private:
        struct DomainResult
        {
            Real beginResult;
            Real endResult;

            DomainResult(Real beginResult, Real endResult) noexcept;
        };

        // ���λ�õ�Ŀǰ�Ĺ�����m_TCurr[0..d-1]��
        // ��ǰ�������ķ�����m_DCurr[0..d-1]�����߱���Եѿ����˻������������ʵ�ֵĹ��̱��ü���
        // ���������m_TCurr + s * m_DCurr���ü����������[beginResult��endResult]��
        NODISCARD DomainResult ComputeDomain(const Container& begin, const Container& end);

        // Minimize1<Real>������ҪC���ĺ�����ִ������һά����
        // ������m_TCurr + s * m_DCurr����
        NODISCARD static Real LineFunction(Real value, const MinimizeNGetMinimum* userData);

        NODISCARD Real GetDirectionCurrent(int index) const;
        void SetDirectionCurrent(int index) noexcept;

        NODISCARD constexpr static int GetIndexSize(int dimensions)
        {
            return dimensions + 1;
        }

        NODISCARD constexpr static int GetStorageSize(int dimensions)
        {
            return dimensions * GetIndexSize(dimensions);
        }

    private:
        int dimensions;
        Container directionStorage;
        IndexContainer directionIndex;
        int directionConjugateIndex;
        int directionCurrentIndex;
        Container save;

        Function function;
        const UserDataType* userData;
        MinimizeNData minimizeNData;
        Container beginContainer;
        Container endContainer;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_GET_MINIMUM_H
