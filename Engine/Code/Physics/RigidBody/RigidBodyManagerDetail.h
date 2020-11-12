// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 18:15)

#ifndef PHYSICS_RIGID_BODY_RIGID_BODY_MANAGER_DETAIL_H
#define PHYSICS_RIGID_BODY_RIGID_BODY_MANAGER_DETAIL_H

#include "RigidBodyManager.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/QuaternionDetail.h"

namespace Physics
{
	template <typename Real>
	RigidBodyManager<Real>::RigidBodyManager()
	{
		// The default body is immovable.
		mMass = Mathematics::Math<Real>::sm_MaxReal;
		mInvMass = (Real)0;
		mInertia = Matrix3::sm_Identity;
		mInvInertia = Matrix3::sm_Zero;
		mPosition = Vector3D::sm_Zero;
		mQuatOrient = Quaternion::sm_Identity;
		mLinearMomentum = Vector3D::sm_Zero;
		mAngularMomentum = Vector3D::sm_Zero;
		mRotOrient = Matrix3::sm_Identity;
		mLinearVelocity = Vector3D::sm_Zero;
		mAngularVelocity = Vector3D::sm_Zero;
	}

	template <typename Real>
	RigidBodyManager<Real>::~RigidBodyManager()
	{
	}

	template <typename Real>
	Mathematics::Vector3D<Real>& RigidBodyManager<Real>::Position()
	{
		return mPosition;
	}

	template <typename Real>
	void RigidBodyManager<Real>::SetMass(float mass)
	{
		if ((Real)0 < mass && mass < Mathematics::Math<Real>::sm_MaxReal)
		{
			mMass = mass;
			mInvMass = ((Real)1) / mass;
		}
		else
		{
			// Assume the body as immovable.
			mMass = Mathematics::Math<Real>::sm_MaxReal;
			mInvMass = (Real)0;
			mInertia = Matrix3::sm_Identity;
			mInvInertia = Matrix3::sm_Zero;
			mQuatOrient = Quaternion::sm_Identity;
			mLinearMomentum = Vector3D::sm_Zero;
			mAngularMomentum = Vector3D::sm_Zero;
			mRotOrient = Matrix3::sm_Identity;
			mLinearVelocity = Vector3D::sm_Zero;
			mAngularVelocity = Vector3D::sm_Zero;
		}
	}

	template <typename Real>
	void RigidBodyManager<Real>::SetBodyInertia(const Matrix3& inertia)
	{
		mInertia = inertia;
		mInvInertia = mInertia.Inverse();
	}

	template <typename Real>
	void RigidBodyManager<Real>::SetPosition(const Vector3D& position)
	{
		mPosition = position;
	}

	template <typename Real>
	void RigidBodyManager<Real>::SetQOrientation(const Quaternion& quatOrient)
	{
		mQuatOrient = quatOrient;
		mRotOrient = mQuatOrient.ToRotationMatrix();
	}

	template <typename Real>
	void RigidBodyManager<Real>::SetLinearMomentum(const Vector3D& linearMomentum)
	{
		mLinearMomentum = linearMomentum;
		mLinearVelocity = mInvMass * mLinearMomentum;
	}

	template <typename Real>
	void RigidBodyManager<Real>::SetAngularMomentum(
		const Vector3D& angularMomentum)
	{
		mAngularMomentum = angularMomentum;
		mAngularVelocity = mRotOrient * mInvInertia * mRotOrient.Transpose() * mAngularMomentum;
	}

	template <typename Real>
	void RigidBodyManager<Real>::SetROrientation(const Matrix3& rotOrient)
	{
		mRotOrient = rotOrient;
		mQuatOrient.FromRotationMatrix(mRotOrient);
	}

	template <typename Real>
	void RigidBodyManager<Real>::SetLinearVelocity(const Vector3D& linearVelocity)
	{
		mLinearVelocity = linearVelocity;
		mLinearMomentum = mMass * mLinearVelocity;
	}

	template <typename Real>
	void RigidBodyManager<Real>::SetAngularVelocity(const Vector3D& angularVelocity)
	{
		mAngularVelocity = angularVelocity;
		mAngularMomentum = mRotOrient * mInertia * mRotOrient.Transpose() *	mAngularVelocity;
	}

	template <typename Real>
	Real RigidBodyManager<Real>::GetMass() const
	{
		return mMass;
	}

	template <typename Real>
	Real RigidBodyManager<Real>::GetInverseMass() const
	{
		return mInvMass;
	}

	template <typename Real>
	const Mathematics::Matrix3<Real>& RigidBodyManager<Real>::GetBodyInertia() const
	{
		return mInertia;
	}

	template <typename Real>
	const Mathematics::Matrix3<Real>& RigidBodyManager<Real>::GetBodyInverseInertia() const
	{
		return mInvInertia;
	}

	template <typename Real>
	Mathematics::Matrix3<Real> RigidBodyManager<Real>::GetWorldInertia() const
	{
		return mRotOrient * mInertia*mRotOrient.Transpose();
	}

	template <typename Real>
	Mathematics::Matrix3<Real> RigidBodyManager<Real>::GetWorldInverseInertia() const
	{
		return mRotOrient * mInvInertia*mRotOrient.Transpose();
	}

	template <typename Real>
	const Mathematics::Vector3D<Real>& RigidBodyManager<Real>::GetPosition() const
	{
		return mPosition;
	}

	template <typename Real>
	const Mathematics::Quaternion<Real>& RigidBodyManager<Real>::GetQOrientation() const
	{
		return mQuatOrient;
	}

	template <typename Real>
	const Mathematics::Vector3D<Real>& RigidBodyManager<Real>::GetLinearMomentum() const
	{
		return mLinearMomentum;
	}

	template <typename Real>
	const Mathematics::Vector3D<Real>& RigidBodyManager<Real>::GetAngularMomentum() const
	{
		return mAngularMomentum;
	}

	template <typename Real>
	const Mathematics::Matrix3<Real>& RigidBodyManager<Real>::GetROrientation() const
	{
		return mRotOrient;
	}

	template <typename Real>
	const Mathematics::Vector3D<Real>& RigidBodyManager<Real>::GetLinearVelocity() const
	{
		return mLinearVelocity;
	}

	template <typename Real>
	const Mathematics::Vector3D<Real>& RigidBodyManager<Real>::GetAngularVelocity() const
	{
		return mAngularVelocity;
	}

	template <typename Real>
	void RigidBodyManager<Real>::Update(Real t, Real dt)
	{
		Real halfDT = ((Real)0.5)*dt;
		Real sixthDT = dt / ((Real)6);
		Real TpHalfDT = t + halfDT;
		Real TpDT = t + dt;

		Vector3D newPosition, newLinearMomentum, newAngularMomentum,newLinearVelocity, newAngularVelocity;
		Quaternion newQuatOrient;
		Matrix3 newRotOrient;

		// A1 = G(T,S0), B1 = S0 + (DT/2)*A1
		Vector3D A1DXDT = mLinearVelocity;
		Quaternion W = Quaternion((Real)0, mAngularVelocity.GetX(),mAngularVelocity.GetY(), mAngularVelocity.GetZ());
		Quaternion A1DQDT = ((Real)0.5)*W*mQuatOrient;

		Vector3D A1DPDT = mForce(t, mMass, mPosition, mQuatOrient,mLinearMomentum, mAngularMomentum, mRotOrient, mLinearVelocity,mAngularVelocity);

		Vector3D A1DLDT = mTorque(t, mMass, mPosition, mQuatOrient,mLinearMomentum, mAngularMomentum, mRotOrient, mLinearVelocity,mAngularVelocity);

		newPosition = mPosition + halfDT * A1DXDT;
		newQuatOrient = mQuatOrient + halfDT * A1DQDT;
		newLinearMomentum = mLinearMomentum + halfDT * A1DPDT;
		newAngularMomentum = mAngularMomentum + halfDT * A1DLDT;
		newRotOrient = newQuatOrient.ToRotationMatrix();
		newLinearVelocity = mInvMass * newLinearMomentum;
		newAngularVelocity = newRotOrient * mInvInertia*newRotOrient.Transpose()*newAngularMomentum;

		// A2 = G(T+DT/2,B1), B2 = S0 + (DT/2)*A2
		Vector3D A2DXDT = newLinearVelocity;
		W = Quaternion((Real)0, newAngularVelocity.GetX(),newAngularVelocity.GetY(), newAngularVelocity.GetZ());
		Quaternion A2DQDT = ((Real)0.5)*W*newQuatOrient;

		Vector3D A2DPDT = mForce(TpHalfDT, mMass, newPosition,newQuatOrient, newLinearMomentum, newAngularMomentum, newRotOrient,newLinearVelocity, newAngularVelocity);

		Vector3D A2DLDT = mTorque(TpHalfDT, mMass, newPosition,newQuatOrient, newLinearMomentum, newAngularMomentum, newRotOrient,newLinearVelocity, newAngularVelocity);

		newPosition = mPosition + halfDT * A2DXDT;
		newQuatOrient = mQuatOrient + halfDT * A2DQDT;
		newLinearMomentum = mLinearMomentum + halfDT * A2DPDT;
		newAngularMomentum = mAngularMomentum + halfDT * A2DLDT;
		newRotOrient = newQuatOrient.ToRotationMatrix();
		newLinearVelocity = mInvMass * newLinearMomentum;
		newAngularVelocity = newRotOrient * mInvInertia*newRotOrient.Transpose()*newAngularMomentum;

		// A3 = G(T+DT/2,B2), B3 = S0 + DT*A3
		Vector3D A3DXDT = newLinearVelocity;
		W = Quaternion((Real)0, newAngularVelocity.GetX(),newAngularVelocity.GetY(), newAngularVelocity.GetZ());
		Quaternion A3DQDT = ((Real)0.5)*W*newQuatOrient;

		Vector3D A3DPDT = mForce(TpHalfDT, mMass, newPosition,newQuatOrient, newLinearMomentum, newAngularMomentum, newRotOrient,newLinearVelocity, newAngularVelocity);

		Vector3D A3DLDT = mTorque(TpHalfDT, mMass, newPosition,newQuatOrient, newLinearMomentum, newAngularMomentum, newRotOrient,newLinearVelocity, newAngularVelocity);

		newPosition = mPosition + dt * A3DXDT;
		newQuatOrient = mQuatOrient + dt * A3DQDT;
		newLinearMomentum = mLinearMomentum + dt * A3DPDT;
		newAngularMomentum = mAngularMomentum + dt * A3DLDT;
		newRotOrient = newQuatOrient.ToRotationMatrix();
		newLinearVelocity = mInvMass * newLinearMomentum;
		newAngularVelocity = newRotOrient * mInvInertia*newRotOrient.Transpose()*newAngularMomentum;

		// A4 = G(T+DT,B3), S1 = S0 + (DT/6)*(A1+2*(A2+A3)+A4)
		Vector3D A4DXDT = newLinearVelocity;
		W = Quaternion((Real)0, newAngularVelocity.GetX(),newAngularVelocity.GetY(), newAngularVelocity.GetZ());
		Quaternion A4DQDT = ((Real)0.5)*W*newQuatOrient;

		Vector3D A4DPDT = mForce(TpDT, mMass, newPosition,newQuatOrient, newLinearMomentum, newAngularMomentum, newRotOrient,newLinearVelocity, newAngularVelocity);

		Vector3D A4DLDT = mTorque(TpDT, mMass, newPosition, newQuatOrient,newLinearMomentum, newAngularMomentum, newRotOrient, newLinearVelocity,newAngularVelocity);

		mPosition = mPosition + sixthDT * (A1DXDT +((Real)2)*(A2DXDT + A3DXDT) + A4DXDT);

		mQuatOrient = mQuatOrient + sixthDT * (A1DQDT +((Real)2)*(A2DQDT + A3DQDT) + A4DQDT);

		mLinearMomentum = mLinearMomentum + sixthDT * (A1DPDT +((Real)2)*(A2DPDT + A3DPDT) + A4DPDT);

		mAngularMomentum = mAngularMomentum + sixthDT * (A1DLDT +((Real)2)*(A2DLDT + A3DLDT) + A4DLDT);

		mRotOrient = mQuatOrient.ToRotationMatrix();
		mLinearVelocity = mInvMass * mLinearMomentum;
		mAngularVelocity = mRotOrient * mInvInertia*mRotOrient.Transpose()*mAngularMomentum;
	}
}

#endif // PHYSICS_RIGID_BODY_RIGID_BODY_MANAGER_DETAIL_H
