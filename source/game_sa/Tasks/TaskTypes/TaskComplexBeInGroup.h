#pragma once

#include "TaskComplex.h"

class CTaskComplexBeInGroup : public CTaskComplex {
    int32  m_nGroupId;
    bool   m_bIsLeader;
    CPed*  m_Ped;
    CTask* m_MainTask;
    int32  m_nMainTaskId;
    CTask* m_SecondaryTask;
    int32  m_nSecondaryTaskSlot; // used as index in `CTaskManager::m_aSecondaryTasks`

public:
    static constexpr auto Type = TASK_COMPLEX_BE_IN_GROUP;

    explicit CTaskComplexBeInGroup(int32 groupId, bool isLeader = false);
    ~CTaskComplexBeInGroup() override = default; // 0x632EA0

    CTask* MonitorMainGroupTask(CPed* ped);
    void MonitorSecondaryGroupTask(CPed* ped);

    CTask*    Clone() const override { return new CTaskComplexBeInGroup(m_nGroupId, m_bIsLeader); }
    eTaskType GetTaskType() const override { return Type; }
    bool      MakeAbortable(CPed* ped, eAbortPriority priority = ABORT_PRIORITY_URGENT, const CEvent* event = nullptr) override;
    CTask*    CreateNextSubTask(CPed* ped) override;
    CTask*    CreateFirstSubTask(CPed* ped) override;
    CTask*    ControlSubTask(CPed* ped) override;

private:
    auto& GetGroup() const { return CPedGroups::GetGroup(m_nGroupId); }

    friend void InjectHooksMain();
    static void InjectHooks();
    CTaskComplexBeInGroup* Constructor(int32 groupId, bool isLeader) { this->CTaskComplexBeInGroup::CTaskComplexBeInGroup(groupId, isLeader); return this; }
    CTaskComplexBeInGroup* Destructor() { this->CTaskComplexBeInGroup::~CTaskComplexBeInGroup(); return this; }
    CTask*    Clone_Reversed() { return CTaskComplexBeInGroup::Clone(); }
    eTaskType GetTaskType_Reversed() { return CTaskComplexBeInGroup::GetTaskType(); }
    bool      MakeAbortable_Reversed(CPed* ped, eAbortPriority priority, CEvent const* event) { return CTaskComplexBeInGroup::MakeAbortable(ped, priority, event); }
    CTask*    CreateNextSubTask_Reversed(CPed* ped) { return CTaskComplexBeInGroup::CreateNextSubTask(ped); }
    CTask*    CreateFirstSubTask_Reversed(CPed* ped) { return CTaskComplexBeInGroup::CreateFirstSubTask(ped); }
    CTask*    ControlSubTask_Reversed(CPed* ped) { return CTaskComplexBeInGroup::ControlSubTask(ped); }
};

VALIDATE_SIZE(CTaskComplexBeInGroup, 0x28);
