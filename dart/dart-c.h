#pragma once

extern "C"
{
    int dartcCreateMultibody(
        float offsetX,
        float offsetY,
        float offsetZ);

    void dartcCreatePhysicsWorld();

    float dartcDartCTest();

    void dartcDestroyPhysicsWorld();


    /*
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

        
    void dartcStepWorld(float seconds);
}
