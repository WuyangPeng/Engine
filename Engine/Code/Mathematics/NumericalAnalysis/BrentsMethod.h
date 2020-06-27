// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/20 12:47)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_H

#include "Mathematics/MathematicsDll.h"

#include "BrentsMethodRoot.h"
#include "Mathematics/Base/Math.h"

namespace Mathematics
{
	template <typename Real, typename UserDataType>
	class BrentsMethod
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = BrentsMethod<Real, UserDataType>;
		using Math = Math<Real>;
		using BrentsMethodRoot = BrentsMethodRoot<Real>;

		// һ������F(x)������һ������Ĳ�����
		// ���㴫���û���������ݸ���Ҫ�����ĺ�����
		using Function = Real(*)(Real, const UserDataType*);

	public:
		// ����Brent�ķ������ڼ���һ�������ĸ��ļ��[x0,x1]����f(x0)*f(x1) < 0�ķ�����
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

		BrentsMethod(Function function, int maxIterations, Real negativeFTolerance, Real positiveFTolerance,
					 Real stepXTolerance, Real convXTolerance, const UserDataType* userData);
		~BrentsMethod();

		CLASS_INVARIANT_DECLARE;

		void SetFunction(Function function);
		Function GetFunction() const;
		void SetMaxIterations(int maxIterations);
		int GetMaxIterations() const;
		void SetNegativeFTolerance(Real negativeFTolerance);
		Real GetNegativeFTolerance() const;
		void SetPositiveFTolerance(Real positiveFTolerance);
		Real GetPositiveFTolerance() const;
		void SetStepXTolerance(Real stepXTolerance);
		Real GetStepXTolerance() const;
		void SetConvXTolerance(Real convXTolerance);
		Real GetConvXTolerance() const;
		void SetUserData(const UserDataType* userData);
		const UserDataType* GetUserData() const;

		Real GetFunctionValue(Real value) const;

		// �����صĸ��н�ʱ��x�Ǹ���y�Ǹ��ĺ���ֵ��
		const BrentsMethodRoot GetRoot(Real begin, Real end);

	private:
		Function m_Function;
		int m_MaxIterations;
		Real m_NegativeFTolerance;
		Real m_PositiveFTolerance;
		Real m_StepXTolerance;
		Real m_ConvXTolerance;
		const UserDataType* m_UserData;
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_H
