// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 18:17)

#ifndef PHYSICS_RIGID_BODY_RIGID_BODY_MANAGER_H
#define PHYSICS_RIGID_BODY_RIGID_BODY_MANAGER_H

#include "Physics/PhysicsDll.h"

#include "Mathematics/Algebra/Matrix3.h"
#include "Mathematics/Algebra/Quaternion.h"

namespace Physics
{
	template <typename Real>
	class   RigidBodyManager
	{
	public:
		using Matrix3 = Mathematics::Matrix3<Real>;
		using Quaternion = Mathematics::Quaternion<Real>;
		using Vector3D = Mathematics::Vector3<Real>;

	public:
		// Construction and destruction.  The rigid body state is uninitialized.
		// Use the set functions to initialize the state before starting the
		// simulation.
		RigidBodyManager ();
		virtual ~RigidBodyManager ();

		// Set/get position.
		Vector3D& Position ();

		// Set rigid body state.
		void SetMass (float mass);
		void SetBodyInertia (const Matrix3 & inertia);
		void SetPosition (const Vector3D & position);
		void SetQOrientation (const Quaternion& quatOrient);
		void SetLinearMomentum (const Vector3D& linearMomentum);
		void SetAngularMomentum (const Vector3D& angularMomentum);
		void SetROrientation (const Matrix3& rotOrient);
		void SetLinearVelocity (const Vector3D& linearVelocity);
		void SetAngularVelocity (const Vector3D& angularVelocity);

		// Get rigid body state.
		Real GetMass () const;
		Real GetInverseMass () const;
		const Matrix3& GetBodyInertia () const;
		const Matrix3& GetBodyInverseInertia () const;
		Matrix3 GetWorldInertia () const;
		Matrix3 GetWorldInverseInertia () const;
		const Vector3D& GetPosition () const;
		const Quaternion& GetQOrientation () const;
		const Vector3D& GetLinearMomentum () const;
		const Vector3D& GetAngularMomentum () const;
		const Matrix3& GetROrientation () const;
		const Vector3D& GetLinearVelocity () const;
		const Vector3D& GetAngularVelocity () const;

		// Force/torque function format.
		typedef Vector3D (*Function)
			(
			Real,                      // time of application
			Real,                      // mass
			const Vector3D&,     // position
			const Quaternion&,   // orientation
			const Vector3D&,     // linear momentum
			const Vector3D&,     // angular momentum
			const Matrix3&,  // orientation
			const Vector3D&,     // linear velocity
			const Vector3D&      // angular velocity
			);

		// Force and torque functions.
		Function mForce;
		Function mTorque;

		// Runge-Kutta fourth-order differential equation solver
		void Update (Real t, Real dt);

	protected:
		// Constant quantities (matrices in body coordinates).
		Real mMass, mInvMass;
		Matrix3 mInertia, mInvInertia;

		// State variables.
		Vector3D mPosition;
		Quaternion mQuatOrient;
		Vector3D mLinearMomentum;
		Vector3D mAngularMomentum;

		// Derived state variables.
		Matrix3 mRotOrient;
		Vector3D mLinearVelocity;
		Vector3D mAngularVelocity;
	};

	typedef RigidBodyManager<float> RigidBodyf;
	typedef RigidBodyManager<double> RigidBodyd;
}

#endif // PHYSICS_RIGID_BODY_RIGID_BODY_MANAGER_H
