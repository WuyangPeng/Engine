// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/08 16:06)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_GET_MINIMUM_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_GET_MINIMUM_H

#include "Mathematics/MathematicsDll.h"

#include "MinimizeNData.h"
#include "Minimize1.h"

namespace Mathematics
{
	template <typename Real, typename UserDataType>
	class MinimizeNGetMinimum
    {
    public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = MinimizeNGetMinimum<Real, UserDataType>;
		using Minimize1 = Minimize1<Real, ClassType>;
		using MinimizeNData = MinimizeNData<Real>;
		using RealVector = std::vector<Real>;
		using RealPtrVector = std::vector<Real*>;
		using Function = Real(*)(const RealVector&, const UserDataType*);
	 
	public:
		MinimizeNGetMinimum(int dimensions, const RealVector& initial, Function function,
							const UserDataType* userData, const RealVector& begin, const RealVector& end);

        CLASS_INVARIANT_DECLARE;

		int GetDimensions() const;
		Real CalculateLineArg(int index, Real value) const;
		Real GetFunctionResult(const RealVector& lineArg) const;

		void FindEachDirection(int index, int maxLevel, int maxBracket);
		Real EstimateUnitLengthConjugateDirection();
		void MinimizeConjugateDirection(Real length, int maxLevel, int maxBracket);

		const MinimizeNData& GetMinimizeNData() const;

	private:
		// ���λ�õ�Ŀǰ�Ĺ�����m_TCurr[0..d-1]��
		// ��ǰ�������ķ�����m_DCurr[0..d-1]�����߱���Եѿ����˻������������ʵ�ֵĹ��̱��ü���
		// ���������m_TCurr + s * m_DCurr���ü����������[beginResult��endResult]��
		void ComputeDomain(const RealVector& begin, const RealVector& end,Real* beginResult, Real* endResult);

		// Minimize1<Real>������ҪC���ĺ�����ִ������һά����
		// ������m_TCurr + s * m_DCurr����
		static Real LineFunction(Real value, const ClassType* userData);
    		
	private:
		int m_Dimensions;
		RealVector m_DirectionStorage;
		RealPtrVector m_Direction;
		Real* m_DirectionConjugate;
		Real* m_DirectionCurrent;
		RealVector m_Save;

		Function m_Function;		 
		const UserDataType* m_UserData;
		MinimizeNData m_MinimizeNData;
		RealVector m_Begin;
		RealVector m_End;
    }; 
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_GET_MINIMUM_H
