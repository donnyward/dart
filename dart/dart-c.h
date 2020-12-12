#pragma once

extern "C"
{
	void CreatePhysicsWorld();

	void DestroyPhysicsWorld();

	/*
        int CreateMultibody(
            const MultibodyConstructionInfo& mbInfo,
            const Vector& offsetPos = {0, 0, 0});

        void CreateStaticBox(
            float halfExtentsX,
            float halfExtentsY,
            float halfExtentsZ,
            float posX,
            float posY,
            float posZ);

        Degree Get1DofJointRotation(int multibodyId, Skeleton::JointId jointId);

        Quaternion Get3DofJointRotation(int multibodyId, Skeleton::JointId jointId);

        Vector GetPosition(int multibodyId, Skeleton::BoneId boneId);

        Quaternion GetRotation(int multibodyId, Skeleton::BoneId boneId);

        State GetState(int multibodyId) const;

        //get multibody frame. +X forward, +Z up

        void SetGravity(float x, float y, float z);

	*/

	int DartCTest(int x);
        
        void StepWorld(float seconds);

}
