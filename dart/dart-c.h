#pragma once

extern "C"
{
    struct dartcState
    {
        float x1;
        float y1;
        float z1;

        float angx1;
        float angy1;
        float angz1;
    };

    int dartcCreateMultibody(
        float offsetX,
        float offsetY,
        float offsetZ);

    void dartcCreatePhysicsWorld();

    /*
     * Mainly for creating the ground.
     */
    void dartcCreateStaticBox(
        float lengthX,
        float lengthY,
        float lengthZ,
        float posX,
        float posY,
        float posZ);

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

    dartcState dartcGetState(int multibodyId);

    void dartcSetTimestep(float seconds);

    void dartcStepWorld();
}
