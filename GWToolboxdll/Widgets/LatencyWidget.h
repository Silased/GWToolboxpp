#pragma once

#include <ToolboxWidget.h>

class LatencyWidget : public ToolboxWidget {
    LatencyWidget() = default;
    ~LatencyWidget() override = default;


public:
    static LatencyWidget& Instance()
    {
        static LatencyWidget instance;
        return instance;
    }


    [[nodiscard]] const char* Name() const override { return "Latency"; }
    [[nodiscard]] const char* Icon() const override { return ICON_FA_STOPWATCH; }

    void Initialize() override;
    void Terminate() override;
    void Update(float delta) override;

    static void SendPing();
    static uint32_t GetPing();
    static uint32_t GetAveragePing();

    // Draw user interface. Will be called every frame if the element is visible
    void Draw(IDirect3DDevice9* pDevice) override;

    void LoadSettings(ToolboxIni* ini) override;

    void SaveSettings(ToolboxIni* ini) override;

    void DrawSettingsInternal() override;

    static ImColor GetColorForPing(uint32_t ping);
};
