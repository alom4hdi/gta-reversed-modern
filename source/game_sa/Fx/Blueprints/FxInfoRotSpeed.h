#pragma once

#include "FxInfo.h"
#include "FxInterpInfoFloat.h"

class FxInfoRotSpeed_c : public FxInfo_c {
protected:
    FxInterpInfoFloat_c m_InterpInfo;

public:
    FxInfoRotSpeed_c();
    ~FxInfoRotSpeed_c() override = default;

    void Load(FILESTREAM file, int32 version) override;
    void GetValue(float currentTime, float mult, float totalTime, float length, bool useConst, void* info) override;
};
