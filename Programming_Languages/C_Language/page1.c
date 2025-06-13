// Compile with: cl volume_control_input.c /link Ole32.lib

#include <windows.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <stdio.h>

int main() {
    HRESULT hr;
    CoInitialize(NULL); // Initialize COM

    IMMDeviceEnumerator* deviceEnumerator = NULL;
    IMMDevice* defaultDevice = NULL;
    IAudioEndpointVolume* endpointVolume = NULL;

    int volumePercent = 0;

    printf("Enter desired system volume (0 to 100): ");
    scanf("%d", &volumePercent);

    if(volumePercent < 0 || volumePercent > 100) {
        printf("Invalid volume! Please enter a value between 0 and 100.\n");
        return -1;
    }

    // Convert to float scale (0.0 to 1.0)
    float newVolume = volumePercent / 100.0f;

    // Create device enumerator
    hr = CoCreateInstance(
        &CLSID_MMDeviceEnumerator, NULL, CLSCTX_INPROC_SERVER,
        &IID_IMMDeviceEnumerator, (LPVOID*)&deviceEnumerator);

    if (FAILED(hr)) {
        printf("Failed to create device enumerator.\n");
        return -1;
    }

    // Get default audio endpoint (output device)
    hr = deviceEnumerator->lpVtbl->GetDefaultAudioEndpoint(
        deviceEnumerator, eRender, eConsole, &defaultDevice);

    if (FAILED(hr)) {
        printf("Failed to get default audio endpoint.\n");
        deviceEnumerator->lpVtbl->Release(deviceEnumerator);
        return -1;
    }

    // Activate the endpoint volume interface
    hr = defaultDevice->lpVtbl->Activate(
        defaultDevice, &IID_IAudioEndpointVolume,
        CLSCTX_INPROC_SERVER, NULL, (LPVOID*)&endpointVolume);

    if (FAILED(hr)) {
        printf("Failed to activate endpoint volume interface.\n");
        defaultDevice->lpVtbl->Release(defaultDevice);
        deviceEnumerator->lpVtbl->Release(deviceEnumerator);
        return -1;
    }

    // Set master volume
    hr = endpointVolume->lpVtbl->SetMasterVolumeLevelScalar(endpointVolume, newVolume, NULL);

    if (SUCCEEDED(hr)) {
        printf("Volume set to %d%% successfully.\n", volumePercent);
    } else {
        printf("Failed to set volume.\n");
    }

    // Clean up
    endpointVolume->lpVtbl->Release(endpointVolume);
    defaultDevice->lpVtbl->Release(defaultDevice);
    deviceEnumerator->lpVtbl->Release(deviceEnumerator);
    CoUninitialize();

    return 0;
}
